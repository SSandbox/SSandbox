/*
 * Copyright (C) 2020 SSandbox project (sovak007@gmail.com)
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
 *along with this program; if not, write to the Free Software Foundation,
 *Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 */
#pragma once
#include "Utils.h"
#include <Windows.h>
#include <Winternl.h>
#include <TlHelp32.h>
#include <optional>
#include <vector>

using uint8_opt = std::optional<uint8>;

template <typename T, std::size_t patternLen>
T* FindPattern(void* buffer, std::size_t byteSize, const uint8_opt(&pattern)[patternLen])
{
    auto begin = reinterpret_cast<uint8*>(buffer);
    auto end = reinterpret_cast<uint8*>(buffer) + byteSize;

    auto iter = std::search(begin, end, std::begin(pattern), std::end(pattern), [](auto byte, auto opt)
    {
        return !opt.has_value() || opt.value() == byte;
    });

    return iter == end ? nullptr : reinterpret_cast<T*>(iter);
}

template <typename T, std::size_t patternLen>
std::vector<T*> FindPatterns(void* buffer, std::size_t byteSize, const uint8_opt(&pattern)[patternLen])
{
    auto begin = reinterpret_cast<uint8*>(buffer);
    auto end = reinterpret_cast<uint8*>(buffer) + byteSize;

    std::vector<T*> ptrs;

    for (T* ptr = FindPattern<T>(begin, byteSize, pattern); ptr != nullptr;)
    {
        ptrs.push_back(reinterpret_cast<T*>(ptr));

        auto next = reinterpret_cast<uint8*>(ptr) + 1;
        std::size_t remaining = (end - next);
        ptr = FindPattern<T>(next, remaining, pattern);
    }

    return ptrs;
}

template <typename T>
T* AddOffset(T* t, std::size_t offset)
{
    return reinterpret_cast<T*>(reinterpret_cast<char*>(t) + offset);
}


class HandleCloser
{
public:
    void operator()(HANDLE handle)
    {
        if (handle != nullptr && handle != INVALID_HANDLE_VALUE)
            CloseHandle(handle);
    }
};

using AutoHandle = std::unique_ptr<void, HandleCloser>;

