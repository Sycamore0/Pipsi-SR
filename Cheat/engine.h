#pragma once
#define GLOBAL_VERSION 1

#include <windows.h>
#include <math.h>

#define FN(n, t, p, a) inline static t(*n)p = ((t(*)p)(a))
#define SD(n, t, a) t* n = (t*)(a)

static PBYTE il2cpp_base = (PBYTE)GetModuleHandleA("gameassembly.dll");

#define GLOBALVARS_UICAMERA_OFFSET 0x1D420
#define GLOBALVARS_BETAHINTDIALOGCONTEXT_OFFSET 0x1D630
#define GLOBALVARS_GAMEPHASEMANAGER_OFFSET 0x1D4B0
#define GLOBALVARS_MODULEMANAGER_OFFSET 0x1D550

#ifdef GLOBAL_VERSION
#define GLOBALVARS (il2cpp_base + 0x8889A80)
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
#define OPTICALILLUSIONPUZZLEBOARD_UPDATE (il2cpp_base + 0x3862E90)
#define OPTICALILLUSIONPUZZLEBOARD_MELEDIOAKMC (il2cpp_base + 0x385EA40)
#define CABLEPUZZLEBOARD_LADNBFDOAMJ (il2cpp_base + 0x3E314A0)
#define RUBIKCUBEPUZZLECUBE_ONROTATEFINISH (il2cpp_base + 0x38BEDB0)
#define ROTATEPILLARPUZZLEFRAGMENT_GET_ISCOMPLETE (il2cpp_base + 0x3E10A00)
#define INSERTIONPUZZLEITEM_ISMATCHITEM (il2cpp_base + 0x3BECFA0)
#define JIGSAWPUZZLEBOARD__CHECKISGAMEFINISH (il2cpp_base + 0x3AD81E0)
#define GAMEPLAYLOCKMODULE_LOCK (il2cpp_base + 0x35487C0)
#define LOCALIZEDTEXT_SET_TEXT (il2cpp_base + 0x38A2470)
#define BETAHINTDIALOGCONTEXT_CFNOBNMKNCA (il2cpp_base + 0x2E79DA0)
#define MESSAGEUTILS_GETWRITINGTIME (il2cpp_base + 0x3D0F4F0)
#define MESSAGESECTIONDATA_GET_WAITINGITEMIDS (il2cpp_base + 0x3999A70)
#define MESSAGEMODULE_FINISHITEMBYCHOICE (il2cpp_base + 0x3334840)
#else
#define GLOBALVARS (il2cpp_base + 0x88711C0)
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
#define OPTICALILLUSIONPUZZLEBOARD_UPDATE (il2cpp_base + 0x373C060)
#define OPTICALILLUSIONPUZZLEBOARD_MELEDIOAKMC (il2cpp_base + 0x3737C10)
#define CABLEPUZZLEBOARD_LADNBFDOAMJ (il2cpp_base + 0x3D4EE60)
#define RUBIKCUBEPUZZLECUBE_ONROTATEFINISH (il2cpp_base + 0x385FF50) // Prop_RubikCubePuzzleCube_OnRotateFinish
#define ROTATEPILLARPUZZLEFRAGMENT_GET_ISCOMPLETE (il2cpp_base + 0x3A12A50)
#define INSERTIONPUZZLEITEM_ISMATCHITEM (il2cpp_base + 0x3AC03C0)
#define JIGSAWPUZZLEBOARD__CHECKISGAMEFINISH (il2cpp_base + 0x39B2980)
#define GAMEPLAYLOCKMODULE_LOCK (il2cpp_base + 0x339DEB0)
#define LOCALIZEDTEXT_SET_TEXT (il2cpp_base + 0x3843610)
#define BETAHINTDIALOGCONTEXT_CFNOBNMKNCA (il2cpp_base + 0x2D55590) // IEGAIDEBOIA_CFNOBNMKNCA
#define MESSAGEUTILS_GETWRITINGTIME (il2cpp_base + 0x3C6B960)
#define MESSAGESECTIONDATA_GET_WAITINGITEMIDS (il2cpp_base + 0x37EAEC0)
#define MESSAGEMODULE_FINISHITEMBYCHOICE (il2cpp_base + 0x3781710)
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

