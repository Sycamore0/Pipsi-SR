#pragma once
#define GLOBAL_VERSION 1

#include <windows.h>
#include <math.h>

#define FN(n, t, p, a) inline static t(*n)p = ((t(*)p)(a))
#define SD(n, t, a) t* n = (t*)(a)

static PBYTE il2cpp_base = (PBYTE)GetModuleHandleA("gameassembly.dll");

#ifdef GLOBAL_VERSION
#define GLOBALVARS (il2cpp_base + 0x8889A80)
#define GLOBALVARS_UICAMERA_OFFSET 0x1D420
#define GLOBALVARS_UIROOT_OFFSET 0x1D428
#define GLOBALVARS_GAMEPHASEMANAGER_OFFSET 0x1D4B0
#define STRING_NEW (il2cpp_base + 0x25F240)
#define BEHAVIOUR_SET_ENABLED (il2cpp_base + 0x2786280)
#define TIME_GET_DELTATIME (il2cpp_base + 0x2891420)
#define SCREEN_GET_WIDTH (il2cpp_base + 0x25A6D30)
#define SCREEN_GET_HEIGHT (il2cpp_base + 0x25A6C90)
#define CAMERA_GET_MAIN (il2cpp_base + 0x25D0C90)
#define CAMERA_GET_PIXELWIDTH (il2cpp_base + 0x25D0D90)
#define CAMERA_GET_PIXELHEIGHT (il2cpp_base + 0x25D0D40)
#define CAMERA_SETFIELD_OFVIEW (il2cpp_base + 0x25D11D0)
#define CAMERA_WORLDTOSCREENPOINT (il2cpp_base + 0x25D0850)
#define TRANSFORM_GET_UP (il2cpp_base + 0x26F87F0)
#define TRANSFORM_GET_FORWARD (il2cpp_base + 0x26F8460)
#define TRANSFORM_GET_POSITION_INJECTED (il2cpp_base + 0x26F86D0)
#define TRANSFORM_SET_POSITION_INJECTED (il2cpp_base + 0x26F8B10)
#define GAMEOBJECT_FIND (il2cpp_base + 0x288E580)
#define GAMEOBJECT_GET_TRANSFORM (il2cpp_base + 0x288ED90)
#define GAMEOBJECT_GET_SET_ACTIVE (il2cpp_base + 0x288EDA0)
#define ANIMATOR_SET_SPEED (il2cpp_base + 0x272D950)
#define GAMEENTITY_GET_UNITYGO (il2cpp_base + 0x3EBE430)
#define ENTITYMANAGER_GET_OWNERWORLDREF (il2cpp_base + 0x391C080)
#define ADVENTURESTATIC_GETENTITYMANAGER (il2cpp_base + 0x390D280)
#define ADVENTURESTATIC_GETPROPMANAGER (il2cpp_base + 0x390FFA0)
#define ADVENTURESTATIC_GETLOCALPLAYER (il2cpp_base + 0x390E580)
#define NPCCOMPONENT_TICKALERTVALUE (il2cpp_base + 0x3C35B00)
#define PROPCOMPONENT_TICK (il2cpp_base + 0x3E824E0)
#define PROPCOMPONENT_GET_OWNERENTITY (il2cpp_base + 0xE03D30)
#define PROPCOMPONENT_GET_PROPSTATE (il2cpp_base + 0x3E85EB0)
#define GAMEPHASEMANAGER_GET_CURRENTGAMEPHASETYPE (il2cpp_base + 0xC55540)
#define BASESHADERPROPERTYTRANSITION_SETELEVATIONDITHERALPHAVALUE (il2cpp_base + 0x33602D0)
#define ADVENTUREWAYPOINTTARGET_GETTARGETPOS (il2cpp_base + 0x3B6B130)
#define LUA_PUSHNUMBER (il2cpp_base + 0x1B9B1A0)
#define RPGGAMECORESIMPLETALKINFOWRAP__G_GET_FORCETONEXTTIME (il2cpp_base + 0x55B7A90)
#define RPGGAMECORESIMPLETALKINFOWRAP__G_GET_PROTECTTIME (il2cpp_base + 0x55B7B70)
#define APPLICATION_SET_TARGETFRAMERATE (il2cpp_base + 0x28800B0)
#define PLAYABLEGRAPH_ISPLAYING_INJECTED (il2cpp_base + 0x288F150)
#define PLAYABLEGRAPH_ISDONE_INJECTED (il2cpp_base + 0x288F140)
#define MANAVIDEOPAGECONTEXT__ONTICK (il2cpp_base + 0x38EA6F0)
#define GAMEENTITY_GET_TEAM (il2cpp_base + 0x3EBE250)
#define BATTLEINSTANCE_GET_TURNBASEDGAMEMODEREF (il2cpp_base + 0x35F3770)
#define BATTLEINSTANCE_ISSTAGEFORBIDAUTOBATTLE (il2cpp_base + 0x35F22F0)
#define TURNBASEDGAMEMODE_GETCURRENTURNACTIONENTITY (il2cpp_base + 0x3F13620)
#else
#define GLOBALVARS (il2cpp_base + 0x88711C0)
#define GLOBALVARS_UICAMERA_OFFSET 0x1D420
#define GLOBALVARS_UIROOT_OFFSET 0x1D428
#define GLOBALVARS_GAMEPHASEMANAGER_OFFSET 0x1D4B0
#define STRING_NEW (il2cpp_base + 0x2272C0)
#define BEHAVIOUR_SET_ENABLED (il2cpp_base + 0x2665760)
#define TIME_GET_DELTATIME (il2cpp_base + 0x2770900)
#define SCREEN_GET_WIDTH (il2cpp_base + 0x24861C0)
#define SCREEN_GET_HEIGHT (il2cpp_base + 0x2486120)
#define CAMERA_GET_MAIN (il2cpp_base + 0x24B0120)
#define CAMERA_GET_PIXELWIDTH (il2cpp_base + 0x24B0220)
#define CAMERA_GET_PIXELHEIGHT (il2cpp_base + 0x24B01D0)
#define CAMERA_SETFIELD_OFVIEW (il2cpp_base + 0x24B0660)
#define CAMERA_WORLDTOSCREENPOINT (il2cpp_base + 0x24AFCE0)
#define TRANSFORM_GET_UP (il2cpp_base + 0x25D7CD0)
#define TRANSFORM_GET_FORWARD (il2cpp_base + 0x25D7940)
#define TRANSFORM_GET_POSITION_INJECTED (il2cpp_base + 0x25D7BB0)
#define TRANSFORM_SET_POSITION_INJECTED (il2cpp_base + 0x25D7FF0)
#define GAMEOBJECT_FIND (il2cpp_base + 0x276DA60)
#define GAMEOBJECT_GET_TRANSFORM (il2cpp_base + 0x276E270)
#define GAMEOBJECT_GET_SET_ACTIVE (il2cpp_base + 0x276E280)
#define ANIMATOR_SET_SPEED (il2cpp_base + 0x260CE30)
#define GAMEENTITY_GET_UNITYGO (il2cpp_base + 0x3B84960)
#define ENTITYMANAGER_GET_OWNERWORLDREF (il2cpp_base + 0x3878DE0)
#define ADVENTURESTATIC_GETENTITYMANAGER (il2cpp_base + 0x3869FE0)
#define ADVENTURESTATIC_GETPROPMANAGER (il2cpp_base + 0x386CD00)
#define ADVENTURESTATIC_GETLOCALPLAYER (il2cpp_base + 0x386B2E0)
#define NPCCOMPONENT_TICKALERTVALUE (il2cpp_base + 0x3C09030)
#define PROPCOMPONENT_TICK (il2cpp_base + 0x3D9FEA0)
#define PROPCOMPONENT_GET_OWNERENTITY (il2cpp_base + 0xD9B660)
#define PROPCOMPONENT_GET_PROPSTATE (il2cpp_base + 0x3DA3870)
#define GAMEPHASEMANAGER_GET_CURRENTGAMEPHASETYPE (il2cpp_base + 0xB815C0)
#define BASESHADERPROPERTYTRANSITION_SETELEVATIONDITHERALPHAVALUE (il2cpp_base + 0x3303E90)
#define ADVENTUREWAYPOINTTARGET_GETTARGETPOS (il2cpp_base + 0x3B09E90)
#define LUA_PUSHNUMBER (il2cpp_base + 0x1AB1970)
#define RPGGAMECORESIMPLETALKINFOWRAP__G_GET_FORCETONEXTTIME (il2cpp_base + 0x5529550)
#define RPGGAMECORESIMPLETALKINFOWRAP__G_GET_PROTECTTIME (il2cpp_base + 0x5529630)
#define APPLICATION_SET_TARGETFRAMERATE (il2cpp_base + 0x275F590)
#define PLAYABLEGRAPH_ISPLAYING_INJECTED (il2cpp_base + 0x276E630)
#define PLAYABLEGRAPH_ISDONE_INJECTED (il2cpp_base + 0x276E620)
#define MANAVIDEOPAGECONTEXT__ONTICK (il2cpp_base + 0x37C15E0)
#define GAMEENTITY_GET_TEAM (il2cpp_base + 0x3B84780)
#define BATTLEINSTANCE_GET_TURNBASEDGAMEMODEREF (il2cpp_base + 0x34C88D0)
#define BATTLEINSTANCE_ISSTAGEFORBIDAUTOBATTLE (il2cpp_base + 0x34C7450)
#define TURNBASEDGAMEMODE_GETCURRENTURNACTIONENTITY (il2cpp_base + 0x3F33DA0)
#endif

