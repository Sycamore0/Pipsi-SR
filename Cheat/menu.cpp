#include "menu.h"

#include "globals.h"
#include "cheats.h"

#include "engine.h"

#include "inputs.h"

#include "imgui_internal.h"
#include "imgui_impl_win32.h"

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

LRESULT WndProcHandler(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	Inputs::OnWindowMessage(uMsg, wParam, lParam);

	Options.bMenu = Inputs::GetState(Options.dwMenuKey, INPUT_TYPE_TOGGLE);

	if (Options.bMenu)
	{
		ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);

		return TRUE;
	}

	return CallWindowProcA(lpWndProc, hWnd, uMsg, wParam, lParam);
}

BOOL RenderTabs()
{
	if (ImGui::BeginTabBar("##tabs"))
	{
		if (ImGui::BeginTabItem("Player"))
		{
			Cheats::RenderPlayerTab();

			ImGui::EndTabItem();
		}

		if (ImGui::BeginTabItem("Battle"))
		{
			Cheats::RenderBattleTab();

			ImGui::EndTabItem();
		}

		if (ImGui::BeginTabItem("World"))
		{
			Cheats::RenderWorldTab();

			ImGui::EndTabItem();
		}

		if (ImGui::BeginTabItem("Visuals"))
		{
			Cheats::RenderVisualsTab();

			ImGui::EndTabItem();
		}

		if (ImGui::BeginTabItem("Misc"))
		{
			Cheats::RenderMiscTab();

			ImGui::EndTabItem();
		}

		ImGui::EndTabBar();
	}

	return TRUE;
}

BOOL RenderHandler(PVOID lpRenderParameter)
{
	if (Options.bMenu)
	{
		ImGui::Begin("Pipsi-SR | " __DATE__);

		RenderTabs();

		ImGui::End();
	}

	Cheats::Update();

	return TRUE;
}

