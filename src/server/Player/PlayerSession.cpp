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

#include <PCH.h>
#include <PlayerSession.h>
#include <WorldConnection.h>
#include <CommandHandler.h>

namespace Player
{

Session::Session(std::shared_ptr<Account::Instance> accountInfo) : _accountInfo(std::move(accountInfo)), _connections{ nullptr, nullptr }, _currentCharacter(nullptr)
{
}

Session::~Session()
{
    if (_currentCharacter)
        _currentCharacter->SetActiveSession(nullptr);
}

void Session::SetConnection(World::ConnectionType type, World::Connection* connection)
{
    _connections[static_cast<int>(type)] = connection;
}

void Session::HandleNever(Packet const& packet)
{
}

void Session::HandleEnumCharacters(Packet const& packet)
{
    auto characters = _accountInfo->GetCharacterList();

    Packet available(Opcode::SMSG_AVAILABLE_HOTFIXES);
    char l_Buff[] = {0x02, 0x00, 0x01, 0x32, 0x00, 0x00, 0x00, 0x00};
    available.WriteBytes(l_Buff, sizeof(l_Buff));
    SendPacket(available);

    Packet response(Opcode::SMSG_ENUM_CHARACTERS_RESULT);

    auto const& raceInfo = World::Connection::RaceClassInfo::Instance();

    response.WriteBits<1>(1);
    response.WriteBits<1>(0);
    response.WriteBits<1>(1);
    response.WriteBits<1>(0);
    response.WriteBits<1>(0);
    response.WriteBits<1>(0);
    response.WriteBits<1>(0);
    response << uint32(characters.size());
    response << int32(Globals::MaxLevel);
    response << uint32(raceInfo.GetCount());
    response << uint32(0);

    uint8 index = 0;
    for (auto const& characterPair : characters)
        characterPair.second->WriteEnumCharacter(response, ++index);

    raceInfo.WriteEnumData(response);

    SendPacket(response);
}

void Session::HandleCreateCharacter(Packet const& packet)
{
    auto character = _accountInfo->CreateCharacter();
    character->ReadCreationFromBuffer(packet);
    character->FinishCreatingCharacter();

    Packet response(Opcode::SMSG_CREATE_CHAR, 1 + 16);
    response << uint8(24);   // OK
    response << character->GetGUID();
    SendPacket(response);
}

void Session::HandlePlayerLogin(Packet const& packet)
{
    Game::ObjectGuid guid;
    packet >> guid;
    packet.ReadSkip<float>();

    _currentCharacter = _accountInfo->GetCharacterByID(guid.GetLoPart());

    if (!_currentCharacter)
        return;

    _currentCharacter->SetActiveSession(this);
    _currentCharacter->FinishLoggingIn();
}

void Session::HandleQueryPlayerName(Packet const& packet)
{
    Game::ObjectGuid guid;
    packet >> guid;

    auto character = _accountInfo->GetCharacterByID(guid.GetLoPart());

    if (!character)
        return;

    Packet response(Opcode::SMSG_QUERY_PLAYER_NAME_RESPONSE);
    response << uint8(0);
    response << guid;

    response.WriteBits<1>(0);
    response.WriteBits<6>(character->_name.length());

    for (int i = 0; i < 5; ++i)
        response.WriteBits<7>(0);

    response.FlushBits();

    response << Game::ObjectGuid(Game::ObjectGuid::HighGuid::WowAccount, _accountInfo->GetID());
    response << Game::ObjectGuid(Game::ObjectGuid::HighGuid::BNetAccount, _accountInfo->GetID());
    response << guid;

    response << uint64(0);
    response << uint32(33619968);
    response << uint8(character->_race);
    response << uint8(character->_sex);
    response << uint8(character->_class);
    response << uint8(character->_level);
    response.WriteString(character->_name);
    SendPacket(response);
}

void Session::HandleChat(Packet const& packet)
{
    packet.ReadSkip<int32>();   // Language
    auto length = packet.ReadBits<9>();
    auto message = packet.ReadString(length);

    if (message.size() && message[0] == '!')
    {
        Game::CommandHandler::Instance().HandleCommand(message, _currentCharacter);
        return;
    }

    _currentCharacter->SendMessage(message);
}

void Session::HandleMovement(Packet const& packet)
{
    if (!_currentCharacter)
        return;

    Game::ObjectGuid guid;

    packet >> guid;
    packet.ReadSkip<uint32>();    // Time
    packet >> _currentCharacter->_position;
    packet >> _currentCharacter->_orientation;
    packet.ReadFinish();
}

void Session::HandleLogout(Packet const& packet)
{
    packet.ReadFinish();
    _currentCharacter->Logout();
}

void Session::HandleSuspendTokenResponse(Packet const& packet)
{
    Packet newWorld(Opcode::SMSG_NEW_WORLD);
    newWorld << int32(_currentCharacter->GetMapID());
    newWorld << _currentCharacter->GetPosition();
    newWorld << _currentCharacter->GetOrientation();
    newWorld << uint32(16); // NormalTP
    newWorld << Game::Position(); // Offset
    SendPacket(newWorld);
}

void Session::HandleWorldPortResponse(Packet const& packet)
{
    Packet resuleToken(Opcode::SMSG_RESUME_TOKEN);
    resuleToken << uint32(0);      // SeqIdx
    resuleToken.WriteBits<2>(1);   // Not seamless
    resuleToken.FlushBits();
    SendPacket(resuleToken);

    _currentCharacter->FinishLoggingIn();
}

void Session::SendUpdateObject()
{
    Packet packet(Opcode::SMSG_UPDATE_OBJECT);
    packet << uint32(1);
    packet << uint16(_currentCharacter->GetMapID());
    packet.WriteBits<1>(0);
    packet.FlushBits();

    uint32 wPos = packet.GetWritePos();
    packet << uint32(0);
    _currentCharacter->WriteCreationBlock(packet);

    uint32 size = packet.GetWritePos() - wPos - 4;
    packet.WriteBytesAt_unsafe(wPos, &size, 1);
    SendPacket(packet);
}

void Session::SendPacket(Packet& packet)
{
    _connections[static_cast<int>(GetConnectionIndexForPacket(packet.GetOpcode()))]->SendPacket(packet);
}

void Session::DispatchPacket(Packet const& packet)
{
    auto const& handler = GetOpcodeInfo(packet.GetOpcode());

    if (handler.Handler)
        (this->*handler.Handler)(packet);
}
} // Session
