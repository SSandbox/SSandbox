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
#include "Character.h"

namespace Account
{

class Instance
{
public:

    using CharacterList = std::unordered_map<uint64, std::shared_ptr<Game::Character>>;

    explicit Instance(std::string name, uint64 id = -1);

    uint64 GetID() const;
    std::string const& GetName() const;

    void GenerateServerSecret();
    void SetClientSecret(void* sourceArray);
    std::array<char, 64> const& GetSecret() const;

    std::shared_ptr<Game::Character> GetCharacterByID(uint64 ID);
    std::shared_ptr<Game::Character> CreateCharacter();
    bool DeleteCharacter(uint64 ID);
    CharacterList const& GetCharacterList();

private:
    std::string _name;
    uint64 _id;
    std::array<char, 64> _secret;

    CharacterList _characterList;
};

class Mgr
{
public:
    Mgr();

    static Mgr& Instance();

    uint64 GenerateID();
    std::shared_ptr<Account::Instance> GetAccountByName(std::string const& accountName);
    std::shared_ptr<Account::Instance> GetOrCreateAccount(std::string const& accountName);

private:
    std::atomic<uint64> _idCounter;
    std::unordered_map<std::string, std::shared_ptr<Account::Instance>> _accountHolder;
};
} // Account
