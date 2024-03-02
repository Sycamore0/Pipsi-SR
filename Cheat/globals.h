#pragma once
#include <windows.h>

#include "imgui_internal.h"

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
	bool bEspTracer;
	float fEspTracerSize;
	bool bEspDebug;
	float fFontSize;
	float flEspDistance;
	bool bEspMonster;
	float vEspMonsterColor[4];
	bool bEspNpc;
	float vEspNpcColor[4];
	bool bEspTrigger;
	float vEspTriggerColor[4];
	bool bEspClosed;
	float vEspClosedColor[4];
	bool bEspCheckPoint;
	float vEspCheckPointColor[4];
	bool bEspEvent;
	float vEspEventColor[4];
	bool bEspChest;
	float vEspChestColor[4];

	bool bDumpEnemies;

	bool bPeeking;

	bool bFov;
	float flFov;

	bool bBattleSpeed;
	bool bBattleSpeedDisableDelay;
	float flBattleSpeed;

	bool bAutoTalk;
	unsigned int dwAutoTalkKey;
	bool bAutoTalkDisableDelay;
	bool bAutoTalkSkipScenes;
	float flAutoTalkSceneSpeed;

	bool bQuestTeleport;
	unsigned int dwQuestTeleportKey;

	bool bChestTeleport;
	unsigned int dwChestTeleportKey;

	bool bSkipCutscene;

	bool bFpsIndicator;
	int iFpsValue;

	bool bUnlockAutoBattle;

	bool bUiHide;

	bool bAutoPuzzle;

	bool bUIDEditor = FALSE;
	char lpUIDEditorText[80] = { "PIPSI-SR" };

	bool bAutoChat;
	bool bAutoChatDisableDelay;
	bool bAutoChatAutoReply;

	OPTIONS() :
		bMenu(FALSE),
		dwMenuKey(VK_INSERT),
		bNoclip(FALSE),
		dwNoclipKey(0),
		flNoclipSpeed(15.f),
		bEsp(FALSE),
		bEspTracer(FALSE),
		fEspTracerSize(2.f),
		bEspDebug(FALSE),
		fFontSize(13.f),
		flEspDistance(25.f),
		bEspMonster(FALSE),
		vEspMonsterColor{ 1.f,1.f,1.f,1.f },
		bEspNpc(FALSE),
		vEspNpcColor{ 1.f,1.f,1.f,1.f },
		bEspTrigger(FALSE),
		vEspTriggerColor{ 1.f,1.f,1.f,1.f },
		bEspClosed(FALSE),
		vEspClosedColor{ 1.f,1.f,1.f,1.f },
		bEspCheckPoint(FALSE),
		vEspCheckPointColor{ 1.f,1.f,1.f,1.f },
		bEspEvent(FALSE),
		vEspEventColor{ 1.f,1.f,1.f,1.f },
		bEspChest(FALSE),
		vEspChestColor{ 1.f,1.f,1.f,1.f },
		bDumpEnemies(FALSE),
		bPeeking(FALSE),
		bFov(FALSE),
		flFov(100.f),
		bBattleSpeed(FALSE),
		bBattleSpeedDisableDelay(FALSE),
		flBattleSpeed(5.f),
		bAutoTalk(FALSE),
		dwAutoTalkKey(FALSE),
		bAutoTalkDisableDelay(FALSE),
		bAutoTalkSkipScenes(FALSE),
		flAutoTalkSceneSpeed(5.f),
		bQuestTeleport(FALSE),
		dwQuestTeleportKey(0),
		bChestTeleport(FALSE),
		dwChestTeleportKey(0),
		bSkipCutscene(FALSE),
		bFpsIndicator(TRUE),
		iFpsValue(60),
		bUnlockAutoBattle(FALSE),
		bUiHide(FALSE),
		bAutoPuzzle(FALSE),
		bUIDEditor(FALSE),
		lpUIDEditorText{ "PIPSI-SR" },
		bAutoChat(FALSE),
		bAutoChatDisableDelay(FALSE),
		bAutoChatAutoReply(FALSE)
	{
	}
};

extern OPTIONS Options;