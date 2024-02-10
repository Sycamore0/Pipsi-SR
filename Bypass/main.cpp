#include "main.h"

BOOL bInit = FALSE;

BOOL ShowWindowHandler(HWND hWnd, int nCmdShow)
{
	return TRUE;
}

HMODULE LoadLibraryExWHandler(LPCWSTR lpLibFileName, HANDLE hFile, DWORD dwFlags)
{
	HMODULE hResult = OriginalLoadLibraryExW(lpLibFileName, hFile, dwFlags);

	if (!bInit && lpLibFileName && hResult && lstrlenW(lpLibFileName) == 16 && lstrcmpW(lpLibFileName, L"GameAssembly.dll") == 0)
	{
		DWORD_PTR lpEncodedBase[4] = {};

		lpEncodedBase[2] = ((DWORD_PTR)hResult - 0x30271D25137D50CF) ^ 0x787761445AC0321D;

		SetupVM(lpEncodedBase, 0x9EB4000, 0x6B18, VM, VM + sizeof(VM));

		bInit = TRUE;
	}

	return hResult;
}

BOOL APIENTRY DllMain(HMODULE hinstDll, DWORD fdwReason, LPVOID lpReserved)
{
	if (fdwReason != DLL_PROCESS_ATTACH)
		return FALSE;
	
	CreateHook(&OriginalLoadLibraryExW, LoadLibraryExWHandler);
	CreateHook(&OriginalShowWindow, ShowWindowHandler);

	*(DWORD*)(StarRail + 0xA6B3E + 0x6) = 0;
	*(PVOID*)(StarRail + 0xA6B3E + 0xA) = GetProcAddress(UnityPlayer, "UnityMain");

	//DWORD dwOldProtect = 0;

	//VirtualProtect((PBYTE)UnityPlayer + 0x1584F4A, sizeof(DWORD_PTR), PAGE_EXECUTE_READWRITE, &dwOldProtect);

	//*(DWORD_PTR*)((PBYTE)UnityPlayer + 0x1584F4A) = 0x5250C3C3C3C3C3C3;

	return TRUE;
}