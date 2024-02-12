#include "engine.h"

namespace Engine
{
	System::Collections::Generic::List* GetWorldEntityList()
	{
		PVOID lpEntityManager = RPG::GameCore::AdventureStatic::GetEntityManager();

		if (!lpEntityManager)
			return NULL;

		RPG::GameCore::GameWorld* lpWorld = RPG::GameCore::EntityManager::get_OwnerWorldRef(lpEntityManager);

		if (!lpWorld)
			return NULL;

		return lpWorld->EntityList;
	}

	System::Collections::Generic::List* GetMapPropList()
	{
		RPG::GameCore::PropManager* lpPropManager = RPG::GameCore::AdventureStatic::GetPropManager();

		if (!lpPropManager)
			return NULL;

		return lpPropManager->MapPropList;
	}

	System::Collections::Generic::List* GetPropEntityList()
	{
		RPG::GameCore::PropManager* lpPropManager = RPG::GameCore::AdventureStatic::GetPropManager();

		if (!lpPropManager)
			return NULL;

		return lpPropManager->PropEntityList;
	}

	bool GetEntityPosition(void* lpEntity, void* lpPosition)
	{
		PVOID lpGameObject = RPG::GameCore::GameEntity::get_UnityGO(lpEntity);

		if (!lpGameObject)
			return false;

		PVOID lpTransform = UnityEngine::GameObject::get_transform(lpGameObject);

		if (!lpTransform)
			return false;

		UnityEngine::Transform::get_position_Injected(lpTransform, lpPosition);

		return true;
	}

	int GetPhaseType()
	{
		PVOID lpPhaseManager = *(PVOID*)((PBYTE)(*lpGlobalVars) + 0x1D4B0); // GamePhaseManager offset

		if (!lpPhaseManager)
			return 0;

		return RPG::Client::GamePhaseManager::get_CurrentGamePhaseType(lpPhaseManager);
	}

	void PlayerTeleport(void* lpPosition)
	{
		PVOID lpPlayer = RPG::GameCore::AdventureStatic::GetLocalPlayer();

		if (!lpPlayer)
			return;

		PVOID lpGameObject = RPG::GameCore::GameEntity::get_UnityGO(lpPlayer);

		if (!lpGameObject)
			return;

		PVOID lpTransform = UnityEngine::GameObject::get_transform(lpGameObject);

		if (!lpTransform)
			return;

		UnityEngine::Transform::set_position_Injected(lpTransform, lpPosition);
	}
}