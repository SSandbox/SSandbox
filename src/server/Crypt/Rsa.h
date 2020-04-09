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
#include <openssl/rsa.h>
#include <openssl/pem.h>

namespace Crypt
{

// Psst
class RSA;
extern RSA ConnectToRSA;

class RSA
{
public:
    bool Load(const char* path)
    {
        if (!fs::exists(path))
            return false;

        auto bioFile = BIO_new_file(path, "r");

        if (!bioFile)
            return false;

        _rsa = RSA_new();

        if (!PEM_read_bio_RSAPrivateKey(bioFile, &_rsa, nullptr, nullptr))
        {
            RSA_free(_rsa);
            return false;
        }

        return true;
    }

    static bool LoadRSAKey(char const* path)
    {
        return Crypt::ConnectToRSA.Load(path);
    }

    ~RSA()
    {
        if (_rsa)
            RSA_free(_rsa);
    }

    bool Sign(void const* data, uint32 length, char* output)
    {
        if (!_rsa)
            return false;

        uint32 outputLength = 0;
        auto res = RSA_sign(NID_sha256, reinterpret_cast<uint8 const*>(data), length, reinterpret_cast<uint8*>(output), &outputLength, _rsa);

        std::reverse(output, output + GetOutputLength());
        return res != 0;
    }


    std::size_t GetOutputLength()
    {
        return RSA_size(_rsa);
    }

private:
    ::RSA* _rsa;
};

inline RSA ConnectToRSA;

} // Crypt