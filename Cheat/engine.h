#pragma once
#include <windows.h>

#define FN(n, t, p, a) t(*n)p = ((t(*)p)(a))
#define SC(n, a) n* n##Data = (n*)(a)
#define SD(n, t, a) t* n = (t*)(a)

static PBYTE il2cpp_base = (PBYTE)GetModuleHandleA("gameassembly.dll");

inline static SD(MaxTimeScale, float, il2cpp_base + 0x697EF90);

struct Vector3
{
	float x, y, z;

    Vector3& operator+=(const Vector3& other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    Vector3 operator-() const
    {
        return { -x, -y, -z };
    }

    Vector3 operator*(float other) const
    {
        return { x * other, y * other, z * other };
    }
};

namespace System
{
    struct String
    {
        char _[0x10]; // 0x0
        long m_stringLength; // 0x10
        wchar_t m_firstChar[1]; // 0x14

        inline static FN(Create, void*, (const char* str), il2cpp_base + 0x2B27C0);
    };
}

namespace UnityEngine
{
	struct Time
	{
		inline static FN(get_deltaTime, float, (), il2cpp_base + 0x2891420);
		inline static FN(set_timeScale, void, (float value), il2cpp_base + 0x28915B0);
	};

    struct Cursor
    {
        inline static FN(set_visible, void, (bool value), il2cpp_base + 0x24EAB10);

        inline static FN(set_lockState, void, (void* value), il2cpp_base + 0x24EAB00);
    };

	struct Camera
	{
		inline static FN(get_main, void*, (), il2cpp_base + 0x25D0C90);

		inline static FN(set_fieldOfView, void, (void* _this, float value), il2cpp_base + 0x25D11D0);
	};

	struct Transform
	{
		inline static FN(get_up, void, (void* ret, void* _this), il2cpp_base + 0x26F87F0);
		inline static FN(get_forward, void, (void* ret, void* _this), il2cpp_base + 0x26F8460);
		inline static FN(get_position_Injected, void, (void* _this, void* ret), il2cpp_base + 0x26F86D0);

		inline static FN(set_position_Injected, void, (void* _this, void* value), il2cpp_base + 0x26F8B10);
	};

	struct GameObject
	{
		inline static FN(Find, void*, (void* name), il2cpp_base + 0x288E580);

        inline static FN(GetComponentByName, void*, (void* _this, void* type), il2cpp_base + 0x288E590);

		inline static FN(get_transform, void*, (void* _this), il2cpp_base + 0x288ED90);
	};

    struct Animator
    {
        inline static FN(set_speed, void, (void* _this, float value), il2cpp_base + 0x272D950);
    };

    namespace UI
    {
        struct Button
        {
            inline static FN(get_onClick, void*, (void* _this), il2cpp_base + 0x1261260);
            inline static FN(Press, void, (void* _this), il2cpp_base + 0x2879E40);
        };
    }

}

namespace RPG
{
	namespace GameCore
	{
        struct PVEGameStatistics {
            char _[0x10];
            void* battleScoringList; // 0x10
            void* battleAchievementList; // 0x18
            void* battleRaidTargetList; // 0x20
            void* battleChallengeScoreList; // 0x28
            void* battleTargetList; // 0x30
            void* lightTeamStt; // 0x38
            void* lightTeam; // 0x40
            void* lightTeamBattleInfoList; // 0x48
            void* monsterBattleInfoList; // 0x50
            void* battleEventBattleInfoList; // 0x58
            void* customValues; // 0x60
            void* avatarDeathInfos; // 0x68
            void* avatarBPChain; // 0x70
            void* monsterPhaseChangeInfos; // 0x78
            void* statisticEvents; // 0x80
            void* AetherDivideSpiritPropertyInfos; // 0x88
            void* ActionBarEventInfos; // 0x90
            double totalDelayCumulate; // 0x98
            double costTime; // 0xA0
            unsigned long skillUltraCount; // 0xA8
            unsigned long totalBattleRounds; // 0xAC
            unsigned long totalBattleTurns; // 0xB0
            unsigned long totalAutoTurns; // 0xB4
            unsigned long totalAvatarTurns; // 0xB8
            unsigned long totalMonsterTurns; // 0xBC
            unsigned long challengeTurnCount; // 0xC0
            unsigned long CleanWave; // 0xC4
            unsigned long totalScore; // 0xC8
            unsigned long totalSkillPerformTime; // 0xCC
            int battleEndReason; // 0xD0
            int mechanismBarState; // 0xD4

            inline static FN(BuildPVEStatistics, void*, (void* _this), il2cpp_base + 0x3C7DAF0);
        };

		struct GameEntity
		{
            inline static FN(get_UnityGO, void*, (void* _this), il2cpp_base + 0x3EBE430);
		};

		struct AdventureStatic
		{
			inline static FN(GetMainWorld, void*, (), il2cpp_base + 0x390E8C0);

			inline static FN(GetEntityManager, void*, (), il2cpp_base + 0x390D280);

			inline static FN(GetLocalPlayer, void*, (), il2cpp_base + 0x390E580);

			inline static FN(GetLocalPlayerIncludeStoryPlayer, void*, (bool bForceGet), il2cpp_base + 0x390E430);
		};

        struct NPCComponent
        {
            inline static FN(TickAlertValue, void, (void* _this, float fElapsedTimeInSec, void* target, void* detail), il2cpp_base + 0x3C35B00);
        };

		struct AvatarRowData
		{
            inline static FN(get_CriticalChance, __int64, (void* _this), il2cpp_base + 0x3151E30);
		};

		struct MonsterRowData
		{
            inline static FN(get_CriticalChance, __int64, (void* _this), il2cpp_base + 0x4427E70);
		};
	}

	namespace Client
	{
        struct AdventureModule
		{
			inline static FN(OnCmdSceneCastSkillScRsp, void, (unsigned short cmd, void* rspObject), il2cpp_base + 0x37452A0);
		};

		struct TurnBasedGameMode
		{
			inline static FN(get_AutoBattle, bool, (void* _this), il2cpp_base + 0x3F249B0);
		};

		struct BaseShaderPropertyTransition
		{
            inline static FN(SetElevationDitherAlphaValue, void, (void* _this, float EOBOBKJIJFA), il2cpp_base + 0x33602D0);
		};

        struct AdventureWaypointTarget
        {
            inline static FN(GetTargetPos, void*, (void* _this, void* _res), il2cpp_base + 0x3B6B130);
        };
    }
}