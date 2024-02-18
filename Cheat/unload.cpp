#include "unload.h"

#include "engine.h"
#include "globals.h"
#include "hooks.h"

#include "utils.h"

#include "imgui_internal.h"

namespace Unload
{
	void Render()
	{
		ImGui::BeginGroupPanel("Unload");

		if (ImGui::Button("Unload"))
		{
			DeleteHooks();

			SetWindowLongPtrA(lpWindow, GWLP_WNDPROC, (LONG_PTR)lpWndProc);
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