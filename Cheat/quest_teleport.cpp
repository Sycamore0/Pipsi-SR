#include "quest_teleport.h"

#include "engine.h"
#include "globals.h"
#include "hooks.h"

#include "inputs.h"

#include "utils.h"

#include "imgui_internal.h"

namespace QuestTeleport
{
	void* GetTargetPosHandler(void* _this, void* _res)
	{
		void* lpResult = CALL_ORIGIN(GetTargetPosHandler, _this, _res);

		if (!lpResult || !Options.bQuestTeleport)
			return lpResult;

		if (Inputs::GetState(Options.dwQuestTeleportKey, INPUT_TYPE_HOLD))
		{
			__try
			{
				Engine::PlayerTeleport(lpResult);
			}
			__except (EXCEPTION_EXECUTE_HANDLER)
			{
				printf("QuestTeleport::GetTargetPosHandler(), exception 0x%X\n", GetExceptionCode());
			}
		}
		
		return lpResult;
	}

	void Render()
	{
		ImGui::BeginGroupPanel("Quest Teleport");

		ImGui::Checkbox("Enable", &Options.bQuestTeleport);

		ImGui::SameLine();

		ImGui::Hotkey(&Options.dwQuestTeleportKey);

		ImGui::EndGroupPanel();
	}

	void Update()
	{

	}

	void Start()
	{
		CreateHook(RPG::Client::AdventureWaypointTarget::GetTargetPos, GetTargetPosHandler);
	}
}