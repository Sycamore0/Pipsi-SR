#include "dump_enemies.h"

#include "engine.h"
#include "globals.h"
#include "hooks.h"

#include "utils.h"

#include "imgui_internal.h"

namespace DumpEnemies
{
	static void* TickAlertValueHandler(void* _this, float fElapsedTimeInSec, void* target, void* detail)
	{
		if (Options.bDumpEnemies)
			return NULL;

		return CALL_ORIGIN(TickAlertValueHandler, _this, fElapsedTimeInSec, target, detail);
	}

	void Render()
	{
		ImGui::BeginGroupPanel("Dump Enemies");

		ImGui::Checkbox("Enable", &Options.bDumpEnemies);

		ImGui::SameLine();

		ImGui::HelpMarker("Prevents monsters from moving.");

		ImGui::EndGroupPanel();
	}

	void Update()
	{
	}

	void Start()
	{
		CreateHook(RPG::GameCore::NPCComponent::TickAlertValue, TickAlertValueHandler);
	}
}