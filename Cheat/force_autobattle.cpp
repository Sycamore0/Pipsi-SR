#include "force_autobattle.h"

#include "engine.h"
#include "globals.h"
#include "hooks.h"

#include "utils.h"

#include "imgui_internal.h"

namespace ForceAutoBattle
{
	static bool get_AutoBattleHandler(void* _this)
	{
		if (bForceAutoBattle)
			return TRUE;

		return CALL_ORIGIN(get_AutoBattleHandler, _this);
	}

	void Render()
	{
		//ImGui::BeginGroupPanel("Force Auto-Battle");

		//ImGui::Checkbox("Enable", &bForceAutoBattle);

		//ImGui::EndGroupPanel();
	}

	void Update()
	{
	}

	void Start()
	{
		// detected ):
		// CreateHook(RPG::Client::TurnBasedGameMode::get_AutoBattle, get_AutoBattleHandler);
	}
}