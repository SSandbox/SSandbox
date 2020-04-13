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

class Buffer
{
public:
    Buffer(std::size_t size = 4096) : _rpos(0), _wpos(0), _bits(0), _bitPos(0), _bitVal(0)
    {
        _buffer.resize(size);
    }


    std::size_t GetSize() const
    {
        return _buffer.size();
    }

    std::size_t GetUsedSize() const
    {
        return _wpos;
    }

    void ReadFinish() const
    {
        _rpos = _wpos;
    }

    template <typename T>
    void WriteBytes(T const* t, std::size_t count)
    {
        if (_bitPos)
            FlushBits();

        std::size_t bytesToWrite = sizeof(T) * count;

        if (GetSize() < bytesToWrite + _wpos)
            _increaseSize(bytesToWrite + _wpos);

        std::memcpy(_buffer.data() + _wpos, t, bytesToWrite);
        _wpos += bytesToWrite;
    }

    template <typename T>
    void ReadBytes(T* t, std::size_t count) const
    {
        std::size_t bytesToRead = sizeof(T) * count;

        if (_wpos < (bytesToRead + _rpos))
            throw new std::exception("Unable to read beyong the end of the stream");

        std::memcpy(t, _buffer.data() + _rpos, bytesToRead);
        _rpos += bytesToRead;
    }

    template <typename T>
    void ReadSkip() const
    {
        if (_wpos < (sizeof(T) + _rpos))
            throw new std::exception("Unable to read beyond the end of the stream");

        _rpos += sizeof(T);
    }

    template <typename T>
    void ReadBytesAt_unsafe(std::size_t offset, T* t, std::size_t count) const
    {
        std::size_t bytesToRead = sizeof(T) * count;
        std::memcpy(t, _buffer.data() + offset, bytesToRead);
    }

    template <typename T>
    void WriteBytesAt_unsafe(std::size_t offset, T const* t, std::size_t count)
    {
        std::size_t bytesToRead = sizeof(T) * count;
        std::memcpy(_buffer.data() + offset, t, bytesToRead);
    }

    bool FromSocketBuffer(Network::SocketBuffer const& buffer, uint32 packetSize)
    {
        auto availableSize = std::min(buffer.GetReadableSize(), packetSize - _wpos);
        WriteBytes(buffer.GetReadPointer(), availableSize);
        buffer.AdvanceReadPos(availableSize);
        return _wpos == packetSize;
    }

    char const* GetBuffer() const
    {
        return _buffer.data();
    }

    char* GetBuffer()
    {
        return _buffer.data();
    }

    template <int size>
    using BitsToType_t = std::conditional_t<(size <= sizeof(uint64) * 8), std::conditional_t<(size > sizeof(uint32) * 8), uint64, std::conditional_t<(size > sizeof(uint16) * 8), uint32, std::conditional_t<(size > sizeof(uint8) * 8), uint16, std::conditional_t<(size == 1), bool, uint8>>>>, void>;

    template <int bits>
    void WriteBits(BitsToType_t<bits> value)
    {
        for (int remaining = bits; remaining > 0;)
        {
            int currentRemainingBits = 8 - _bitPos;
            int bitsToWrite = std::min(currentRemainingBits, remaining);

            if (currentRemainingBits)
            {
                _bitVal |= (value & ((1 << bitsToWrite) - 1)) << (8 - _bitPos - bitsToWrite);

                if constexpr (bits != 1)
                    value >>= bitsToWrite;

                _bitPos += bitsToWrite;
                remaining -= bitsToWrite;
            }

            if (_bitPos == 8)
            {
                _bitPos = 0;
                WriteBytes(&_bitVal, 1);
                _bitVal = 0;
            }
        }
    }

    template <int bits>
    BitsToType_t<bits> ReadBits() const
    {
        BitsToType_t<bits> value = 0;

        for (int remaining = bits; remaining > 0;)
        {
            if (!_bitPos)
            {
                _bitPos = 8;
                ReadBytes(&_bitVal, 1);
            }

            int bitsToRead = std::min<int>(_bitPos, remaining);

            if constexpr (bits != 1)
                value <<= bitsToRead;

            value |= (_bitVal >> (_bitPos - bitsToRead)) & ((1 << bitsToRead) - 1);

            _bitPos -= bitsToRead;
            remaining -= bitsToRead;
        }

        return value;
    }

