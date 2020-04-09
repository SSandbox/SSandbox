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
#include "ServerMgr.h"

int main()
{
    if (!Utils::Config::Instance().Load("SSandbox.conf"))
    {
        std::cerr << "Failed to load the configuration file";
        return 1;
    }

    auto begin = std::chrono::steady_clock::now();
    DataStores::Init(Utils::Config::Instance().Get<std::string>("DataStoresPath", "./datastores"));
    auto end = std::chrono::steady_clock::now();

    Log::Log(LogSeverity::Command, "Datastores loaded in %u ms", std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count());
    ServerMgr::Instance().Run();
}
