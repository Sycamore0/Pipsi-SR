#include "config.h"

#include "engine.h"
#include "globals.h"
#include "hooks.h"

#include "utils.h"

#include "imgui_internal.h"

namespace Config
{
	static void SaveConfig()
	{
		HANDLE hFile = CreateFileA("Pipsi-SR.cfg", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

		if (hFile == INVALID_HANDLE_VALUE || hFile == NULL)
			return;

		DWORD dwBytesWritten;

		if (!WriteFile(hFile, &Options, sizeof(Options), &dwBytesWritten, NULL))
		{
			printf("Unable to save config\n");
		}

		printf("Saved config %x\n", dwBytesWritten);

		CloseHandle(hFile);
	}

	static void LoadConfig()
	{
		HANDLE hFile = CreateFileA("Pipsi-SR.cfg", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

		if (hFile == INVALID_HANDLE_VALUE || hFile == NULL)
			return;

		DWORD dwBytesRead;

		if (!ReadFile(hFile, &Options, sizeof(Options), &dwBytesRead, NULL))
		{
			printf("Unable to load config\n");
		}
		
		printf("Loaded config %x\n", dwBytesRead);

		CloseHandle(hFile);
	}

	void Render()
	{
		ImGui::BeginGroupPanel("Config");
		
		if (ImGui::Button("Save"))
		{
			SaveConfig();
		}

		ImGui::SameLine();

		if (ImGui::Button("Load"))
		{
			LoadConfig();
		}

		ImGui::EndGroupPanel();
	}

	void Update()
	{
	}

	void Start()
	{
	}
}