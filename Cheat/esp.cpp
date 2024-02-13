#include "esp.h"

#include "globals.h"
#include "engine.h"

#include "utils.h"

#include "imgui_internal.h"

namespace Esp
{
	void OnEntity(ImDrawList* lpDrawList, RPG::GameCore::GameEntity* lpEntity, Vector3* PlayerPosition, Vector2* lpResolutionScale)
	{
		Vector3 Position = {};

		if (!Engine::GetEntityPosition(lpEntity, &Position))
			return;

		if (PlayerPosition->Distance(Position) > flEspDistance)
			return;

		Vector3 ScreenPosition = {};

		if (!Engine::GetScreenPosition(lpResolutionScale, &Position, &ScreenPosition))
			return;

		if (ScreenPosition.z < 1.f)
			return;

		CHAR lpText[256] = {};

		ImTextStrToUtf8(lpText, sizeof(lpText), lpEntity->Name->m_firstChar, lpEntity->Name->m_firstChar + lpEntity->Name->m_stringLength);

		lpDrawList->AddText(ImVec2(ScreenPosition.x, ScreenPosition.y), ImColor(255, 255, 255), lpText);
	}

	void Render()
	{
		ImGui::BeginGroupPanel("Esp");

		ImGui::Checkbox("Enable", &bEsp);

		if (bEsp)
		{
			ImGui::Indent();

			ImGui::SliderFloat("Distance", &flEspDistance, 1.f, 300.f, "%.1f");

			ImGui::Checkbox("Monster", &bEspMonster);
			ImGui::Checkbox("Npc", &bEspNpc);
			ImGui::Checkbox("Prop", &bEspProp);
			ImGui::Checkbox("Mission", &bEspMission);

			ImGui::Unindent();
		}

		ImGui::EndGroupPanel();
	}

	void Update()
	{
		if (!bEsp || Engine::GetPhaseType() != RPG::Client::GamePhaseType_Adventure)
			return;

		__try
		{
			ImDrawList* lpDrawList = ImGui::GetBackgroundDrawList();

			PVOID lpPlayer = RPG::GameCore::AdventureStatic::GetLocalPlayer();

			if (!lpPlayer)
				return;

			Vector3 PlayerPosition = {};

			if (!Engine::GetEntityPosition(lpPlayer, &PlayerPosition))
				return;

			Vector2 ResolutionScale = {};

			if (!Engine::GetResolutionScale(&ResolutionScale))
				return;

			System::Collections::Generic::List* lpEntityList = Engine::GetWorldEntityList();

			for (int i = 0; i < lpEntityList->size; i++)
			{
				RPG::GameCore::GameEntity* lpEntity = (RPG::GameCore::GameEntity*)lpEntityList->items->vector[i];

				if (!lpEntity || !lpEntity->Visible || !lpEntity->Name->m_stringLength)
					continue;

				switch (lpEntity->EntityType)
				{
				case RPG::GameCore::EntityType_Monster:
				case RPG::GameCore::EntityType_NPCMonster:
					if (!bEspMonster) continue;
					break;
				case RPG::GameCore::EntityType_NPC:
					if (!bEspNpc) continue;
					break;
				case RPG::GameCore::EntityType_Prop:
					if (!bEspProp) continue;
					break;
				case RPG::GameCore::EntityType_Mission:
					if (!bEspMission) continue;
					break;
				default:
					continue;
				}

				OnEntity(lpDrawList, lpEntity, &PlayerPosition, &ResolutionScale);
			}
		}
		__except (EXCEPTION_EXECUTE_HANDLER)
		{
			printf("Esp::Update(), exception 0x%X\n", GetExceptionCode());
		}
	}

	void Start()
	{

	}
}