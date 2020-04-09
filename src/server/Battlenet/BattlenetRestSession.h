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
#include "RestServer.h"
#include "BattlenetSession.h"

namespace Battlenet::Rest
{

class Session final : public Network::Rest::Server<Battlenet::Rest::Session>
{
public:
    // Needs to be here for SocketMgr
    using ServerType = Network::Rest::Server<Battlenet::Rest::Session>;

    struct TicketHolder
    {
        std::string accountName;
        size_t timeRemaining = 10;
    };

    Session(ServerType::RawSocketType&& socket) : ServerType(std::move(socket))
    {
        RegisterHandler("GET", "/bnetserver/login/", [this](HttpHeader const& header, Network::SocketBuffer const& buffer)
        {
            char const loginString[] = "{\"type\":\"LOGIN_FORM\",\"inputs\":[{\"input_id\":\"account_name\",\"type\":\"text\",\"label\":\"E-mail\",\"max_length\":320},{\"input_id\":\"password\",\"type\":\"password\",\"label\":\"Password\",\"max_length\":16},{\"input_id\":\"log_in_submit\",\"type\":\"submit\",\"label\":\"Log In\"}]}";

            HttpHeader responseHeader;
            responseHeader.Code = "HTTP/1.1 200 OK";
            responseHeader.Headers["Content-Type"] = "application/json;charset=UTF-8";

            Network::SocketBuffer responseBuffer(sizeof(loginString) - 1);
            responseBuffer.Write(std::string_view(loginString));

            Enqueue(responseHeader.Serialize(responseBuffer));
        });

        RegisterHandler("POST", "/bnetserver/login/", [this](HttpHeader const& header, Network::SocketBuffer const& buffer)
        {
            std::string json(buffer.AsStringView());
            std::string accountName;

            rapidjson::Document document;
            document.Parse(json.c_str());

            if (document.HasMember("inputs"))
            {
                auto& inputs = document["inputs"];

                for (int i = 0; i < inputs.Size(); ++i)
                {
                    auto& input = inputs[i];
                    if (input.HasMember("input_id") && input.HasMember("value") && std::string_view(input["input_id"].GetString()) == "account_name")
                        accountName = input["value"].GetString();
                }
            }

            char ticketNumber[20];
            Utils::Random(ticketNumber);

            char ticket[44];
            sprintf(ticket, "SK-%s", Utils::Bytes2HexString(ticketNumber).c_str());

            char loginString[128];
            sprintf(loginString, "{\"authentication_state\":\"DONE\",\"login_ticket\":\"%s\"}", ticket);

            HttpHeader responseHeader;
            responseHeader.Code = "HTTP/1.1 200 OK";
            responseHeader.Headers["Content-Type"] = "application/json;charset=UTF-8";

            Network::SocketBuffer responseBuffer(strlen(loginString));
            responseBuffer.Write(loginString, responseBuffer.GetRemainingSize());

            auto ticketHolder = std::make_unique<TicketHolder>();
            ticketHolder->accountName = std::move(accountName);
            _ticketHolder.emplace(ticket, std::move(ticketHolder));

            Enqueue(responseHeader.Serialize(responseBuffer));
        });
    }

    static void UpdateTimer(boost::system::error_code error, asio::steady_timer* ticketListTimer)
    {
        for (auto iter = _ticketHolder.begin(); iter != _ticketHolder.end();)
        {
            if (!--iter->second->timeRemaining)
            {
                iter = _ticketHolder.erase(iter);
            }
            else
                ++iter;
        }

        if (!error && ServerMgr::Instance().IsStopped())
        {
            ticketListTimer->expires_after(1s);
            ticketListTimer->async_wait(std::bind(&Battlenet::Rest::Session::UpdateTimer, std::placeholders::_1, ticketListTimer));
        }
    }

    static std::string GetAccountNameForTicket(char const* ticket)
    {
        auto iter = _ticketHolder.find(ticket);
        return iter == _ticketHolder.end() ? "" : iter->second->accountName;
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
private:
    static inline std::unordered_map<std::string, std::unique_ptr<TicketHolder>> _ticketHolder;
};

} // Battlenet::Rest