inline static SD(lpGlobalVars, void**, GLOBALVARS);

struct Vector2
{
	float x, y;
};

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

	float Distance(const Vector3& other) const
	{
		float dx = x - other.x;
		float dy = y - other.y;
		float dz = z - other.z;
		return sqrtf(dx * dx + dy * dy + dz * dz);
	}
};

namespace System
{
	struct String {
		char _[0x10]; // 0x0
		long m_stringLength; // 0x10
		const unsigned short m_firstChar[1]; // 0x14

		FN(New, System::String*, (const char* str), STRING_NEW);
	};

	namespace Collections
	{
		namespace Generic
		{
			struct Array {
				void* klass; // 0x0
				void* monitor; // 0x0
				void* bounds; // 0x0
				size_t max_length; // 0x0
				void* vector[32]; // 0x0
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
	struct Behaviour {
		FN(set_enabled, void, (void* _this, bool value), il2cpp_base + 0x2786280);
	};

	struct Time {
		FN(get_deltaTime, float, (), TIME_GET_DELTATIME);
	};

	struct Screen {
		FN(get_width, long, (), SCREEN_GET_WIDTH);
		FN(get_height, long, (), SCREEN_GET_HEIGHT);
	};

	struct Camera {
		FN(get_main, void*, (), CAMERA_GET_MAIN);
		FN(get_pixelWidth, long, (void* _this), CAMERA_GET_PIXELWIDTH);
		FN(get_pixelHeight, long, (void* _this), CAMERA_GET_PIXELHEIGHT);

