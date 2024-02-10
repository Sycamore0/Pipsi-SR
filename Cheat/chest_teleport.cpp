#include "chest_teleport.h"

#include "engine.h"
#include "globals.h"
#include "hooks.h"

#include "inputs.h"

#include "utils.h"

#include "imgui_internal.h"

namespace ChestTeleport
{
	static bool IsUnlockedChest(const wchar_t* lpEntityName) { 			
		// || wcsstr(lpEntityName, L"PROP_32") != NULL
		return (wcsstr(lpEntityName, L"PROP_10-") != NULL
			|| wcsstr(lpEntityName, L"PROP_13-") != NULL);
			// || wcsstr(lpEntityName, L"PROP_33") != NULL);
	}

	static bool IsLockedChest(const wchar_t* lpEntityName) {
		// not tested
		return (wcsstr(lpEntityName, L"PROP_27-") != NULL
			|| wcsstr(lpEntityName, L"PROP_28-") != NULL);
	}

	void Render()
	{
		ImGui::BeginGroupPanel("Chest Teleport");

		ImGui::Checkbox("Enable", &bChestTeleport);

		ImGui::EndGroupPanel();
	}

	void Update()
	{
		if (!bChestTeleport || !Inputs::GetState(dwChestTeleportKey, INPUT_TYPE_HOLD))
			return;

		UPDATE_DELAY(100);

		__try
		{
			PVOID lpEntityManager = RPG::GameCore::AdventureStatic::GetEntityManager();

			if (!lpEntityManager)
				return;

			RPG::GameCore::GameWorld* lpWorld = RPG::GameCore::EntityManager::get_OwnerWorldRef(lpEntityManager);

			if (!lpWorld)
				return;
			
			for (int i = 0; i < lpWorld->_EntityList->size; i++)
			{
				RPG::GameCore::GameEntity* lpEntity = (RPG::GameCore::GameEntity*)lpWorld->_EntityList->items->vector[i];
				
				if (!lpEntity || !lpEntity->_Visible || !lpEntity->_Name || lpEntity->_Name->m_stringLength < 8)
					continue;

				if (!IsUnlockedChest(lpEntity->_Name->m_firstChar))
					continue;
				
				Vector3 Position = {};

				if (Engine::GetEntityPosition(lpEntity, &Position))
				{
					// printf("%ws, %i %i %i %i\n", lpEntity->_Name->m_firstChar, lpEntity->_Tickable, lpEntity->_IsLoaded, lpEntity->_Visible, lpEntity->KillImmediately);

					Engine::PlayerTeleport(&Position);

					return;
				}
			}

			for (int i = 0; i < lpWorld->_EntityList->size; i++)
			{
				RPG::GameCore::GameEntity* lpEntity = (RPG::GameCore::GameEntity*)lpWorld->_EntityList->items->vector[i];

				if (!lpEntity || !lpEntity->_Name || lpEntity->_Name->m_stringLength < 8)
					continue;

				if (!IsLockedChest(lpEntity->_Name->m_firstChar))
					continue;

				Vector3 Position = {};

				if (Engine::GetEntityPosition(lpEntity, &Position))
				{
					Engine::PlayerTeleport(&Position);

					return;
				}
			}
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