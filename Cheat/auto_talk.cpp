#include "auto_talk.h"

#include "engine.h"
#include "globals.h"
#include "hooks.h"

#include "utils.h"

#include "imgui_internal.h"

namespace AutoTalk
{
	static long _g_get_ForceToNextTimeHandler(__int64 L)
	{
		if (!bAutoTalk)
			return CALL_ORIGIN(_g_get_ForceToNextTimeHandler, L);

		XLua::LuaDLL::Lua::lua::pushnumber(L, 0.000001f);

		return 1;
	}

	static long _g_get_ProtectTimeHandler(__int64 L)
	{
		if (!bAutoTalkDisableDelay)
			return CALL_ORIGIN(_g_get_ProtectTimeHandler, L);

		XLua::LuaDLL::Lua::lua::pushnumber(L, 0.f);

		return 1;
	}

	void Render()
	{
		ImGui::BeginGroupPanel("Auto-Talk");

		ImGui::Checkbox("Enable", &bAutoTalk);

		if (bAutoTalk)
		{
			ImGui::Indent();

			ImGui::Checkbox("Disable Delay", &bAutoTalkDisableDelay);

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
	}
}