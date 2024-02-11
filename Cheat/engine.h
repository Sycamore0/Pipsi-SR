#pragma once
#include <windows.h>
#include <math.h>

#define FN(n, t, p, a) t(*n)p = ((t(*)p)(a))
#define SC(n, a) n* n##Data = (n*)(a)
#define SD(n, t, a) t* n = (t*)(a)

static PBYTE il2cpp_base = (PBYTE)GetModuleHandleA("gameassembly.dll");

inline static SD(lpMaxTimeScale, float, il2cpp_base + 0x697EF90);
inline static SD(lpGlobalVars, void**, il2cpp_base + 0x8889A80);

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

    float distance(const Vector3& other) const
    {
        float dx = x - other.x;
        float dy = y - other.y;
        float dz = z - other.z;
        return sqrtf(dx * dx + dy * dy + dz * dz);
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

    namespace Collections
    {
        namespace Generic
        {
            struct Array
            {
                void* klass;
                void* monitor;
                void* bounds;
                size_t max_length;
                void* vector[32];
            };

            struct List {
                char _[0x10]; // 0x0
                Array* items; // 0x0
                long size; // 0x0
                long version; // 0x0
                void* syncRoot; // 0x0
            };

        }
    }
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
            char _[0x10]; // 0x0
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
            char _[0x10]; // 0x0
            void* TickLodTemplate; // 0x10
            void* _TickLodProxy; // 0x18
            System::String* _Name; // 0x20
            void* OnStageStateChange; // 0x28
            void* OnTeamChange; // 0x30
            void* TimeScaleStack; // 0x38
            void* HoyoTagContainer; // 0x40
            void* DisposeCallback; // 0x48
            void* _OwnerWorldRef; // 0x50
            void* _ComponentList; // 0x58
            void* _TickComponentList; // 0x60
            void* _LateUpdateComponentList; // 0x68
            void* _ComponentArrayRef; // 0x70
            void* _ComponentArray; // 0x78
            void* _UnstageReasonKey; // 0x80
            void* _DestroyWaitList; // 0x88
            void* _UnityGO; // 0x90
            void* _ComponentDelayedTickDataList; // 0x98
            void* _ComponentDelayedLateUpdateDataList; // 0xA0
            void* _CurTickListRef; // 0xA8
            char __[0x8]; // 0xB0
            unsigned long long _LastTickFrame; // 0xB8
            float _LastTickTime; // 0xC0
            float _TickLodBoundSize; // 0xC4
            float _MaxTickDistance; // 0xC8
            unsigned long ForceIgnoreTickLodBistSet; // 0xCC
            unsigned long _TickDelayFrameCount; // 0xD0
            unsigned long _RuntimeID; // 0xD4
            int _EntityType; // 0xD8
            int _CampID; // 0xDC
            int _ObjectFeature; // 0xE0
            int _AliveState; // 0xE4
            int _Team; // 0xE8
            unsigned long _ServerEntityID; // 0xEC
            unsigned long _GroupID; // 0xF0
            unsigned long _GroupEntityID; // 0xF4
            bool _Tickable; // 0xF8
            bool _IsLoaded; // 0xF9
            bool _ForceIgnoreTickLod; // 0xFA
            bool _ShouldLateUpdate; // 0xFB
            bool HasDisposed; // 0xFC
            bool Disposing; // 0xFD
            bool _IsStoryMode; // 0xFE
            bool KillImmediately; // 0xFF
            bool _IsHero; // 0x100
            bool _IsFakeAvatar; // 0x101
            bool _Visible; // 0x102
            bool _IsOnStage; // 0x103

            inline static FN(get_UnityGO, void*, (void* _this), il2cpp_base + 0x3EBE430);
		};

        struct GameWorld {
            char _[0x10]; // 0x0
            void* _EntityTickList; // 0x10
            void* _TickedEntityListPerFrame; // 0x18
            void* _GlobalTimeScaleDatas; // 0x20
            void* _BattleInstanceRef; // 0x28
            void* _BattleModeRef; // 0x30
            void* LogicRandom; // 0x38
            void* _ParamRegister; // 0x40
            void* NewEntityCallback; // 0x48
            void* EntityBeforeDyingCallback; // 0x50
            void* EntityDiedCallback; // 0x58
            void* EntityReviveCallback; // 0x60
            void* EntityWillDestroyCallback; // 0x68
            void* MonoEffectManagerRef; // 0x70
            void* _TimeScaleStack; // 0x78
            void* _EntityManager; // 0x80
            void* _EventManager; // 0x88
            System::Collections::Generic::List* _EntityList; // 0x90
            void* _DyingEntityList; // 0x98
            void* _DeferDeleteEntityList; // 0xA0
            void* _EnterDyingEntityList; // 0xA8
            void* _LevelAreaManager; // 0xB0
            void* _PrefabGameObjectMap; // 0xB8
            void* _Modules; // 0xC0
            void* _NeedTickModules; // 0xC8
            void* _NeedLateUpdateModules; // 0xD0
            float _BalanceTickDurationTime; // 0xD8
            float _UnscaledDeltaTime; // 0xDC
            unsigned long _IDFactory; // 0xE0
            unsigned long _IDFactory_ClientOnly; // 0xE4
            unsigned long _IDFactory_Battle; // 0xE8
            long _NextTickDeferDeleteCount; // 0xEC
            bool _IsBattleGameWorld; // 0xF0
            bool _IsPause; // 0xF1
            bool _IsInTick; // 0xF2
            bool _IsDisposing; // 0xF3

            inline static FN(get_BattleInstanceRef, void*, (void* _this), il2cpp_base + 0xC1C400);
        };

        struct EntityManager {
            inline static FN(get_OwnerWorldRef, RPG::GameCore::GameWorld*, (void* _this), il2cpp_base + 0x391C080);
        };
        

        struct BattleInstance
        {
            inline static FN(get_TurnBasedGameModeRef, void*, (void* _this), il2cpp_base + 0x35F3770);
        };

		struct AdventureStatic
		{
			inline static FN(GetMainWorld, RPG::GameCore::GameWorld*, (), il2cpp_base + 0x390E8C0);

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
        enum GamePhaseType {
            GamePhaseType_Unknow = 0x0,
            GamePhaseType_ClientStartup = 0x1,
            GamePhaseType_DevClientStartup = 0x2,
            GamePhaseType_GameDev = 0x3,
            GamePhaseType_VersionUpdate = 0x4,
            GamePhaseType_EnterGame = 0x5,
            GamePhaseType_InitGame = 0x6,
            GamePhaseType_SelectServer = 0x7,
            GamePhaseType_SDKLogin = 0x8,
            GamePhaseType_LoginWait = 0x9,
            GamePhaseType_FullPackageDownload = 0xA,
            GamePhaseType_PreDownload = 0xB,
            GamePhaseType_VersionUpdateCheck = 0xC,
            GamePhaseType_Adventure = 0xD,
            GamePhaseType_BattleLineup = 0xE,
            GamePhaseType_QABattleLineup = 0xF,
            GamePhaseType_Battle = 0x10,
            GamePhaseType_BattleNew = 0x11,
            GamePhaseType_Replay = 0x12,
            GamePhaseType_DevLevel = 0x13,
            GamePhaseType_RenderTest = 0x14,
            GamePhaseType_StoryTest = 0x15,
            GamePhaseType_AdventureMapTest = 0x16,
            GamePhaseType_AssetMemStatisticsTest = 0x17,
            GamePhaseType_Empty = 0x18,
        };

        struct GamePhaseManager
        {
            inline static FN(get_CurrentGamePhaseType, int, (void* _this), il2cpp_base + 0xC55540);
        };

        struct AdventureModule
		{
			inline static FN(OnCmdSceneCastSkillScRsp, void, (unsigned short cmd, void* rspObject), il2cpp_base + 0x37452A0);
		};

		struct TurnBasedGameMode
		{
            inline static FN(get_IsInBattle, bool, (void* _this), il2cpp_base + 0x3F24D20);

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

namespace Engine
{
    bool GetEntityPosition(void* lpEntity, void* lpPosition);
    int GetPhaseType();

    void PlayerTeleport(void* lpPosition);
    
}