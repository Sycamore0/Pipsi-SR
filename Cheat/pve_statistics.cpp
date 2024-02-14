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
			printf("Statistics->totalDelayCumulate: %f\n", lpResult->totalDelayCumulate);
			printf("Statistics->costTime: %f\n", lpResult->costTime);

			if (bBattleSpeed && flBattleSpeed > 2.f)
			{
				if (lpResult->totalDelayCumulate > lpResult->costTime)
				{
					lpResult->costTime = lpResult->totalDelayCumulate
						+ fmod((lpResult->totalDelayCumulate + lpResult->costTime) * 2.f, lpResult->totalDelayCumulate * 2.f);
				}
			}
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