#include "cheats.h"

#include "auto_chat.h"
#include "uid_editor.h"
#include "auto_puzzle.h"
#include "hide_ui.h"
#include "unlock_autobattle.h"
#include "unload.h"
#include "config.h"
#include "fps.h"
#include "skip_cutscene.h"
#include "open_menu.h"
#include "chest_teleport.h"
#include "quest_teleport.h"
#include "auto_talk.h"
#include "battle_speed.h"
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
		UnlockAutoBattle::Render();
		BattleSpeed::Render();
	}

	VOID RenderWorldTab()
	{
		AutoChat::Render();
		AutoPuzzle::Render();
		SkipCutscene::Render();
		ChestTeleport::Render();
		QuestTeleport::Render();
		AutoTalk::Render();
		DumpEnemies::Render();
	}

	VOID RenderVisualsTab()
	{
		UIDEditor::Render();
		HideUI::Render();
		Esp::Render();
		Fov::Render();
		Peeking::Render();
	}

	VOID RenderMiscTab()
	{
		Unload::Render();
		Config::Render();
		Fps::Render();
		OpenMenu::Render();
	}

	VOID Update()
	{
		AutoChat::Update();
		UIDEditor::Update();
		AutoPuzzle::Update();
		HideUI::Update();
		UnlockAutoBattle::Update();
		Unload::Update();
		Config::Update();
		Fps::Update();
		SkipCutscene::Update();
		OpenMenu::Update();
		ChestTeleport::Update();
		QuestTeleport::Update();
		AutoTalk::Update();
		BattleSpeed::Update();
		DumpEnemies::Update();
		Esp::Update();
		Fov::Update();
		Noclip::Update();
		Peeking::Update();
	}

	VOID Start()
	{
		AutoChat::Start();
		UIDEditor::Start();
		AutoPuzzle::Start();
		HideUI::Start();
		UnlockAutoBattle::Start();
		Unload::Start();
		Config::Start();
		Fps::Start();
		SkipCutscene::Start();
		OpenMenu::Start();
		ChestTeleport::Start();
		QuestTeleport::Start();
		AutoTalk::Start();
		BattleSpeed::Start();
		DumpEnemies::Start();
		Esp::Start();
		Fov::Start();
		Noclip::Start();
		Peeking::Start();
	}
}