namespace Base
{
	struct Class
	{
		char _[0x10];
		char* name;
		char __[0x90];
		unsigned long id;
	};

	struct Actor
	{
		Base::Class* klass;
		void* monitor;
	};
}

namespace System
{
	struct String {
		char _[0x10]; // 0x0
		long m_stringLength; // 0x10
		unsigned short m_firstChar[1]; // 0x14

		FN(New, System::String*, (const char* str), STRING_NEW);
	};

	namespace Collections
	{
		namespace Generic
		{
			template<typename T>
			struct Array {
				void* klass; // 0x0
				void* monitor; // 0x8
				void* bounds; // 0x10
				size_t max_length; // 0x18
				T vector[32]; // 0x20
			};

			template<typename A>
			struct List {
				char _[0x10]; // 0x0
				Array<A>* items; // 0x10
				long size; // 0x18
				long version; // 0x1C
				void* syncRoot; // 0x20
			};

		}
	}
}

namespace UnityEngine
{
	struct Behaviour {
		FN(set_enabled, void, (void* _this, bool value), BEHAVIOUR_SET_ENABLED);
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

	struct Object {
		char _[0x10]; // 0x0
		void* m_CachedPtr; // 0x10
	};

	struct Transform : Object {
		FN(get_up, void, (void* ret, void* _this), TRANSFORM_GET_UP);
		FN(get_forward, void, (void* ret, void* _this), TRANSFORM_GET_FORWARD);
		FN(get_position_Injected, void, (void* _this, void* ret), TRANSFORM_GET_POSITION_INJECTED);

		FN(set_position_Injected, void, (void* _this, void* value), TRANSFORM_SET_POSITION_INJECTED);
	};

	struct GameObject : Object {
		FN(get_transform, void*, (void* _this), GAMEOBJECT_GET_TRANSFORM);

		FN(Find, UnityEngine::GameObject*, (void* name), GAMEOBJECT_FIND);
	};

	struct Animator {
		FN(set_speed, void, (void* _this, float value), ANIMATOR_SET_SPEED);
	};

	struct Application {
		FN(set_targetFrameRate, void, (int value), APPLICATION_SET_TARGETFRAMERATE);
	};

	namespace UI
	{
		struct Text {
			char _[0xF8]; // 0x0
			void* m_FontData; // 0xF8
			System::String* m_Text; // 0x100
			bool m_EnableUnderline; // 0x108
			void* m_TextCache; // 0x110
			void* m_TextCacheForLayout; // 0x118
			bool m_DisableFontTextureRebuiltCallback; // 0x120
			float m_TextureScale; // 0x124
			void* m_TempVerts; // 0x128
			char m_EllipsisChar; // 0x130
		};
	}

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

