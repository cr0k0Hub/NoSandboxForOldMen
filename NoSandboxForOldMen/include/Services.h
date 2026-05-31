#pragma once
#include <stdio.h>
#include <windows.h>

DWORD ServiceTypes[6];

SC_HANDLE GetSCManager();
BOOL ServiceExist(LPCSTR serviceName);
BOOL EnumServices(const char* services[], DWORD servicesLength);