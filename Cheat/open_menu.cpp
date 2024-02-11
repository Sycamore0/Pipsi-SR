#include "open_menu.h"

#include "globals.h"
#include "hooks.h"

#include "inputs.h"

#include "utils.h"

#include "imgui_internal.h"

namespace OpenMenu
{
	void Render()
	{
		ImGui::BeginGroupPanel("Open Menu");

		ImGui::Hotkey(&dwMenuKey);

		ImGui::SameLine();

		ImGui::HelpMarker("Hotkey for open menu");

		ImGui::EndGroupPanel();
	}

	void Update()
	{

	}

	void Start()
	{

	}
}