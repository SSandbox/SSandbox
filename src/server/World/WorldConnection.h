/*
 * Copyright (C) 2020 SSandbox project (https://github.com/SSandbox)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 */

#pragma once
#include "Socket.h"
#include "PlayerSession.h"
#include "Sha256.h"
#include "HmacSha256.h"
#include "Rsa.h"
#include "AES.h"
#include "SessionKeyGeneration.h"

namespace World
{

class Connection final : public Network::Socket<asio::ip::tcp::socket>
{
    constexpr static char serverConnectionString[] = "WORLD OF WARCRAFT CONNECTION - SERVER TO CLIENT - V2\n";
    constexpr static char clientConnectionString[] = "WORLD OF WARCRAFT CONNECTION - CLIENT TO SERVER - V2\n";

    static constexpr uint8 WindowsSeed[16] = { 0x0E, 0xCE, 0x03, 0x3C, 0xA9, 0xB1, 0x1D, 0x92, 0xF7, 0xD2, 0x79, 0x2C, 0x78, 0x5B, 0x47, 0xDF };
    static constexpr uint8 AuthCheckSeed[16] = { 0xC5, 0xC6, 0x98, 0x95, 0x76, 0x3F, 0x1D, 0xCD, 0xB6, 0xA1, 0x37, 0x28, 0xB3, 0x12, 0xFF, 0x8A };
    static constexpr uint8 SessionKeySeed[16] = { 0x58, 0xCB, 0xCF, 0x40, 0xFE, 0x2E, 0xCE, 0xA6, 0x5A, 0x90, 0xB8, 0x01, 0x68, 0x6C, 0x28, 0x0B };
    static constexpr uint8 ContinuedSessionSeed[16] = { 0x16, 0xAD, 0x0C, 0xD4, 0x46, 0xF9, 0x4F, 0xB2, 0xEF, 0x7D, 0xEA, 0x2A, 0x17, 0x66, 0x4D, 0x2F };
    static constexpr uint8 EncryptionKeySeed[16] = { 0xE9, 0x75, 0x3C, 0x50, 0x90, 0x93, 0x61, 0xDA, 0x3B, 0x07, 0xEE, 0xFA, 0xFF, 0x9D, 0x41, 0xB8 };
    static constexpr uint8 EnableEncryptionSeed[16] = { 0x90, 0x9C, 0xD0, 0x50, 0x5A, 0x2C, 0x14, 0xDD, 0x5C, 0x2C, 0xC0, 0x64, 0x14, 0xF3, 0xFE, 0xC9 };

    struct Header
    {
        uint32 Size;
        uint8 Tag[12];
    };

public:
    // Needs to be here for SocketMgr
    using SocketType = Network::Socket<asio::ip::tcp::socket>;

    Connection(SocketType::RawSocketType&& socket) : SocketType(std::move(socket)), _initialized(false), _header(sizeof(Header)), _sentPacketCounter(0), _receivedPacketCounter(0), _playerSession(nullptr), _account(nullptr), _serverCrypt(), _clientCrypt(), _connectionType(ConnectionType::Realm), _connectToKey()
    {
        Log::Log(LogSeverity::WorldConnectionInfo, "New connection from %s:%i", GetRemoteAddress().c_str(), GetRemotePort());
        std::memset(_aesKey.data(), 0, _aesKey.size());
    }

    void OnStart() final
    {

        OnRead(std::bind(&Connection::HandleRead, this));
        AsyncRead();

        Network::SocketBuffer buffer;
        buffer.Write(serverConnectionString, sizeof(serverConnectionString) - 1);
        Enqueue(std::move(buffer));
    }

