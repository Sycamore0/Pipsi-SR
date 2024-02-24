#include "ui.h"

#include "engine.h"
#include "globals.h"
#include "hooks.h"

#include "utils.h"

#include "imgui_internal.h"

namespace Ui
{
	void Render()
	{
		ImGui::BeginGroupPanel("UI-Tools");

		ImGui::Checkbox("Enable", &Options.bUi);

		if (Options.bUi)
		{
			ImGui::Indent();

			ImGui::Checkbox("Hide UI", &Options.bUiHide);
			// ImGui::Checkbox("Hide UID", &bUiHideUid);

			ImGui::Unindent();
		}

		ImGui::EndGroupPanel();
	}

	void Update()
	{
		UPDATE_DELAY(100);

		if (Options.bUi)
		{
			UnityEngine::Behaviour::set_enabled(Engine::GetUICamera(), !Options.bUiHide);
		}
	}

	void Start()
	{

	}
}