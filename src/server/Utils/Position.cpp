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
#include "Position.h"

namespace Game
{

Position::Position() : X(0.f), Y(0.f), Z(0.f)
{
}

Position::Position(float x, float y, float z) : X(x), Y(y), Z(z)
{
}

void Position::Relocate(float x, float y, float z)
{
    X = x;
    Y = y;
    Z = z;
}

Buffer& operator<<(Buffer& lhs, Position const& rhs)
{
    lhs << rhs.GetX() << rhs.GetY() << rhs.GetZ();
    return lhs;
}

Buffer const& operator>>(Buffer const& lhs, Position& rhs)
{
    lhs >> rhs.X >> rhs.Y >> rhs.Z;
    return lhs;
}

float Position::GetX() const
{
    return X;
}
float Position::GetY() const
{
    return Y;
}

float Position::GetZ() const
{
    return Z;
}
} // Game
