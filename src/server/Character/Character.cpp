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
#include "Character.h"
#include "PlayerSession.h"

namespace Game
{

std::atomic<uint64> gIDCounter = 0;

Character::Character() : _guid(ObjectGuid::HighGuid::Player, gIDCounter++), _position(-2325, -5124, 6570), _session(nullptr), _flightSpeed(1.f)
{
    std::fill(_equipedItems.begin(), _equipedItems.end(), 0);
}

void Character::SetActiveSession(Player::Session* session)
{
    _session = session;
}

void Character::Logout()
{
    Packet logoutComplete(Opcode::SMSG_LOGOUT_COMPLETE);
    _session->SendPacket(logoutComplete);
    _session->_currentCharacter = nullptr;
    _session = nullptr;
}

void Character::ReadCreationFromBuffer(Buffer const& buffer)
{
    auto length = buffer.ReadBits<6>();
    auto hasTemplateSet = buffer.ReadBits<1>();
    buffer.ReadBits<1>(); // IsTrialBoost
    buffer.ReadBits<1>(); // IsTrialBoost

    buffer >> _race;
    buffer >> _class;
    buffer >> _sex;
    buffer >> _skin;
    buffer >> _face;
    buffer >> _hairStyle;
    buffer >> _hairColor;
    buffer >> _facialHairStyle;
    buffer >> _outfitID;
    buffer.ReadBytes(_customDisplayData.data(), _customDisplayData.size());
    _name = buffer.ReadString(length);

    if (hasTemplateSet)
        buffer.ReadSkip<uint32>();
}

void Character::FinishCreatingCharacter()
{
    _level = Globals::MaxLevel;
    _mapID = 2222;
    _orientation = 0;

    for (auto outfit : DataStores::CharStartOutfit)
    {
        if (outfit.RaceID == _race && outfit.ClassID == _class)
        {
            for (auto itemID : outfit.ItemID)
            {
                auto slot = GetEquipmentSlotForItem(itemID);

                if (slot != EquipmentSlot::None)
                    _equipedItems[Utils::ToUnderlying(slot)] = itemID;
            }
        }
    }
}

void Character::FinishLoggingIn()
{
    uint32 tutorialFlags[8] = { 0xFFF797BB, 0x1EE58DFF, 0, 0, 0, 0, 0, 0};
    Packet tutorialFlagsPacket(Opcode::SMSG_TUTORIAL_FLAGS);
    tutorialFlagsPacket.WriteBytes(tutorialFlags, 8);
    _session->SendPacket(tutorialFlagsPacket);

    Packet talentData(Opcode::SMSG_UPDATE_TALENT_DATA);
    talentData << uint8(0);
    talentData << uint32(0); // Spec
    talentData << uint32(1);

    talentData << uint32(0);
    talentData << uint32(0);
    talentData << uint32(0);
    _session->SendPacket(talentData);

    Packet knownSpells(Opcode::SMSG_SEND_KNOWN_SPELLS);
    knownSpells.WriteBits<1>(true);
    knownSpells << uint32(1);
    knownSpells << uint32(0);
    knownSpells << uint32(668); // Common language
    _session->SendPacket(knownSpells);

    Packet actionButtons(Opcode::SMSG_UPDATE_ACTION_BUTTONS);

    for (int i = 0; i < 132; ++i)
        actionButtons << uint64(0);

    actionButtons << uint8(0);
    _session->SendPacket(actionButtons);

    Packet accountDataTimes(Opcode::SMSG_ACCOUNT_DATA_TIMES);
    accountDataTimes << _guid;
    accountDataTimes << uint32(time(nullptr));

    for (int i = 0; i < 8; ++i)
        accountDataTimes << uint32((i == 0 || i == 4) ? time(nullptr) : 0);

    _session->SendPacket(accountDataTimes);

    _session->SendUpdateObject();
    SetCanFly(true);
    SendMessage("Welcome to SSandbox!");
}

void Character::Teleport(uint16 mapID, Position pos)
{
    bool isTeleportingFar = mapID != _mapID;

    if (isTeleportingFar)
    {
        Packet transferPending(Opcode::SMSG_TRANSFER_PENDING);
        transferPending << int32(mapID);
        transferPending << _position;
        transferPending.WriteBits<1>(0);
        transferPending.WriteBits<1>(0);
        transferPending.FlushBits();
        _session->SendPacket(transferPending);


        Packet suspendToken(Opcode::SMSG_SUSPEND_TOKEN);
        suspendToken << uint32(0);      // SeqIdx
        suspendToken.WriteBits<2>(1);   // Not seamless
        suspendToken.FlushBits();
        _session->SendPacket(suspendToken);

         _mapID = mapID;
        _position = pos;
    }
    else
    {
        _position = pos;

        Packet moveTeleport(Opcode::SMSG_MOVE_TELEPORT);
        moveTeleport << _guid;
        moveTeleport << uint32(0);  // SeqIdx
        moveTeleport << pos;
        moveTeleport << float(_orientation);
        moveTeleport << uint8(0);
        moveTeleport.WriteBits<1>(0);
        moveTeleport.WriteBits<1>(0);
        moveTeleport.FlushBits();
        _session->SendPacket(moveTeleport);
    }

}

void Character::WriteEnumCharacter(Buffer& buffer, uint8 index) const
{
    buffer << _guid;
    buffer << uint64(0);    // GuidClubMember
    buffer << uint8(index);
    buffer << uint8(_race);
    buffer << uint8(_class);
    buffer << uint8(_sex);
    buffer << uint8(_skin);
    buffer << uint8(_face);
    buffer << uint8(_hairStyle);
    buffer << uint8(_hairColor);
    buffer << uint8(_facialHairStyle);
    buffer.WriteBytes(_customDisplayData.data(), _customDisplayData.size());
    buffer << uint8(_level);
    buffer << int32(0);    // Zone
    buffer << int32(_mapID);
    buffer << _position;
    buffer << ObjectGuid(); // Guild
    buffer << uint32(0);    // Flags
    buffer << uint32(0);    // Flags2
    buffer << uint32(0);    // Flags3
    buffer << uint32(0);    // PetInfo
    buffer << uint32(0);    // PetInfo
    buffer << uint32(0);    // PetInfo

    buffer << uint32(0);    // Professions
    buffer << uint32(0);    // Professions

    for (int i = 0; i < 23; ++i)
    {
        buffer << uint32(0);
        buffer << uint32(0);
        buffer << uint8(0);
        buffer << uint8(0);
    }

    buffer << uint32(0);
    buffer << uint16(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer.WriteBits<6>(_name.length());
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<5>(0);

    buffer.FlushBits();
    buffer.WriteString(_name);
}

void Character::WriteCreationBlock(Buffer& buffer) const
{
    buffer << uint8(2);
    buffer << GetGUID();
    buffer << uint8(7);

    // Start of movement block
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(1);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(1);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(1);
    buffer.WriteBits<1>(0);
    buffer.FlushBits();

    buffer << GetGUID();
    buffer << uint32(0);
    buffer << _position;
    buffer << float(_orientation);

    buffer << float(0.f);
    buffer << float(0.f);

    buffer << uint32(0);
    buffer << uint32(0);

    buffer.WriteBits<30>(0);
    buffer.WriteBits<18>(0);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);

    buffer << float(7.f);
    buffer << float(7.f);
    buffer << float(7.f);
    buffer << float(7.f);
    buffer << float(7.f);
    buffer << float(150.f);
    buffer << float(7.f);
    buffer << float(7.f);
    buffer << float(7.f);

    buffer << uint32(0);
    buffer << float(1.0f);

    buffer.WriteBits<1>(0);
    buffer.FlushBits();

    buffer << uint32(0);

    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.FlushBits();

    // End of Movement block

    // Start of Values block

    uint32 wPos = buffer.GetWritePos();
    buffer << uint32(0);
    buffer << uint8(1);

    buffer << int32(0);
    buffer << uint32(0);
    buffer << float(1.f);

    buffer << int32(GetNativeDisplayID());
    for (std::size_t i = 0; i < 2; ++i)
        buffer << uint32(0);

    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);////////// added

