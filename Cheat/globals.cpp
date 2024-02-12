#include "globals.h"

WNDPROC lpWndProc = NULL;

bool bMenu = FALSE;
unsigned int dwMenuKey = VK_INSERT;

bool bNoclip = FALSE;
unsigned int dwNoclipKey = 0;
float flNoclipSpeed = 1.f;

bool bEsp = FALSE;

bool bForceAutoBattle = FALSE;

bool bDumpEnemies = FALSE;

bool bPeeking = FALSE;

bool bFov = FALSE;
float flFov = 100.f;

bool bBattleSpeed = FALSE;
float flBattleSpeed = 2.f;

bool bAutoTalk = FALSE;
float flAutoTalkSpeed = 2.f;

bool bQuestTeleport = FALSE;
unsigned int dwQuestTeleportKey = 0;

bool bCriticalChance = FALSE;

bool bChestTeleport = FALSE;
unsigned int dwChestTeleportKey = 0;