		enum PuzzleCustomEvent {
			PuzzleCustomEvent_PillarPuzzleSequenceActivateWithHint = 0x1,
			PuzzleCustomEvent_PillarPuzzleSequenceActivateSkipHint = 0x2,
			PuzzleCustomEvent_PillarPuzzleDisappear = 0x3,
			PuzzleCustomEvent_PillarPuzzleWrongAttriHit = 0x4,
			PuzzleCustomEvent_PadsPuzzleTeleport = 0xA,
			PuzzleCustomEvent_PadsPuzzleFinishPads = 0xB,
			PuzzleCustomEvent_PadsPuzzleResetPads = 0xC,
			PuzzleCustomEvent_PadsPuzzleResetTeleportBlend = 0xD,
			PuzzleCustomEvent_PadsPuzzleResetTeleportInstant = 0xE,
			PuzzleCustomEvent_ProbePuzzleReset = 0xF,
			PuzzleCustomEvent_ProbePuzzleInRange = 0x10,
			PuzzleCustomEvent_ProbePuzzleOutOfRange = 0x11,
			PuzzleCustomEvent_DeployPuzzleBasePointDisabled = 0x14,
			PuzzleCustomEvent_DeployPuzzleBasePointPlaced = 0x15,
			PuzzleCustomEvent_DeployPuzzleBasePointWait = 0x16,
			PuzzleCustomEvent_DeployPuzzleBasePointSwap = 0x17,
			PuzzleCustomEvent_DeployPuzzleBasePointActivate = 0x18,
			PuzzleCustomEvent_DeployPuzzleBasePointDeactivate = 0x19,
			PuzzleCustomEvent_DeployPuzzleBoardWaitInteract = 0x1A,
			PuzzleCustomEvent_DeployPuzzleBoardInteract = 0x1B,
			PuzzleCustomEvent_DeployPuzzleBoardEndInteract = 0x1C,
			PuzzleCustomEvent_CoilPuzzleAllPillarLightup = 0x64,
			PuzzleCustomEvent_CoilPuzzleCancelAllPillarLightup = 0x65,
			PuzzleCustomEvent_AdventurePinballOnPlateUnhover = 0xC0,
			PuzzleCustomEvent_AdventurePinballOnPlateHover = 0xC1,
			PuzzleCustomEvent_AdventurePinballOnPlateUnselect = 0xC2,
			PuzzleCustomEvent_AdventurePinballOnPlateSelect = 0xC3,
			PuzzleCustomEvent_AdventurePinballOnPlateHit = 0xC4,
			PuzzleCustomEvent_AdventurePinballOnArriveStation = 0xC5,
			PuzzleCustomEvent_AdventurePinballOnStationPrepareLaunch = 0xC6,
			PuzzleCustomEvent_AdventurePinballOnInteractStation = 0xC7,
			PuzzleCustomEvent_AdventurePinballOnStationEnter = 0xC8,
			PuzzleCustomEvent_AdventurePinballOnConnectSuccess = 0xC9,
			PuzzleCustomEvent_AdventurePinballOnConnectFail = 0xCA,
			PuzzleCustomEvent_AdventurePinballOnStartConnect = 0xCB,
			PuzzleCustomEvent_AdventurePinballOnLoseConnect = 0xCC,
			PuzzleCustomEvent_AdventurePinballOnOtherStationEnter = 0xCD,
			PuzzleCustomEvent_AdventurePinballOnStationExit = 0xCE,
			PuzzleCustomEvent_AdventurePinballOnLaunchStart = 0xCF,
			PuzzleCustomEvent_AdventurePinballOnLaunchEnd = 0xD0,
			PuzzleCustomEvent_AdventurePinballOnLaunchBy = 0xD2,
			PuzzleCustomEvent_AdventureMovieOnFlip = 0xD3,
			PuzzleCustomEvent_AdventureMovieOnCollider = 0xD4,
			PuzzleCustomEvent_OpticalIllusionFinish = 0x12C,
			PuzzleCustomEvent_OpticalIllusionQuit = 0x12D,
			PuzzleCustomEvent_OpticalIllusionWayPass = 0x12E,
			PuzzleCustomEvent_OpticalIllusionRotateBlock = 0x12F,
			PuzzleCustomEvent_OpticalIllusionReach = 0x130,
			PuzzleCustomEvent_OpticalIllusionReset = 0x131,
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
			System::Collections::Generic::List<Base::Actor*>* TickComponentList; // 0x60
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
			System::Collections::Generic::List<RPG::GameCore::GameEntity*>* EntityList; // 0x90
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

		struct AdventureStatic {
			FN(GetEntityManager, void*, (), ADVENTURESTATIC_GETENTITYMANAGER);

			FN(GetLocalPlayer, void*, (), ADVENTURESTATIC_GETLOCALPLAYER);
		};

		struct NPCComponent {
			FN(TickAlertValue, void, (void* _this, float fElapsedTimeInSec, void* target, void* detail), NPCCOMPONENT_TICKALERTVALUE);
		};

