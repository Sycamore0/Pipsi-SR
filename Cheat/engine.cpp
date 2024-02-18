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

	void* GetTurnBasedGameMode()
	{
		PVOID lpEntityManager = RPG::GameCore::AdventureStatic::GetEntityManager();

		if (!lpEntityManager)
			return NULL;

		RPG::GameCore::GameWorld* lpWorld = RPG::GameCore::EntityManager::get_OwnerWorldRef(lpEntityManager);

		if (!lpWorld)
			return NULL;

		PVOID lpBattleInstance = lpWorld->_BattleInstanceRef;

		if (!lpBattleInstance)
			return NULL;

		return RPG::GameCore::BattleInstance::get_TurnBasedGameModeRef(lpBattleInstance);
	}

	bool GetResolutionScale(Vector2* lpResolutionScale)
	{
		PVOID lpMainCamera = UnityEngine::Camera::get_main();

		if (!lpMainCamera)
			return FALSE;

		DWORD dwPixelWidth = UnityEngine::Camera::get_pixelWidth(lpMainCamera);
		DWORD dwPixelHeight = UnityEngine::Camera::get_pixelHeight(lpMainCamera);

		if (!dwPixelWidth || !dwPixelHeight)
			return FALSE;

		DWORD dwScreenWidth = UnityEngine::Screen::get_width();
		DWORD dwScreenHeight = UnityEngine::Screen::get_height();

		if (dwScreenWidth == 0 || dwScreenHeight == 0)
			return FALSE;

		ZeroMemory(lpResolutionScale, sizeof(*lpResolutionScale));

		if (dwPixelWidth != dwScreenWidth && dwPixelHeight != dwScreenHeight)
		{
			lpResolutionScale->x = (FLOAT)dwPixelWidth / (FLOAT)dwScreenWidth;
			lpResolutionScale->y = (FLOAT)dwPixelHeight / (FLOAT)dwScreenHeight;
		}

		return TRUE;
	}

	bool GetScreenPosition(Vector2* lpResolutionScale, void* lpWorldPosition, Vector3* lpRet)
	{
		PVOID lpMainCamera = UnityEngine::Camera::get_main();

		if (!lpMainCamera)
			return FALSE;

		UnityEngine::Camera::WorldToScreenPoint(lpRet, lpMainCamera, lpWorldPosition);

		if (lpResolutionScale->x != 0)
		{
			lpRet->x *= lpResolutionScale->x;
			lpRet->y *= lpResolutionScale->y;
		}

		lpRet->y = UnityEngine::Screen::get_height() - lpRet->y;

		return TRUE;
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
		PVOID lpPhaseManager = *(PVOID*)((PBYTE)(*lpGlobalVars) + GLOBALVARS_GAMEPHASEMANAGER_OFFSET);

		if (!lpPhaseManager)
			return 0;

		return RPG::Client::GamePhaseManager::get_CurrentGamePhaseType(lpPhaseManager);
	}

	void* GetTransform(void* lpEntity)
	{
		PVOID lpGameObject = RPG::GameCore::GameEntity::get_UnityGO(lpEntity);

		if (!lpGameObject)
			return NULL;

		return UnityEngine::GameObject::get_transform(lpGameObject);
	}

	void PlayerTeleport(void* lpPosition)
	{
		PVOID lpPlayer = RPG::GameCore::AdventureStatic::GetLocalPlayer();

		if (!lpPlayer)
			return;

		PVOID lpTransform = Engine::GetTransform(lpPlayer);

		if (!lpTransform)
			return;

		UnityEngine::Transform::set_position_Injected(lpTransform, lpPosition);
	}
}