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
#include <charconv>

namespace DataStores
{

template <typename T, char rowSeparator = '\n', char columnSeparator = ','>
class DB2
{
public:
    using Structure = typename T::Structure;
    static constexpr auto& Filename = T::Filename;
    static constexpr auto& Format = T::Format;
    static constexpr auto& Names = T::Names;
    static constexpr auto& Arrays = T::Arrays;
    static constexpr auto& IndexField = T::IndexField;

    static constexpr std::size_t FieldCount = sizeof(Names) / sizeof(Names[0]);

    explicit DB2() : minElement(0)
    {
    }

    auto const begin()
    {
        return _elems.begin();
    }

    auto const end()
    {
        return _elems.end();
    }

    bool Load(fs::path directory)
    {
        std::ifstream stream(directory / Filename, std::ios::binary);

        if (!stream.is_open())
            return false;

        stream.seekg(0, std::ios::end);
        std::size_t fileSize = stream.tellg();
        stream.seekg(0, std::ios::beg);

        auto buffer = std::make_unique<char[]>(fileSize);
        stream.read(buffer.get(), fileSize);
        stream.close();

        auto lines = Utils::Tokenize(std::string_view{buffer.get(), fileSize}, rowSeparator, false);

        if (lines.size() < 2)
            return false;

        std::vector<std::size_t> columnIncides;
        columnIncides.reserve(FieldCount);

        auto names = Utils::Tokenize(lines[0], columnSeparator, false);

        for (auto& name : names)
        {
            auto arrayChar = name.find('[');

            if (arrayChar != std::string::npos)
                name = std::string_view(name.data(), arrayChar);
        }

        for (auto name : Names)
        {
            for (std::size_t i = 0; i < names.size(); ++i)
            {
                if (name == names[i])
                {
                    columnIncides.push_back(i);
                    break;
                }
            }
        }

        if (columnIncides.size() != FieldCount)
            return false;

        std::vector<std::tuple<uint32, uint32>> indices;

        _elems.reserve(lines.size() - 1);
        indices.reserve(lines.size() - 1);

        Utils::TokenList columns;
        columns.reserve(names.size());

        for (std::size_t i = 1; i < lines.size(); ++i, columns.clear())
        {
            Utils::Tokenize(columns, lines[i], columnSeparator, false);
            alignas(sizeof(void*)) char rowBuffer[sizeof(Structure)];
            uint64 offset = 0;

            for (std::size_t j = 0; j < columnIncides.size(); ++j)
            {
                auto format = Format[j];
                auto index = columnIncides[j];

                for (uint8 y = 0; y < Arrays[j]; ++y)
                {
                    auto str = columns[index + y];

                    switch (format)
                    {
                        case 'u':
                        {
                            uint32 value;
                            std::from_chars(str.data(), str.data() + str.size(), value);

                            _align<uint32>(offset);
                            new (rowBuffer + offset) uint32(value);
                            offset += sizeof(uint32);

                            if (j == IndexField)
                                indices.emplace_back(value, i - 1);

                            break;
                        }
                        case 'i':
                        {
                            int32 value;
                            std::from_chars(str.data(), str.data() + str.size(), value);

                            _align<int32>(offset);
                            new (rowBuffer + offset) int32(value);
                            offset += sizeof(int32);
                            break;
                        }
                        case 's':
                        {
                            _align<std::string>(offset);
                            new (rowBuffer + offset) std::string(str);
                            offset += sizeof(std::string);
                            break;
                        }
                        default:
                            break;
                    }
                }
            }

            assert(offset == sizeof(Structure));
            _elems.emplace_back(std::move(*reinterpret_cast<Structure*>(rowBuffer)));
        }

        auto [min, max] = std::minmax_element(indices.begin(), indices.end());
        _indices.resize(std::get<0>(*max) - std::get<0>(*min) + 1, nullptr);

        for (auto const& index : indices)
            _indices[std::get<0>(index) - std::get<0>(*min)] = _elems.data() + std::get<1>(index);

        minElement = std::get<0>(*min);
        return true;
    }


    Structure const* operator[](std::size_t index)
    {
        index -= minElement;
        return index >= _indices.size() ? nullptr : _indices[index];
    }

private:

    template <typename T>
    void _align(uint64& offset)
    {
        std::size_t space;
        void* asVoidPtr = reinterpret_cast<void*>(offset);
        std::align(alignof(T), sizeof(T), asVoidPtr, space);
        offset =  reinterpret_cast<uint64>(asVoidPtr);
    }

    std::vector<Structure> _elems;
    std::vector<Structure*> _indices;

    uint32 minElement;
};
} // Datastores