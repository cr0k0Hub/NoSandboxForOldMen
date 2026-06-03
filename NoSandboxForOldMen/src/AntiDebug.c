#include <intrin.h>
#include "AntiDebug.h"

BOOL GetCpuId() {
	int regs[4] = { 0 };
	char vendor[13];

	__cpuid(regs, 0x40000000);
	memcpy(vendor, &regs[1], 4);
	memcpy(vendor + 4, &regs[3], 4);
	memcpy(vendor + 8, &regs[2], 4);
	vendor[12] = '\0';

	//printf("%s\n", vendor);

	return 0;
}

BOOL CheckRegistry() {
	if (CheckVirtualBoxRegKeys())
		return TRUE;

	return FALSE;
}

BOOL AntiDebug() {
	//if (IsDebuggerPresent()) return TRUE;

	//PPEB peb = (PPEB)__readgsqword(0x60);
	//if (peb->BeingDebugged) return TRUE;

	//GetCpuId();
	//if (CheckRegistry()) return TRUE;
	if (CheckVirtualBoxInfo()) return TRUE;

	return FALSE;
}
