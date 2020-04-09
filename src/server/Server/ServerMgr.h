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

namespace Network
{
    class SessionMgrBase;
}

class ServerMgr
{
public:
    ServerMgr();
    static ServerMgr& Instance();

    void NewMgr(std::unique_ptr<Network::SessionMgrBase>&& sessionMgr);
    bool StartAll();
    bool UpdateAll();
    void Run();
    void Stop();
    bool IsStopped();

    void CloseAllSockets();

    uint16 GetWorldServerPort();
    uint16 GetRestPort();
    uint16 BnetPort();
    std::string const& GetBindIP();
    std::string const& GetExternalIP();

private:
    asio::io_context _ioContext;
    bool _stopped;
    std::vector<std::unique_ptr<Network::SessionMgrBase>> _sessionMgrList;

    uint16 _wsPort;
    uint16 _restPort;
    uint16 _bnetPort;
    std::string _bindIP;
    std::string _externalIP;
};

