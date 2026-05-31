#include "Files.h"

BOOL FileExist(LPCSTR fileName) {
    OFSTRUCT of = { 0 };
    HANDLE hfile = CreateFileA(fileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hfile != INVALID_HANDLE_VALUE) {
        CloseHandle(hfile);
        //printf("[!] found file: %s\n", of.szPathName);
        return TRUE;
    }

    return FALSE;
}
