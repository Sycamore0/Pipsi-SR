#include "chest_teleport.h"

#include "engine.h"
#include "globals.h"
#include "hooks.h"

#include "inputs.h"

#include "utils.h"

#include "imgui_internal.h"

namespace ChestTeleport
{
	static void OnChestComponent(PVOID lpPropComponent)
	{
		UPDATE_DELAY(500);

		PVOID lpOwnerEntity = RPG::GameCore::PropComponent::get_OwnerEntity(lpPropComponent);

		if (!lpOwnerEntity)
			return;

		Vector3 Position = {};

		if (!Engine::GetEntityPosition(lpOwnerEntity, &Position))
			return;

		Engine::PlayerTeleport(&Position);
	}

	int iPropState = 0;

	static void TickHandler(void* _this, float fElapsedTimeInSec)
	{
		CALL_ORIGIN(TickHandler, _this, fElapsedTimeInSec);

		if (Options.bChestTeleport && Inputs::GetState(Options.dwChestTeleportKey, INPUT_TYPE_HOLD))
		{
			__try
			{
				switch (RPG::GameCore::PropComponent::get_PropState(_this))
				{
				case RPG::GameCore::PropState_ChestClosed:
				 case RPG::GameCore::PropState_ChestLocked:
					OnChestComponent(_this);
					break;
				default:
					break;
				}
			}
			__except (EXCEPTION_EXECUTE_HANDLER)
			{
				printf("ChestTeleport::TickHandler(), exception 0x%X\n", GetExceptionCode());
			}
		}
	}

	void Render()
	{
		ImGui::BeginGroupPanel("Chest Teleport");

		ImGui::Checkbox("Enable", &Options.bChestTeleport);

		ImGui::SameLine();

		ImGui::Hotkey(&Options.dwChestTeleportKey);

		ImGui::EndGroupPanel();
	}

	void Update()
	{
		
	}

	void Start()
	{
		CreateHook(RPG::GameCore::PropComponent::Tick, TickHandler);
	}
}