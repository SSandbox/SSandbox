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
#include <Opcodes.h>
#include <PlayerSession.h>
#include <WorldConnection.h>

std::array<OpcodeInfo, static_cast<uint16>(Opcode::MAX_OPCODE) - static_cast<uint16>(Opcode::MIN_OPCODE)> _opcodeList;

bool OpcodeInfo::IsValid(uint16 opcode)
{
    return opcode >= static_cast<uint16>(Opcode::MIN_OPCODE) && opcode < static_cast<uint16>(Opcode::MAX_OPCODE);
}

bool OpcodeInfo::IsValid(::Opcode opcode)
{
    return IsValid(static_cast<uint16>(opcode));
}

OpcodeInfo invalid;

World::ConnectionType GetConnectionIndexForPacket(Opcode opcode)
{
    switch (opcode)
    {
        case Opcode::SMSG_MOVE_TELEPORT:
            return World::ConnectionType::Instance;
        default:
            return World::ConnectionType::Realm;
    }
}

OpcodeInfo const& GetOpcodeInfo(uint16 opcode)
{
    if (!OpcodeInfo::IsValid(opcode))
        return invalid;

    return _opcodeList[opcode - static_cast<uint16>(Opcode::MIN_OPCODE)];
}

struct InitOpcodes
{
    #define OPCODE(x, h) if (static_cast<uint16>(Opcode::x)) { entry = _opcodeList.data() + (static_cast<uint16>(Opcode::x) - static_cast<uint16>(Opcode::MIN_OPCODE)); entry->Opcode = Opcode::x; entry->Name = #x; entry->Handler = &h; }

    InitOpcodes()
    {
        memset(&invalid, 0, sizeof(invalid));
        memset(_opcodeList.data(), 0, _opcodeList.size());
        OpcodeInfo* entry;

        OPCODE(SMSG_AUTH_RESPONSE, Player::Session::HandleNever)
        OPCODE(SMSG_AUTH_CHALLENGE, Player::Session::HandleNever)
        OPCODE(SMSG_ENABLE_ENCRYPTION, Player::Session::HandleNever)
        OPCODE(SMSG_ENUM_CHARACTERS_RESULT, Player::Session::HandleNever)
        OPCODE(SMSG_CONNECT_TO, Player::Session::HandleNever)
        OPCODE(SMSG_FEATURE_STATUS_GLUE_SCREEN, Player::Session::HandleNever)
        OPCODE(SMSG_CREATE_CHAR, Player::Session::HandleNever)
        OPCODE(SMSG_DELETE_CHAR, Player::Session::HandleNever)
        OPCODE(SMSG_UPDATE_OBJECT, Player::Session::HandleNever)
        OPCODE(SMSG_AVAILABLE_HOTFIXES, Player::Session::HandleNever)
        OPCODE(SMSG_UPDATE_TALENT_DATA, Player::Session::HandleNever)
        OPCODE(SMSG_SEND_KNOWN_SPELLS, Player::Session::HandleNever)
        OPCODE(SMSG_UPDATE_ACTION_BUTTONS, Player::Session::HandleNever)
        OPCODE(SMSG_RESUME_COMMS, Player::Session::HandleNever)
        OPCODE(SMSG_CHAT, Player::Session::HandleNever)
        OPCODE(SMSG_QUERY_PLAYER_NAME_RESPONSE, Player::Session::HandleNever)
        OPCODE(SMSG_TUTORIAL_FLAGS, Player::Session::HandleNever)
        OPCODE(SMSG_ACCOUNT_DATA_TIMES, Player::Session::HandleNever)
        OPCODE(SMSG_LOGOUT_COMPLETE, Player::Session::HandleNever)
        OPCODE(SMSG_MOVE_TELEPORT, Player::Session::HandleNever)
        OPCODE(SMSG_TRANSFER_PENDING, Player::Session::HandleNever)
        OPCODE(SMSG_SUSPEND_TOKEN, Player::Session::HandleNever)
        OPCODE(SMSG_RESUME_TOKEN, Player::Session::HandleNever)
        OPCODE(SMSG_NEW_WORLD, Player::Session::HandleNever)
        OPCODE(SMSG_MOVE_SET_CAN_FLY, Player::Session::HandleNever)
        OPCODE(SMSG_MOVE_UNSET_CAN_FLY, Player::Session::HandleNever)

        OPCODE(CMSG_AUTH_CONTINUED_SESSION, Player::Session::HandleNever)
        OPCODE(CMSG_AUTH_SESSION, Player::Session::HandleNever)
        OPCODE(CMSG_ENABLE_ENCRYPTION_ACK, Player::Session::HandleNever)
        OPCODE(CMSG_PING, Player::Session::HandleNever)
        OPCODE(CMSG_LOG_DISCONNECT, Player::Session::HandleNever)
        OPCODE(CMSG_ENUM_CHARACTERS, Player::Session::HandleEnumCharacters)
        OPCODE(CMSG_CREATE_CHARACTER, Player::Session::HandleCreateCharacter)
        OPCODE(CMSG_DELETE_CHARACTER, Player::Session::HandleDeleteCharacter)
        OPCODE(CMSG_PLAYER_LOGIN, Player::Session::HandlePlayerLogin)
        OPCODE(CMSG_QUERY_PLAYER_NAME, Player::Session::HandleQueryPlayerName)
        OPCODE(CMSG_CHAT_MESSAGE_SAY, Player::Session::HandleChat)
        OPCODE(CMSG_MOVE_HEARTBEAT, Player::Session::HandleMovement)
        OPCODE(CMSG_MOVE_STOP, Player::Session::HandleMovement)
        OPCODE(CMSG_LOGOUT, Player::Session::HandleLogout)
        OPCODE(CMSG_SUSPEND_TOKEN_RESPONSE, Player::Session::HandleSuspendTokenResponse);
        OPCODE(CMSG_WORLD_PORT_RESPONSE, Player::Session::HandleWorldPortResponse);

    }
};

InitOpcodes initOpcodes;
