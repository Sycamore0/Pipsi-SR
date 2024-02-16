#include "skip_cutscene.h"

#include "engine.h"
#include "globals.h"
#include "hooks.h"

#include "utils.h"

#include "imgui_internal.h"

namespace SkipCutscene
{
	void _OnTickHandler(RPG::Client::ManaVideoPageContext* _this, float deltaSecond)
	{
		if (Options.bSkipCutscene && _this)
		{
			_this->_canSkip = TRUE;
		}

		CALL_ORIGIN(_OnTickHandler, _this, deltaSecond);
	}

	void Render()
	{
		ImGui::BeginGroupPanel("Skip Cutscene");

		ImGui::Checkbox("Enable", &Options.bSkipCutscene);

		ImGui::SameLine();

		ImGui::HelpMarker("Unlocks the game skip button (work only with video cutscene).");

		ImGui::EndGroupPanel();
	}

	void Update()
	{

	}

	void Start()
	{
		CreateHook(RPG::Client::ManaVideoPageContext::_OnTick, _OnTickHandler);
	}
}