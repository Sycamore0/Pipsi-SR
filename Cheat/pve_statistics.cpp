#include "pve_statistics.h"

#include "engine.h"
#include "globals.h"
#include "hooks.h"

#include "utils.h"

#include "imgui_internal.h"

namespace PveStatistics
{
	RPG::GameCore::PVEGameStatistics* BuildPVEStatisticsHandler(void* _this)
	{
		RPG::GameCore::PVEGameStatistics* lpResult = CALL_ORIGIN(BuildPVEStatisticsHandler, _this);

		if (lpResult)
		{
			lpResult->costTime *= flBattleSpeed;
		}

		return lpResult;
	}

	void Render()
	{
	}

	void Update()
	{
	}

	void Start()
	{
		CreateHook(RPG::GameCore::PVEGameStatistics::BuildPVEStatistics, BuildPVEStatisticsHandler);
	}
}