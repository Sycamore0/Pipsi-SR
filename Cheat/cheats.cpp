#include "cheats.h"

#include "open_menu.h"
#include "chest_teleport.h"
#include "quest_teleport.h"
#include "auto_talk.h"
#include "pve_statistics.h"
#include "battle_speed.h"
#include "force_autobattle.h"
#include "dump_enemies.h"
#include "esp.h"
#include "fov.h"
#include "noclip.h"
#include "peeking.h"

#include "engine.h"

namespace Cheats
{
	VOID RenderPlayerTab()
	{
		Noclip::Render();
	}

	VOID RenderBattleTab()
	{
		ForceAutoBattle::Render();
		BattleSpeed::Render();
	}

	VOID RenderWorldTab()
	{
		ChestTeleport::Render();
		QuestTeleport::Render();
		AutoTalk::Render();
		DumpEnemies::Render();
	}

	VOID RenderVisualsTab()
	{
		Esp::Render();
		Fov::Render();
		Peeking::Render();
	}

	VOID RenderMiscTab()
	{
		OpenMenu::Render();
	}

	VOID Update()
	{
		//if (!RPG::Client::GlobalVars->s_MainCamera)
		//	return;

		//if (RPG::Client::GlobalVars->s_LoadingManager)
		//	return;
		OpenMenu::Update();
		ChestTeleport::Update();
		QuestTeleport::Update();
		AutoTalk::Update();
		PveStatistics::Update();
		ForceAutoBattle::Update();
		BattleSpeed::Update();
		DumpEnemies::Update();
		Esp::Update();
		Fov::Update();
		Noclip::Update();
		Peeking::Update();
	}

	VOID Start()
	{
		OpenMenu::Start();
		ChestTeleport::Start();
		QuestTeleport::Start();
		AutoTalk::Start();
		PveStatistics::Start();
		ForceAutoBattle::Start();
		BattleSpeed::Start();
		DumpEnemies::Start();
		Esp::Start();
		Fov::Start();
		Noclip::Start();
		Peeking::Start();
	}
}