		struct PropComponent {
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

		struct GamePlayLockModule {
			FN(Lock, void, (void* _this, void* lockSource, void* lockParams), GAMEPLAYLOCKMODULE_LOCK);
		};

		struct LocalizedText : UnityEngine::UI::Text {
			bool mForbidNoLeadingChar; // 0x138
			void* _CustomFont; // 0x140
			void* TextmapID; // 0x148
			void* textID; // 0x150
			void* replaceParams; // 0x158
			bool _InUse; // 0x160
			bool _InMCVPattern; // 0x161
			bool _RegisteredDirtyLayoutCallback; // 0x162
			void* _CustomizedTextBeforeCompileRuby; // 0x168
			float _DefaultDisplayHeight; // 0x170
			bool _IsResized; // 0x174
			bool RefreshByLanguageChange; // 0x175
			bool IsWhiteBG; // 0x176
			bool EnableRuby; // 0x177
			bool IsSingleLineEllipsis; // 0x178
			int ForcedFont; // 0x17C
			bool IsDynamicTextID; // 0x180

			FN(set_text, void, (void* _this, void* value), LOCALIZEDTEXT_SET_TEXT);
		};

		struct EAIECBLOINL {
			char _[0x18]; // 0x0
			LocalizedText* HintText; // 0x18
			LocalizedText* VersionText; // 0x20
		};
		
		struct BetaHintDialogContext {
			FN(CFNOBNMKNCA, RPG::Client::EAIECBLOINL*, (void* _this), BETAHINTDIALOGCONTEXT_CFNOBNMKNCA);
		};

		struct MessageUtils {
			FN(GetWritingTime, float, (void* _this, void* itemData), MESSAGEUTILS_GETWRITINGTIME);
		};

		struct MessageSectionData {
			FN(get_WaitingItemIDs, System::Collections::Generic::Array<int>*, (void* _this), MESSAGESECTIONDATA_GET_WAITINGITEMIDS);
		};

		struct MessageModule {
			FN(FinishItemByChoice, void, (void* _this, unsigned int itemID), MESSAGEMODULE_FINISHITEMBYCHOICE);
		};

