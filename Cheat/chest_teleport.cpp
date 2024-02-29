#include "chest_teleport.h"

#include "engine.h"
#include "globals.h"
#include "hooks.h"

#include "inputs.h"

#include "utils.h"

#include "imgui_internal.h"

namespace ChestTeleport
{
	static bool IsValid(RPG::GameCore::GameEntity* lpEntity, Vector3* PlayerPosition, bool bCheckLocked) {
		PVOID lpPropComponent = Engine::GetPropComponent(lpEntity->TickComponentList);

		if (!lpPropComponent)
			return FALSE;

		INT iPropState = RPG::GameCore::PropComponent::get_PropState(lpPropComponent);

		if ((bCheckLocked && iPropState != RPG::GameCore::PropState_ChestLocked) ||
			(!bCheckLocked && (iPropState != RPG::GameCore::PropState_CheckPointDisable && iPropState != RPG::GameCore::PropState_ChestClosed))) {
			return FALSE;
		}

		Vector3 ChestPosition;

		if (!Engine::GetEntityPosition(lpEntity, &ChestPosition))
			return FALSE;

		FLOAT fDistance = PlayerPosition->Distance(ChestPosition);

		if (fDistance < 3.0f)
			return FALSE;

		return TRUE;
	}

	static void* TryFindChest(Vector3* PlayerPosition, System::Collections::Generic::List* lpEntityList, bool bCheckLocked)
	{
		for (int i = 0; i < lpEntityList->size; i++)
		{
			RPG::GameCore::GameEntity* lpEntity = (RPG::GameCore::GameEntity*)lpEntityList->items->vector[i];

			if (!lpEntity || lpEntity->EntityType != RPG::GameCore::EntityType_Prop)
				continue;

			if (IsValid(lpEntity, PlayerPosition, FALSE))
				return lpEntity;
		}

		return NULL;
	}

	static void* FindChest(System::Collections::Generic::List* lpEntityList)
	{
		PVOID lpPlayer = RPG::GameCore::AdventureStatic::GetLocalPlayer();

		if (!lpPlayer)
			return NULL;

		Vector3 PlayerPosition = {};

		if (!Engine::GetEntityPosition(lpPlayer, &PlayerPosition))
			return NULL;

		PVOID lpChest = TryFindChest(&PlayerPosition, lpEntityList, FALSE);

		if (!lpChest)
			return lpChest;

		return TryFindChest(&PlayerPosition, lpEntityList, TRUE);
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
		UPDATE_DELAY(500);

		if (!Options.bChestTeleport || Engine::GetPhaseType() != RPG::Client::GamePhaseType_Adventure)
			return;

		if (!Inputs::GetState(Options.dwChestTeleportKey, INPUT_TYPE_HOLD))
			return;

		__try
		{
			System::Collections::Generic::List* lpEntityList = Engine::GetWorldEntityList();

			if (!lpEntityList)
				return;

			PVOID lpChest = FindChest(lpEntityList);

			if (!lpChest)
				return;

			Vector3 Position = {};

			if (!Engine::GetEntityPosition(lpChest, &Position))
				return;

			Engine::PlayerTeleport(&Position);
		}
		__except (EXCEPTION_EXECUTE_HANDLER)
		{
			printf("ChestTeleport::Update(), exception 0x%X\n", GetExceptionCode());
		}
	}

	void Start()
	{
	}
}