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

	static void TickHandler(void* _this, float fElapsedTimeInSec)
	{
		CALL_ORIGIN(TickHandler, _this, fElapsedTimeInSec);

		if (bChestTeleport && Inputs::GetState(dwChestTeleportKey, INPUT_TYPE_HOLD))
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
	}

	void Render()
	{
		ImGui::BeginGroupPanel("Chest Teleport");

		ImGui::Checkbox("Enable", &bChestTeleport);

		ImGui::SameLine();

		ImGui::Hotkey(&dwChestTeleportKey);

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