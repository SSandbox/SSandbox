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
#include "Defines.h"

namespace Utils
{

using TokenList = std::vector<std::string_view>;

void TokenizeAnyOf(TokenList& tokens, std::string_view view, std::string_view token, bool skipEmpty);
void Tokenize(TokenList& tokens, std::string_view view, std::string_view token, bool skipEmpty);
void Tokenize(TokenList& tokens, std::string_view view, char token, bool skipEmpty);
TokenList TokenizeAnyOf(std::string_view view, std::string_view token, bool skipEmpty);
TokenList Tokenize(std::string_view view, std::string_view token, bool skipEmpty);
TokenList Tokenize(std::string_view view, char token, bool skipEmpty);

static inline std::mt19937 mt(std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count());

void Random(char* bytes, std::size_t count);

template <std::size_t count>
inline void Random(char(& bytes)[count])
{
    return Random(bytes, count);
}

std::string Bytes2HexString(char const* bytes, std::size_t count);

template <std::size_t count>
inline std::string Bytes2HexString(const char(& bytes)[count])
{
    return Bytes2HexString(bytes, count);
}

void ToLower(std::string& string);

template<typename T>
T Random()
{
    char bytes[sizeof(T)];
    Random(bytes);

    T t;
    std::memcpy(&t, bytes, sizeof(T));
    return t;
}

template <typename T>
 std::underlying_type_t<T> ToUnderlying(T e)
{
    return static_cast< std::underlying_type_t<T>>(e);
}

template <typename T, typename T2, typename = std::enable_if_t<std::is_integral_v<T2>>>
T ToEnum(T2 e)
{
    return static_cast<T>(e);
}

template <typename T>
class EnumFlags
{
public:
    using BaseType = std::underlying_type_t<T>;

    EnumFlags(T flags) : _flags(ToUnderlying(flags))
    {
    }

    EnumFlags(BaseType flags) : _flags(flags)
    {
    }

    bool HasFlag(T flag)
    {
        return (_flags & ToUnderlying(flag)) != 0;
    }

private:
    BaseType _flags;
};

template <typename T>
bool StrToInt(std::string_view str, T& value)
{
    auto [ptr, ecc] = std::from_chars(str.data(), str.data() + str.size(), value);
    return ecc == std::errc();
}

} // Utils