    void HandleRead()
    {
        for (auto size = _readBuffer.GetReadableSize(); size; size = _readBuffer.GetReadableSize())
        {
            if (!_initialized)
            {
                if (size >= sizeof(clientConnectionString) - 1)
                {
                    std::string_view view(_readBuffer.GetReadPointer(), sizeof(clientConnectionString) - 1);

                    if (view != clientConnectionString)
                    {
                        Close();
                        return;
                    }

                    _readBuffer.AdvanceReadPos(view.size());
                    _initialized = true;
                    SendAuthChallenge();
                }
                else
                    return;
            }
            else
            {
                if (auto remainingHeaderSize = _header.GetRemainingSize())
                {
                    auto sizeToRead = std::min(remainingHeaderSize, size);
                    _header.Write(_readBuffer.GetReadPointer(), sizeToRead);
                    _readBuffer.AdvanceReadPos(sizeToRead);

                    if (sizeToRead != remainingHeaderSize)
                        continue;

                    Header const* header = reinterpret_cast<Header const*>(_header.GetReadPointer());
                    _packet.ResetForNetwork(header->Size);
                }

                Header const* header = reinterpret_cast<Header const*>(_header.GetReadPointer());

                if (header->Size > 128 * 1024)
                {
                    Close();
                    return;
                }

                if (_packet.FromSocketBuffer(_readBuffer, header->Size))
                {
                    ProcessEncryption(*const_cast<Header*>(header), _packet, false);
                    HandleNewPacket(_packet);
                    _header.Reset(sizeof(Header));
                }
            }
        }
    }

    void HandleNewPacket(Packet const& packet)
    {
        auto opcode = packet.GetOpcode();

        if (!OpcodeInfo::IsValid(opcode))
        {
            Log::Log(LogSeverity::WorldConnectionInfo, "Received invalid opcode 0x%04X size: %i connectionIndex: %i", opcode, packet.GetWritePos() - 2, _connectionType);
            Close();
            return;
        }

        auto& opcodeInfo = GetOpcodeInfo(opcode);
        if (!opcodeInfo.Name)
        {
            Log::Log(LogSeverity::WorldConnectionInfo, "Received unknown opcode 0x%04X size: %i connectionIndex: %i", opcode, packet.GetWritePos() - 2, _connectionType);
            return;
        }

        Log::Log(LogSeverity::WorldConnectionInfo, "Received opcode %s (0x%04X) size: %i connectionIndex: %i", opcodeInfo.Name, opcode, packet.GetWritePos() - 2, _connectionType);

        try
        {
            switch (packet.GetOpcode())
            {
                case Opcode::CMSG_AUTH_SESSION:
                    HandleAuthSession(packet);
                    break;
                case Opcode::CMSG_AUTH_CONTINUED_SESSION:
                    HandleAuthContinuedSession(packet);
                    break;
                case Opcode::CMSG_ENABLE_ENCRYPTION_ACK:
                    HandleEnableEncryptionAck(packet);
                    break;
                default:
                    if (_playerSession)
                        _playerSession->DispatchPacket(packet);
                    break;
            }
        }
        catch (std::exception ex)
        {

        }
    }

    void SendPacket(Packet& packet)
    {
        Opcode opcode = packet.GetOpcode();
        auto& opcodeInfo = GetOpcodeInfo(opcode);

        Header header;
        header.Size = packet.GetUsedSize();
        ProcessEncryption(header, packet, true);

        Network::SocketBuffer buffer(sizeof(Header) + header.Size);
        buffer.Write(&header);
        buffer.Write(packet.GetBuffer(), header.Size);

        Log::Log(LogSeverity::WorldConnectionInfo, "Sent opcode %s (0x%04X) size: %i connectionIndex: %i", opcodeInfo.Name, opcode, packet.GetWritePos() - 2, _connectionType);

        Enqueue(std::move(buffer));
    }

    void SendAuthChallenge()
    {
        GenerateServerSeed();

        char dosChallenge[32];
        memset(dosChallenge, 0, sizeof(dosChallenge));

        Packet packet(Opcode::SMSG_AUTH_CHALLENGE, 16 + 32 + 1);
        packet.WriteBytes(dosChallenge, sizeof(dosChallenge));
        packet.WriteBytes(_serverSeed.data(), _serverSeed.size());
        packet << uint8(1);                                         // DosZeroBits
        SendPacket(packet);
    }

