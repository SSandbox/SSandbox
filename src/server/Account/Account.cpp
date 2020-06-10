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
#include <Account.h>

namespace Account
{

Mgr::Mgr() : _idCounter(0) // account storying not implemented
{
}

Mgr& Mgr::Instance()
{
    static Mgr instace;
    return instace;
}

uint64 Mgr::GenerateID()
{
    return _idCounter++;
}

std::shared_ptr<Account::Instance> Mgr::GetAccountByName(std::string const& accountName)
{
    auto lower = accountName;
    Utils::ToLower(lower);

    auto iter = _accountHolder.find(lower);
    return iter == _accountHolder.end() ? nullptr : iter->second;
}

std::shared_ptr<Account::Instance> Mgr::GetOrCreateAccount(std::string const& accountName)
{
    auto lower = accountName;
    Utils::ToLower(lower);

    auto iter = _accountHolder.find(lower);

    if (iter == _accountHolder.end())
        iter = _accountHolder.emplace(lower, std::make_shared<Account::Instance>(lower)).first;

    assert(iter != _accountHolder.end());
    return iter->second;
}

Instance::Instance(std::string name, uint64 guid) : _name(std::move(name)), _id(guid != -1 ? guid : Mgr::Instance().GenerateID())
{
    std::memset(_secret.data(), 0, _secret.size());
}

uint64 Instance::GetID() const
{
    return _id;
}

std::string const& Instance::GetName() const
{
    return _name;
}

void Instance::GenerateServerSecret()
{
    Utils::Random(_secret.data() + _secret.size() / 2, _secret.size() / 2);
}

void Instance::SetClientSecret(void* sourceArray)
{
    std::memcpy(_secret.data(), sourceArray, _secret.size() / 2);
}

std::array<char, 64> const& Instance::GetSecret() const
{
    return _secret;
}

std::shared_ptr<Game::Character> Instance::GetCharacterByID(uint64 ID)
{
    auto iter = _characterList.find(ID);
    return iter == _characterList.end() ? nullptr : iter->second;
}

std::shared_ptr<Game::Character> Instance::CreateCharacter()
{
    auto character = std::make_shared<Game::Character>();
    _characterList.emplace(character->GetGUID().GetLoPart(), character);
    return character;
}

bool Instance::DeleteCharacter(uint64 ID)
{
    auto iter = _characterList.find(ID);
    if (iter == _characterList.end())
        return false;

    _characterList.erase(iter);
    return true;
}

Instance::CharacterList const& Instance::GetCharacterList()
{
    return _characterList;
}
} // Account
