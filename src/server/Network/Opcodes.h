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

enum class Opcode : uint16
{
    MIN_OPCODE                      = 0x2000,
    MAX_OPCODE                      = 0x3FFF,

    SMSG_AUTH_RESPONSE              = 0x256D, // SL
    SMSG_AUTH_CHALLENGE             = 0x3048, // SL
    SMSG_ENABLE_ENCRYPTION          = 0x3049, // SL
    SMSG_RESUME_COMMS               = 0x304B, // SL
    SMSG_CONNECT_TO                 = 0x304D, // SL
    SMSG_FEATURE_STATUS_GLUE_SCREEN = 0x25D5, // SL
    SMSG_ENUM_CHARACTERS_RESULT     = 0x2584, // SL

    SMSG_CREATE_CHAR                = 0x2747, // SL
    SMSG_DELETE_CHAR                = 0x2748, // SL
    SMSG_UPDATE_OBJECT              = 0x2819, // SL
    SMSG_AVAILABLE_HOTFIXES         = 0x25A4, // SL
    SMSG_UPDATE_TALENT_DATA         = 0x25EF, // SL
    SMSG_UPDATE_ACTION_BUTTONS      = 0x25F7, // SL
    SMSG_TUTORIAL_FLAGS             = 0x280A, // SL
    SMSG_ACCOUNT_DATA_TIMES         = 0x2752, // SL
    SMSG_LOGOUT_COMPLETE            = 0x26B7, // SL

    SMSG_QUERY_PLAYER_NAME_RESPONSE = 0x270C, // SL
    SMSG_MOVE_TELEPORT              = 0x2DD2, // SL
    SMSG_TRANSFER_PENDING           = 0x25E6, // SL
    SMSG_SUSPEND_TOKEN              = 0x25BE, // SL
    SMSG_RESUME_TOKEN               = 0x25BF, // SL

    SMSG_CHAT                       = 0x2BAD, // SL
    SMSG_SEND_KNOWN_SPELLS          = 0x2C2A, // SL
    SMSG_NEW_WORLD                  = 0x25AE, // SL

    SMSG_MOVE_SET_CAN_FLY           = 0x2DD3, // SL
    SMSG_MOVE_UNSET_CAN_FLY         = 0x2DD4, // SL

    CMSG_AUTH_CONTINUED_SESSION     = 0x3766, // SL
    CMSG_AUTH_SESSION               = 0x3765, // SL
    CMSG_ENABLE_ENCRYPTION_ACK      = 0x3767, // SL
    CMSG_PING                       = 0x3768, // SL
    CMSG_LOG_DISCONNECT             = 0x3769, // SL
    CMSG_ENUM_CHARACTERS            = 0x35E8, // SL
    CMSG_PLAYER_LOGIN               = 0x35EA, // SL

    CMSG_CREATE_CHARACTER           = 0x3644, // SL
    CMSG_DELETE_CHARACTER           = 0x369E, // SL
    CMSG_QUERY_PLAYER_NAME          = 0x368A, // SL

    CMSG_CHAT_MESSAGE_SAY           = 0x37E7, // SL

    CMSG_MOVE_HEARTBEAT             = 0x3A0F, // SL
    CMSG_MOVE_STOP                  = 0x39E6, // SL

    CMSG_LOGOUT                     = 0x34E4, // SL
    CMSG_SUSPEND_TOKEN_RESPONSE     = 0x376A, // SL
    CMSG_WORLD_PORT_RESPONSE        = 0x35F9, // SL
};

namespace World
{
    enum class ConnectionType;
}

namespace Player
{
    class Session;
}

class Packet;

struct OpcodeInfo
{
    Opcode Opcode;
    char const* Name;
    void(Player::Session:: *Handler)(Packet const&);

    static bool IsValid(uint16 opcode);
    static bool IsValid(::Opcode opcode);
};

World::ConnectionType GetConnectionIndexForPacket(Opcode opcode);

OpcodeInfo const& GetOpcodeInfo(uint16 opcode);

inline OpcodeInfo const& GetOpcodeInfo(Opcode opcode)
{
    return GetOpcodeInfo(static_cast<uint16>(opcode));
}
