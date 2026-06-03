#pragma once
#include <stdio.h>
#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>
#include <shlwapi.h>

HANDLE GetThSnapshot();

BOOL ProcessExist(const char* processName);
BOOL EnumProcessez(const char* processes[], DWORD processesLength);