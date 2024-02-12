#include "main.h"

#include "render.h"
#include "menu.h"

DWORD WINAPI ThreadProcHandler(LPVOID lpThreadParameter)
{
	if (!RenderSetup(WndProcHandler, RenderHandler))
		return -1;

	return 0;
}

BOOL APIENTRY DllMain(HMODULE hinstDll, DWORD fdwReason, LPVOID lpReserved)
{
	if (fdwReason != DLL_PROCESS_ATTACH)
		return FALSE;

	//AllocConsole();
	//freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
	//freopen_s((FILE**)stderr, "CONOUT$", "w", stderr);

	CreateThread(NULL, 0, ThreadProcHandler, hinstDll, 0, NULL);

	return TRUE;
}