    void HandleAuthSession(Packet const& packet)
    {
        std::array<char, 24> digest;
        std::array<char, 16> clientSeed;
        uint32 accountNameSize;

        packet.ReadSkip<uint64>();  // DosResponse
        packet.ReadSkip<uint32>();  // RegionID;
        packet.ReadSkip<uint32>();  // BattlegroupID;
        packet.ReadSkip<uint32>();  // RealmID;
        packet.ReadBytes(clientSeed.data(), clientSeed.size());
        packet.ReadBytes(digest.data(), digest.size());
        packet.ReadSkip<int8>();    // UseIPv6
        packet >> accountNameSize;

        auto accountName = packet.ReadString(accountNameSize);
        _account = Account::Mgr::Instance().GetAccountByName(accountName);

        if (!_account)
        {
            Close();
            return;
        }

        Crypt::Sha256 windowsSeedHash;
        windowsSeedHash.UpdateData(_account->GetSecret().data(), _account->GetSecret().size());
        windowsSeedHash.UpdateData(WindowsSeed, sizeof(WindowsSeed));
        windowsSeedHash.Finalize();

        Crypt::HmacSha256 authCheckHmac(windowsSeedHash.GetDigest(), Crypt::HmacSha256::Length);
        authCheckHmac.UpdateData(clientSeed.data(), clientSeed.size());
        authCheckHmac.UpdateData(_serverSeed.data(), _serverSeed.size());
        authCheckHmac.UpdateData(AuthCheckSeed, sizeof(AuthCheckSeed));
        authCheckHmac.Finalize();

        /*if (memcmp(digest.data(), authCheckHmac.GetDigest(), digest.size()))
        {
            FinishSendingAndClose();
            return;
        }*/

        Crypt::Sha256 authKeyHash;
        authKeyHash.UpdateData(_account->GetSecret().data(), _account->GetSecret().size());
        authKeyHash.Finalize();

        Crypt::HmacSha256 sessionKeyHmac(authKeyHash.GetDigest(), Crypt::HmacSha256::Length);
        sessionKeyHmac.UpdateData(_serverSeed.data(), _serverSeed.size());
        sessionKeyHmac.UpdateData(clientSeed.data(), clientSeed.size());
        sessionKeyHmac.UpdateData(SessionKeySeed, sizeof(SessionKeySeed));
        sessionKeyHmac.Finalize();

        uint8 sessionKeyHash[Crypt::HmacSha256::Length];
        std::memcpy(sessionKeyHash, sessionKeyHmac.GetDigest(), Crypt::HmacSha256::Length);

        uint8 sessionKey[40];
        Crypt::SessionKeyGenerator sessionKeyGenerator(sessionKeyHash, Crypt::HmacSha256::Length);
        sessionKeyGenerator.Generate(sessionKey, _sessionKey.size());

        Crypt::HmacSha256 encryptKeyGen(sessionKey, sizeof(sessionKey));
        encryptKeyGen.UpdateData(clientSeed.data(), clientSeed.size());
        encryptKeyGen.UpdateData(_serverSeed.data(), _serverSeed.size());
        encryptKeyGen.UpdateData(EncryptionKeySeed, sizeof(EncryptionKeySeed));
        encryptKeyGen.Finalize();

        std::memcpy(_aesKey.data(), encryptKeyGen.GetDigest(), 16);
        std::memcpy(_sessionKey.data(), sessionKey, _sessionKey.size());

        if (_playerSession)
        {
            FinishSendingAndClose();
            return;
        }

        _playerSession = std::make_shared<Player::Session>(_account);
        _playerSession->SetConnection(_connectionType, this);

        EnableEncryption();
    }

