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
#include "SslStream.h"
#include "Socket.h"

namespace Network::Rest
{

template <typename SslContext>
class Server : public Network::Socket<Network::SslStream<SslContext>>
{
public:

    struct HttpHeader
    {
        std::string Code;
        std::string Url;
        std::string Parameters;
        std::string Method;
        std::unordered_map<std::string, std::string> Headers;

        bool Init(std::vector<std::string_view> const& httpHeader)
        {
            if (httpHeader.size() < 2)
                return false;

            auto versionLine = Utils::Tokenize(httpHeader[0], ' ', true);

            if (versionLine.size() != 3)
                return false;

            if (!versionLine[2].starts_with("HTTP"))
                return false;

            auto method = Utils::Tokenize(versionLine[0], '?', false);
            Method = method[0];

            if (method.size() > 2)
                return false;

            if (method.size() == 2)
                Parameters =  method[1].data();

            Url = versionLine[1];

            for (auto header = httpHeader.begin() + 1; header != httpHeader.end(); ++header)
            {
                auto const& str = *header;
                auto pos = str.find(':');

                if (pos == std::string::npos)
                    return false;

                Headers.emplace(std::string(str.data(), pos), std::string(str.data() + pos + 2, str.size() - pos - 2));
            }

            return true;
        }

        char const* GetHeaderValue(std::string_view header) const
        {
            auto iter = Headers.find(header.data());
            return iter == Headers.end() ? "" : iter->second.c_str();
        }

        Network::SocketBuffer Serialize(Network::SocketBuffer const& bodyBuffer)
        {
            Network::SocketBuffer buffer(4096);
            buffer.Write(Code).Write("\r\n", 2);

            Headers["Content-Length"] = std::to_string(bodyBuffer.GetReadableSize());

            for (auto const& header : Headers)
            {
                buffer.Write(header.first).Write(": ", 2).Write(header.second).Write("\r\n", 2);
            }

            buffer.Write("\r\n", 2);

            if (std::size_t readableSize = bodyBuffer.GetReadableSize())
            {
                buffer.Resize(buffer.GetWritePos() + readableSize);
                buffer.Write(bodyBuffer.GetReadPointer(), readableSize);
                bodyBuffer.AdvanceReadPos(readableSize);
            }

            return buffer;
        }
    };

    // Needs to be here for SocketMgr
    using SocketType = Network::Socket<Network::SslStream<SslContext>>;

    Server(typename SocketType::RawSocketType&& socket) : SocketType(std::move(socket)), _buffer(0)
    {
        OnRead([this]()
        {

            while (std::size_t readableSize = _readBuffer.GetReadableSize())
            {
                if (std::size_t otherReadableSize = _buffer.GetRemainingSize())
                {
                    auto min = std::min(readableSize, otherReadableSize);
                    _buffer.Write(_readBuffer.GetReadPointer(), min);
                    _readBuffer.AdvanceReadPos(min);

                    if (!_buffer.GetRemainingSize())
                        HandleRest(_header.Method, _header.Url);
                }
                else
                {
                    std::string_view buffer(_readBuffer.GetReadPointer(), readableSize);
                    auto loc = buffer.find("\r\n\r\n");

                    if (loc == std::string::npos)
                        return;

                    std::string_view headerBuffer(_readBuffer.GetReadPointer(), loc + 4);

                    auto tokens = Utils::Tokenize(headerBuffer, "\r\n", false);

                    if (!_header.Init(tokens))
                    {
                        Close();
                        return;
                    }

                    _readBuffer.AdvanceReadPos(loc + 4);

                    auto length = _header.GetHeaderValue("Content-Length");

                    if (length != "")
                    {
                        auto intLength = std::atoi(length);

                        if (intLength > 128 * 1024 * 1024)
                        {
                            Close();
                            return;
                        }
                        _buffer.Reset(intLength);
                    }
                    else
                    {
                        _buffer.Reset(0);
                        HandleRest(_header.Method, _header.Url);
                    }
                }
            }
        });

        _socket.async_handshake(boost::asio::ssl::stream_base::server, [this](boost::system::error_code error)
        {
            if (!error)
                AsyncRead();
            else
                Close();
        });
    }

    void HandleRest(std::string const& method, std::string const& url)
    {
        Log::Log(LogSeverity::AuthConnectionInfo, "REST handler: %s %s", method.c_str(), url.c_str());

        auto methodHandler = _handlers.find(method);
        if (methodHandler == _handlers.end())
            return;

        auto urlHandler = methodHandler->second.find(url);

        if (urlHandler != methodHandler->second.end())
            urlHandler->second(_header, _buffer);
    }

    void RegisterHandler(std::string_view method, std::string_view url, std::function<void(HttpHeader const&, Network::SocketBuffer const&)>&& function)
    {
        _handlers[method.data()][url.data()] = std::move(function);
    }

    static boost::asio::ssl::context& GetSslContext()
    {
        static boost::asio::ssl::context gSslContext(boost::asio::ssl::context::method::sslv23_server);
        return gSslContext;
    }

    static bool InitSslContext(std::string_view certFilePath, std::string_view keyFilePath)
    {
        if (!fs::exists(certFilePath) || !fs::exists(keyFilePath))
            return false;

        auto& context = GetSslContext();
        boost::system::error_code error;

        context.use_certificate_chain_file(certFilePath.data(), error);

        if (error)
            return false;

        context.use_private_key_file(keyFilePath.data(), boost::asio::ssl::context::pem, error);
        return !error;
    }

    virtual bool Update() final
    {
        return SocketType::Update();
    }

private:
    HttpHeader _header;
    Network::SocketBuffer _buffer;
    std::unordered_map<std::string, std::unordered_map<std::string, std::function<void(HttpHeader const&, Network::SocketBuffer const&)>>> _handlers;
};
} // Rest
