#include "battle_speed.h"

#include "engine.h"
#include "globals.h"
#include "hooks.h"

#include "utils.h"

#include "imgui_internal.h"

namespace BattleSpeed
{
	void set_speedHandler(void* _this, float value)
	{
		FLOAT flValue = value;

		if (bBattleSpeed)
		{
			__try
			{
				RPG::GameCore::GameWorld* lpMainWorld = RPG::GameCore::AdventureStatic::GetMainWorld();

				if (!lpMainWorld)
					return;

				PVOID lpBattleInstance = RPG::GameCore::GameWorld::get_BattleInstanceRef(lpMainWorld);

				if (lpBattleInstance)
					return;

				PVOID lpTurnBasedGameMode = RPG::GameCore::BattleInstance::get_TurnBasedGameModeRef(lpBattleInstance);

				if (!lpTurnBasedGameMode)
					return;

				if (RPG::Client::TurnBasedGameMode::get_IsInBattle(lpTurnBasedGameMode))
					flValue = flBattleSpeed;

			}
			__except (EXCEPTION_EXECUTE_HANDLER)
			{
				printf("ChestTeleport::Update(), exception 0x%X\n", GetExceptionCode());

				flValue = value;
			}
		}

		return CALL_ORIGIN(set_speedHandler, _this, flValue);
	}

	void Render()
	{
		ImGui::BeginGroupPanel("Battle Speed");

		ImGui::Checkbox("Enable", &bBattleSpeed);

		if (bBattleSpeed)
		{
			ImGui::SliderFloat("Value", &flBattleSpeed, 0.1f, 50.f, "%.1f");
		}

		ImGui::EndGroupPanel();
	}

	void Update()
	{
	}

	void Start()
	{
		CreateHook(UnityEngine::Animator::set_speed, set_speedHandler);
	}
}