		struct ModuleManager {
			char _[0x10];
			void* modules; // 0x10
			void* PlayerModule; // 0x18
			void* TeamModule; // 0x20
			void* BigMapModule; // 0x28
			void* BattleModule; // 0x30
			void* OperationModule; // 0x38
			void* LoginModule; // 0x40
			void* AdventureModule; // 0x48
			void* RogueModule; // 0x50
			void* ServerPrefsModule; // 0x58
			void* FloorConnectivityModule; // 0x60
			void* MissionModule; // 0x68
			void* AvatarModule; // 0x70
			void* InventoryModule; // 0x78
			void* ItemComposeModule; // 0x80
			void* ActivityModule; // 0x88
			void* ResidentActivityModule; // 0x90
			void* QuestModule; // 0x98
			void* NovelModule; // 0xA0
			void* ChallengeModule; // 0xA8
			void* SystemOpenModule; // 0xB0
			void* GamePlayLockModule; // 0xB8
			void* AntiAddictionModule; // 0xC0
			void* GachaModule; // 0xC8
			void* ExpeditionModule; // 0xD0
			void* TalkModule; // 0xD8
			void* PamModule; // 0xE0
			void* TrainModule; // 0xE8
			void* DialogueModule; // 0xF0
			void* RaidModule; // 0xF8
			void* RaidCollectionModule; // 0x100
			void* ScheduleModule; // 0x108
			void* PayModule; // 0x110
			void* LuaDataModule; // 0x118
			void* LoadingTipsModule; // 0x120
			void* AchievementModule; // 0x128
			void* SpaceAnchorModule; // 0x130
			void* EntityScoreModule; // 0x138
			RPG::Client::MessageModule* MessageModule; // 0x140
			void* FeatureSwitchModule; // 0x148
			void* FriendModule; // 0x150
			void* PhotoGraphModule; // 0x158
			void* MusicAlbumModule; // 0x160
			void* MapPropOverrideConditionModule; // 0x168
			void* TutorialSupportModule; // 0x170
			void* BattlePassModule; // 0x178
			void* BattleTipsModule; // 0x180
			void* BattleEventModule; // 0x188
			void* PunkLordModule; // 0x190
			void* RogueHandbookModule; // 0x198
			void* TransferModule; // 0x1A0
			void* HandbookModule; // 0x1A8
			void* FarmModule; // 0x1B0
			void* TextJoinModule; // 0x1B8
			void* ChessRogueModule; // 0x1C0
			void* RogueAdventureModule; // 0x1C8
			void* FightActivityModule; // 0x1D0
			void* FantasticStoryActivityModule; // 0x1D8
			void* CompanionMissionActivityModule; // 0x1E0
			void* MultipleDropModule; // 0x1E8
			void* SilverWolfModule; // 0x1F0
			void* ArchiveModule; // 0x1F8
			void* PerformanceRecallModule; // 0x200
			void* ChatModule; // 0x208
			void* PersonalizeModule; // 0x210
			void* ShareModule; // 0x218
			void* BoxingClubModule; // 0x220
			void* BattleCollegeModule; // 0x228
			void* ActivityTelevisionModule; // 0x230
			void* RoleTrialModule; // 0x238
			void* ActivityMonsterResearchModule; // 0x240
			void* MuseumModule; // 0x248
			void* TravelBrochureModule; // 0x250
			void* TreasureDungeonModule; // 0x258
			void* ActivityGuessTheSilhouetteModule; // 0x260
			void* ActivityPlayerReturnModule; // 0x268
			void* AlleyModule; // 0x270
			void* AetherDivideModule; // 0x278
			void* FloorDataModule; // 0x280
			void* MapRotationModule; // 0x288
			void* ActivityAetherDivideModule; // 0x290
			void* ActivityStrongChallengeModule; // 0x298
			void* RollShopModule; // 0x2A0
			void* SpaceZooModule; // 0x2A8
			void* HeliobusModule; // 0x2B0
			void* HeartDialModule; // 0x2B8
			void* StoryLineModule; // 0x2C0
			void* OfferingModule; // 0x2C8
			void* MissionChronicleModule; // 0x2D0
			void* _ModuleInitRequestList; // 0x2D8
			bool isInited; // 0x2E0
		};

		namespace Prop
		{
			enum PuzzlePhase {
				PuzzlePhase_FreeOP = 0x0,
				PuzzlePhase_PathEffect = 0x1,
				PuzzlePhase_NPCMove = 0x2,
				PuzzlePhase_FinishDelay = 0x3,
				PuzzlePhase_Finish = 0x4,
				PuzzlePhase_Reset = 0x5,
			};

