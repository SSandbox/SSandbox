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
#include "SslStream.h"
#include "Socket.h"
#include "BattlenetRestSession.h"
#include "Account.h"

namespace Battlenet
{

class Session final : public Network::Socket<Network::SslStream<Battlenet::Session>>
{
public:

    enum class Stage : uint8
    {
        Size,
        Header,
        Body
    };

    // Needs to be here for SocketMgr
    using SocketType = Network::Socket<Network::SslStream<Battlenet::Session>>;

    Session(SocketType::RawSocketType&& socket) : SocketType(std::move(socket)), _stage(Stage::Size), _buffer(0), _serverToken(0), _account(nullptr), _build(0)
    {
        OnRead([this]()
        {
            for (std::size_t availableSize = _readBuffer.GetReadableSize(); availableSize; availableSize = _readBuffer.GetReadableSize())
            {
                switch (_stage)
                {
                    case Stage::Size:
                    {
                        if (availableSize < sizeof(_headerSize))
                            return;

                        char bytes[2];
                        _readBuffer.Read(bytes, 2);

                        _headerSize = (bytes[0] << 8) | bytes[1];
                        _buffer.Reset(_headerSize);
                        _stage = Stage::Header;
                    }
                    case Stage::Header:
                    {
                        std::size_t size = std::min(_readBuffer.GetReadableSize(), _buffer.GetRemainingSize());

                        _readBuffer.Read(_buffer.GetWritePointer(), size);
                        _buffer.AdvanceWritePos(size);

                        if (_buffer.GetRemainingSize())
                            break;

                        if (!_header.ParseFromArray(_buffer.GetReadPointer(), _headerSize))
                        {
                            Close();
                            return;
                        }

                        _buffer.Reset(_header.size());
                        _stage = Stage::Body;
                        break;
                    }
                    case Stage::Body:
                    {
                        std::size_t size = std::min(_readBuffer.GetReadableSize(), _buffer.GetRemainingSize());
                        _readBuffer.Read(_buffer.GetWritePointer(), size);
                        _buffer.AdvanceWritePos(size);

                        if (_buffer.GetRemainingSize())
                            break;

                        _handleRPC(_header.service_hash(), _header.method_id(), _header.token());
                        _stage = Stage::Size;
                        break;
                    }
                }
            }
            _readBuffer.Normalize();
        });

    }

    void OnStart() final
    {
        _socket.async_handshake(boost::asio::ssl::stream_base::server, std::bind(&Session::_asyncHandshake, this, std::placeholders::_1));
    }

    virtual bool Update() final
    {
        return SocketType::Update();
    }

    static boost::asio::ssl::context& GetSslContext()
    {
        static boost::asio::ssl::context gSslContext(boost::asio::ssl::context::method::sslv23);
        return gSslContext;
    }

    static bool InitSslContext(std::string_view certFilePath, std::string_view keyFilePath)
    {
        if (!fs::exists(certFilePath) || !fs::exists(keyFilePath))
            return false;

        auto& context = GetSslContext();
        boost::system::error_code error;

        context.set_options(boost::asio::ssl::context::no_sslv3, error);
        context.use_certificate_chain_file(certFilePath.data(), error);

        if (error)
            return false;

        context.use_private_key_file(keyFilePath.data(), boost::asio::ssl::context::pem, error);
        return !error;
    }

private:

    void _asyncHandshake(boost::system::error_code error)
    {
        if (!error)
            AsyncRead();
        else
            Close();
    }

    struct RealmCharacterCountList final : public JSON::Serializable
    {
        void Serialize(Writer& writer) const final
        {
            writer.StartObject();
            writer.EndObject();
        }
    };

    struct RealmListUpdates final : public JSON::Serializable
    {
        struct RealmListUpdate : public JSON::Serializable
        {
            struct Version : public JSON::Serializable
            {
                uint32 versionMajor = 6;
                uint32 versionMinor = 2;
                uint32 versionRevision = 4;
                uint32 versionBuild = 0;