    void HandleAuthContinuedSession(Packet const& packet)
    {
        _connectionType = ConnectionType::Instance;

        uint64 key;
        std::array<char, 16> clientSeed;
        std::array<char, 24> digest;

        packet.ReadSkip<uint64>();   // DosResponse
        packet >> key;
        packet.ReadBytes(clientSeed.data(), clientSeed.size());
        packet.ReadBytes(digest.data(), digest.size());

        auto primaryConnection = GetConnectionByKeyAndErase(key);

        if (!primaryConnection)
        {
            FinishSendingAndClose();
            return;
        }

        InitFromOtherConnection(*primaryConnection);

        Crypt::HmacSha256 hmac(_sessionKey.data(), _sessionKey.size());
        hmac.UpdateData(&key, sizeof(key));
        hmac.UpdateData(clientSeed.data(), clientSeed.size());
        hmac.UpdateData(_serverSeed.data(), _serverSeed.size());
        hmac.UpdateData(ContinuedSessionSeed, 16);
        hmac.Finalize();

        if (memcmp(digest.data(), hmac.GetDigest(), digest.size()))
        {
            Log::Log(LogSeverity::WorldConnectionInfo, "Auth failed for account %s", _account->GetName().c_str());
            FinishSendingAndClose();
            return;
        }

        Crypt::HmacSha256 keyHash(_sessionKey.data(), _sessionKey.size());
        keyHash.UpdateData(clientSeed.data(), clientSeed.size());
        keyHash.UpdateData(_serverSeed.data(), _serverSeed.size());
        keyHash.UpdateData(EncryptionKeySeed, sizeof(EncryptionKeySeed));
        keyHash.Finalize();

        // only first 16 bytes of the hmac are used
        std::memcpy(_aesKey.data(), keyHash.GetDigest(), _aesKey.size());

        _playerSession->SetConnection(_connectionType, this);

        EnableEncryption();
    }

    void InitFromOtherConnection(World::Connection& connection)
    {
        std::memcpy(_sessionKey.data(), connection._sessionKey.data(), _sessionKey.size());
        _playerSession = connection._playerSession;
        _account = connection._account;
    }

    uint64 GenerateKey()
    {
        uint64 rand = Utils::Random<uint64>();
        gKeyToSession.emplace(rand, this);
        return rand;
    }

    struct RaceClassInfo
    {

        friend class Buffer& operator<<(Buffer& buffer, RaceClassInfo const& info)
        {
            for (auto const& race : info._info)
            {
                auto const& classes = race.second;

                buffer << uint8(race.first);
                buffer << uint32(classes.size());

                for (auto const& playerClass : classes)
                {
                    buffer << uint8(playerClass.ClassID);
                    buffer << uint8(playerClass.Expansion1);
                    buffer << uint8(playerClass.Expansion2);
                }
            }
            return buffer;
        }

        void WriteEnumData(Buffer& buffer) const
        {
            for (auto const& race : _info)
            {
                buffer << uint32(race.first);
                buffer.WriteBits<1>(1);
                buffer.WriteBits<1>(1);
                buffer.WriteBits<1>(1);
                buffer.FlushBits();
            }
        }

        static RaceClassInfo const& Instance()
        {
            static RaceClassInfo gRaceClassInfo;
            return gRaceClassInfo;
        }

