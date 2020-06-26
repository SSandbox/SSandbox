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

class Object
{
public:
    enum class ObjectType : uint8
    {
        Player = 7,
    };

    Object(ObjectGuid guid, ObjectType objectType);
    Object(ObjectGuid guid, ObjectType objectType, int32 entry);

    ObjectGuid GetGUID() const;

    void WriteObjectData(Buffer& buffer) const;
    void WriteCreationBlock(Buffer& buffer) const;
    virtual void WriteMovementCreateBlock(Buffer& buffer) const;
    virtual void WriteUpdateFieldsCreateBlock(Buffer& buffer) const;

private:
    ObjectGuid _guid;
    ObjectType _objectType;
    int32 _entry;
    uint32 _dynamicFlags;
    float _scale;
};

} // Game
