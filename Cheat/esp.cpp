#include "esp.h"

#include "globals.h"
#include "engine.h"

#include "utils.h"

#include "imgui_internal.h"

namespace Esp
{
	void Render()
	{
		ImGui::BeginGroupPanel("Esp");

		ImGui::Checkbox("Enable", &bEsp);

		if (bEsp)
		{
			ImGui::Text("Soon");
		}

		ImGui::EndGroupPanel();
	}

	void Update()
	{
	}

	void Start()
	{

	}
}