        RaceClassInfo()
        {
            _info[1] = { {1, 0, 0}, {2, 0, 0}, {4, 0, 0}, {5, 0, 0}, {8, 0, 0}, {9, 0, 0}, {6, 2, 0}, {3, 0, 0}, {10, 4, 0} };
            _info[2] = { {1, 0, 0}, {3, 0, 0}, {4, 0, 0}, {7, 0, 0}, {9, 0, 0}, {6, 2, 0}, {8, 0, 0}, {10, 4, 0} };
            _info[3] = { {1, 0, 0}, {2, 0, 0}, {3, 0, 0}, {5, 0, 0}, {4, 0, 0}, {6, 2, 0}, {8, 0, 0}, {7, 0, 0}, {9, 0, 0}, {10, 4, 0} };
            _info[4] = { {1, 0, 0}, {3, 0, 0}, {4, 0, 0}, {5, 0, 0}, {11, 0, 0}, {6, 2, 0}, {8, 0, 0}, {10, 4, 0}, {12, 0, 0} };
            _info[5] = { {1, 0, 0}, {4, 0, 0}, {5, 0, 0}, {8, 0, 0}, {9, 0, 0}, {6, 2, 0}, {3, 0, 0}, {10, 4, 0} };
            _info[6] = { {1, 0, 0}, {3, 0, 0}, {7, 0, 0}, {11, 0, 0}, {6, 2, 0}, {5, 0, 0}, {2, 0, 0}, {10, 4, 0} };
            _info[7] = { {1, 0, 0}, {4, 0, 0}, {8, 0, 0}, {9, 0, 0}, {6, 2, 0}, {5, 0, 0}, {10, 4, 0}, {3, 0, 0} };
            _info[8] = { {1, 0, 0}, {4, 0, 0}, {3, 0, 0}, {5, 0, 0}, {7, 0, 0}, {8, 0, 0}, {6, 2, 0}, {11, 0, 0}, {9, 0, 0}, {10, 4, 0} };
            _info[9] = { {6, 2, 0}, {3, 0, 0}, {8, 0, 0}, {5, 0, 0}, {4, 0, 0}, {7, 0, 0}, {9, 0, 0}, {1, 0, 0} };
            _info[10] = { {3, 0, 0}, {4, 0, 0}, {5, 0, 0}, {8, 0, 0}, {9, 0, 0}, {2, 0, 0}, {6, 2, 0}, {1, 0, 0}, {10, 4, 0}, {12, 0, 0} };
            _info[11] = { {1, 0, 0}, {2, 0, 0}, {3, 0, 0}, {5, 0, 0}, {8, 0, 0}, {7, 0, 0}, {6, 2, 0}, {10, 4, 0} };
            _info[22] = { {6, 2, 0}, {11, 0, 0}, {3, 0, 0}, {8, 0, 0}, {4, 0, 0}, {5, 0, 0}, {9, 0, 0}, {1, 0, 0} };
            _info[24] = { {3, 0, 0}, {8, 0, 0}, {10, 4, 0}, {5, 0, 0}, {4, 0, 0}, {7, 0, 0}, {1, 0, 0}, {6, 2, 8} };
            _info[25] = { {1, 0, 0}, {7, 0, 0}, {4, 0, 0}, {5, 0, 0}, {10, 4, 0}, {8, 0, 0}, {3, 0, 0}, {6, 2, 8} };
            _info[26] = { {1, 0, 0}, {3, 0, 0}, {4, 0, 0}, {5, 0, 0}, {7, 0, 0}, {8, 0, 0}, {10, 4, 0}, {6, 2, 8} };
            _info[27] = { {8, 6, 7}, {3, 6, 7}, {10, 6, 7}, {5, 6, 7}, {4, 6, 7}, {9, 6, 7}, {1, 6, 7}, {6, 6, 8} };
            _info[28] = { {3, 6, 7}, {11, 6, 7}, {7, 6, 7}, {1, 6, 7}, {10, 6, 7}, {6, 6, 8} };
            _info[29] = { {8, 6, 7}, {9, 6, 7}, {3, 6, 7}, {10, 6, 7}, {5, 6, 7}, {4, 6, 7}, {1, 6, 7}, {6, 6, 8} };
            _info[30] = { {2, 6, 7}, {3, 6, 7}, {8, 6, 7}, {5, 6, 7}, {1, 6, 7}, {6, 6, 8} };
            _info[31] = { {7, 7, 7}, {11, 7, 7}, {3, 7, 7}, {8, 7, 7}, {5, 7, 7}, {4, 7, 7}, {1, 7, 7}, {10, 7, 7}, {2, 7, 7}, {6, 7, 8} };
            _info[32] = { {1, 7, 7}, {3, 7, 7}, {4, 7, 7}, {5, 7, 7}, {8, 7, 7}, {7, 7, 7}, {11, 7, 7}, {10, 7, 7}, {6, 7, 8} };
            _info[34] = { {1, 7, 7}, {3, 7, 7}, {8, 7, 7}, {10, 7, 7}, {2, 7, 7}, {5, 7, 7}, {4, 7, 7}, {7, 7, 7}, {9, 7, 7}, {6, 7, 8} };
            _info[35] = { {1, 7, 7}, {4, 7, 7}, {10, 7, 7}, {3, 7, 7}, {5, 7, 7}, {8, 7, 7}, {9, 7, 7}, {7, 7, 7}, {6, 7, 8} };
            _info[36] = { {1, 7, 7}, {3, 7, 7}, {8, 7, 7}, {10, 7, 7}, {5, 7, 7}, {4, 7, 7}, {7, 7, 7}, {6, 7, 8} };
            _info[37] = { {1, 7, 7}, {4, 7, 7}, {10, 7, 7}, {3, 7, 7}, {5, 7, 7}, {8, 7, 7}, {9, 7, 7}, {6, 7, 8} };
        }

