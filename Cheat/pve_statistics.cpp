#include "pve_statistics.h"

#include "engine.h"
#include "globals.h"
#include "hooks.h"

#include "utils.h"

#include "imgui_internal.h"

namespace PveStatistics
{
	RPG::GameCore::PVEGameStatistics* BuildPVEStatisticsHandler(RPG::GameCore::StatisticsComponent* _this)
	{
		if (_this)
		{
			printf("StatisticsComponent->_turnSkillPerformTime: %f\n", _this->_turnSkillPerformTime);
			printf("StatisticsComponent->_totalSkillPerformTime: %f\n", _this->_totalSkillPerformTime);
		}

		RPG::GameCore::PVEGameStatistics* lpResult = CALL_ORIGIN(BuildPVEStatisticsHandler, _this);

		if (lpResult)
		{
			printf("StatisticsComponent->totalDelayCumulate: %f\n", lpResult->totalDelayCumulate);
			printf("StatisticsComponent->costTime: %f\n", lpResult->costTime);
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
		// CreateHook(RPG::GameCore::StatisticsComponent::BuildPVEStatistics, BuildPVEStatisticsHandler);
	}
}