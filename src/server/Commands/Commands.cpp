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
#include "Commands.h"
#include "ServerMgr.h"

namespace Game
{

struct Dispatcher
{
    struct CommandInfo
    {
        char const* Description;
        decltype(&Command::ExampleCommand) Function;
        bool CanExecuteAsConsole;
    };

    Dispatcher()
    {
        RegisterCommand("kickall", "Closes all active connections", true, &Command::HandleKickAll);
        RegisterCommand("commands", "Lists all commands", true, &Command::HandleCommands);
        RegisterCommand("telexyz", "Teleports to the given coordinates [x, y, z, mapid]", false, &Command::HandeTeleportXYZ);
        RegisterCommand("gps", "Returns the current character position", false, &Command::HandleGPS);
        RegisterCommand("fly", "Sets fly mode on/off", false, &Command::HandleFly);
    }

    void RegisterCommand(char const* commandName, char const* description, bool canExecuteAsConsole, decltype(&Command::ExampleCommand) func)
    {
        CommandMap.emplace(commandName, CommandInfo
        {
            .Description = description,
            .Function = func,
            .CanExecuteAsConsole = canExecuteAsConsole
        });
    }

    bool Dispatch(Command& command)
    {
        auto iter = CommandMap.find(command.Command.data());
        if (iter == CommandMap.end())
            return false;

        if (!iter->second.CanExecuteAsConsole && command.IsConsole)
            return false;

        return (command.*iter->second.Function)();
    }

    std::unordered_map<std::string, CommandInfo> CommandMap;
};

Dispatcher gDispatcher;

void Command::Dispatch()
{
    if (!gDispatcher.Dispatch(*this))
    {
        SendMessageChat("Error: Error handling command %s", Command.c_str());
    }
}

void Command::SendMessageChat(char const* message, ...)
{
    char buffer[1024];

    va_list args;
    va_start(args, message);
    vsprintf(buffer, message, args);
    va_end(args);

    if (IsConsole)
        Log::Log(LogSeverity::Command, buffer);
    else
        Character->SendMessage(buffer);
}

bool Command::ExampleCommand()
{
    return true;
}

bool Command::HandleKickAll()
{
    ServerMgr::Instance().CloseAllSockets();
    return true;
}

bool Command::HandleCommands()
{
    for (auto const& commands : gDispatcher.CommandMap)
        SendMessageChat("!%s - %s", commands.first.c_str(), commands.second.Description);

    return true;
}

bool Command::HandeTeleportXYZ()
{
    if (Args.size() != 4 && Args.size() != 3)
        return false;

    float x, y, z;
    uint16 mapID = Character->GetMapID();

    if (!Utils::StrToInt(Args[0], x))
        return false;

    if (!Utils::StrToInt(Args[1], y))
        return false;

    if (!Utils::StrToInt(Args[2], z))
        return false;

    if (Args.size() == 4)
    {
        if (!Utils::StrToInt(Args[3], mapID))
            return false;
    }

    Position pos(x, y, z);
    Character->Teleport(mapID, pos);
    return true;
}

bool Command::HandleFly()
{
    if (Args.size() != 1)
        return false;

    Character->SetCanFly(Args[0] == "on");
    return true;
}

bool Command::HandleGPS()
{
    Position pos = Character->GetPosition();
    SendMessageChat("Position: %f %f %f - %f MapID: %u", pos.GetX(), pos.GetY(), pos.GetZ(), Character->GetOrientation(), Character->GetMapID());
    return true;
}
} // Game
