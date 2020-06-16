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
#include "Object.h"

namespace Game
{

enum class EquipmentSlot : uint8
{
    Head        = 0,
    Neck        = 1,
    Shoulders   = 2,
    Body        = 3,
    Chest       = 4,
    Waist       = 5,
    Legs        = 6,
    Feet        = 7,
    Wrist       = 8,
    Hands       = 9,
    Finger1     = 10,
    Finger2     = 11,
    Trinket1    = 12,
    Trinket2    = 13,
    Back        = 14,
    MainHand    = 15,
    OffHand     = 16,
    Ranged      = 17,
    Tabard      = 18,
    None        = 255
};

enum InventoryType : uint8
{
    None            = 0,
    Head            = 1,
    Neck            = 2,
    Shoulds         = 3,
    Body            = 4,
    Chest           = 5,
    Waist           = 6,
    Legs            = 7,
    Feet            = 8,
    Wrist           = 9,
    Hands           = 10,
    Finger          = 11,
    Trinket         = 12,
    Weapon          = 13,
    Shield          = 14,
    Ranged          = 15,
    Cloak           = 16,
    TwoHandedWeapon = 17,
    Bag             = 18,
    Tabard          = 19,
    Robe            = 20,
    MainHandWeapon  = 21,
    OffHandWeapon   = 22,
    Holdable        = 23,
    Ammo            = 24,
    Thrown          = 25,
};

class Character : public Object
{
    friend class Player::Session;

public:

    struct CustomizationOption
    {
        uint32 OptionID;
        uint32 Value;

        friend Buffer& operator<<(Buffer& lhs, Character::CustomizationOption const& rhs);
        friend Buffer const& operator>>(Buffer const& lhs, Character::CustomizationOption& rhs);
    };

    Character();
    void SetActiveSession(Player::Session* session);
    void Logout();
    void ReadCreationFromBuffer(Buffer const& buffer);
    void FinishCreatingCharacter();

    void FinishLoggingIn();

    void Teleport(uint16 mapID, Position pos);

    void WriteEnumCharacter(Buffer& buffer, uint8 index) const;
    void WriteCreationBlock(Buffer& buffer) const;

    void WriteUnitData(Buffer& buffer) const;
    void WritePlayerData(Buffer& buffer) const;
    void WriteActivePlayerData(Buffer& buffer) const;

    void SetCanFly(bool value);

    void SendMessage(std::string_view message);

    ObjectGuid GetGUID() const;

    uint16 GetMapID() const;
    Position GetPosition() const;
    float GetOrientation() const;

    uint32 GetNativeDisplayID() const;

    EquipmentSlot GetEquipmentSlotForItem(uint32 itemID) const;

private:

    struct SkillInfo
    {
        uint16 SkillLineID;
        uint16 SkillStep;
        uint16 SkillRank;
        uint16 SkillStartingRank;
        uint16 SkillMaxRank;
        int16 SkillTempBonus;
        uint16 SkillPermBonus;
    };

    ObjectGuid _guid;

    uint8 _race;
    uint8 _class;
    uint8 _sex;
    uint8 _skin;
    uint8 _face;
    uint8 _hairStyle;
    uint8 _hairColor;
    uint8 _facialHairStyle;
    uint8 _outfitID;
    std::array<uint8, 3> _customDisplayData;
    std::vector<CustomizationOption> _customizationOptions;

    uint8 _level;
    uint16 _mapID;
    Position _position;
    float _orientation;
    float _flightSpeed;

    std::string _name;

    std::array<uint32, 23> _equipedItems;
    std::array<SkillInfo, 256> _skills;
    std::vector<uint32> _knownSpells;

    Player::Session* _session;
};

} // Game
