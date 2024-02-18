#pragma once
#include <windows.h>

extern WNDPROC lpWndProc;
extern HWND lpWindow;

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
	float flBattleDarkTeamSpeed;
	float flBattleLightTeamSpeed;

	bool bAutoTalk;
	bool bAutoTalkDisableDelay;
	bool bAutoTalkSkipScenes;

	bool bQuestTeleport;
	unsigned int dwQuestTeleportKey;

	bool bChestTeleport;
	unsigned int dwChestTeleportKey;

	bool bSkipCutscene;

	bool bFpsIndicator;
	int iFpsValue;

    OPTIONS() :
        bMenu(FALSE),
        dwMenuKey(VK_INSERT),
        bNoclip(FALSE),
        dwNoclipKey(0),
        flNoclipSpeed(15.f),
        bEsp(FALSE),
        flEspDistance(25.f),
        bEspMonster(FALSE),
        bEspNpc(FALSE),
        bEspProp(FALSE),
        bEspMission(FALSE),
        bDumpEnemies(FALSE),
        bPeeking(FALSE),
        bFov(FALSE),
        flFov(100.f),
        bBattleSpeed(FALSE),
        flBattleDarkTeamSpeed(5.f),
        flBattleLightTeamSpeed(2.f),
        bAutoTalk(FALSE),
        bAutoTalkDisableDelay(FALSE),
        bAutoTalkSkipScenes(FALSE),
        bQuestTeleport(FALSE),
        dwQuestTeleportKey(0),
        bChestTeleport(FALSE),
        dwChestTeleportKey(0),
        bSkipCutscene(FALSE),
        bFpsIndicator(TRUE),
        iFpsValue(60)
    {
    }
};

extern OPTIONS Options;