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
#include <openssl/sha.h>

namespace Crypt
{
class Sha256
{
public:
    constexpr static int Length = 32;

    Sha256()
    {
        SHA256_Init(&_context);
    }

    ~Sha256()
    {
        SHA256_Init(&_context);
    }

    void UpdateData(void const* data, std::size_t length)
    {
        SHA256_Update(&_context, data, length);
    }

    void UpdateData(std::string_view data)
    {
        UpdateData(data.data(), data.length());
    }

    void Finalize()
    {
        SHA256_Final(_digest.data(), &_context);
    }

    uint8 const* GetDigest()
    {
        return _digest.data();
    }

private:
    SHA256_CTX _context;
    std::array<uint8, Length> _digest;
};
} // Crypt
