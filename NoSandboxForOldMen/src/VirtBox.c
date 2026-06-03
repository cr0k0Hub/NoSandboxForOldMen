#include "VirtBox.h"

const char* VirtualBoxRegKeys[6] = {
   "SOFTWARE\\Oracle\\VirtualBox Guest Additions",
   "SYSTEM\\CurrentControlSet\\Services\\VBoxGuest",
   "SYSTEM\\CurrentControlSet\\Services\\VBoxMouse",
   "SYSTEM\\CurrentControlSet\\Services\\VBoxSF",
   "SYSTEM\\CurrentControlSet\\Services\\VBoxVideo",
   "SYSTEM\\CurrentControlSet\\Services\\VBoxWddm"
};

const char* VirtualBoxServices[6] = {
	"VBoxSDS",
	"VBoxGuest",
	"VBoxMouse",
	"VBoxSF",
	"VBoxVideo",
	"VBoxService"
};

const char* VirtualBoxDevices[4] = {
	"VBOX HARDDISK",
	"VirtualBox Host-Only Ethernet Adapter",
	"VirtualBox Graphics Adapter",
	"VirtualBox"
};

const char* VirtualBoxProcesses[3] = {
	"VBoxTray.exe",
	"VBoxService.exe",
	"VBoxControl.exe"
};

const char* VirtualBoxFiles[9] = {
	"C:\\Windows\\System32\\drivers\\VBoxGuest.sys",
	"C:\\Windows\\System32\\drivers\\VBoxMouse.sys",
	"C:\\Windows\\System32\\drivers\\VBoxSF.sys",
	"C:\\Windows\\System32\\drivers\\VBoxVideo.sys",
	"C:\\Windows\\System32\\drivers\\VBoxWddm.sys",
	"C:\\Windows\\System32\\VBoxDisp.dll",
	"C:\\Windows\\System32\\VBoxHook.dll",
	"C:\\Windows\\System32\\VBoxMRXNP.dll",
	"C:\\Windows\\System32\\VBoxOGL.dll"
};

BOOL CheckVirtualBoxRegKeys() {
	for (size_t i = 0; i < 6; i++) {
		if (RegKeyExist(VirtualBoxRegKeys[i])) {
			return TRUE;
		}
	}

	return FALSE;
}

BOOL CheckVirtualBoxFiles() {
	for (size_t i = 0; i < 9; i++) {
		if (FileExist(VirtualBoxFiles[i]))
			return TRUE;
	}

	return FALSE;
}

BOOL CheckVirtualBoxServices() {
	if (EnumServices(VirtualBoxServices, 6)) return TRUE;

	return FALSE;
}

BOOL CheckVirtualBoxProcesses() {
	// TODO: create process-check funcs
	if (EnumProcessez(VirtualBoxProcesses, 3)) return TRUE;
	return FALSE;
}

BOOL CheckVirtualBoxInfo() {
	//if (CheckVirtualBoxRegKeys()) return TRUE;
	//if (CheckVirtualBoxFiles()) return TRUE;
	// if (CheckVirtualBoxServices()) return TRUE;
	if (CheckVirtualBoxProcesses()) return TRUE;

	return FALSE;
}