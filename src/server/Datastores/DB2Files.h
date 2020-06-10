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
#include "DB2.h"

namespace DataStores
{
namespace Structures
{
struct ChrModel
{
    static constexpr char Filename[] = "chrmodel.csv";
    static constexpr char Format[] = "uuu";
    static constexpr char Arrays[] = { 1, 1, 1 };
    static constexpr char* Names[] = { "ID", "Sex", "DisplayID" };
    static constexpr std::size_t IndexField = 0;

    struct Structure
    {
        uint32 ID;
        uint32 Sex;
        uint32 DisplayID;
    };
};

struct ChrRaceXChrModel
{
    static constexpr char Filename[] = "chrracexchrmodel.csv";
    static constexpr char Format[] = "uuu";
    static constexpr char Arrays[] = { 1, 1, 1 };
    static constexpr char* Names[] = { "ID", "ChrModelID", "ChrRacesID" };
    static constexpr std::size_t IndexField = 0;

    struct Structure
    {
        uint32 ID;
        uint32 ChrModelID;
        uint32 RaceID;
    };
};

struct ChrRaces
{
    static constexpr char Filename[] = "chrraces.csv";
    static constexpr char Format[] = "usu";
    static constexpr char Arrays[] = { 1, 1, 1 };
    static constexpr char* Names[] = { "ID", "Name_lang", "Alliance" };
    static constexpr std::size_t IndexField = 0;

    struct Structure
    {
        uint32 ClassID;
        std::string Name;
        uint32 Alliance;
    };
};

struct CharStartOutfit
{
    static constexpr char Filename[] = "charstartoutfit.csv";
    static constexpr char Format[] = "uuuu";
    static constexpr char Arrays[] = { 1, 1, 24, 1 };
    static constexpr char* Names[] = { "ID", "ClassID", "ItemID", "RaceID" };
    static constexpr std::size_t IndexField = 0;

    struct Structure
    {
        uint32 ID;
        uint32 ClassID;
        uint32 ItemID[24];
        uint32 RaceID;
    };
};

struct Item
{
    static constexpr char Filename[] = "item.csv";
    static constexpr char Format[] = "uuu";
    static constexpr char Arrays[] = { 1, 1, 1 };
    static constexpr char* Names[] = { "ID", "SubclassID", "InventoryType" };
    static constexpr std::size_t IndexField = 0;

    struct Structure
    {
        uint32 ID;
        uint32 SubClassID;
        uint32 InventoryType;
    };
};

struct ItemModifiedAppearence
{
    static constexpr char Filename[] = "itemmodifiedappearance.csv";
    static constexpr char Format[] = "uuuuu";
    static constexpr char Arrays[] = { 1, 1, 1, 1, 1 };
    static constexpr char* Names[] = { "ID", "ItemID", "ItemAppearanceModifierID", "ItemAppearanceID", "OrderIndex" };
    static constexpr std::size_t IndexField = 0;

    struct Structure
    {
        uint32 ID;
        uint32 ItemID;
        uint32 ItemAppearanceModifierID;
        uint32 ItemAppearanceID;
        uint32 OrderIndex;
    };
};

struct ItemAppearence
{
    static constexpr char Filename[] = "itemappearance.csv";
    static constexpr char Format[] = "uu";
    static constexpr char Arrays[] = { 1, 1 };
    static constexpr char* Names[] = { "ID", "ItemDisplayInfoID" };
    static constexpr std::size_t IndexField = 0;

    struct Structure
    {
        uint32 ID;
        uint32 ItemDisplayInfoID;
    };
};

} // Structures

inline DB2<Structures::ChrModel> ChrModel;
inline DB2<Structures::ChrRaceXChrModel> ChrRaceXChrModel;
inline DB2<Structures::ChrRaces> ChrRaces;
inline DB2<Structures::CharStartOutfit> CharStartOutfit;
inline DB2<Structures::Item> Item;
inline DB2<Structures::ItemModifiedAppearence> ItemModifiedAppearence;
inline DB2<Structures::ItemAppearence> ItemAppearence;

void LoadAdditionalInfo();

Structures::ItemModifiedAppearence::Structure const* GetItemModifiedAppearanceByItemID(uint32 itemID, uint32 ItemAppearanceModifierID = 0);
uint32 GetDisplayIDForRace(uint32 raceID, uint32 sex);

inline void Init(fs::path folder)
{
    #define LoadDB2(x) if (!x.Load(folder)) { Log::Log(LogSeverity::Error, "Error loading %s", x.Filename); exit(1); };
    LoadDB2(ChrModel)
    LoadDB2(ChrRaceXChrModel)
    LoadDB2(ChrRaces)
    LoadDB2(CharStartOutfit)
    LoadDB2(Item)
    LoadDB2(ItemModifiedAppearence)
    LoadDB2(ItemAppearence)

    LoadAdditionalInfo();
}
} // Datastores
