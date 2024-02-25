#include "auto_talk.h"

#include "engine.h"
#include "globals.h"
#include "hooks.h"

#include "inputs.h"

#include "utils.h"

#include "imgui_internal.h"

namespace AutoTalk
{
	static long _g_get_ForceToNextTimeHandler(__int64 L)
	{
		if (!Options.bAutoTalk || !Inputs::GetState(Options.dwAutoTalkKey, INPUT_TYPE_HOLD))
			return CALL_ORIGIN(_g_get_ForceToNextTimeHandler, L);

		XLua::LuaDLL::Lua::lua::pushnumber(L, 0.000001f);

		return 1;
	}

	static long _g_get_ProtectTimeHandler(__int64 L)
	{
		if (!Options.bAutoTalk || !Options.bAutoTalkDisableDelay)
			return CALL_ORIGIN(_g_get_ProtectTimeHandler, L);

		XLua::LuaDLL::Lua::lua::pushnumber(L, 0.f);

		return 1;
	}

	static bool IsDoneHandler(void* _unity_self)
	{
		if (Options.bAutoTalk && Options.bAutoTalkSkipScenes && Inputs::GetState(Options.dwAutoTalkKey, INPUT_TYPE_HOLD) && _unity_self)
		{
			__try
			{
				if (Engine::GetPhaseType() == RPG::Client::GamePhaseType_Adventure)
					return UnityEngine::Playables::PlayableGraph::IsPlaying_Injected(_unity_self);
			}
			__except (EXCEPTION_EXECUTE_HANDLER)
			{
				printf("AutoTalk::IsDoneHandler(), exception 0x%X\n", GetExceptionCode());
			}
		}

		return CALL_ORIGIN(IsDoneHandler, _unity_self);
	}

	void Render()
	{
		ImGui::BeginGroupPanel("Auto-Talk");

		ImGui::Checkbox("Enable", &Options.bAutoTalk);

		//ImGui::SameLine();

		//ImGui::Hotkey(&Options.dwAutoTalkKey);

		if (Options.bAutoTalk)
		{
			ImGui::Indent();

			ImGui::Checkbox("Disable Delay", &Options.bAutoTalkDisableDelay);
			ImGui::Checkbox("Skip Scenes", &Options.bAutoTalkSkipScenes);

			ImGui::Unindent();
		}

		ImGui::EndGroupPanel();
	}

	void Update()
	{

	}

	void Start()
	{
		CreateHook(XLua::CSObjectWrap::RPGGameCoreSimpleTalkInfoWrap::_g_get_ForceToNextTime, _g_get_ForceToNextTimeHandler);
		CreateHook(XLua::CSObjectWrap::RPGGameCoreSimpleTalkInfoWrap::_g_get_ProtectTime, _g_get_ProtectTimeHandler);

		CreateHook(UnityEngine::Playables::PlayableGraph::IsDone_Injected, IsDoneHandler);
	}
}