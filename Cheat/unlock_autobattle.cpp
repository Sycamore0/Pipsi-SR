#include "unlock_autobattle.h"

#include "engine.h"
#include "globals.h"
#include "hooks.h"

#include "utils.h"

#include "imgui_internal.h"

namespace UnlockAutoBattle
{
	static bool IsStageForbidAutoBattleHandler(void* _this)
	{
		if (Options.bUnlockAutoBattle)
			return FALSE;

		return CALL_ORIGIN(IsStageForbidAutoBattleHandler, _this);
	}

	void Render()
	{
		ImGui::BeginGroupPanel("Unlock Auto Battle");

		ImGui::Checkbox("Enable", &Options.bUnlockAutoBattle);

		ImGui::SameLine();

		ImGui::HelpMarker("Will work only after the tutorial.");

		ImGui::EndGroupPanel();
	}

	void Update()
	{
	}

	void Start()
	{
		CreateHook(RPG::GameCore::BattleInstance::IsStageForbidAutoBattle, IsStageForbidAutoBattleHandler);
	}
}