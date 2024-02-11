#include "engine.h"

namespace Engine
{
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