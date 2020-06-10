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
#include <Account.h>

namespace World
{
    enum class ConnectionType
    {
        Realm,
        Instance,
        Max
    };

    class Connection;
}

namespace Player
{

    enum class ResponseCodes : uint8
    {
        CreationSucess  = 24,
        DeletionSuccess = 52,
    };

class Session
{
    friend class Game::Character;

public:
    explicit Session(std::shared_ptr<Account::Instance> accountInfo);
    ~Session();

    void SetConnection(World::ConnectionType type, World::Connection* connection);

    void HandleNever(Packet const& packet);
    void HandleEnumCharacters(Packet const& packet);
    void HandleCreateCharacter(Packet const& packet);
    void HandleDeleteCharacter(Packet const& packet);
    void HandlePlayerLogin(Packet const& packet);
    void HandleQueryPlayerName(Packet const& packet);
    void HandleChat(Packet const& packet);
    void HandleMovement(Packet const& packet);
    void HandleLogout(Packet const& packet);
    void HandleSuspendTokenResponse(Packet const& packet);
    void HandleWorldPortResponse(Packet const& packet);

    void SendUpdateObject();

    void SendPacket(Packet& packet);
    void DispatchPacket(Packet const& packet);

private:
    std::shared_ptr<Account::Instance> _accountInfo;
    World::Connection* _connections[static_cast<int>(World::ConnectionType::Max)];
    std::shared_ptr<Game::Character> _currentCharacter;
};
} // Player
