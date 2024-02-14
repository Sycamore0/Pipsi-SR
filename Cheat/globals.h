#pragma once
#include <windows.h>

extern WNDPROC lpWndProc;

extern bool bMenu;
extern unsigned int dwMenuKey;

extern bool bNoclip;
extern unsigned int dwNoclipKey;
extern float flNoclipSpeed;

extern bool bEsp;
extern float flEspDistance;
extern bool bEspMonster;
extern bool bEspNpc;
extern bool bEspProp;
extern bool bEspMission;

extern bool bForceAutoBattle;

extern bool bDumpEnemies;

extern bool bPeeking;

extern bool bFov;
extern float flFov;

extern bool bBattleSpeed;
extern float flBattleSpeed;

extern bool bAutoTalk;
extern bool bAutoTalkDisableDelay;

extern bool bQuestTeleport;
extern unsigned int dwQuestTeleportKey;

extern bool bCriticalChance;

extern bool bChestTeleport;
extern unsigned int dwChestTeleportKey;

extern bool bSkipCutscene;