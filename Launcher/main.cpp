#include "main.h"

#include "inject.h"

BOOL LoadFile(LPCSTR lpFileName, PCHAR* lpBuffer, PDWORD lpSize)
{
	HANDLE hFile = CreateFileA(lpFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hFile == INVALID_HANDLE_VALUE || hFile == NULL)
		return FALSE;

	DWORD dwFileSize = GetFileSize(hFile, NULL);

	if (dwFileSize == INVALID_FILE_SIZE)
	{
		CloseHandle(hFile);

		return FALSE;
	}

	*lpBuffer = new CHAR[dwFileSize];

	if (!ReadFile(hFile, *lpBuffer, dwFileSize, lpSize, NULL))
	{
		delete[] * lpBuffer;

		CloseHandle(hFile);

		return FALSE;
	}

	CloseHandle(hFile);

	return TRUE;
}

BOOL InjectBypass(HANDLE hProcess, HANDLE hThread)
{
	printf("Injecting bypass..\n");

	PCHAR lpBypassDll = NULL;
	DWORD dwBypassSize = 0;

	if (!LoadFile("Bypass.dll", &lpBypassDll, &dwBypassSize))
	{
		printf("Unable to load/find Bypass.dll\n");

		delete[] lpBypassDll;

		return FALSE;
	}

	if (!ManualMapDll(hProcess, (PBYTE)lpBypassDll, dwBypassSize))
	{
		printf("Failed to inject bypass\n");

		delete[] lpBypassDll;

		return FALSE;
	}


	delete[] lpBypassDll;

	printf("Bypass successfully injected!\n");

	return TRUE;
}

BOOL InjectCheat(HANDLE hProcess)
{
	printf("Injecting cheat..\n");

	PCHAR lpCheatDll = NULL;
	DWORD dwCheatSize = 0;

	if (!LoadFile("Cheat.dll", &lpCheatDll, &dwCheatSize))
	{
		printf("Unable to load/find Cheat.dll\n");

		delete[] lpCheatDll;

		return FALSE;
	}

	if (!ManualMapDll(hProcess, (PBYTE)lpCheatDll, dwCheatSize))
	{
		printf("Failed to inject cheat\n");

		delete[] lpCheatDll;

		return FALSE;
	}

	delete[] lpCheatDll;

	printf("Cheat successfully injected!\n");

	return TRUE;
}

int main()
{
	CHAR lpCurrentDirectory[MAX_PATH];
	GetCurrentDirectoryA(MAX_PATH, lpCurrentDirectory);

	std::string ConfigFilePath = lpCurrentDirectory;

	ConfigFilePath += CONFIG_NAME;

	CHAR lpExecutablePath[MAX_PATH] = { 0 };

	DWORD dwBytesRead = GetPrivateProfileStringA("Paths", "ExecutablePath", "", lpExecutablePath, sizeof(lpExecutablePath), ConfigFilePath.c_str());

	if (dwBytesRead == 0)
	{
		OPENFILENAMEA OpenFileName = { sizeof(OpenFileName) };

		OpenFileName.lpstrFile = lpExecutablePath;
		OpenFileName.nMaxFile = sizeof(lpExecutablePath);
		OpenFileName.lpstrFilter = "Executable Files\0StarRail.exe\0All Files (*.*)\0*.*\0";
		OpenFileName.nFilterIndex = 1;
		OpenFileName.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

		if (!GetOpenFileNameA(&OpenFileName))
			return -1;

		WritePrivateProfileStringA("Paths", "ExecutablePath", lpExecutablePath, ConfigFilePath.c_str());

		SetCurrentDirectoryA(lpCurrentDirectory);
	}

	STARTUPINFOA StartupInfo = { sizeof(StartupInfo) };
	PROCESS_INFORMATION ProcessInfo = {};

	if (!CreateProcessA(NULL, lpExecutablePath, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &StartupInfo, &ProcessInfo))
		return -1;

	if (!InjectBypass(ProcessInfo.hProcess, ProcessInfo.hThread))
	{
		TerminateProcess(ProcessInfo.hProcess, 0);

		system("pause");

		return -1;
	}

	ResumeThread(ProcessInfo.hThread);

	printf("Waiting for the game to initialize..\n");

	HWND hWnd = NULL;

	while ((hWnd = FindWindowA("UnityWndClass", NULL)) == NULL)
		Sleep(1000);

	Sleep(15000);

	if (!InjectCheat(ProcessInfo.hProcess))
	{
		TerminateProcess(ProcessInfo.hProcess, 0);

		system("pause");

		return -1;
	}

	CloseHandle(ProcessInfo.hProcess);
	CloseHandle(ProcessInfo.hThread);

	return 0;
}