			struct OpticalIllusionPuzzleBoard {
				char _[0x40]; // 0x0
				void* ABEJDKOOIAP; // 0x40
				void* LKFJGEBBFHJ; // 0x48
				int KDHABOGLJKC; // 0x50
				bool PKBKJIDHAGC; // 0x54
				void* OPIPJDIPDPF; // 0x58
				void* PDEIJJEOFNK; // 0x60
				void* CCNNIGBKMJD; // 0x68
				void* IGHPBOJHANB; // 0x70
				void* FCBMDJMBPGF; // 0x78
				void* AEAACGEDMDK; // 0x80
				void* EFLPLKJPMCI; // 0x88
				void* FCNIMIBEEOJ; // 0x90
				bool AIKMKPOJGAJ; // 0x98
				void* AGDCJMJNACN; // 0xA0
				void* DBJKBCNPNDJ; // 0xA8
				void* CJMMODJLIFB; // 0xB0
				int OJGDACMPLFC; // 0xB8
				char HPJKOOAFFAN[0xC]; // 0xBC
				int KCAOEKAOBJH; // 0xC8
				void* NBDGGCGDGDG; // 0xD0
				bool NMPDEDMEDIA; // 0xD8
				float JMFBPBBJMFI; // 0xDC
				float PMPIJCGMKGH; // 0xE0
				float IIPAIKNCNHJ; // 0xE4
				void* CHEKMKPPNML; // 0xE8
				float NFMAMDIILGO; // 0xF0
				float NHHBJDCKPOG; // 0xF4
				void* PEPDMNGCCOE; // 0xF8
				char AJMKAJJCGBN[0xC]; // 0x100
				char CLBBADOPJMI[0xC]; // 0x10C
				char FPCLFMNHEDO[0x10]; // 0x118
				void* FNPMLCLEPOM; // 0x128
				void* INBNKIGCONH; // 0x130
				void* HOACMNDALBP; // 0x138
				char ENOBEHJJEAA[0x10]; // 0x140
				void* ADCAKCFPONK; // 0x150
				bool DMGBMGGBMCN; // 0x158
				void* HGCENHFELGC; // 0x160
				bool MOAFFLIPMHL; // 0x168
				int MCBMDKHHPAG; // 0x16C
				int CAFCCKAKBFI; // 0x170
				int HICENGBBJBJ; // 0x174
				int MIMKKAGMLMJ; // 0x178
				bool FOLNGHJHCID; // 0x17C
				void* OPBNHPCNACL; // 0x180
				void* DEEEOJHDPPC; // 0x188
				void* NADEJLLOKFO; // 0x190
				void* DKIFGDPJKMG; // 0x198
				void* GDPANCCJJBF; // 0x1A0
				float CBNKIDDACID; // 0x1A8
				unsigned int NKOEOHEMLLF; // 0x1AC
				float NECPLMIKJIP; // 0x1B0
				bool CEBNHPJONLK; // 0x1B4
				char PlayerStartPosition[0xC]; // 0x1B8
				char PlayerStartRotation[0x10]; // 0x1C4
				int PlayerMotion; // 0x1D4
				float PlayerSpeedRate; // 0x1D8
				System::Collections::Generic::Array<void*>* DesignPaths; // 0x1E0
				int MirrorPlane; // 0x1E8
				bool SetCamera; // 0x1EC
				char CameraPosition[0xC]; // 0x1F0
				char CameraRotation[0x10]; // 0x1FC
				float OrthographicSize; // 0x20C
				int HEHGDADCDNO; // 0x210
				unsigned int NKAEFBKDOGJ; // 0x214
				int LEPPBLHMNFC; // 0x218
				void* PPGNOIIODDL; // 0x220

				FN(Update, void, (void* _this), OPTICALILLUSIONPUZZLEBOARD_UPDATE);

				FN(MELEDIOAKMC, void, (void* _this), OPTICALILLUSIONPUZZLEBOARD_MELEDIOAKMC);
			};

			struct CablePuzzleBoard {
				char _[0xE0]; // 0x0
				float RotateSpeed; // 0xE0
				void* ResetTriggerCustomString; // 0xE8
				void* ControllerModeInitHighlightPos; // 0xF0
				float DelayResetTime; // 0xF8
				void* RotationSpeedCurve; // 0x100
				void* InitAnimationCurve; // 0x108
				void* CenterCoord; // 0x110
				float InitAnimationDuration; // 0x118
				float CenterItemInitAnimationHeight; // 0x11C
				float CenterLightDelay; // 0x120
				float LightDelay; // 0x124
				void* RotateSoundEvent; // 0x128
				void* ConnectSoundEvent; // 0x130
				void* FinishSoundEvent; // 0x138
				long StartTime; // 0x140
				bool MOHOIPOMKBF; // 0x144
				void* MEFNLAALECB; // 0x148
				long EOHFEHDDOHN; // 0x150
				void* PDEIJJEOFNK; // 0x158
				void* LADBNAFBFDA; // 0x160
				void* GCGLPABFJCH; // 0x168
				void* EOBGPLBPEEH; // 0x170
				void* BCHLPJAAGPE; // 0x178
				void* GANALNEDEFH; // 0x180
				void* ACCLNDCNGPB; // 0x188
				void* CLLNOKCIKNI; // 0x190
				void* OINNEDHHODB; // 0x198
				bool COIAGGPMFAI; // 0x1A0
				bool PBIBKCCEFLH; // 0x1A1
				void* PABPHGHBDCP; // 0x1A8

