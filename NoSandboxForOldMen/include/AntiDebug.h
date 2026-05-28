#pragma once
#include <stdio.h>
#include <windows.h>
#include "nt_utils.h"
#include "VirtBox.h"

/*
* [ AntiDebug ]
* checks is program being debugged
* returns true if it is
*
* also checks for virt env
*/
BOOL GetCpuId();
BOOL CheckRegistry();
BOOL AntiDebug();