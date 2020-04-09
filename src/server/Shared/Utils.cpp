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

#include "PCH.h"
#include "Utils.h"

namespace Utils
{

void TokenizeAnyOf(TokenList& tokens, std::string_view view, std::string_view token, bool skipEmpty)
{
    auto size = view.size();

    for (std::size_t offset = 0;;)
    {
        auto loc = view.find_first_of(token, offset);

        if (loc == std::string::npos)
        {
            if (size != offset)
                tokens.emplace_back(view.data() + offset, size - offset);

            break;
        }

        if (loc == offset)
        {
            ++offset;

            if (offset >= size)
                break;

            if (skipEmpty)
                continue;
        }

        tokens.emplace_back(view.data() + offset, loc - offset);
        offset = loc + 1;
    }
}

TokenList TokenizeAnyOf(std::string_view view, std::string_view token, bool skipEmpty)
{
    TokenList tokens;
    TokenizeAnyOf(tokens, view, token, skipEmpty);
    return tokens;
}

void Tokenize(TokenList& tokens, std::string_view view, std::string_view token, bool skipEmpty)
{
    auto size = view.size();

    for (std::size_t offset = 0;;)
    {
        auto loc = view.find(token, offset);

        if (loc == std::string::npos)
        {
            if (size != offset)
                tokens.emplace_back(view.data() + offset, size - offset);

            break;
        }

        if (loc == offset)
        {
            offset += token.size();

            if (offset >= size)
                break;

            if (skipEmpty)
                continue;
        }

        tokens.emplace_back(view.data() + offset, loc - offset);
        offset = loc + token.size();
    }
}

TokenList Tokenize(std::string_view view, std::string_view token, bool skipEmpty)
{
    TokenList tokens;
    Tokenize(tokens, view, token, skipEmpty);
    return tokens;
}

void Tokenize(TokenList& tokens, std::string_view view, char token, bool skipEmpty)
{
    auto size = view.size();

    for (std::size_t offset = 0;;)
    {
        auto loc = view.find(token, offset);

        if (loc == std::string::npos)
        {
            if (size != offset)
                tokens.emplace_back(view.data() + offset, size - offset);

            break;
        }

        if (loc == offset)
        {
            ++offset;

            if (offset >= size)
                break;

            if (skipEmpty)
                continue;
        }

        tokens.emplace_back(view.data() + offset, loc - offset);
        offset = loc + 1;
    }
}

TokenList Tokenize(std::string_view view, char token, bool skipEmpty)
{
    TokenList tokens;
    Tokenize(tokens, view, token, skipEmpty);
    return tokens;
}

// TODO: Improve this
void Random(char* bytes, std::size_t count)
{
    for (std::size_t offset = 0; offset < count; offset += sizeof(uint32))
    {
        int rand = mt();
        std::memcpy(bytes + offset, &rand, std::min(sizeof(uint32), count - offset));
    }
}

std::string Bytes2HexString(char const* bytes, std::size_t count)
{
    std::string str(count * 2 + 1, 0);
    constexpr char symbols[] = "0123456789ABCDEF";

    for (std::size_t i = 0; i < count; ++i)
    {

		char u = 0x0f & (bytes[i] >> 4);
		char l = 0x0f & bytes[i];

		str[i * 2] = symbols[u];
		str[i * 2 + 1] = symbols[l];
	}

    return str;
}

void ToLower(std::string& string)
{
    std::transform(string.begin(), string.end(), string.begin(), [](auto c)
    {
        return std::tolower(c);
    });
}
} // Utils
