#undef UNICODE
#undef _UNICODE
#include "Processes.h"

HANDLE GetThSnapshot() {
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE) {
        printf("[-] failed to create snapshot. Error: %d\n", GetLastError());
        return NULL;
    }
    return snapshot;
}

BOOL ProcessExist(const char* processName) {
    return FALSE;
}

BOOL EnumProcessez(const char* processes[], DWORD processesLength) {
    HANDLE snapshot = GetThSnapshot();
    if (snapshot == NULL) return FALSE;
    PROCESSENTRY32 PE;
    ZeroMemory(&PE, sizeof(PROCESSENTRY32));
    PE.dwSize = sizeof(PROCESSENTRY32);
    if (!Process32First(snapshot, &PE)) {
        //printf("[-] failed to enum processes. Error: %d\n", GetLastError());
        CloseHandle(snapshot);
        return FALSE;
    }

    do {
        for (size_t i = 0; i < processesLength; i++) {
            if (_stricmp(PE.szExeFile, processes[i]) == 0) {
                return TRUE;
            }
        }
    } while (Process32Next(snapshot, &PE));
    CloseHandle(snapshot);

    return FALSE;
}
