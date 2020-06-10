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
 *along with this program; if not, write to the Free Software Foundation,
 *Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 */
#include "LauncherShared.h"
#include <Windows.h>
#include <Winternl.h>
#include <iostream>
#include <fstream>

uint8_opt bnetModulus[] = { 0x91, 0xD5, 0x9B, 0xB7, 0xD4, 0xE1, 0x83, 0xA5 };
uint8_opt connectToModulus[] = { 0x71, 0xFD, 0xFA, 0x60, 0x14, 0x0D, 0xF2, 0x05};

char newModulus[] =
{
    0x5F, 0xD6, 0x80, 0x0B, 0xA7, 0xFF, 0x01, 0x40, 0xC7, 0xBC, 0x8E, 0xF5, 0x6B, 0x27, 0xB0, 0xBF,
    0xF0, 0x1D, 0x1B, 0xFE, 0xDD, 0x0B, 0x1F, 0x3D, 0xB6, 0x6F, 0x1A, 0x48, 0x0D, 0xFB, 0x51, 0x08,
    0x65, 0x58, 0x4F, 0xDB, 0x5C, 0x6E, 0xCF, 0x64, 0xCB, 0xC1, 0x6B, 0x2E, 0xB8, 0x0F, 0x5D, 0x08,
    0x5D, 0x89, 0x06, 0xA9, 0x77, 0x8B, 0x9E, 0xAA, 0x04, 0xB0, 0x83, 0x10, 0xE2, 0x15, 0x4D, 0x08,
    0x77, 0xD4, 0x7A, 0x0E, 0x5A, 0xB0, 0xBB, 0x00, 0x61, 0xD7, 0xA6, 0x75, 0xDF, 0x06, 0x64, 0x88,
    0xBB, 0xB9, 0xCA, 0xB0, 0x18, 0x8B, 0x54, 0x13, 0xE2, 0xCB, 0x33, 0xDF, 0x17, 0xD8, 0xDA, 0xA9,
    0xA5, 0x60, 0xA3, 0x1F, 0x4E, 0x27, 0x05, 0x98, 0x6F, 0xAA, 0xEE, 0x14, 0x3B, 0xF3, 0x97, 0xA8,
    0x12, 0x02, 0x94, 0x0D, 0x84, 0xDC, 0x0E, 0xF1, 0x76, 0x23, 0x95, 0x36, 0x13, 0xF9, 0xA9, 0xC5,
    0x48, 0xDB, 0xDA, 0x86, 0xBE, 0x29, 0x22, 0x54, 0x44, 0x9D, 0x9F, 0x80, 0x7B, 0x07, 0x80, 0x30,
    0xEA, 0xD2, 0x83, 0xCC, 0xCE, 0x37, 0xD1, 0xD1, 0xCF, 0x85, 0xBE, 0x91, 0x25, 0xCE, 0xC0, 0xCC,
    0x55, 0xC8, 0xC0, 0xFB, 0x38, 0xC5, 0x49, 0x03, 0x6A, 0x02, 0xA9, 0x9F, 0x9F, 0x86, 0xFB, 0xC7,
    0xCB, 0xC6, 0xA5, 0x82, 0xA2, 0x30, 0xC2, 0xAC, 0xE6, 0x98, 0xDA, 0x83, 0x64, 0x43, 0x7F, 0x0D,
    0x13, 0x18, 0xEB, 0x90, 0x53, 0x5B, 0x37, 0x6B, 0xE6, 0x0D, 0x80, 0x1E, 0xEF, 0xED, 0xC7, 0xB8,
    0x68, 0x9B, 0x4C, 0x09, 0x7B, 0x60, 0xB2, 0x57, 0xD8, 0x59, 0x8D, 0x7F, 0xEA, 0xCD, 0xEB, 0xC4,
    0x60, 0x9F, 0x45, 0x7A, 0xA9, 0x26, 0x8A, 0x2F, 0x85, 0x0C, 0xF2, 0x19, 0xC6, 0x53, 0x92, 0xF7,
    0xF0, 0xB8, 0x32, 0xCB, 0x5B, 0x66, 0xCE, 0x51, 0x54, 0xB4, 0xC3, 0xD3, 0xD4, 0xDC, 0xB3, 0xEE
};

