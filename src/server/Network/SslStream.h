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
#include "boost/asio/ssl.hpp"

namespace asio = boost::asio;
// ported from TrinityCore
namespace Network
{

template<class SslContext>
class SslStream
{
public:
    explicit SslStream(asio::ip::tcp::socket&& socket) : _socket(std::move(socket)), _SslStream(_socket, SslContext::GetSslContext())
    {
        _SslStream.set_verify_mode(asio::ssl::verify_none);
    }

    // adapting tcp::socket api
    void close(boost::system::error_code& error)
    {
        _socket.close(error);
    }

    void close()
    {
        _socket.close();
    }

    void shutdown(asio::socket_base::shutdown_type what, boost::system::error_code& shutdownError)
    {
        _SslStream.shutdown(shutdownError);
        _socket.shutdown(what, shutdownError);
    }

    template<typename MutableBufferSequence, typename ReadHandlerType>
    void async_read_some(MutableBufferSequence const& buffers, ReadHandlerType&& handler)
    {
        _SslStream.async_read_some(buffers, std::move(handler));
    }

    template<typename ConstBufferSequence, typename WriteHandlerType>
    void async_write_some(ConstBufferSequence const& buffers, WriteHandlerType&& handler)
    {
        _SslStream.async_write_some(buffers, std::move(handler));
    }

    template<typename ConstBufferSequence>
    std::size_t write_some(ConstBufferSequence const& buffers, boost::system::error_code& error)
    {
        return _SslStream.write_some(buffers, error);
    }

    template<typename SettableSocketOption>
    void set_option(SettableSocketOption const& option, boost::system::error_code& error)
    {
        _socket.set_option(option, error);
    }

    asio::ip::tcp::socket::endpoint_type remote_endpoint() const
    {
        return _socket.remote_endpoint();
    }

    bool is_open() const
    {
        return _socket.is_open();
    }

    asio::executor& get_executor()
    {
        return _socket.get_executor();
    }

    // ssl api
    template<typename HandshakeHandlerType>
    void async_handshake(boost::asio::ssl::stream_base::handshake_type type, HandshakeHandlerType&& handler)
    {
        _SslStream.async_handshake(type, std::move(handler));
    }

private:
    asio::ip::tcp::socket _socket;
    boost::asio::ssl::stream<asio::ip::tcp::socket&> _SslStream;
};
} // Network
