#include "battle_speed.h"

#include "engine.h"
#include "globals.h"
#include "hooks.h"

#include "utils.h"

#include "imgui_internal.h"

namespace BattleSpeed
{
	void set_speedHandler(void* _this, float value)
	{
		FLOAT flValue = value;

		if (bBattleSpeed)
		{
			__try
			{
				switch (Engine::GetPhaseType())
				{
				case RPG::Client::GamePhaseType_BattleLineup:
				case RPG::Client::GamePhaseType_QABattleLineup:
				case RPG::Client::GamePhaseType_Battle:
				case RPG::Client::GamePhaseType_BattleNew:
					flValue = flBattleSpeed;
					break;
				default:
					break;
				}
			}
			__except (EXCEPTION_EXECUTE_HANDLER)
			{
				printf("BattleSpeed::set_speedHandler(), exception 0x%X\n", GetExceptionCode());

				flValue = value;
			}
		}

		return CALL_ORIGIN(set_speedHandler, _this, flValue);
	}

	void Render()
	{
		ImGui::BeginGroupPanel("Battle Speed");

		ImGui::Checkbox("Enable", &bBattleSpeed);

		if (bBattleSpeed)
		{
			ImGui::Indent();

			ImGui::SliderFloat("Value", &flBattleSpeed, 0.1f, 25.f, "%.1f");

			ImGui::SameLine();

			ImGui::HelpMarker("Recommended value: 3 - 15.");

			ImGui::Unindent();
		}

		ImGui::EndGroupPanel();
	}

	void Update()
	{
	}

	void Start()
	{
		CreateHook(UnityEngine::Animator::set_speed, set_speedHandler);
	}
}