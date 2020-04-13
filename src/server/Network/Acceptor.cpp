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

#include <PCH.h>
#include "Acceptor.h"
#include <boost/asio.hpp>

Network::Acceptor::Acceptor(std::string_view ipv4, uint16 port, asio::io_context& ioContext) : _endpoint(asio::ip::address_v4::from_string(ipv4.data()), port), _acceptor(ioContext), _closing(false), _ioContext(ioContext)
{
    _acceptor.open(_endpoint.protocol());
    _acceptor.set_option(asio::socket_base::reuse_address(false));

#ifdef WIN32
    _acceptor.set_option(asio::detail::socket_option::boolean<BOOST_ASIO_OS_DEF(SOL_SOCKET), SO_EXCLUSIVEADDRUSE>(true));
#endif
}

bool Network::Acceptor::BindAndRun()
{
    boost::system::error_code errorCode;
    _acceptor.bind(_endpoint, errorCode);

    if (errorCode)
        return false;

    _acceptor.listen(boost::asio::socket_base::max_listen_connections, errorCode);

    return !errorCode;
}

Network::Acceptor::~Acceptor()
{
}

bool Network::Acceptor::IsOpen()
{
    return _acceptor.is_open();
}

void Network::Acceptor::Close()
{
    if (_closing.exchange(true))
        return;

    _acceptor.close();
}
