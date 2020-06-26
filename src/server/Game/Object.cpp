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
#include "Object.h"

namespace Game
{

Object::Object(ObjectGuid guid, ObjectType objectType) : Object(guid, objectType, 0)
{
}

Object::Object(ObjectGuid guid, ObjectType objectType, int32 entry) : _guid(guid), _objectType(objectType), _entry(entry), _dynamicFlags(0), _scale(1.f)
{
}

ObjectGuid Object::Object::GetGUID() const
{
    return _guid;
}

void Object::WriteObjectData(Buffer& buffer) const
{
    buffer << int32(_entry);
    buffer << uint32(_dynamicFlags);
    buffer << float(_scale);
}

void Object::WriteCreationBlock(Buffer& buffer) const
{
    buffer << uint8(2); // CreationType
    buffer << GetGUID();
    buffer << uint8(_objectType);

    WriteMovementCreateBlock(buffer);

    uint32 wPos = buffer.GetWritePos();
    buffer << uint32(0);    // Size
    buffer << uint8(0xFF);  // Flags
    WriteUpdateFieldsCreateBlock(buffer);
    uint32 size = buffer.GetWritePos() - wPos - 4;
    buffer.WriteBytesAt_unsafe(wPos, &size, 1);
}

void Object::WriteMovementCreateBlock(Buffer& buffer) const
{
    // @todo: handle creation flags better
}

void Object::WriteUpdateFieldsCreateBlock(Buffer& buffer) const
{
    buffer << int32(0);
    buffer << uint32(0);
    buffer << float(1.f);
}

} // Game
