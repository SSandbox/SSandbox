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

namespace Network
{

class SocketBuffer
{
public:
    explicit SocketBuffer() : _wpos(0), _rpos(0)
    {
        _buffer.resize(16384);
    }

    explicit SocketBuffer(std::size_t size) : _wpos(0), _rpos(0)
    {
        _buffer.resize(size);
    }

    void Reset(std::size_t size)
    {
        _wpos = 0;
        _rpos = 0;
        _buffer.resize(size);
    }

    void Resize(std::size_t size)
    {
        _buffer.resize(size);
    }

    std::size_t GetWritePos() const
    {
        return _wpos;
    }

    std::size_t GetReadPos() const
    {
        return _rpos;
    }

    void ResetReadPos()
    {
        _rpos = 0;
    }

    char* GetWritePointer()
    {
        return _buffer.data() + _wpos;
    }

    std::size_t GetReadableSize() const
    {
        return _wpos - _rpos;
    }

    char const* GetReadPointer() const
    {
        return _buffer.data() + _rpos;
    }

    std::size_t AdvanceWritePos(std::size_t amount)
    {
        assert(amount + _wpos <= _buffer.size());
        return _wpos += amount;
    }

    std::size_t AdvanceReadPos(std::size_t amount) const
    {
        assert(amount + _rpos <= _buffer.size());
        return _rpos += amount;
    }

    std::size_t GetRemainingSize() const
    {
        return _buffer.size() - _wpos;
    }

    std::string_view AsStringView() const
    {
        return { GetReadPointer(), GetReadableSize() };
    }

    template <typename T>
    SocketBuffer const& Read(T* dest, std::size_t count) const
    {
        std::memcpy(dest, _buffer.data() + _rpos, count * sizeof(T));
        AdvanceReadPos(count * sizeof(T));
        return *this;
    }

    template <typename T>
    SocketBuffer& Write(T* src, std::size_t count = 1u)
    {
        std::memcpy(_buffer.data() + _wpos, src, count * sizeof(T));
        AdvanceWritePos(count * sizeof(T));
        return *this;
    }

    SocketBuffer& Write(std::string_view string)
    {
        return Write(string.data(), string.size());
    }

    boost::asio::mutable_buffer ToBoostMutableBuffer()
    {
        return {_buffer.data() + _wpos, GetRemainingSize()};
    }

    boost::asio::const_buffer ToBoostConstBuffer() const
    {
        return {_buffer.data() + _rpos, GetReadableSize()};
    }

    void Normalize()
    {
        if (GetRemainingSize() < 128)
        {
            _buffer.resize(_buffer.size() * 2);
        }

        if (_rpos)
        {
            if (_rpos != _wpos)
                memmove(_buffer.data(), GetReadPointer(), GetReadableSize());

            _wpos -= _rpos;
            _rpos = 0;
        }
    }

private:
    std::vector<char> _buffer;
    std::size_t _wpos;
    mutable std::size_t _rpos;
};
} // Network
