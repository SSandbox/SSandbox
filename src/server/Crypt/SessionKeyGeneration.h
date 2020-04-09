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
#include "Sha256.h"

// Ported from TrinityCore
namespace Crypt
{

class SessionKeyGenerator
{
public:
    SessionKeyGenerator(uint8* buff, uint32 size)
    {
        uint32 halfSize = size / 2;

        Sha256 sh;
        sh.UpdateData(buff, halfSize);
        sh.Finalize();

        memcpy(o1, sh.GetDigest(), Sha256::Length);

        Sha256 sh2;
        sh2.UpdateData(buff + halfSize, size - halfSize);
        sh2.Finalize();

        memcpy(o2, sh2.GetDigest(), Sha256::Length);

        memset(o0, 0x00, Sha256::Length);

        FillUp();
    }

    void Generate(uint8* buf, uint32 sz)
    {
        for (uint32 i = 0; i < sz; ++i)
        {
            if (taken == Sha256::Length)
                FillUp();

            buf[i] = o0[taken];
            taken++;
        }
    }

private:
    void FillUp()
    {
        Sha256 sh;
        sh.UpdateData(o1, Sha256::Length);
        sh.UpdateData(o0, Sha256::Length);
        sh.UpdateData(o2, Sha256::Length);
        sh.Finalize();

        memcpy(o0, sh.GetDigest(), Sha256::Length);

        taken = 0;
    }

    uint32 taken;
    uint8 o0[Sha256::Length];
    uint8 o1[Sha256::Length];
    uint8 o2[Sha256::Length];
};
} // Crypt