		FN(set_fieldOfView, void, (void* _this, float value), CAMERA_SETFIELD_OFVIEW);

		FN(WorldToScreenPoint, void*, (void* ret, void* _this, void* position), CAMERA_WORLDTOSCREENPOINT);
	};

	struct Transform {
		FN(get_up, void, (void* ret, void* _this), TRANSFORM_GET_UP);
		FN(get_forward, void, (void* ret, void* _this), TRANSFORM_GET_FORWARD);
		FN(get_position_Injected, void, (void* _this, void* ret), TRANSFORM_GET_POSITION_INJECTED);

		FN(set_position_Injected, void, (void* _this, void* value), TRANSFORM_SET_POSITION_INJECTED);
	};

	struct GameObject {
		char _[0x10]; // 0x0
		void* m_CachedPtr; // 0x10

		FN(Find, UnityEngine::GameObject*, (void* name), GAMEOBJECT_FIND);

		FN(get_transform, void*, (void* _this), GAMEOBJECT_GET_TRANSFORM);
	};

	struct Animator {
		FN(set_speed, void, (void* _this, float value), ANIMATOR_SET_SPEED);
	};

	struct Application {
		FN(set_targetFrameRate, void, (int value), APPLICATION_SET_TARGETFRAMERATE);
	};

	namespace Playables
	{
		struct PlayableGraph {
			FN(IsPlaying_Injected, bool, (void* _unity_self), PLAYABLEGRAPH_ISPLAYING_INJECTED);
			FN(IsDone_Injected, bool, (void* _unity_self), PLAYABLEGRAPH_ISDONE_INJECTED);
		};
	}
}

namespace RPG
{
	namespace GameCore
	{
		enum TeamType {
			TeamType_TeamUnknow = 0x0,
			TeamType_TeamLight = 0x1,
			TeamType_TeamDark = 0x2,
			TeamType_TeamNeutral = 0x3,
			TeamType_TeamNPC = 0x4,
			TeamType_Count = 0x5,
		};