                void Serialize(Writer& writer) const final
                {
                    writer.StartObject();

                    writer.Key("versionMajor");
                    writer.Uint(versionMajor);
                    writer.Key("versionMinor");
                    writer.Uint(versionMinor);
                    writer.Key("versionRevision");
                    writer.Uint(versionRevision);
                    writer.Key("versionBuild");
                    writer.Uint(versionBuild);

                    writer.EndObject();
                }
            };

            uint32 wowRealmAddress = 0;
            uint32 cfgTimezonesID = 1;
            uint32 populationState = 1;
            uint32 cfgCategoriesID = 1;
            Version version{};
            uint32 cfgRealmsID = 0;
            uint32 flags = 32;
            std::string name = "SSandbox";
            uint32 cfgConfigsID = 1;
            uint32 cfgLanguagesID = 1;

            bool deleting = false;
            void Serialize(Writer& writer) const final
            {
                writer.StartObject();

                writer.Key("update");
                writer.StartObject();

                writer.Key("wowRealmAddress");
                writer.Uint(wowRealmAddress);
                writer.Key("cfgTimezonesID");
                writer.Uint(cfgTimezonesID);
                writer.Key("populationState");
                writer.Uint(populationState);
                writer.Key("cfgCategoriesID");
                writer.Uint(cfgCategoriesID);
                writer.Key("version");
                version.Serialize(writer);
                writer.Key("flags");
                writer.Uint(flags);
                writer.Key("name");
                writer.String(name.c_str(), name.length());
                writer.Key("cfgConfigsID");
                writer.Uint(cfgConfigsID);
                writer.Key("cfgLanguagesID");
                writer.Uint(cfgLanguagesID);

                writer.EndObject();

                writer.Key("deleting");
                writer.Bool(deleting);

                writer.EndObject();
            }

        };

        void Serialize(Writer& writer) const final
        {
            writer.StartObject();

            writer.Key("updates");
            writer.StartArray();

            for (auto const& update : Updates)
                update.Serialize(writer);

            writer.EndArray();

            writer.EndObject();
        }

        std::vector<RealmListUpdate> Updates;
    };

    struct RealmListServerIPAddresses final : public JSON::Serializable
    {
        struct Family : public JSON::Serializable
        {
            uint32 CurrentFamily = 1;
            std::string IP  = "";
            uint16 Port = 0;

            void Serialize(Writer& writer) const final
            {
                writer.StartObject();

                writer.Key("family");
                writer.Uint(CurrentFamily);

                writer.Key("addresses");
                writer.StartArray();

                writer.StartObject();

                writer.Key("ip");
                writer.String(IP.c_str());

                writer.Key("port");
                writer.Uint(Port);

                writer.EndObject();

                writer.EndArray();

                writer.EndObject();
            }

        };

        void Serialize(Writer& writer) const final
        {
            writer.StartObject();

            writer.Key("families");
            writer.StartArray();

            for (auto const& family : Families)
                family.Serialize(writer);

            writer.EndArray();

            writer.EndObject();
        }

        std::vector<RealmListServerIPAddresses::Family> Families;
    };

