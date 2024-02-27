#include "uid_editor.h"

#include "engine.h"
#include "globals.h"
#include "hooks.h"

#include "utils.h"

#include "imgui_internal.h"

namespace UIDEditor
{
	bool bUIDEditor = FALSE;
	char lpUIDEditorText[80] = { "PIPSI-SR" };

	void set_textHandler(void* _this, void* value)
	{
		if (bUIDEditor && _this)
		{
			PVOID lpBetaHintDialogContext = Engine::GetBetaHintDialogContext();

			if (lpBetaHintDialogContext)
			{
				RPG::Client::EAIECBLOINL* lpCFNOBNMKNCA = RPG::Client::BetaHintDialogContext::CFNOBNMKNCA(lpBetaHintDialogContext);

				if (lpCFNOBNMKNCA)
				{
					RPG::Client::LocalizedText* lpHintText = lpCFNOBNMKNCA->HintText;

					if (lpHintText && _this == lpHintText)
							value = System::String::New(lpUIDEditorText);
				}
			}
		}

		CALL_ORIGIN(set_textHandler, _this, value);
	}

	void Render()
	{
		ImGui::BeginGroupPanel("UID Editor");

		ImGui::Checkbox("Enable", &bUIDEditor);

		ImGui::SameLine();

		ImGui::HelpMarker("To update the UID you need to teleport.");

		if (bUIDEditor)
		{
			ImGui::Indent();

			ImGui::InputText("New Text", lpUIDEditorText, sizeof(lpUIDEditorText));

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