		enum EntityType {
			EntityType_None = 0x0,
			EntityType_Avatar = 0x1,
			EntityType_Monster = 0x2,
			EntityType_LocalPlayer = 0x3,
			EntityType_NPC = 0x4,
			EntityType_NPCMonster = 0x5,
			EntityType_StoryCharacter = 0x6,
			EntityType_Prop = 0x7,
			EntityType_Mission = 0x8,
			EntityType_LevelEntity = 0x9,
			EntityType_Neutral = 0xA,
			EntityType_AtmoNpc = 0xB,
			EntityType_BattleEvent = 0xC,
			EntityType_TutorialEntity = 0xD,
			EntityType_Team = 0xE,
			EntityType_Partner = 0xF,
			EntityType_LevelGraph = 0x10,
			EntityType_Snapshot = 0x11,
			EntityType_TeamFormation = 0x12,
			EntityType_Model = 0x13,
			EntityType_UICamera = 0x14,
			EntityType_District = 0x15,
			EntityType_GlobalShield = 0x16,
			EntityType_CustomData = 0x17,
			EntityType_Simple = 0x18,
			EntityType_PuzzleGameObjectProp = 0x19,
			EntityType_PerformanceLevelGraph = 0x1A,
			EntityType_Group = 0x1B,
			EntityType_ChessCharacter = 0x1C,
			EntityType_ChessTerrain = 0x1D,
			EntityType_SummonUnit = 0x1E,
		};