        struct ClassInfo
        {
            ClassInfo(uint8 classID, uint8 expansion1, uint8 expansion2) : ClassID(classID), Expansion1(expansion1), Expansion2(expansion2)
            {
            }

            uint8 ClassID;
            uint8 Expansion1;
            uint8 Expansion2;
        };

        uint32 GetCount() const
        {
            return _info.size();
        }

    private:
        std::map<uint8, std::vector<ClassInfo>> _info;
    };

    void SendResumeComs()
    {
        Packet packet(Opcode::SMSG_RESUME_COMMS);
        SendPacket(packet);
    }

    void SendAuthResponse()
    {
        Packet packet(Opcode::SMSG_AUTH_RESPONSE);
        packet << uint32(0);
        packet.WriteBits<1>(1);
        packet.WriteBits<1>(0);
        packet.FlushBits();

        auto const& raceClassInfo = RaceClassInfo::Instance();

        packet << uint32(33619968);
        packet << uint32(1);
        packet << uint32(0);
        packet << uint8(Globals::Expansion);
        packet << uint8(Globals::Expansion);
        packet << uint32(0);
        packet << uint32(raceClassInfo.GetCount());
        packet << uint32(0);
        packet << uint32(0);
        packet << int32(int32(time(nullptr)));

        packet << raceClassInfo;

        packet.WriteBits<1>(0);
        packet.WriteBits<1>(0);
        packet.WriteBits<1>(0);
        packet.WriteBits<1>(0);
        packet.WriteBits<1>(0);
        packet.FlushBits();

        {
            packet << uint32(0);
            packet << uint32(0);
            packet << uint32(0);
            packet.WriteBits<1>(0);
            packet.WriteBits<1>(0);
            packet.WriteBits<1>(0);
            packet.FlushBits();
        }


        {
            std::string realmName = "SSandbox";
            packet << uint32(33619968);
            packet.WriteBits<1>(1);
            packet.WriteBits<1>(0);
            packet.WriteBits<8>(realmName.length());
            packet.WriteBits<8>(realmName.length());
            packet.WriteString(realmName);
            packet.WriteString(realmName);
        }

        SendPacket(packet);

        Buffer endpointBuffer;
        uint32 type = 1;
        uint16 port = 8085;

        endpointBuffer << uint8(type);
        endpointBuffer << asio::ip::make_address_v4("127.0.0.1").to_bytes();

        Crypt::Sha256 hash;
        hash.UpdateData(endpointBuffer.GetBuffer(), endpointBuffer.GetWritePos());
        hash.UpdateData(&type, sizeof(type));
        hash.UpdateData(&port, sizeof(port));
        hash.Finalize();

        std::array<char, 256> Signature;

        if (!Crypt::ConnectToRSA.Sign(hash.GetDigest(), Crypt::Sha256::Length, Signature.data()))
        {
            FinishSendingAndClose();
            return;
        }

        uint64 key = GenerateKey();

        Packet connectTo(Opcode::SMSG_CONNECT_TO);
        connectTo << Signature;
        connectTo << endpointBuffer;
        connectTo << uint16(port);
        connectTo << uint32(14);
        connectTo << uint8(ConnectionType::Instance);
        connectTo << key;
        SendPacket(connectTo);
    }


