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
		FLOAT flValue;

		if (bBattleSpeed)
		{
			flValue = flBattleSpeed;
		}
		else
		{
			flValue = value;
		}

		return CALL_ORIGIN(set_speedHandler, _this, flValue);
	}

	void Render()
	{
		ImGui::BeginGroupPanel("Battle Speed");

		ImGui::Checkbox("Enable", &bBattleSpeed);

		if (bBattleSpeed)
		{
			ImGui::SliderFloat("Value", &flBattleSpeed, 0.1f, 50.f, "%.1f");
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