    buffer << ObjectGuid();
    buffer << ObjectGuid();
    buffer << ObjectGuid();
    buffer << ObjectGuid();
    buffer << ObjectGuid();
    buffer << ObjectGuid();
    buffer << ObjectGuid();
    buffer << ObjectGuid();
    buffer << ObjectGuid();
    buffer << ObjectGuid();
    buffer << uint64(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint8(_race);
    buffer << uint8(_class);
    buffer << uint8(_class);
    buffer << uint8(_sex);
    buffer << uint8(0);
    buffer << uint32(0);
    buffer << int64(1);

    for (std::size_t i = 0; i < 6; ++i)
    {
        buffer << int32(0);
        buffer << int32(0);
    }

    for (std::size_t i = 0; i < 6; ++i)
    {
        buffer << float(0.f);
        buffer << float(0.f);
    }

    buffer << int64(1);
    buffer << int32(_level);
    buffer << int32(_level);
    buffer << int32(0);
    buffer << int32(0);
    buffer << int32(0);
    buffer << int32(0);
    buffer << int32(0);
    buffer << int32(0);
    buffer << int32(0);
    buffer << int32(35); // Faction

    for (std::size_t i = 0; i < 3; ++i)
    {
        buffer << uint32(0);
        buffer << uint16(0);
        buffer << uint16(0);
    }

    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);

