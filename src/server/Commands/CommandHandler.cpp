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
#include "CommandHandler.h"

namespace Game
{

CommandHandler::CommandHandler()
{
}

CommandHandler& CommandHandler::Instance()
{
    static CommandHandler instance;
    return instance;
}

void CommandHandler::Run()
{
    while (true)
    {
        std::string line;
        std::cin >> line;

        if (line == "exit")
            break;

        HandleCommand(line, nullptr);
    }
}

void CommandHandler::HandleCommand(std::string_view args, std::shared_ptr<Game::Character> character /* = nullptr */)
{
    if (args.starts_with('!'))
        args = std::string_view(args.data() + 1, args.size() - 1);

    auto tokens = Utils::Tokenize(args, ' ', true);

    Command command;
    command.Command = tokens[0];
    command.Args = std::vector(tokens.begin() + 1, tokens.end());
    command.IsConsole = character == nullptr;
    command.Character = character;
    command.Dispatch();
}
} // Game