		enum PropState {
			PropState_Closed = 0x0,
			PropState_Open = 0x1,
			PropState_Locked = 0x2,
			PropState_BridgeState1 = 0x3,
			PropState_BridgeState2 = 0x4,
			PropState_BridgeState3 = 0x5,
			PropState_BridgeState4 = 0x6,
			PropState_CheckPointDisable = 0x7, // closed exits teleport etc
			PropState_CheckPointEnable = 0x8, // opened exits teleport etc
			PropState_TriggerDisable = 0x9,
			PropState_TriggerEnable = 0xA,
			PropState_ChestLocked = 0xB,
			PropState_ChestClosed = 0xC,
			PropState_ChestUsed = 0xD,
			PropState_Elevator1 = 0xE,
			PropState_Elevator2 = 0xF,
			PropState_Elevator3 = 0x10,
			PropState_WaitActive = 0x11,
			PropState_EventClose = 0x12, // paper items etc
			PropState_EventOpen = 0x13,
			PropState_Hidden = 0x14,
			PropState_TeleportGate0 = 0x15,
			PropState_TeleportGate1 = 0x16,
			PropState_TeleportGate2 = 0x17,
			PropState_TeleportGate3 = 0x18,
			PropState_Destructed = 0x19,
			PropState_CustomState01 = 0x65,
			PropState_CustomState02 = 0x66,
			PropState_CustomState03 = 0x67,
			PropState_CustomState04 = 0x68,
			PropState_CustomState05 = 0x69,
			PropState_CustomState06 = 0x6A,
			PropState_CustomState07 = 0x6B,
			PropState_CustomState08 = 0x6C,
			PropState_CustomState09 = 0x6D,
		};

		struct GameEntity {
			char _[0x10]; // 0x0
			void* TickLodTemplate; // 0x10
			void* _TickLodProxy; // 0x18
			System::String* Name; // 0x20
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
			int EntityType; // 0xD8
			int _CampID; // 0xDC
			int _ObjectFeature; // 0xE0
			int _AliveState; // 0xE4
			int _Team; // 0xE8
			unsigned long _ServerEntityID; // 0xEC
			unsigned long _GroupID; // 0xF0
			unsigned long _GroupEntityID; // 0xF4
			bool Tickable; // 0xF8
			bool IsLoaded; // 0xF9
			bool ForceIgnoreTickLod; // 0xFA
			bool ShouldLateUpdate; // 0xFB
			bool HasDisposed; // 0xFC
			bool Disposing; // 0xFD
			bool _IsStoryMode; // 0xFE
			bool KillImmediately; // 0xFF
			bool IsHero; // 0x100
			bool IsFakeAvatar; // 0x101
			bool Visible; // 0x102
			bool IsOnStage; // 0x103

			FN(get_UnityGO, void*, (void* _this), GAMEENTITY_GET_UNITYGO);
			FN(get_Team, int, (void* _this), GAMEENTITY_GET_TEAM);
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
			System::Collections::Generic::List* EntityList; // 0x90
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
		};

		struct EntityManager {
			FN(get_OwnerWorldRef, RPG::GameCore::GameWorld*, (void* _this), ENTITYMANAGER_GET_OWNERWORLDREF);
		};

		struct PropManager {
			char _[0x10]; // 0x0
			System::Collections::Generic::List* PropEntityList; // 0x10
			void* BNNLPNNKOPA; // 0x18
			void* DIFDPHNFOMB; // 0x20
			void* BHCDIDNBIEO; // 0x28
			void* ILKJAAEMHDD; // 0x30
			System::Collections::Generic::List* MapPropList; // 0x38
			void* PDINLCMCJPE; // 0x40
		};
		
		struct AdventureStatic {
			FN(GetEntityManager, void*, (), ADVENTURESTATIC_GETENTITYMANAGER);

			FN(GetPropManager, RPG::GameCore::PropManager*, (), ADVENTURESTATIC_GETPROPMANAGER);

			FN(GetLocalPlayer, void*, (), ADVENTURESTATIC_GETLOCALPLAYER);
		};

		struct NPCComponent {
			FN(TickAlertValue, void, (void* _this, float fElapsedTimeInSec, void* target, void* detail), NPCCOMPONENT_TICKALERTVALUE);
		};
		
		struct PropComponent {
			FN(Tick, void, (void* _this, float fElapsedTimeInSec), PROPCOMPONENT_TICK);

			FN(get_OwnerEntity, void*, (void* _this), PROPCOMPONENT_GET_OWNERENTITY);
			FN(get_PropState, int, (void* _this), PROPCOMPONENT_GET_PROPSTATE);
		};

