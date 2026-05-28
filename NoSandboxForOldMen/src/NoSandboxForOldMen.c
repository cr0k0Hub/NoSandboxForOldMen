#include <stdio.h>
#include <windows.h>
#include "AntiDebug.h"

int main() {
	if (AntiDebug()) {
		printf("[!] sandboxed/debugged\n");
	}
	else {
		printf("[+] everything is fine :)\n");
	}

	return 0;
}