    void HandleEnableEncryptionAck(Packet const& packet)
    {
        _clientCrypt.Init(false, _aesKey.data());

        if (_connectionType == ConnectionType::Realm)
            SendAuthResponse();
        else
            SendResumeComs();
    }

    virtual bool Update() final
    {
        return SocketType::Update();
    }

    void GenerateServerSeed()
    {
        Utils::Random(_serverSeed.data(), _serverSeed.size());
    }

    void ProcessEncryption(Header& header, Packet& packet, bool encrypting)
    {
        auto& crypt = encrypting ? _serverCrypt : _clientCrypt;
        auto& counter = encrypting ? _sentPacketCounter : _receivedPacketCounter;
        constexpr char Magic[2][4] = {{'C', 'L', 'N', 'T'}, {'S', 'R', 'V', 'R'}};

        if (crypt.IsInitialized())
        {
            uint8 IV[12];
            std::memcpy(IV, &counter, sizeof(counter));
            std::memcpy(IV + sizeof(counter), Magic[encrypting], sizeof(Magic[encrypting]));

            if (!crypt.Process(IV, packet.GetBuffer(), header.Size, header.Tag))
            {
                FinishSendingAndClose();
                return;
            }
        }
        else if (encrypting)
        {
            std::memset(header.Tag, 0, sizeof(header.Tag));
        }

        ++counter;
    }

    void OnClose() final
    {
        if (_connectToKey.has_value())
            GetConnectionByKeyAndErase(_connectToKey.value());

        if (_playerSession)
            _playerSession->SetConnection(_connectionType, this);
    }


    static inline std::unordered_map<uint64, World::Connection*> gKeyToSession;

    static inline World::Connection* GetConnectionByKeyAndErase(uint64 key)
    {
        World::Connection* ptr;

        auto iter = gKeyToSession.find(key);
        if (iter == gKeyToSession.end())
            return nullptr;

        ptr = iter->second;
        gKeyToSession.erase(iter);

        if (ptr)
            ptr->_connectToKey.reset();

        return ptr;
    }

    void EnableEncryption()
    {
        uint8 Enabled = 1;

        Crypt::HmacSha256 keyHash(_aesKey.data(), _aesKey.size());
        keyHash.UpdateData(&Enabled, 1);
        keyHash.UpdateData(EnableEncryptionSeed, sizeof(EnableEncryptionSeed));
        keyHash.Finalize();

        std::size_t rsaLen = Crypt::ConnectToRSA.GetOutputLength();

        Packet enableEncryption(Opcode::SMSG_ENABLE_ENCRYPTION, rsaLen + 1);
        Crypt::ConnectToRSA.Sign(keyHash.GetDigest(), Crypt::HmacSha256::Length, enableEncryption.GetBuffer() + 2);
        enableEncryption.AdvanceWritePos(rsaLen);
        enableEncryption.WriteBits<1>(Enabled);
        enableEncryption.FlushBits();
        SendPacket(enableEncryption);

        _serverCrypt.Init(true, _aesKey.data());
    }

private:
    bool _initialized;
    char corruptionTest[256] = {0};
    Network::SocketBuffer _header;
    char corruptionTest2[256] = {0};
    Packet _packet;
    char corruptionTest3[256] = {0};

    std::size_t _sentPacketCounter;
    std::size_t _receivedPacketCounter;

    std::array<char, 16> _serverSeed;
    std::array<uint8, 16> _aesKey;
    std::array<uint8, 40> _sessionKey;

    std::shared_ptr<Player::Session> _playerSession;
    std::shared_ptr<Account::Instance> _account;

    Crypt::Aes _clientCrypt;
    Crypt::Aes _serverCrypt;

    ConnectionType _connectionType;
    std::optional<uint64> _connectToKey;
};
} // World
