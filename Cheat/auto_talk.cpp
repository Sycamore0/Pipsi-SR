#include "auto_talk.h"

#include "engine.h"
#include "globals.h"
#include "hooks.h"

#include "utils.h"

#include "imgui_internal.h"

namespace AutoTalk
{
	// to do: find gameobject "SkipBtn" and set_active(true) 

	void Render()
	{
		ImGui::BeginGroupPanel("Auto-Talk");

		ImGui::Checkbox("Enable", &bAutoTalk);

		if (bAutoTalk)
		{
			ImGui::SliderFloat("Speed", &flAutoTalkSpeed, 0.1f, 20.f, "%.1f");
		}

		ImGui::EndGroupPanel();
	}

	void Update()
	{
		__try
		{
			if (bAutoTalk)
			{
				PVOID lpTalkString = System::String::Create("/UIRoot/Page/TalkDialog(Clone)/TalkContainer/SimpleTalk");

				PVOID lpSimpleTalk = UnityEngine::GameObject::Find(lpTalkString);

				if (lpSimpleTalk)
				{
					*MaxTimeScale = flAutoTalkSpeed + 0.1f;
					UnityEngine::Time::set_timeScale(flAutoTalkSpeed);

					return;
				}
			}

			*MaxTimeScale = 1.1f;
			UnityEngine::Time::set_timeScale(1.f);
		}
		__except (EXCEPTION_EXECUTE_HANDLER)
		{
			printf("AutoTalk::Update(), exception 0x%X\n", GetExceptionCode());
		}
	}

	void Start()
	{
		DWORD dwOldProtect = 0;
		
		VirtualProtect(MaxTimeScale, sizeof(MaxTimeScale), PAGE_READWRITE, &dwOldProtect);
	}
}