				FN(LADNBFDOAMJ, bool, (void* _this, void* FMJLOIDBOKI, void* BHMGPLJEDCH), CABLEPUZZLEBOARD_LADNBFDOAMJ);
			};

			struct RubikCubePuzzleCube {
				char _[0x18]; // 0x0
				bool _IsRotate; // 0x18
				bool _IsDrag; // 0x19
				void* UniqueName; // 0x20
				int Order; // 0x28
				void* Blocks; // 0x30
				float RotateSpeed; // 0x38
				void* CubeStatus; // 0x40
				void* StartRotateCustomString; // 0x48
				void* StopRotateCustomString; // 0x50
				void* SolidNormalMaterial; // 0x58
				void* SolidSelectMaterial; // 0x60
				void* ThirdStatusNormalMaterial; // 0x68
				void* ThirdStatusSelectMaterial; // 0x70
				void* EmptyNormalMaterial; // 0x78
				void* EmptySelectMaterial; // 0x80
				void* CompleteMaterial; // 0x88
				void* RotateCurve; // 0x90
				void* LECBPFBNIMA; // 0x98
				void* EJHMDFFLGFN; // 0xA0
				void* ODCBCCOAKME; // 0xA8
				void* FDFECPCMJKF; // 0xB0
				void* PDMKCOEONHI; // 0xB8
				void* LOAJPFHKCNG; // 0xC0
				void* JIKLGALCJIH; // 0xC8
				void* HCNPPAKMALJ; // 0xD0
				void* HCINFOIKAEP; // 0xD8
				void* OGAOEAAFHPG; // 0xE0
				void* DCMHOANOOFI; // 0xE8
				void* JDICCHNAGAA; // 0xF0
				void* PDABLOGCFJE; // 0xF8
				void* LDPJHDGBPCD; // 0x100
				int IMEBLMIBLPJ; // 0x108
				unsigned int GNGBLKIDMEC; // 0x10C
				int PEBBPDGJDHL; // 0x110
				int LAPHEAMBAGC; // 0x114
				int CHKIOPKIEKA; // 0x118

				FN(OnRotateFinish, void, (void* _this), RUBIKCUBEPUZZLECUBE_ONROTATEFINISH);
			};

			struct RotatePillarPuzzleFragment {
				FN(get_IsComplete, bool, (void* _this), ROTATEPILLARPUZZLEFRAGMENT_GET_ISCOMPLETE);
			};

			struct InsertionPuzzleItem {
				FN(IsMatchItem, bool, (void* _this, void* FBLKNKFEIFI), INSERTIONPUZZLEITEM_ISMATCHITEM);
			};

			struct JigsawPuzzleBoard {
				FN(_CheckIsGameFinish, bool, (void* _this), JIGSAWPUZZLEBOARD__CHECKISGAMEFINISH);
			};
		}
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
	System::Collections::Generic::List<RPG::GameCore::GameEntity*>* GetWorldEntityList();

	void* GetTurnBasedGameMode();
	void* GetPropComponent(System::Collections::Generic::List<Base::Actor*>* lpComponentList);

	bool GetResolutionScale(Vector2* lpResolution, Vector2* lpResolutionScale);
	bool GetScreenPosition(Vector2* lpResolutionScale, void* lpWorldPosition, Vector3* lpRet);

	bool GetEntityPosition(void* lpEntity, void* lpPosition);
	int GetPhaseType();

	void* GetUICamera();
	void* GetBetaHintDialogContext();
	RPG::Client::ModuleManager* GetModuleManager();

	void* GetTransform(void* lpEntity);

	void PlayerTeleport(void* lpPosition);
}