		struct TurnBasedGameMode {
			FN(GetCurrenTurnActionEntity, void*, (void* _this), TURNBASEDGAMEMODE_GETCURRENTURNACTIONENTITY);
		};
		
		struct BattleInstance {
			FN(get_TurnBasedGameModeRef, RPG::GameCore::TurnBasedGameMode*, (void* _this), BATTLEINSTANCE_GET_TURNBASEDGAMEMODEREF);
			FN(IsStageForbidAutoBattle, bool, (void* _this), BATTLEINSTANCE_ISSTAGEFORBIDAUTOBATTLE);
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

		struct GamePhaseManager {
			FN(get_CurrentGamePhaseType, int, (void* _this), GAMEPHASEMANAGER_GET_CURRENTGAMEPHASETYPE);
		};

		struct BaseShaderPropertyTransition {
			FN(SetElevationDitherAlphaValue, void, (void* _this, float EOBOBKJIJFA), BASESHADERPROPERTYTRANSITION_SETELEVATIONDITHERALPHAVALUE);
		};

		struct AdventureWaypointTarget {
			FN(GetTargetPos, void*, (void* _this, void* _res), ADVENTUREWAYPOINTTARGET_GETTARGETPOS);
		};

		struct ManaVideoPageContext {
			char _[0x138]; // 0x0
			void* _captionConfig; // 0x138
			void* _videoFullPath; // 0x140
			void* _skilDialog; // 0x148
			void* _movieControllerForUI; // 0x150
			void* _ActiveCaptionConfig; // 0x158
			unsigned long long _videoKey; // 0x160
			long _controllerRuntimeID; // 0x168
			unsigned long _videoID; // 0x16C
			float _lastVideoTime; // 0x170
			float _maskTimer; // 0x174
			int _videoStep; // 0x178
			int _lastPlayerStatus; // 0x17C
			unsigned long _blockUID; // 0x180
			float _EndBlackBeforeTime; // 0x184
			void* _maskColor; // 0x188
			char __[0x8]; // 0x190
			bool _hasCaption; // 0x198
			bool _canSkip; // 0x199
			bool _isLoop; // 0x19A
			bool _isVideoPlaying; // 0x19B
			bool _isMasking; // 0x19C
			bool _isSkipBtnShow; // 0x19D
			bool _isCG; // 0x19E
			bool _HasSend_VideoNearlyEnd; // 0x19F

			FN(_OnTick, void, (RPG::Client::ManaVideoPageContext* _this, float deltaSecond), MANAVIDEOPAGECONTEXT__ONTICK);
		};
	}
}

namespace XLua
{
	namespace LuaDLL
	{
		namespace Lua
		{
			struct lua {
				FN(pushnumber, void, (__int64 L, double number), LUA_PUSHNUMBER);
			};
		}
	}

	namespace CSObjectWrap
	{
		struct RPGGameCoreSimpleTalkInfoWrap {
			FN(_g_get_ForceToNextTime, long, (__int64 L), RPGGAMECORESIMPLETALKINFOWRAP__G_GET_FORCETONEXTTIME);
			FN(_g_get_ProtectTime, long, (__int64 L), RPGGAMECORESIMPLETALKINFOWRAP__G_GET_PROTECTTIME);
		};
	}
}

namespace Engine
{
	System::Collections::Generic::List* GetWorldEntityList();
	System::Collections::Generic::List* GetMapPropList();
	System::Collections::Generic::List* GetPropEntityList();

	void* GetTurnBasedGameMode();

	bool GetResolutionScale(Vector2* lpResolution, Vector2* lpResolutionScale);
	bool GetScreenPosition(Vector2* lpResolutionScale, void* lpWorldPosition, Vector3* lpRet);

	bool GetEntityPosition(void* lpEntity, void* lpPosition);
	int GetPhaseType();

	void* GetUICamera();
	void* GetUIRoot();

	void* GetTransform(void* lpEntity);

	void PlayerTeleport(void* lpPosition);
}