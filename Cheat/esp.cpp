#include "esp.h"

#include "globals.h"
#include "engine.h"

#include "utils.h"

#include "imgui_internal.h"

namespace Esp
{
	static bool OnMonster(RPG::GameCore::GameEntity* lpEntity, LPCSTR* lpName, ImColor* lpColor)
	{
		if (!Options.bEspMonster)
			return false;

		*lpName = "Monster";
		lpColor->Value = { Options.vEspMonsterColor[0], Options.vEspMonsterColor[1], Options.vEspMonsterColor[2], Options.vEspMonsterColor[3] };

		return TRUE;
	}

	static bool OnNpc(RPG::GameCore::GameEntity* lpEntity, LPCSTR* lpName, ImColor* lpColor)
	{
		if (!Options.bEspNpc)
			return false;

		*lpName = "NPC";
		lpColor->Value = { Options.vEspNpcColor[0], Options.vEspNpcColor[1], Options.vEspNpcColor[2], Options.vEspNpcColor[3] };

		return TRUE;
	}

	static bool OnProp(RPG::GameCore::GameEntity* lpEntity, LPCSTR* lpName, ImColor* lpColor)
	{
		PVOID lpPropComponent = Engine::GetPropComponent(lpEntity->TickComponentList);

		if (!lpPropComponent)
			return FALSE;

		switch (RPG::GameCore::PropComponent::get_PropState(lpPropComponent))
		{
		case RPG::GameCore::PropState_TriggerDisable:
		case RPG::GameCore::PropState_TriggerEnable:
			if (!Options.bEspTrigger) return false;
			*lpName = "Trigger";
			lpColor->Value = { Options.vEspTriggerColor[0], Options.vEspTriggerColor[1], Options.vEspTriggerColor[2], Options.vEspTriggerColor[3] };
			break;
		case RPG::GameCore::PropState_Closed:
			if (!Options.bEspClosed) return false;
			*lpName = "Closed";
			lpColor->Value = { Options.vEspClosedColor[0], Options.vEspClosedColor[1], Options.vEspClosedColor[2], Options.vEspClosedColor[3] };
			break;
		case RPG::GameCore::PropState_CheckPointDisable:
		case RPG::GameCore::PropState_CheckPointEnable:
			if (!Options.bEspCheckPoint) return false;
			*lpName = "CheckPoint";
			lpColor->Value = { Options.vEspCheckPointColor[0], Options.vEspCheckPointColor[1], Options.vEspCheckPointColor[2], Options.vEspCheckPointColor[3] };
			break;
		case RPG::GameCore::PropState_EventClose:
			if (!Options.bEspEvent) return false;
			*lpName = "Event";
			lpColor->Value = { Options.vEspEventColor[0], Options.vEspEventColor[1], Options.vEspEventColor[2], Options.vEspEventColor[3] };
			break;
		case RPG::GameCore::PropState_ChestLocked:
		case RPG::GameCore::PropState_ChestClosed:
			if (!Options.bEspChest) return false;
			*lpName = "Chest";
			lpColor->Value = { Options.vEspChestColor[0], Options.vEspChestColor[1], Options.vEspChestColor[2], Options.vEspChestColor[3] };
			break;
		default:
			return FALSE;
		}

		return TRUE;
	}

	static void OnDraw(ImDrawList* lpDrawList, RPG::GameCore::GameEntity* lpEntity, Vector3* PlayerPosition, Vector2* lpResolution, Vector2* lpResolutionScale, LPCSTR lpName, ImColor* lpColor)
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

		ImVec2 TextPosition = { ScreenPosition.x, ScreenPosition.y };

		lpDrawList->AddText(ImGui::GetIO().FontDefault, Options.fFontSize, ImGui::CalcCenterPosition(&TextPosition, lpName), *lpColor, lpName);
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

			ImGui::Checkbox("Trigger", &Options.bEspTrigger);
			ImGui::SameLine();
			ImGui::ColorEdit4("Trigger Color", Options.vEspTriggerColor, ImGuiColorEditFlags_PickerMask_);

			ImGui::Checkbox("Closed", &Options.bEspClosed);
			ImGui::SameLine();
			ImGui::ColorEdit4("Closed Color", Options.vEspClosedColor, ImGuiColorEditFlags_PickerMask_);

			ImGui::Checkbox("CheckPoint", &Options.bEspCheckPoint);
			ImGui::SameLine();
			ImGui::ColorEdit4("CheckPoint Color", Options.vEspCheckPointColor, ImGuiColorEditFlags_PickerMask_);

			ImGui::Checkbox("Event", &Options.bEspEvent);
			ImGui::SameLine();
			ImGui::ColorEdit4("Event Color", Options.vEspEventColor, ImGuiColorEditFlags_PickerMask_);

			ImGui::Checkbox("Chest", &Options.bEspChest);
			ImGui::SameLine();
			ImGui::ColorEdit4("Chest Color", Options.vEspChestColor, ImGuiColorEditFlags_PickerMask_);

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

				LPCSTR lpName = NULL;
				ImColor lpColor = {};

				switch (lpEntity->EntityType)
				{
				case RPG::GameCore::EntityType_Monster:
				case RPG::GameCore::EntityType_NPCMonster:
					if (!OnMonster(lpEntity, &lpName, &lpColor))
						continue;
					break;
				case RPG::GameCore::EntityType_NPC:
					if (!OnNpc(lpEntity, &lpName, &lpColor))
						continue;
					break;
				case RPG::GameCore::EntityType_Prop:
					if (!OnProp(lpEntity, &lpName, &lpColor))
						continue;
					break;
				default:
					continue;
				}

				OnDraw(lpDrawList, lpEntity, &PlayerPosition, &Resolution, &ResolutionScale, lpName, &lpColor);
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