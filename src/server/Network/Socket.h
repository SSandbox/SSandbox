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
#include "SocketBuffer.h"

namespace asio = boost::asio;
namespace Network
{
template <typename T = asio::ip::tcp::socket>
class Socket
{
public:
    using RawSocketType = asio::ip::tcp::socket;
    using SocketType = T;

    explicit Socket(RawSocketType&& socket) : _socket(std::move(socket)), _closing(false), _sending(false), _delayedClose(false)
    {
    }

    ~Socket()
    {
    }

    virtual void OnStart()
    {
    }

    void OnRead(std::function<void()>&& callback)
    {
        _onReadExternalCallback = std::move(callback);
    }

    SocketBuffer const& GetReadBuffer()
    {
        return _readBuffer;
    }

    void AsyncRead()
    {
        _socket.async_read_some(_readBuffer.ToBoostMutableBuffer(), std::bind(&Network::Socket<T>::AsyncReadCallback, this, std::placeholders::_1, std::placeholders::_2));
    }

    void AsyncReadCallback(boost::system::error_code error, std::size_t bytesTransferred)
    {
        if (!error)
        {
            if (!_closing)
            {
                _readBuffer.AdvanceWritePos(bytesTransferred);
                _onReadExternalCallback();
                _readBuffer.Normalize();
                AsyncRead();
            }
        }
        else if (error.value() != boost::asio::error::shut_down && error.value() != boost::asio::error::operation_aborted)
            Close();
    }

    virtual bool Update()
    {
        if (_closing)
        {
            _socket.close();
            return false;
        }

        return true;
    }

    asio::executor& GetExecutor()
    {
        return _socket.get_executor();
    }

    void Enqueue(SocketBuffer&& buffer)
    {
        if (_delayedClose)
            return;

        buffer.ResetReadPos();

        {
            std::lock_guard lock(_sendMutex);
            _writeQueue.push(buffer);
        }

        AsyncWrite();
    }

    void AsyncWrite()
    {
        if (_writeQueue.empty() || _closing)
            return;

        if (_sending.exchange(true))
            return;

        std::lock_guard lock(_sendMutex);
        auto const& buffer = _writeQueue.front();

        _socket.async_write_some(buffer.ToBoostConstBuffer(), std::bind(&Network::Socket<T>::AsyncWriteCallback, this, std::placeholders::_1, std::placeholders::_2));
    }

    void AsyncWriteCallback(boost::system::error_code error, std::size_t bytesTransferred)
    {
        if (!error)
        {
            if (_closing)
                return;

            {
                std::lock_guard lock(_sendMutex);
                auto const& buffer = _writeQueue.front();
                buffer.AdvanceReadPos(bytesTransferred);

                if (!buffer.GetReadableSize())
                    _writeQueue.pop();

                _sending = false;
            }

            if (!_writeQueue.empty())
                AsyncWrite();
            else if (_delayedClose)
                Close();
        }
        else if (error.value() != boost::asio::error::shut_down && error.value() != boost::asio::error::operation_aborted)
            Close();

    }

    void FinishSendingAndClose()
    {
        if (_sending.exchange(true) || _delayedClose)
            _delayedClose = true;
        else
            Close();
    }

    virtual void OnClose()
    {
    }

    void Close()
    {
        if (_closing.exchange(true))
            return;

        boost::system::error_code err;
        _socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both, err);

        OnClose();
    }

    std::string GetRemoteAddress()
    {
        return _socket.remote_endpoint().address().to_string();
    }

    uint16 GetRemotePort()
    {
        return _socket.remote_endpoint().port();
    }

protected:
    SocketBuffer _readBuffer;
    SocketType _socket;

private:
    std::atomic<bool> _closing;
    std::atomic<bool> _delayedClose;
    std::atomic<bool> _sending;
    std::queue<SocketBuffer> _writeQueue;
    std::function<void()> _onReadExternalCallback = [](){};
    std::mutex _sendMutex;
};
} // Network