    void FlushBits()
    {
        if (!_bitPos)
            return;

        _bitPos = 0;
        WriteBytes(&_bitVal, 1);
        _bitVal = 0;
    }

    void AdvanceWritePos(std::size_t count)
    {
        _wpos += count;
    }

    template <std::size_t size>
    Buffer& operator<<(std::array<uint8, size> const& u)
    {
        WriteBytes(u.data(), size);
        return *this;
    }

    template <std::size_t size>
    Buffer& operator<<(std::array<char, size> const& u)
    {
        WriteBytes(u.data(), size);
        return *this;
    }

    Buffer& operator<<(Buffer const& rhs)
    {
        WriteBytes(rhs.GetBuffer(), rhs.GetWritePos());
        return *this;
    }

    Buffer& operator<<(int8 u)
    {
        WriteBytes(&u, 1);
        return *this;
    }

    Buffer& operator<<(uint8 u)
    {
        WriteBytes(&u, 1);
        return *this;
    }

    Buffer& operator<<(uint16 u)
    {
        WriteBytes(&u, 1);
        return *this;
    }

    Buffer& operator<<(int16 u)
    {
        WriteBytes(&u, 1);
        return *this;
    }

    Buffer& operator<<(uint32 u)
    {
        WriteBytes(&u, 1);
        return *this;
    }

    Buffer& operator<<(int32 u)
    {
        WriteBytes(&u, 1);
        return *this;
    }

    Buffer& operator<<(float f)
    {
        WriteBytes(&f, 1);
        return *this;
    }

    Buffer const& operator<<(uint64 u)
    {
        WriteBytes(&u, 1);
        return *this;
    }

    Buffer const& operator<<(int64 u)
    {
        WriteBytes(&u, 1);
        return *this;
    }

    Buffer const& operator>>(uint8& u) const
    {
        ReadBytes(&u, 1);
        return *this;
    }

    Buffer const& operator>>(uint16& u) const
    {
        ReadBytes(&u, 1);
        return *this;
    }

    Buffer const& operator>>(uint32& u) const
    {
        ReadBytes(&u, 1);
        return *this;
    }

    Buffer const& operator>>(uint64& u) const
    {
        ReadBytes(&u, 1);
        return *this;
    }

    Buffer const& operator>>(int64& u) const
    {
        ReadBytes(&u, 1);
        return *this;
    }

    Buffer const& operator>>(float& u) const
    {
        ReadBytes(&u, 1);
        return *this;
    }

    std::string ReadString(std::size_t size) const
    {
        if (_wpos < (size + _rpos))
            throw new std::exception("Unable to read beyond the end of the stream");

        std::string str(std::string_view(_buffer.data() + _rpos, size));
        _rpos += size;
        return str;
    }

    std::size_t GetWritePos() const
    {
        return _wpos;
    }

    void WriteString(std::string_view str)
    {
        WriteBytes(str.data(), str.size());
    }

protected:
    void _increaseSize(std::size_t requiredSize)
    {
        std::size_t newSize = _buffer.size();

        for (; newSize <= requiredSize; newSize *= 2);

        if (newSize != requiredSize)
            _buffer.resize(newSize);
    }

    std::vector<char> _buffer;
    mutable std::size_t _rpos;
    std::size_t _wpos;
    mutable uint8 _bits;
    mutable uint8 _bitPos;
    mutable uint8 _bitVal;
};

class Packet : public Buffer
{
public:
    Packet() : Packet(4096)
    {
    }

    Packet(std::size_t size) : Buffer(size)
    {
        _wpos = 2;
        _rpos = 2;
        _buffer[0] = 0;
        _buffer[1] = 0;
    }

    Packet(Opcode opcode, std::size_t size = 4094) : Buffer(size + 2)
    {
        _wpos = 2;
        _rpos = 2;
        SetOpcode(opcode);
    }

    void ResetForNetwork(std::size_t size)
    {
        _wpos = 0;
        _rpos = 2;
        _bitPos = 0;
        _buffer.resize(size);
    }

    void SetOpcode(Opcode opcode)
    {
        WriteBytesAt_unsafe(0, &opcode, 1);
    }

    Opcode GetOpcode() const
    {
        Opcode opcode;
        ReadBytesAt_unsafe(0, &opcode, 1);
        return opcode;
    }
};
