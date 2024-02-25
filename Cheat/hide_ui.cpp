#include "hide_ui.h"

#include "engine.h"
#include "globals.h"
#include "hooks.h"

#include "utils.h"

#include "imgui_internal.h"

namespace HideUI
{
	void Render()
	{
		ImGui::BeginGroupPanel("Hide UI");

		ImGui::Checkbox("Enable", &Options.bUiHide);

		ImGui::EndGroupPanel();
	}

	void Update()
	{
		UPDATE_DELAY(100);

		UnityEngine::Behaviour::set_enabled(Engine::GetUICamera(), !Options.bUiHide);
	}

	void Start()
	{

	}
}