decltype(&NtQueryInformationProcess) gNtQueryInformationProcess;

void* GetImageBase(HANDLE processHandle)
{
    _PROCESS_BASIC_INFORMATION PBI;
    DWORD bytes;
    void* redAddr = nullptr;
    SIZE_T read;

    if (gNtQueryInformationProcess(processHandle, ProcessBasicInformation, &PBI, sizeof(PBI), &bytes) == 0)
        ReadProcessMemory(processHandle, reinterpret_cast<char*>(PBI.PebBaseAddress) + 0x10, &redAddr, 8, &read);

    return redAddr;
}

template <typename T, std::size_t length>
bool WriteRemoteMemory(HANDLE procHandle, void* remoteAddr, const T(&buff)[length])
{
    DWORD oldProtect;
    std::size_t written;

    VirtualProtectEx(procHandle, remoteAddr, length, PAGE_EXECUTE_WRITECOPY, &oldProtect);
    WriteProcessMemory(procHandle, remoteAddr, buff, length, &written);
    VirtualProtectEx(procHandle, remoteAddr, length, oldProtect, &oldProtect);

    return written == length;
}

bool WriteRemoteMemory(HANDLE procHandle, void* remoteAddr, void* buff, std::size_t length)
{
    DWORD oldProtect;
    std::size_t written;

    VirtualProtectEx(procHandle, remoteAddr, length, PAGE_EXECUTE_WRITECOPY, &oldProtect);
    WriteProcessMemory(procHandle, remoteAddr, buff, length, &written);
    VirtualProtectEx(procHandle, remoteAddr, length, oldProtect, &oldProtect);

    return written == length;
}

