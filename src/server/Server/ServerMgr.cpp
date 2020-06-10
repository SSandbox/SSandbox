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

#include "PCH.h"
#include "ServerMgr.h"
#include "BattlenetSession.h"
#include "BattlenetRestSession.h"
#include "SessionMgr.h"
#include "WorldConnection.h"
#include <chrono>
#include "CommandHandler.h"

ServerMgr::ServerMgr() : _stopped(false), _wsPort(0), _restPort(0), _bnetPort(0)
{
}

ServerMgr& ServerMgr::Instance()
{
    static ServerMgr instance;
    return instance;
}

void ServerMgr::NewMgr(std::unique_ptr<Network::SessionMgrBase>&& sessionMgr)
{
    _sessionMgrList.emplace_back(std::move(sessionMgr));
}

bool ServerMgr::StartAll()
{
    bool result = true;

    for (auto& mgr : _sessionMgrList)
        result = std::min(result, mgr->Start());

    return result;
}

bool ServerMgr::UpdateAll()
{
    bool result = false;

    for (auto& mgr : _sessionMgrList)
        result = std::max(result, mgr->Update());

    return result;
}

void ServerMgr::Run()
{
    bool certLoaded = Battlenet::Session::InitSslContext("bnetserver.cert.pem", "bnetserver.key.pem");
    certLoaded = std::min(certLoaded, Battlenet::Rest::Session::InitSslContext("bnetserver.cert.pem", "bnetserver.key.pem"));
    if (!certLoaded)
    {
        Log::Log(LogSeverity::Error, "Error: Failed to load certificate files");
        return;
    }

    if (!Crypt::ConnectToRSA.LoadRSAKey("id_rsa_connect_to"))
    {
        Log::Log(LogSeverity::Error, "Error: Failed to load rsa key file id_rsa_connect_to");
        return;
    }

    _bindIP = Utils::Config::Instance().Get<std::string>("BindIP", "0.0.0.0");
    _externalIP = Utils::Config::Instance().Get<std::string>("ExternalIP", "127.0.0.1");
    _bnetPort = Utils::Config::Instance().Get<uint16>("BnetServerPort", 1119);
    _restPort = Utils::Config::Instance().Get<uint16>("BnetRestServerPort", 8080);
    _wsPort = Utils::Config::Instance().Get<uint16>("WorldServerPort", 8085);

    NewMgr(std::make_unique<Network::SessionMgr<Battlenet::Session>>(_bindIP, _bnetPort, _ioContext));
    NewMgr(std::make_unique<Network::SessionMgr<Battlenet::Rest::Session>>(_bindIP, _restPort, _ioContext));
    NewMgr(std::make_unique<Network::SessionMgr<World::Connection>>(_bindIP, _wsPort, _ioContext));

    if (!StartAll())
    {
        Log::Log(LogSeverity::Error, "Error starting session managers");
        return;
    }

    asio::steady_timer ticketListTimer(_ioContext, 1s);
    ticketListTimer.async_wait(std::bind(&Battlenet::Rest::Session::UpdateTimer, std::placeholders::_1, &ticketListTimer));

    asio::steady_timer updateTimer(_ioContext, 10ms);
    std::function<void(boost::system::error_code)> UpdateFunction = [this, &updateTimer, &UpdateFunction](boost::system::error_code error)
    {
        if (_stopped)
        {
            _ioContext.stop();
            return;
        }

        if (UpdateAll())
        {
            updateTimer.expires_after(10ms);
            updateTimer.async_wait(UpdateFunction);
        }
    };

    updateTimer.async_wait(UpdateFunction);

    std::thread networkThread([this]()
    {
        _ioContext.run();
        _ioContext.reset();
    });


    Game::CommandHandler::Instance().Run();
    Stop();

    networkThread.join();

    _sessionMgrList.clear();
}

void ServerMgr::Stop()
{
    _stopped = true;
}

bool ServerMgr::IsStopped()
{
    return _stopped;
}

void ServerMgr::CloseAllSockets()
{
    std::for_each(_sessionMgrList.begin(), _sessionMgrList.end(), [](auto& mgr)
    {
        mgr->CloseAllSockets();
    });
}

uint16 ServerMgr::GetWorldServerPort()
{
    return _wsPort;
}

uint16 ServerMgr::GetRestPort()
{
    return _restPort;
}

uint16 ServerMgr::BnetPort()
{
    return _bnetPort;
}

std::string const& ServerMgr::GetBindIP()
{
    return _bindIP;
}

std::string const& ServerMgr::GetExternalIP()
{
    return _externalIP;
}