    void _handleRPC(uint32 serviceHash, uint32 methodID, uint32 token)
    {
        Log::Log(LogSeverity::AuthConnectionInfo, "Battlenet RPC: ServiceHash: %08X - MethodID %i - Token %i", serviceHash, methodID, token);

        switch (serviceHash)
        {
            case 0x65446991: // ConnectionService
            {
                switch (methodID)
                {
                    case 1: // ConnectRequest
                    {
                        bgs::protocol::connection::v1::ConnectRequest request;
                        if (!request.ParseFromArray(_buffer.GetReadPointer(), _buffer.GetReadableSize()))
                        {
                            SendMessage(0xFE, token, 0x00000003);
                            FinishSendingAndClose();
                            return;
                        }

                        bgs::protocol::connection::v1::ConnectResponse response;
                        std::chrono::system_clock::duration now = std::chrono::system_clock::now().time_since_epoch();

                        if (request.has_client_id())
                            response.mutable_client_id()->CopyFrom(request.client_id());

                        response.mutable_server_id()->set_label(1);
                        response.mutable_server_id()->set_epoch(std::chrono::duration_cast<std::chrono::seconds>(now).count());
                        response.set_server_time(std::chrono::duration_cast<std::chrono::milliseconds>(now).count());
                        response.set_use_bindless_rpc(request.use_bindless_rpc());

                        SendMessage(0xFE, token, response);
                        break;
                    }
                    case 5: // KeepAlive
                    {
                        SendMessage(0xFE, token, 0);
                        break;
                    }
                    case 7: // Close
                    {
                        bgs::protocol::connection::v1::DisconnectRequest request;
                        if (!request.ParseFromArray(_buffer.GetReadPointer(), _buffer.GetReadableSize()))
                        {
                            SendMessage(0xFE, token, 0x00000003);
                            return;
                        }

                        bgs::protocol::connection::v1::DisconnectNotification dc;
                        dc.set_error_code(request.error_code());
                        SendRPC(serviceHash, 4, dc);
                        FinishSendingAndClose();

                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case 0xDECFC01: // AuthenticationService
            {
                switch (methodID)
                {
                    case 1:
                    {
                        bgs::protocol::authentication::v1::LogonRequest request;
                        if (!request.ParseFromArray(_buffer.GetReadPointer(), _buffer.GetReadableSize()))
                        {
                            SendMessage(0xFE, token, 0x00000003);
                            return;
                        }

                        char url[256];
                        sprintf(url, "https://%s:%u/bnetserver/login/", ServerMgr::Instance().GetExternalIP().c_str(), ServerMgr::Instance().GetRestPort());

                        bgs::protocol::challenge::v1::ChallengeExternalRequest newRequest;
                        newRequest.set_payload_type("web_auth_url");
                        newRequest.set_payload(url);
                        SendRPC(0xBBDA171Fu, 3, newRequest); // ChallengeService
                        break;
                    }
                    case 7: // VerifyWebCredentialsRequest
                    {
                        bgs::protocol::authentication::v1::VerifyWebCredentialsRequest request;
                        if (!request.ParseFromArray(_buffer.GetReadPointer(), _buffer.GetReadableSize()))
                        {
                            SendMessage(0xFE, token, 0x00000003);
                            return;
                        }

                        auto accountName = Battlenet::Rest::Session::GetAccountNameForTicket(request.web_credentials().c_str());
                        if (accountName == "")
                        {
                            SendMessage(0xFE, token, 0x00000003);
                            return;
                        }

                        _account = Account::Mgr::Instance().GetOrCreateAccount(accountName);

                        bgs::protocol::authentication::v1::LogonResult result;

                        result.set_error_code(0);
                        result.mutable_account_id()->set_low(_account->GetID());
                        result.mutable_account_id()->set_high(0x100000000000000ull);

                        auto gameAccount = result.add_game_account_id();
                        gameAccount->set_low(_account->GetID());
                        gameAccount->set_high(0x200000200576F57ull);

                        char randomBytes[64];
                        memset(randomBytes, 0, sizeof(randomBytes));
                        result.set_session_key(randomBytes, 64);

                        SendRPC(0x71240E35u, 5, result); /// Auth
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case 0x62DA0891: // AccountService
            {
                // Required authed account here
                if (!_account)
                {
                    SendMessage(0xFE, token, 0x00000003);
                    return;
                }

                switch (methodID)
                {
                    case 30:
                    {
                        bgs::protocol::account::v1::GetAccountStateRequest request;
                        if (!request.ParseFromArray(_buffer.GetReadPointer(), _buffer.GetReadableSize()))
                        {
                            SendMessage(0xFE, token, 0x00000003);
                            return;
                        }

                        bgs::protocol::account::v1::GetAccountStateResponse response;

                        if (request.options().field_privacy_info())
                        {
                            response.mutable_state()->mutable_privacy_info()->set_is_using_rid(false);
                            response.mutable_state()->mutable_privacy_info()->set_is_visible_for_view_friends(true);
                            response.mutable_state()->mutable_privacy_info()->set_is_hidden_from_friend_finder(true);

                            response.mutable_tags()->set_privacy_info_tag(0xD7CA834D);
                        }

                        SendMessage(0xFE, token, response);
                        break;
                    }
                    case 31:
                    {
                        bgs::protocol::account::v1::GetGameAccountStateRequest request;
                        if (!request.ParseFromArray(_buffer.GetReadPointer(), _buffer.GetReadableSize()))
                        {
                            SendMessage(0xFE, token, 0x00000003);
                            return;
                        }

                        bgs::protocol::account::v1::GetGameAccountStateResponse response;
                        if (request.options().field_game_level_info())
                        {
                            response.mutable_state()->mutable_game_level_info()->set_name("WoW1");
                            response.mutable_state()->mutable_game_level_info()->set_program(5730135); // WoW
                            response.mutable_tags()->set_game_level_info_tag(0x5C46D483);
                        }

                        if (request.options().field_game_status())
                        {
                            response.mutable_state()->mutable_game_status()->set_is_suspended(false);
                            response.mutable_state()->mutable_game_status()->set_is_banned(false);
                            response.mutable_state()->mutable_game_status()->set_program(5730135); // WoW
                            response.mutable_tags()->set_game_status_tag(0x98B75F99);
                        }
                        SendMessage(0xFE, token, response);
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case 0x3FC1274Du: // Game utilities
            {
                // Required authed account here
                if (!_account)
                {
                    SendMessage(0xFE, token, 0x00000003);
                    return;
                }

                switch (methodID)
                {
                    case 1: // ClientRequest
                    {
                        bgs::protocol::game_utilities::v1::ClientRequest request;
                        if (!request.ParseFromArray(_buffer.GetReadPointer(), _buffer.GetReadableSize()))
                        {
                            SendMessage(0xFE, token, 0x00000003);
                            return;
                        }

                        for (int i = 0; i < request.attribute_size(); ++i)
                        {
                            auto const& attribute = request.attribute(i);

                            if (attribute.name() == "Command_RealmListTicketRequest_v1_b9")
                            {
                                bgs::protocol::game_utilities::v1::ClientResponse response;

                                auto attribute = response.add_attribute();
                                attribute->set_name("Param_RealmListTicket");
                                attribute->mutable_value()->set_blob_value("AuthRealmListTicket");

                                SendMessage(0xFE, token, response);
                            }
                            else if (attribute.name() == "Param_ClientInfo")
                            {
                                auto const& res = attribute.value().blob_value();
                                auto loc = res.find(":");

                                if (loc == std::string::npos)
                                    continue;

                                rapidjson::Document document;
                                document.Parse(res.c_str() + loc + 1);

                                if (document.HasMember("info"))
                                {
                                    auto const& elem = document["info"];

                                    if (elem.HasMember("version"))
                                    {
                                        auto const& version = elem["version"];

                                        if (version.HasMember("versionBuild"))
                                        {
                                            _build = version["versionBuild"].GetUint();
                                        }
                                    }

                                    if (elem.HasMember("secret"))
                                    {
                                        auto& arr = elem["secret"].GetArray();
                                        std::array<uint8, 32> clientSecret;

                                        if (arr.Size() != clientSecret.size())
                                            continue;

                                        for (std::size_t i = 0; i < arr.Size(); ++i)
                                            clientSecret[i] = static_cast<uint8>(arr[i].GetUint());

                                        _account->SetClientSecret(clientSecret.data());
                                    }

                                }
                            }
                            else if (attribute.name() == "Command_RealmListRequest_v1_b9")
                            {
                                bgs::protocol::game_utilities::v1::ClientResponse response;

                                RealmListUpdates realmResponse;
                                realmResponse.Updates.emplace_back();
                                realmResponse.Updates[0].wowRealmAddress = 33619968;
                                realmResponse.Updates[0].version.versionBuild = _build;

                                std::string realmResponseStr = + "JSONRealmListUpdates:" + JSON::SerializeObjectToString(realmResponse);
                                auto compressed = Compress(realmResponseStr.c_str(), realmResponseStr.length() + 1);

                                auto attribute = response.add_attribute();
                                attribute->set_name("Param_RealmList");
                                attribute->mutable_value()->set_blob_value(compressed.data(), compressed.size());

                                std::string charactersCount = "JSONRealmCharacterCountList:" + JSON::SerializeObjectToString(RealmCharacterCountList{});
                                compressed = Compress(charactersCount.c_str(), charactersCount.length() + 1);

                                attribute = response.add_attribute();
                                attribute->set_name("Param_CharacterCountList");
                                attribute->mutable_value()->set_blob_value(compressed.data(), compressed.size());

                                SendMessage(0xFE, token, response);
                            }
                            else if (attribute.name() == "Command_LastCharPlayedRequest_v1_b9")
                            {
                                bgs::protocol::game_utilities::v1::ClientResponse response;

                                auto attribute = response.add_attribute();
                                attribute->set_name("Param_RealmEntry");
                                attribute->mutable_value()->set_blob_value("", 0);

                                attribute = response.add_attribute();
                                attribute->set_name("Param_CharacterName");
                                attribute->mutable_value()->set_string_value("", 0);

                                attribute = response.add_attribute();
                                attribute->set_name("Param_CharacterGUID");
                                attribute->mutable_value()->set_blob_value("", 0);

                                attribute = response.add_attribute();
                                attribute->set_name("Param_LastPlayedTime");
                                attribute->mutable_value()->set_int_value(0);

                                SendMessage(0xFE, token, response);
                            }
                            else if (attribute.name() == "Command_RealmJoinRequest_v1_b9")
                            {
                                bgs::protocol::game_utilities::v1::ClientResponse response;

                                //char const realmResponse[] = "JSONRealmListServerIPAddresses:{\"families\":[{\"family\":1,\"addresses\":[{\"ip\":\"127.0.0.1\",\"port\":8085}]}]}";

                                RealmListServerIPAddresses ips;
                                ips.Families.emplace_back();
                                ips.Families[0].IP = ServerMgr::Instance().GetExternalIP();
                                ips.Families[0].Port = ServerMgr::Instance().GetWorldServerPort();

                                std::string ipsString = + "JSONRealmListServerIPAddresses:" + JSON::SerializeObjectToString(ips);
                                auto compressed = Compress(ipsString.c_str(), ipsString.length() + 1);

                                auto attribute = response.add_attribute();
                                attribute->set_name("Param_RealmJoinTicket");
                                attribute->mutable_value()->set_blob_value(_account->GetName());

                                attribute = response.add_attribute();
                                attribute->set_name("Param_ServerAddresses");
                                attribute->mutable_value()->set_blob_value(compressed.data(), compressed.size());

                                _account->GenerateServerSecret();
                                attribute = response.add_attribute();
                                attribute->set_name("Param_JoinSecret");
                                attribute->mutable_value()->set_blob_value(_account->GetSecret().data() + 32, 32);

                                SendMessage(0xFE, token, response);
                            }
                        }
                        break;
                    }
                    case 10:
                    {
                        bgs::protocol::game_utilities::v1::GetAllValuesForAttributeRequest request;
                        if (!request.ParseFromArray(_buffer.GetReadPointer(), _buffer.GetReadableSize()))
                        {
                            SendMessage(0xFE, token, 0x00000003);
                            return;
                        }


                        bgs::protocol::game_utilities::v1::GetAllValuesForAttributeResponse response;
                        if (request.attribute_key() == "Command_RealmListRequest_v1_b9")
                        {
                            response.add_attribute_value()->set_string_value("0-0-0");
                        }

                        SendMessage(0xFE, token, response);
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            default:
                break;
        }
    }

    std::vector<char> Compress(char const* buff, std::size_t len)
    {
        std::vector<char> result;

        auto compressedLength = compressBound(len);

        result.resize(sizeof(compressedLength) + compressedLength);
        *reinterpret_cast<decltype(compressedLength)*>(result.data()) = len;

        auto res = compress(reinterpret_cast<Bytef*>(result.data() + sizeof(compressedLength)), &compressedLength, reinterpret_cast<Bytef const*>(buff), len);
        result.resize(compressedLength + sizeof(compressedLength));

        assert(res == Z_OK && sizeof(compressedLength) == 4);
        return result;
    }

    void SendMessage(uint32 serviceID, uint32 token, google::protobuf::Message const& message)
    {
        std::size_t messageSize = message.ByteSizeLong();

        bgs::protocol::Header header;
        header.set_token(token);
        header.set_service_id(serviceID);
        header.set_size(messageSize);

        uint16 headerSize = header.ByteSizeLong();

        char sizeBytes[2];
        sizeBytes[1] = headerSize & 0xFF;
        sizeBytes[0] = headerSize >> 8;

        Network::SocketBuffer packet(sizeof(headerSize) + headerSize + messageSize);

        packet.Write(sizeBytes, sizeof(sizeBytes));

        header.SerializePartialToArray(packet.GetWritePointer(), headerSize);
        packet.AdvanceWritePos(headerSize);

        message.SerializePartialToArray(packet.GetWritePointer(), messageSize);
        packet.AdvanceWritePos(messageSize);

        Enqueue(std::move(packet));
    }

    void SendRPC(uint32 serviceHash, uint32 methodID, google::protobuf::Message const& message)
    {
        std::size_t messageSize = message.ByteSizeLong();

        bgs::protocol::Header header;
        header.set_token(_serverToken++);
        header.set_service_id(0);
        header.set_size(messageSize);
        header.set_service_hash(serviceHash);
        header.set_method_id(methodID);

        uint16 headerSize = header.ByteSizeLong();

        char sizeBytes[2];
        sizeBytes[1] = headerSize & 0xFF;
        sizeBytes[0] = headerSize >> 8;

        Network::SocketBuffer packet(sizeof(headerSize) + headerSize + messageSize);

        packet.Write(sizeBytes, sizeof(sizeBytes));

        header.SerializePartialToArray(packet.GetWritePointer(), headerSize);
        packet.AdvanceWritePos(headerSize);

        message.SerializePartialToArray(packet.GetWritePointer(), messageSize);
        packet.AdvanceWritePos(messageSize);

        Enqueue(std::move(packet));
    }

    void SendMessage(uint32 service, uint32 token, uint32 status)
    {
        bgs::protocol::Header header;
        header.set_token(token);
        header.set_service_id(service);
        header.set_status(status);

        uint16 headerSize = header.ByteSizeLong();

        char sizeBytes[2];
        sizeBytes[1] = headerSize & 0xFF;
        sizeBytes[0] = headerSize >> 8;

        Network::SocketBuffer packet(sizeof(headerSize) + headerSize);

        packet.Write(sizeBytes, sizeof(sizeBytes));

        header.SerializePartialToArray(packet.GetWritePointer(), headerSize);
        packet.AdvanceWritePos(headerSize);

        Enqueue(std::move(packet));

        if (status != 0)
            FinishSendingAndClose();
    }

    Stage _stage;
    uint16 _headerSize;
    Network::SocketBuffer _buffer;
    bgs::protocol::Header _header;
    uint32 _serverToken;
    std::shared_ptr<Account::Instance> _account;
    uint16 _build;
};
} // Battlenet