int main(int argc, char const** argv)
{
    std::list<char const*> possiblePaths = { "_beta_\\WowB.exe" };

    if (argc > 1)
    {
        possiblePaths.push_front(argv[1]);
    }

    auto iter = std::find_if(possiblePaths.begin(), possiblePaths.end(), [](auto path) -> bool
    {
        return fs::exists(path);
    });

    if (iter == possiblePaths.end())
    {
        std::cerr << "Error: Binary not found!\n";
        return 1;
    }

    fs::path path(*iter);
    fs::path wtf(path.parent_path() / "WTF");

    if (!fs::exists(wtf))
    {
        if (!fs::create_directory(wtf))
        {
            std::cerr << "Error: Could not create directory " << wtf << "\n";
            return 1;
        }
    }

    fs::path config(wtf / "SSbox.wtf");
    if (!fs::exists(config))
    {
        std::ofstream stream(config);

        if (!stream.is_open())
        {
            std::cerr << "Error: creating file " << config << "\n";
            return 1;
        }

        stream <<  "SET portal \"127.0.0.1\"\n";
        stream <<  "SET textLocale \"enUS\"\n";
        stream <<  "SET audioLocale \"enUS\"\n";
        stream <<  "SET synchronizeSettings \"0\"\n";

        stream.flush();
        stream.close();
    }

    fs::path dllPath(fs::current_path() / "LibLauncher.dll");
    auto dllPathString = dllPath.string();

    if (!fs::exists(dllPath))
    {
        std::cerr << "Erro: file " << dllPathString << " does not exist\n";
        return 1;
    }

    char cmd[2048];
    sprintf(cmd, "%s -console", path.c_str());

    STARTUPINFO startupInfo;
    PROCESS_INFORMATION processInformation;

    ZeroMemory(&startupInfo, sizeof(startupInfo));
    ZeroMemory(&processInformation, sizeof(processInformation));

    auto pathStr = path.string();

    gNtQueryInformationProcess = reinterpret_cast<decltype(gNtQueryInformationProcess)>( GetProcAddress(GetModuleHandleA("ntdll.dll"), "NtQueryInformationProcess"));

    if (CreateProcess(pathStr.data(), cmd, nullptr, nullptr, false, CREATE_SUSPENDED, nullptr, nullptr, &startupInfo, &processInformation))
    {
        AutoHandle procHandle(processInformation.hProcess);
        AutoHandle threadHandle(processInformation.hThread);

        auto imageBase = GetImageBase(procHandle.get());

        char* rdataAddr = nullptr;
        std::size_t rdataSize = 0;

        MEMORY_BASIC_INFORMATION mbi;
        std::size_t offset = 0x1000; // Skip header

        do
        {
            if (!VirtualQueryEx(procHandle.get(), AddOffset(imageBase, offset), &mbi, sizeof(mbi)))
                break;

            if (mbi.Protect == 2)
            {
                rdataAddr = reinterpret_cast<char*>(mbi.BaseAddress);
                rdataSize = mbi.RegionSize;
                break;
            }

            offset += mbi.RegionSize;
        }
        while (mbi.AllocationBase == imageBase);

        if (!rdataAddr)
        {
            std::cerr << "Unable to find rdata address\n";
            return 1;
        }

        auto remoteRdata = std::make_unique<char[]>(rdataSize);

        std::size_t read;
        ReadProcessMemory(procHandle.get(), rdataAddr, remoteRdata.get(), rdataSize, &read);

        if (read != rdataSize)
        {
            std::cerr << "Error reading remote memory\n";
            return 1;
        }

        auto bnetModulusAddr = FindPattern<char>(remoteRdata.get(), rdataSize, bnetModulus);
        auto connectToModulusAddr = FindPattern<char>(remoteRdata.get(), rdataSize, connectToModulus);

        WriteRemoteMemory(procHandle.get(), bnetModulusAddr - remoteRdata.get() + rdataAddr, newModulus, sizeof(newModulus));
        WriteRemoteMemory(procHandle.get(), connectToModulusAddr - remoteRdata.get() + rdataAddr, newModulus, sizeof(newModulus));

        auto loadLibrary = GetProcAddress(GetModuleHandleA("kernel32.dll"), "LoadLibraryA");
        auto allocAddress = VirtualAllocEx(procHandle.get(), nullptr, dllPathString.size() + 1, MEM_COMMIT, PAGE_READWRITE);

        auto configAddrs = FindPatterns<char>(remoteRdata.get(), rdataSize, { 'C', 'o', 'n', 'f', 'i', 'g', '.', 'w', 't', 'f'});
        for (auto configAddr : configAddrs)
            WriteRemoteMemory(procHandle.get(), configAddr - remoteRdata.get() + rdataAddr, {'S', 'S', 'b', 'o', 'x', '.', 'w', 't', 'f', '\0'});

        auto actual = FindPattern<char>(remoteRdata.get(), rdataSize, {'.', 'a', 'c', 't', 'u', 'a', 'l'});
        WriteRemoteMemory(procHandle.get(), actual - remoteRdata.get() + rdataAddr, { '\0' });

        std::size_t written;
        WriteProcessMemory(procHandle.get(), allocAddress, dllPathString.data(), dllPathString.size() + 1, &written);

        if (written != dllPathString.size() + 1)
        {
            std::cerr << "Error loading wow process\n";
            TerminateProcess(procHandle.get(), 0);
            return 1;
        }

        AutoHandle loadLibraryThread(CreateRemoteThread(procHandle.get(), nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(loadLibrary), allocAddress, 0, nullptr));

        WaitForSingleObject(loadLibraryThread.get(), INFINITE);
        ResumeThread(threadHandle.get());

        std::cout << "Started successfully\n";
        return 0;
    }
    else
    {
        std::cerr << "Error: creating process " << pathStr.c_str() << "\n";
        return 1;
    }

    return 0;
}
