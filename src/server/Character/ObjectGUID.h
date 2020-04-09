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

namespace Game
{

class ObjectGuid
{
    friend Buffer& operator<<(Buffer& buffer, Game::ObjectGuid guid)
    {
        uint8 loMask = 0;
        uint8 hiMask = 0;

        auto oldPos = buffer.GetWritePos();
        buffer << uint8(loMask);
        buffer << uint8(hiMask);

        auto Pack = [&buffer](uint64 value, uint8& mask)
        {
            for (uint8 i = 0; value; value >>= 8, ++i)
            {
                uint8 byteVal = value & 0xFF;

                if (byteVal)
                {
                    mask |= (1 << i);
                    buffer << uint8(byteVal);
                }
            }
        };

        Pack(guid.GetLoPart(), loMask);
        Pack(guid.GetHiPart(), hiMask);

        buffer.WriteBytesAt_unsafe(oldPos, &loMask, 1);
        buffer.WriteBytesAt_unsafe(oldPos + 1, &hiMask, 1);
        return buffer;
    }

    friend Buffer const& operator>>(Buffer const& buffer, ObjectGuid& guid)
    {
        uint8 loMask;
        uint8 hiMask;

        uint64 loPart = 0;
        uint64 hiPart = 0;

        buffer >> loMask >> hiMask;

        auto Unpack = [&buffer](uint64& value, uint8 mask)
        {
            if (!mask)
                return;

            for (uint8 i = 0; i < 8; ++i)
            {
                if (mask & (1 << i))
                {
                    uint8 byte;
                    buffer >> byte;
                    value |=  uint64(byte) << (i * 8);
                }
            }
        };

        Unpack(loPart, loMask);
        Unpack(hiPart, hiMask);

        guid = {hiPart, loPart};
        return buffer;
    }

public:
    enum class HighGuid
    {
        Player           = 2,
        Item             = 3,
        Creature         = 8,
        GameObject       = 11,
        WowAccount       = 29,
        BNetAccount      = 30,
        Spell            = 34,
    };

    ObjectGuid(HighGuid highGuid, uint64 ID) : _high(static_cast<uint64>(highGuid) << 58), _low(ID)
    {
    }

    ObjectGuid() : _high(0), _low(0)
    {
    }

    ObjectGuid(uint64 hiPart, uint64 loPart) : _high(hiPart), _low(loPart)
    {
    }

    uint64 GetHiPart()
    {
        return _high;
    }

    uint64 GetLoPart()
    {
        return _low;
    }


private:
    uint64 _high;
    uint64 _low;
};
} // Game
