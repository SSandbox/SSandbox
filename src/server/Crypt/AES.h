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
#include "openssl/evp.h"

namespace Crypt
{

class Aes
{
public:
    Aes() : _initialized(false), _context(nullptr)
    {
    }

    ~Aes()
    {
        if (_context)
            EVP_CIPHER_CTX_free(_context);
    }

    void Init(bool encrypting, uint8 const* key)
    {
        if (_context)
            EVP_CIPHER_CTX_free(_context);

        _context = EVP_CIPHER_CTX_new();
        EVP_CIPHER_CTX_init(_context);
        EVP_CipherInit_ex(_context, EVP_aes_128_gcm(), nullptr, key, nullptr, encrypting);

        _initialized = true;
        _encrypting = encrypting;
    }

    bool Process(uint8 const* iv, void* data, std::size_t length, uint8(&tag)[12])
    {
        if (!_context)
            return false;

        uint8* ucharPtr = reinterpret_cast<uint8*>(data);

        if (!EVP_CipherInit_ex(_context, nullptr, nullptr, nullptr, iv, -1))
            return false;

        int outLen;
        if (!EVP_CipherUpdate(_context, ucharPtr, &outLen, ucharPtr, length))
            return false;

        if (!_encrypting)
        {
            if (EVP_CIPHER_CTX_ctrl(_context, EVP_CTRL_GCM_SET_TAG, sizeof(tag), tag))
                return EVP_CipherFinal_ex(_context, ucharPtr + outLen, &outLen);

            return false;
        }
        else
        {
            if (EVP_CipherFinal_ex(_context, ucharPtr + outLen, &outLen))
                return EVP_CIPHER_CTX_ctrl(_context, EVP_CTRL_GCM_GET_TAG, sizeof(tag), tag);

            return false;
        }
    }

    bool IsInitialized()
    {
        return _initialized;
    }
private:
    EVP_CIPHER_CTX* _context;
    bool _encrypting;
    bool _initialized;
};
} // Crypt
