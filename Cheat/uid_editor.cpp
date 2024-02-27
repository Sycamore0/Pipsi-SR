#include "uid_editor.h"

#include "engine.h"
#include "globals.h"
#include "hooks.h"

#include "utils.h"

#include "imgui_internal.h"

namespace UIDEditor
{
	static void set_textHandler(void* _this, void* value)
	{
		if (Options.bUIDEditor && _this)
		{
			PVOID lpBetaHintDialogContext = Engine::GetBetaHintDialogContext();

			if (lpBetaHintDialogContext)
			{
				RPG::Client::EAIECBLOINL* lpCFNOBNMKNCA = RPG::Client::BetaHintDialogContext::CFNOBNMKNCA(lpBetaHintDialogContext);

				if (lpCFNOBNMKNCA)
				{
					RPG::Client::LocalizedText* lpHintText = lpCFNOBNMKNCA->HintText;

					if (lpHintText && _this == lpHintText)
							value = System::String::New(Options.lpUIDEditorText);
				}
			}
		}

		CALL_ORIGIN(set_textHandler, _this, value);
	}

	void Render()
	{
		ImGui::BeginGroupPanel("UID Editor");

		ImGui::Checkbox("Enable", &Options.bUIDEditor);

		ImGui::SameLine();

		ImGui::HelpMarker("To update the UID you need to teleport.");

		if (Options.bUIDEditor)
		{
			ImGui::Indent();

			ImGui::InputText("New Text", Options.lpUIDEditorText, sizeof(Options.lpUIDEditorText));

			ImGui::Unindent();
		}

		ImGui::EndGroupPanel();
	}

	void Update()
	{
	}

	void Start()
	{
		CreateHook(RPG::Client::LocalizedText::set_text, set_textHandler);
	}
}