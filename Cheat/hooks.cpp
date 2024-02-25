#include "hooks.h"

#include "detours/detours.h"

std::map<PVOID, PVOID> mCache = {};

PVOID GetHookOrigin(PVOID lpHandler, LPCSTR caller_name)
{
	if (mCache.count(lpHandler) == 0)
		return NULL;

	return mCache[lpHandler];
}

VOID DisableHook(PVOID lpHandler)
{
	PVOID lpOrigin = GetHookOrigin(lpHandler);

	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourDetach(&(PVOID&)lpOrigin, lpHandler);
	DetourTransactionCommit();
}

VOID EnableHook(PVOID& lpFunction, PVOID lpHandler)
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());

	if (DetourAttach(&(PVOID&)lpFunction, lpHandler) != NO_ERROR)
	{
		MessageBoxA(NULL, "Failed to attach hook.", "Error", MB_ICONERROR | MB_OK);
		TerminateProcess(GetCurrentProcess(), 0);
	}

	DetourTransactionCommit();
}

VOID CreateHook(PVOID lpFunction, PVOID lpHandler)
{
	EnableHook(lpFunction, lpHandler);

	mCache[lpHandler] = lpFunction;
}

VOID DeleteHook(PVOID lpHandler)
{
	DisableHook(lpHandler);

	mCache.erase(lpHandler);
}

VOID DeleteHooks()
{
	for (auto& [key, value] : mCache)
		DisableHook(key);

	mCache.clear();
}
