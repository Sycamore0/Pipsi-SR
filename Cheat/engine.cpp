#include "engine.h"

namespace Engine
{
	System::Collections::Generic::List<RPG::GameCore::GameEntity*>* GetWorldEntityList()
	{
		PVOID lpEntityManager = RPG::GameCore::AdventureStatic::GetEntityManager();

		if (!lpEntityManager)
			return NULL;

		RPG::GameCore::GameWorld* lpWorld = RPG::GameCore::EntityManager::get_OwnerWorldRef(lpEntityManager);

		if (!lpWorld)
			return NULL;

		return lpWorld->EntityList;
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

	void* GetPropComponent(System::Collections::Generic::List<Base::Actor*>* lpComponentList)
	{
		static INT iPropId = 0;

		if (!lpComponentList)
			return NULL;

		if (lpComponentList->size > 3 && iPropId)
		{
			Base::Actor* lpComponent = lpComponentList->items->vector[3];

			if (lpComponent && lpComponent->klass && lpComponent->klass->id == iPropId)
				return lpComponent;
		}

		for (INT i = 0; i < lpComponentList->size; i++)
		{
			Base::Actor* lpComponent = lpComponentList->items->vector[i];

			if (!lpComponent->klass)
				continue;

			if (iPropId == 0 && lpComponent->klass->name && strcmp(lpComponent->klass->name, "PropComponent") == 0)
				iPropId = lpComponent->klass->id;

			if (lpComponent && lpComponent->klass->id == iPropId)
				return lpComponent;
		}

		return NULL;
	}

	bool GetResolutionScale(Vector2* lpResolution, Vector2* lpResolutionScale)
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

		if (lpResolution)
		{
			lpResolution->x = (FLOAT)dwScreenWidth;
			lpResolution->y = (FLOAT)dwScreenHeight;
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
		if (!*lpGlobalVars)
			return 0;

		PVOID lpPhaseManager = *(PVOID*)((PBYTE)(*lpGlobalVars) + GLOBALVARS_GAMEPHASEMANAGER_OFFSET);

		if (!lpPhaseManager)
			return 0;

		return RPG::Client::GamePhaseManager::get_CurrentGamePhaseType(lpPhaseManager);
	}

	void* GetUICamera()
	{
		if (!*lpGlobalVars)
			return 0;

		return *(PVOID*)((PBYTE)(*lpGlobalVars) + GLOBALVARS_UICAMERA_OFFSET);
	}
	
	void* GetBetaHintDialogContext()
	{
		if (!*lpGlobalVars)
			return 0;

		return *(PVOID*)((PBYTE)(*lpGlobalVars) + GLOBALVARS_BETAHINTDIALOGCONTEXT_OFFSET);
	}

	RPG::Client::ModuleManager* GetModuleManager()
	{
		if (!*lpGlobalVars)
			return 0;

		return *(RPG::Client::ModuleManager**)((PBYTE)(*lpGlobalVars) + GLOBALVARS_MODULEMANAGER_OFFSET);
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