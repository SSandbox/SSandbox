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
#include "Acceptor.h"

namespace asio = boost::asio;
namespace Network
{

class SessionMgrBase
{
public:
    virtual bool Start() = 0;
    virtual void Stop() = 0;
    virtual void CloseAllSockets() = 0;
    virtual bool Update() = 0;

    virtual ~SessionMgrBase()
    {
    }
};

template <typename SessionType>
class SessionMgr final : public SessionMgrBase
{
public:

    using SocketType = typename SessionType::SocketType;
    using RawSocketType = typename SessionType::RawSocketType;

    SessionMgr(std::string_view ip, uint16 port, asio::io_context& ioContext) : _ioContext(ioContext), _acceptor(ip, port, ioContext), _stopping(false)
    {
        _sessionList.reserve(512);
    }

    // All sessions must be killed before ctor!
    ~SessionMgr()
    {
    }

    bool Start() final
    {
        _stopping = false;

        if (!_acceptor.BindAndRun())
            return false;

        _acceptor.AsyncAccept([this](auto&& socket)
        {
            std::lock_guard lock(_mutex);
            _sessionList.emplace_back(std::make_unique<SessionType>(std::move(*socket)));
            _sessionList[_sessionList.size() - 1]->OnStart();
        });

        return true;
    }

    void Stop() final
    {
        _stopping = true;

        if (_acceptor.IsOpen())
            _acceptor.Close();

        CloseAllSockets();
    }

    void CloseAllSockets() final
    {
        std::lock_guard lock(_mutex);
        std::for_each(_sessionList.begin(), _sessionList.end(), [](auto& ptr)
        {
            ptr->Close();
        });
    }

    bool Update() final
    {
        if (ServerMgr::Instance().IsStopped())
        {
            Stop();
        }

        std::lock_guard lock(_mutex);
        auto iter = std::remove_if(_sessionList.begin(), _sessionList.end(), [this](auto& ptr) -> bool
        {
            if (!ptr->Update())
            {
                return true;
            }

            return false;
        });

         _sessionList.erase(iter, _sessionList.end());
         return !_stopping;
    }

private:
    bool _stopping;
    asio::io_context& _ioContext;
    std::mutex _mutex;
    std::vector<std::unique_ptr<SessionType>> _sessionList;
    Acceptor _acceptor;
};
} // Network
