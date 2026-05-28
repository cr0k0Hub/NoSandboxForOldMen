#include "Reg.h"

BOOL RegKeyExist(const char* reg) {
	HKEY hKey = NULL;
	if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, reg, 0, KEY_READ, &hKey) == ERROR_SUCCESS) {
		RegCloseKey(hKey);
		return TRUE;
	}

	return FALSE;
}
