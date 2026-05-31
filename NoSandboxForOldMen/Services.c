#include "Services.h"

DWORD ServiceTypesLength = 6;
DWORD ServiceTypes[6] = {
    SERVICE_DRIVER,
    SERVICE_FILE_SYSTEM_DRIVER, 
    SERVICE_KERNEL_DRIVER,
    SERVICE_WIN32,
    SERVICE_WIN32_OWN_PROCESS,
    SERVICE_WIN32_SHARE_PROCESS
};

SC_HANDLE GetSCManager() {
    SC_HANDLE scm = OpenSCManagerA(NULL, SERVICES_ACTIVE_DATABASEA, SC_MANAGER_CONNECT);
    if (scm == INVALID_HANDLE_VALUE || scm == NULL) {
        printf("[-] failed to get scm. Error: %d\n", GetLastError());
        return NULL;
    }
    return scm;
}

BOOL ServiceExist(const char* serviceName) {
    SC_HANDLE scm = GetSCManager();
    SC_HANDLE service = OpenServiceA(scm, serviceName, SC_MANAGER_CONNECT);
    BOOL exist = FALSE;
    if (service) {
        //printf("[+] %s exist!\n", serviceName);
        exist = TRUE;
    }
    //else {
    //    printf("[-] failed to open service <%s>. Error: %d\n", serviceName, GetLastError());
    //}
    CloseServiceHandle(scm);

    return exist;
}

BOOL EnumServices(const char* services[], DWORD servicesLength) {
    for (size_t i = 0; i < servicesLength; i++) {
        if (ServiceExist(services[i])) return TRUE;
    }

    return FALSE;
}