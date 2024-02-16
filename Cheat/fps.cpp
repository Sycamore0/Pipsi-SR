#include "fps.h"

#include "engine.h"
#include "globals.h"
#include "hooks.h"

#include "utils.h"

#include "imgui_internal.h"

namespace Fps
{
	void Render()
	{
		ImGui::BeginGroupPanel("FPS");

		ImGui::Checkbox("Enable Indicator", &Options.bFpsIndicator);

		ImGui::InputInt("FPS Value", &Options.iFpsValue);

		ImGui::EndGroupPanel();
	}

	void Update()
	{
		if (Options.bFpsIndicator)
		{
			if (ImGui::Begin("FPS Indicator", NULL, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoFocusOnAppearing
				| ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize))
			{
				ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);

				ImGui::End();
			}
		}

		UPDATE_DELAY(100);

		UnityEngine::Application::set_targetFrameRate(Options.iFpsValue);
	}

	void Start()
	{
	}
}