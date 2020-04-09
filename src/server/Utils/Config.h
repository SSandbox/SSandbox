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
#include <fstream>

namespace Utils
{

class Config
{
public:
    Config()
    {
    }

    static Config& Instance()
    {
        static Config gConfig;
        return gConfig;
    }

    bool Load(fs::path path)
    {
        std::ifstream stream(path);

        if (!stream.is_open())
            return false;

        for (std::string line; std::getline(stream, line);)
        {
            auto tokens = TokenizeAnyOf(line, "\r\n\t =", true);

            if (!tokens.size())
                continue;

            if (tokens[0][0] == '#')
                continue;

            if (tokens.size() != 2)
                return false;

            _values.emplace(std::string(tokens[0]), std::string(tokens[1]));
        }

        stream.close();
        return true;
    }

    template <typename T, typename = std::enable_if_t<std::disjunction_v<std::is_same<T, std::string>, std::is_arithmetic<T>>>>
    T Get(std::string const& key, T const& defaultValue)
    {
        auto iter = _values.find(key);
        if (iter == _values.end())
            return defaultValue;

        if constexpr (std::is_arithmetic_v<T>)
        {
            T t;
            if (!Utils::StrToInt(iter->second, t))
                t = defaultValue;
            return t;
        }
        else
            return iter->second;
    }


private:
    std::unordered_map<std::string, std::string> _values;

private:
};
} // Utils
