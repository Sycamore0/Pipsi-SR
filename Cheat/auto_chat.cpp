#include "auto_chat.h"

#include "engine.h"
#include "globals.h"
#include "hooks.h"

#include "utils.h"

#include "imgui_internal.h"

namespace AutoChat
{
	float GetWritingTimeHandler(void* _this, void* itemData)
	{
		if (!Options.bAutoChat || !Options.bAutoChatDisableDelay)
			return CALL_ORIGIN(GetWritingTimeHandler, _this, itemData);

		return 0.f;
	}

	System::Collections::Generic::Array<int>* get_WaitingItemIDsHandler(void* _this)
	{
		System::Collections::Generic::Array<int>* lpResult = CALL_ORIGIN(get_WaitingItemIDsHandler, _this);

		if (Options.bAutoChat && Options.bAutoChatAutoReply && lpResult && lpResult->max_length > 0)
		{
			RPG::Client::ModuleManager* lpModuleManager = Engine::GetModuleManager();

			if (lpModuleManager && lpModuleManager->MessageModule)
				RPG::Client::MessageModule::FinishItemByChoice(lpModuleManager->MessageModule, lpResult->vector[0]);
		}

		return lpResult;
	}

	void Render()
	{
		ImGui::BeginGroupPanel("Auto-Chat");

		ImGui::Checkbox("Enable", &Options.bAutoChat);

		if (Options.bAutoChat)
		{
			ImGui::Indent();

			ImGui::Checkbox("Disable Delay", &Options.bAutoChatDisableDelay);
			ImGui::Checkbox("Auto Reply", &Options.bAutoChatAutoReply);

			ImGui::Unindent();
		}

		ImGui::EndGroupPanel();
	}

	void Update()
	{

	}

	void Start()
	{
		CreateHook(RPG::Client::MessageUtils::GetWritingTime, GetWritingTimeHandler);
		CreateHook(RPG::Client::MessageSectionData::get_WaitingItemIDs, get_WaitingItemIDsHandler);
	}
}