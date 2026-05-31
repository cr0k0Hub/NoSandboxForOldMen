#pragma once
#include <stdio.h>
#include <windows.h>
#include "Files.h"
#include "Reg.h"
#include "Services.h"


/*
* [ VirtBox ]
* contains VirtualBox-specific data
*/
extern const char* VirtualBoxRegKeys[6];
extern const char* VirtualBoxServices[6];
extern const char* VirtualBoxDevices[4];
extern const char* VirtualBoxProcesses[3];
extern const char* VirtualBoxFiles[9];

BOOL CheckVirtualBoxRegKeys();
BOOL CheckVirtualBoxFiles();
BOOL CheckVirtualBoxServices();

BOOL CheckVirtualBoxInfo();