    for (std::size_t i = 0; i < 2; ++i)
    {
        buffer << uint32(0);
    } //

    buffer << uint32(1);
    buffer << float(1);
    buffer << float(1);
    buffer << float(1);
    buffer << int32(GetNativeDisplayID());
    buffer << int32(0);//n
    buffer << int32(0);//n
    buffer << float(1);
    buffer << int32(0);
    buffer << int32(0);

    buffer << float(1);
    buffer << float(1);
    buffer << float(1);
    buffer << float(1);

    buffer << uint8(0);
    buffer << uint8(0);
    buffer << uint8(0);
    buffer << uint8(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << float(1);
    buffer << float(1);
    buffer << float(1);
    buffer << float(1);
    buffer << float(1);
    buffer << float(1);
    buffer << int32(0);
    buffer << int32(0);

    for (std::size_t i = 0; i < 4; ++i)
    {
        buffer << int32(0);
        buffer << int32(0);
        buffer << int32(0);
    }

    for (std::size_t i = 0; i < 7; ++i)
    {
        buffer << int32(0);
    }

    for (std::size_t i = 0; i < 7; ++i)
    {
        buffer << int32(0);
        buffer << int32(0);
        buffer << float(1);
    }

    buffer << int32(1);
    buffer << int32(1);

    buffer << uint8(0);
    buffer << uint8(1);
    buffer << uint8(0);
    buffer << uint8(0);

    buffer << int32(0);
    buffer << int32(0);
    buffer << int32(0);
    buffer << float(1);
    buffer << int32(0);
    buffer << int32(0);
    buffer << int32(0);
    buffer << float(1);
    buffer << int32(0);
    buffer << int32(0);
    buffer << int32(0);
    buffer << int32(0);
    buffer << float(0);
    buffer << float(0);
    buffer << float(0);
    buffer << float(1);
    buffer << float(1);

    buffer << float(0);
    buffer << int32(0);
    buffer << int32(0);
    buffer << int32(0);
    buffer << int32(0);
    buffer << int32(0);
    buffer << uint32(0);
    buffer << int32(0);
    buffer << int32(0);
    buffer << int32(0);
    buffer << int32(0);
    buffer << int32(0);
    buffer << int32(0);
    //buffer << int32(0);
    buffer << ObjectGuid();
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << ObjectGuid();

    buffer << ObjectGuid();
    buffer << ObjectGuid();
    buffer << ObjectGuid();
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << int32(0);
    buffer << uint8(_skin);
    buffer << uint8(_face);
    buffer << uint8(_hairStyle);
    buffer << uint8(_hairColor);
    buffer.WriteBytes(_customDisplayData.data(), _customDisplayData.size());
    buffer << uint8(_facialHairStyle);
    buffer << uint8(0);
    buffer << uint8(_sex);
    buffer << uint8(0);
    buffer << uint8(0);
    buffer << uint8(0);
    buffer << uint32(0);
    buffer << int32(0);

    for (std::size_t i = 0; i < 19; ++i)
    {
        buffer << uint32(_equipedItems[i]);
        buffer << uint16(0);
        buffer << uint16(0);
    }

    buffer << int32(672); // Title
    buffer << int32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << int32(0);

    for (std::size_t i = 0; i < 4; ++i)
    {
        buffer << float(0);
    }
    buffer << uint8(0);
    buffer << int32(0);
    buffer << uint32(0);
    buffer << int32(0);
    buffer << int32(0);

    {
    buffer << int32(0);
    buffer << int32(0); //n
    }
    buffer << ObjectGuid();
    buffer << int32(0);
    buffer << int32(0);//n
    buffer << int32(0);//n

    buffer.WriteBits<1>(0);
    buffer.FlushBits();

    // ActivePlayer
    for (std::size_t i = 0; i < 199; ++i)
    {
        buffer << ObjectGuid();
    }
    buffer << ObjectGuid();
    buffer << ObjectGuid();
    buffer << uint32(0);
    buffer << uint64(99999999999);
    buffer << int32(0);
    buffer << int32(0);
    buffer << int32(0);

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

    std::array<SkillInfo, 256> skills{};
    skills[0].SkillLineID = 98; // Common language
    skills[0].SkillRank = 1;
    skills[0].SkillMaxRank = 1;
    skills[0].SkillStep = 1;

    for (auto const& skill : skills)
    {
        buffer << uint16(skill.SkillLineID);
        buffer << uint16(skill.SkillStep);
        buffer << uint16(skill.SkillRank);
        buffer << uint16(skill.SkillStartingRank);
        buffer << uint16(skill.SkillMaxRank);
        buffer << int16(skill.SkillTempBonus);
        buffer << uint16(skill.SkillPermBonus);
    }

    buffer << int32(0);
    buffer << int32(0);
    buffer << int32(0);

    for (std::size_t i = 0; i < 2; ++i)
    {
        buffer << uint32(0);
    }

    buffer << float(0);
    buffer << float(0);
    buffer << float(0);
    buffer << float(0);
    buffer << float(0);
    buffer << float(0);
    buffer << float(0);
    buffer << float(0);
    buffer << float(0);
    buffer << float(0);
    buffer << float(0);
    buffer << float(0);
    buffer << float(0);
    buffer << int32(0);
    buffer << float(0);
    buffer << float(0);
    buffer << float(0);
    buffer << float(0);
    buffer << float(0);
    buffer << int32(0);
    buffer << float(0);
    buffer << float(0);
    buffer << float(0);

    for (std::size_t i = 0; i < 192; ++i)
    {
        buffer << uint64(0xFFFFFFFFFFFFFFFF);
    }

    for (std::size_t i = 0; i < 2; ++i)
    {
        buffer << uint32(0);
        buffer << uint8(0);
    }

    for (std::size_t i = 0; i < 7; ++i)
    {
        buffer << int32(0);
        buffer << int32(0);
        buffer << float(1);
    }

    buffer << int32(0);
    buffer << float(1);
    buffer << float(1);
    buffer << float(1);

    for (std::size_t i = 0; i < 3; ++i)
    {
        buffer << float(1);
        buffer << float(1);
    }

    buffer << float(1);
    buffer << float(1);
    buffer << float(0);
    buffer << float(0);
    buffer << int32(0);
    buffer << int32(0);
    buffer << int32(0);
    buffer << uint8(0);
    buffer << uint8(0);
    buffer << uint8(0);
    buffer << uint8(0);
    buffer << uint32(0);

    for (std::size_t i = 0; i < 12; ++i)
    {
        buffer << uint32(0);
        buffer << uint32(0);
    }

    buffer << uint16(0);
    buffer << uint16(0);
    buffer << uint32(0);
    buffer << int32(0);

    for (std::size_t i = 0; i < 32; ++i)
    {
        buffer << int32(0);
    }

    buffer << int32(0);
    buffer << int32(0);
    buffer << int32(0);

    for (std::size_t i = 0; i < 4; ++i)
    {
        buffer << uint32(0);
    }
    buffer << int32(0);

    for (std::size_t i = 0; i < 2; ++i)
    {
        buffer << int32(0);
    }

    buffer << float(1);
    buffer << float(1);
    buffer << int32(0);
    buffer << float(0);
    buffer << uint8(0);
    buffer << uint8(0);
    buffer << uint8(24);
    buffer << int32(0);
    buffer << int32(0);
    buffer << uint16(0);
    buffer << uint32(0);

    for (std::size_t i = 0; i < 4; ++i)
    {
        buffer << uint32(0);
    }
    buffer << uint32(0); //n

    for (std::size_t i = 0; i < 2; ++i)
    {
        buffer << uint32(0); //n
    }
    buffer << float(0); //n
    buffer << float(0);

    buffer << int32(0);
    buffer << float(0);

    buffer << uint8(0); //nblock
    buffer << uint8(0);
    buffer << uint8(0);
    buffer << uint8(0);
    buffer << uint8(0);

    buffer << uint32(0); //n
    buffer << uint32(0); //n

    buffer << uint16(0); //n
    buffer << uint32(0); //n

    buffer << ObjectGuid(); //n
    buffer << uint64(0); //n

    for (std::size_t i = 0; i < 4; ++i)
    {
        buffer << uint32(0);
    }
    for (std::size_t i = 0; i < 7; ++i)
    {
        buffer << uint32(0);
    }
    for (std::size_t i = 0; i < 875; ++i)
    {
        buffer << uint64(0);
    }

    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint8(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);
    buffer << uint32(0);



    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.WriteBits<1>(0);
    buffer.FlushBits();

    uint32 size = buffer.GetWritePos() - wPos - 4;
    buffer.WriteBytesAt_unsafe(wPos, &size, 1);
}

void Character::SetCanFly(bool value)
{
    Packet packet(value ? Opcode::SMSG_MOVE_SET_CAN_FLY : Opcode::SMSG_MOVE_UNSET_CAN_FLY);
    packet << _guid;
    packet << uint32(0);    // SeqIdx
    _session->SendPacket(packet);
}

void Character::SendMessage(std::string_view message)
{
    if (!_session)
        return;

    Packet packet(Opcode::SMSG_CHAT);

    packet << uint8(0);
    packet << uint32(0);
    packet << ObjectGuid();
    packet << ObjectGuid();
    packet << ObjectGuid();
    packet << ObjectGuid();
    packet << uint32(33619968);
    packet << uint32(33619968);
    packet << ObjectGuid();
    packet << uint32(0);
    packet << float(0.f);
    packet.WriteBits<11>(0);
    packet.WriteBits<11>(0);
    packet.WriteBits<5>(0);
    packet.WriteBits<7>(0);
    packet.WriteBits<12>(message.size());
    packet.WriteBits<11>(0);
    packet.WriteBits<1>(0);
    packet.WriteBits<1>(0);
    packet.WriteBits<1>(0);
    packet.FlushBits();

    packet.WriteString(message);
    _session->SendPacket(packet);
}

ObjectGuid Character::GetGUID() const
{
    return _guid;
}

uint16 Character::GetMapID() const
{
    return _mapID;
}

Position Character::GetPosition() const
{
    return _position;
}

float Character::GetOrientation() const
{
    return _orientation;
}

uint32 Character::GetNativeDisplayID() const
{
    auto row = DataStores::ChrRaces[_race];
    return !_sex ? row->MaleDisplayID : row->FemaleDisplayID;
}

EquipmentSlot Character::GetEquipmentSlotForItem(uint32 itemID) const
{
    auto itemEntry = DataStores::Item[itemID];

    if (!itemEntry)
        return EquipmentSlot::None;

    switch (Utils::ToEnum<InventoryType>(itemEntry->InventoryType))
    {
        case Head:
            return EquipmentSlot::Head;
        case Neck:
            return EquipmentSlot::Neck;
        case Shoulds:
            return EquipmentSlot::Shoulders;
        case Body:
            return EquipmentSlot::Body;
        case Robe:
        case Chest:
            return EquipmentSlot::Chest;
        case Waist:
            return EquipmentSlot::Waist;
        case Legs:
            return EquipmentSlot::Legs;
        case Feet:
            return EquipmentSlot::Feet;
        case Wrist:
            return EquipmentSlot::Wrist;
        case Hands:
            return EquipmentSlot::Hands;
        case Finger:
            return _equipedItems[Utils::ToUnderlying(EquipmentSlot::Finger1)] ? EquipmentSlot::Finger2 : EquipmentSlot::Finger1;
        case Trinket:
            return _equipedItems[Utils::ToUnderlying(EquipmentSlot::Trinket1)] ? EquipmentSlot::Trinket2 : EquipmentSlot::Trinket1;
        case Weapon:
            return _equipedItems[Utils::ToUnderlying(EquipmentSlot::MainHand)] ? EquipmentSlot::OffHand : EquipmentSlot::MainHand;
        case Shield:
            return EquipmentSlot::OffHand;
        case Ranged:
            return EquipmentSlot::MainHand;
        case Cloak:
            return EquipmentSlot::Back;
        case TwoHandedWeapon:
            return EquipmentSlot::MainHand;
        case Tabard:
            return EquipmentSlot::Tabard;
        case MainHandWeapon:
            return EquipmentSlot::MainHand;
        case OffHandWeapon:
            return EquipmentSlot::OffHand;
        default:
            return EquipmentSlot::None;
    }
}
} // Game
