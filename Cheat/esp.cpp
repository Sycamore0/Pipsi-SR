#include "esp.h"

#include "globals.h"
#include "engine.h"

#include "utils.h"

#include "imgui_internal.h"

namespace Esp
{
	static void OnEntity(ImDrawList* lpDrawList, RPG::GameCore::GameEntity* lpEntity, Vector3* PlayerPosition, Vector2* lpResolution, Vector2* lpResolutionScale, LPCSTR lpName, ImColor* lpColor)
	{
		Vector3 Position = {};

		if (!Engine::GetEntityPosition(lpEntity, &Position))
			return;

		if (PlayerPosition->Distance(Position) > Options.flEspDistance)
			return;

		Vector3 ScreenPosition = {};

		if (!Engine::GetScreenPosition(lpResolutionScale, &Position, &ScreenPosition))
			return;

		if (ScreenPosition.z < 1.f)
			return;

		if (Options.bEspTracer)
		{
			lpDrawList->AddLine(ImVec2(lpResolution->x, lpResolution->y) / 2.f, ImVec2(ScreenPosition.x, ScreenPosition.y), *lpColor, Options.fEspTracerSize);
		}

		if (Options.bEspDebug)
		{
			CHAR lpText[256] = {};

			ImTextStrToUtf8(lpText, sizeof(lpText), lpEntity->Name->m_firstChar, lpEntity->Name->m_firstChar + lpEntity->Name->m_stringLength);

			lpName = lpText;
		}

		lpDrawList->AddText(ImGui::GetIO().FontDefault, Options.fFontSize, ImVec2(ScreenPosition.x, ScreenPosition.y), *lpColor, lpName);
	}

	void Render()
	{
		ImGui::BeginGroupPanel("Esp");

		ImGui::Checkbox("Enable", &Options.bEsp);

		if (Options.bEsp)
		{
			ImGui::Indent();

			ImGui::Checkbox("Tracer", &Options.bEspTracer);
			ImGui::Checkbox("Debug Names", &Options.bEspDebug);
			
			ImGui::SliderFloat("Tracer Size", &Options.fEspTracerSize, 1.f, 100.f, "%.1f");
			ImGui::SliderFloat("Font Size", &Options.fFontSize, 1.f, 100.f, "%.1f");

			ImGui::SliderFloat("Distance", &Options.flEspDistance, 1.f, 300.f, "%.1f");

			ImGui::Checkbox("Monster", &Options.bEspMonster);
			ImGui::SameLine();
			ImGui::ColorEdit4("Monster Color", Options.vEspMonsterColor, ImGuiColorEditFlags_PickerMask_);
			
			ImGui::Checkbox("Npc", &Options.bEspNpc);
			ImGui::SameLine();
			ImGui::ColorEdit4("Npc Color", Options.vEspNpcColor, ImGuiColorEditFlags_PickerMask_);

			ImGui::Checkbox("Prop", &Options.bEspProp);
			ImGui::SameLine();
			ImGui::ColorEdit4("Prop Color", Options.vEspPropColor, ImGuiColorEditFlags_PickerMask_);

			ImGui::Checkbox("Mission", &Options.bEspMission);
			ImGui::SameLine();
			ImGui::ColorEdit4("Mission Color", Options.vEspMissionColor, ImGuiColorEditFlags_PickerMask_);

			ImGui::Unindent();
		}

		ImGui::EndGroupPanel();
	}

	void Update()
	{
		if (!Options.bEsp || Engine::GetPhaseType() != RPG::Client::GamePhaseType_Adventure)
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

			Vector2 Resolution = {};
			Vector2 ResolutionScale = {};

			if (!Engine::GetResolutionScale(&Resolution, &ResolutionScale))
				return;

			System::Collections::Generic::List* lpEntityList = Engine::GetWorldEntityList();

			for (int i = 0; i < lpEntityList->size; i++)
			{
				RPG::GameCore::GameEntity* lpEntity = (RPG::GameCore::GameEntity*)lpEntityList->items->vector[i];

				if (!lpEntity || !lpEntity->Visible || !lpEntity->Name || !lpEntity->Name->m_stringLength)
					continue;

				LPCSTR lpName;
				ImColor lpColor;

				switch (lpEntity->EntityType)
				{
				case RPG::GameCore::EntityType_Monster:
				case RPG::GameCore::EntityType_NPCMonster:
					if (!Options.bEspMonster) continue;
					lpName = "Monster";
					lpColor = ImColor(Options.vEspMonsterColor[0], Options.vEspMonsterColor[1], Options.vEspMonsterColor[2], Options.vEspMonsterColor[3]);
					break;
				case RPG::GameCore::EntityType_NPC:
					if (!Options.bEspNpc) continue;
					lpName = "NPC";
					lpColor = ImColor(Options.vEspNpcColor[0], Options.vEspNpcColor[1], Options.vEspNpcColor[2], Options.vEspNpcColor[3]);
					break;
				case RPG::GameCore::EntityType_Prop:
					if (!Options.bEspProp) continue;
					lpName = "Prop";
					lpColor = ImColor(Options.vEspPropColor[0], Options.vEspPropColor[1], Options.vEspPropColor[2], Options.vEspPropColor[3]);
					break;
				case RPG::GameCore::EntityType_Mission:
					if (!Options.bEspMission) continue;
					lpName = "Mission";
					lpColor = ImColor(Options.vEspMissionColor[0], Options.vEspMissionColor[1], Options.vEspMissionColor[2], Options.vEspMissionColor[3]);
					break;
				default:
					continue;
				}

				OnEntity(lpDrawList, lpEntity, &PlayerPosition, &Resolution , &ResolutionScale, lpName, &lpColor);
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