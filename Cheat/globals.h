#pragma once
#include <windows.h>

extern WNDPROC lpWndProc;

struct OPTIONS
{
	bool bMenu;
	unsigned int dwMenuKey;

	bool bNoclip;
	unsigned int dwNoclipKey;
	float flNoclipSpeed;

	bool bEsp;
	float flEspDistance;
	bool bEspMonster;
	bool bEspNpc;
	bool bEspProp;
	bool bEspMission;

	bool bDumpEnemies;

	bool bPeeking;

	bool bFov;
	float flFov;

	bool bBattleSpeed;
	float flBattleSpeed;

	bool bAutoTalk;
	bool bAutoTalkDisableDelay;

	bool bQuestTeleport;
	unsigned int dwQuestTeleportKey;

	bool bChestTeleport;
	unsigned int dwChestTeleportKey;

	bool bSkipCutscene;

	bool bFpsIndicator;
	int iFpsValue;
};

extern OPTIONS Options;