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
#include <openssl/hmac.h>

namespace Crypt
{

class HmacSha256
{
public:

    static constexpr int Length = Sha256::Length;

    HmacSha256(void const* key, int length)
    {
        _context = HMAC_CTX_new();
        HMAC_Init(_context, reinterpret_cast<uint8 const*>(key), length, EVP_sha256());
    }

    ~HmacSha256()
    {
        HMAC_CTX_free(_context);
    }

    void UpdateData(void const* data, size_t length)
    {
        HMAC_Update(_context, reinterpret_cast<uint8 const*>(data), length);
    }

    void Finalize()
    {
        uint32 length = 0;
        HMAC_Final(_context, _digest.data(), &length);
    }

    uint8 const* GetDigest()
    {
        return _digest.data();
    }

private:
    HMAC_CTX* _context;
    std::array<uint8, Length> _digest;
};
} // Crypt
