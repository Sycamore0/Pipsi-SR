#include "menu.h"

#include "globals.h"
#include "cheats.h"

#include "engine.h"

#include "inputs.h"

#include "imgui_internal.h"
#include "imgui_impl_win32.h"

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

DWORD dwCurrentTab = 0;

LRESULT WndProcHandler(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	Inputs::OnWindowMessage(uMsg, wParam, lParam);

	Options.bMenu = Inputs::GetState(Options.dwMenuKey, INPUT_TYPE_TOGGLE);

	if (Options.bMenu)
	{
		ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);

		return TRUE;
	}

    lpWindow = hWnd;

	return CallWindowProcA(lpWndProc, hWnd, uMsg, wParam, lParam);
}

BOOL RenderTabs()
{
    LPCSTR lpTabs[] = { "Player", "Battle", "World", "Visuals", "Misc" };
    
    ImGui::BeginGroup();

    ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1.0f);

    if (ImGui::BeginListBox("##MainListbox", ImVec2(ImGui::GetWindowWidth() / 5.f, -FLT_MIN)))
    {
        for (INT i = 0; i < IM_ARRAYSIZE(lpTabs); i++)
        {
            BOOL bIsSelected = i == dwCurrentTab;

            if (ImGui::Selectable(lpTabs[i], bIsSelected))
                dwCurrentTab = i;

            if (bIsSelected)
                ImGui::SetItemDefaultFocus();
        }

        ImGui::EndListBox();
    }

    ImGui::PopStyleVar();

    ImGui::EndGroup();

    ImGui::SameLine();

    ImGui::BeginGroup();
    ImGui::BeginChild("##MainChild", ImVec2(0, 0), ImGuiChildFlags_Border);

    switch (dwCurrentTab)
    {
    case 0:
        Cheats::RenderPlayerTab();
        break;
    case 1:
        Cheats::RenderBattleTab();
        break;
    case 2:
        Cheats::RenderWorldTab();
        break;
    case 3:
        Cheats::RenderVisualsTab();
        break;
    case 4:
        Cheats::RenderMiscTab();
        break;
    default:
        break;
    }

    ImGui::EndChild();
    ImGui::EndGroup();

    return TRUE;
}

BOOL RenderHandler(PVOID lpRenderParameter)
{
	if (Options.bMenu)
	{
        ImGui::SetNextWindowSize(ImVec2(800, 440), ImGuiCond_FirstUseEver);

		ImGui::Begin("Pipsi-SR | " __DATE__);

		RenderTabs();

		ImGui::End();
	}

	Cheats::Update();

	return TRUE;
}

