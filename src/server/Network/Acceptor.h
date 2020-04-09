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

class Acceptor
{
public:
    explicit Acceptor(std::string_view ipv4, uint16 port, asio::io_context& ioContext);
    ~Acceptor();

    bool BindAndRun();

    template <typename Callback>
    void AsyncAccept(Callback&& callback)
    {
        _callback = std::move(callback);
        _asyncAccept();
    }

    bool IsOpen();
    void Close();

private:
    void _asyncAccept()
    {
        auto socket = std::make_shared<asio::ip::tcp::socket>(_ioContext);
        _acceptor.async_accept(*socket, [this, socket](boost::system::error_code error) mutable
        {
            if (!error && !_closing)
            {
                socket->non_blocking(true);
                _callback(std::move(socket));
                _asyncAccept();
            }
            else
                Close();
        });
    }

    std::atomic<bool> _closing;
    asio::io_context& _ioContext;
    asio::ip::tcp::endpoint _endpoint;
    asio::ip::tcp::acceptor _acceptor;
    std::function<void(std::shared_ptr<asio::ip::tcp::socket>&&)> _callback;
};
} // Network
