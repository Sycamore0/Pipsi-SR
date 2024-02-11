#pragma once
#include <windows.h>

#include "imgui_internal.h"

#define UPDATE_DELAY(delay) static unsigned long long lpLastTick = 0; \
                            unsigned long long lpTickCount = GetTickCount64();\
                            if (lpLastTick + (delay) > lpTickCount) \
                                return; \
							lpLastTick = lpTickCount;

namespace ImGui
{
	VOID HelpMarker(LPCSTR lpTesc);

	bool BeginGroupPanel(const char* label, bool node = false, const ImVec2& size = ImVec2(-1.0f, 0.0f));
	void EndGroupPanel();

	void Hotkey(unsigned int* lpValue);
}