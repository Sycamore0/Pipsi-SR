#include "fov.h"

#include "engine.h"
#include "globals.h"
#include "hooks.h"

#include "utils.h"

#include "imgui_internal.h"

namespace Fov
{
	static void set_fieldOfViewHandler(void* _this, float value)
	{
		FLOAT flValue;

		if (bFov)
		{
			flValue = flFov;
		}
		else
		{
			flValue = value;
		}

		return CALL_ORIGIN(set_fieldOfViewHandler, _this, flValue);
	}

	void Render()
	{
		ImGui::BeginGroupPanel("Fov");

		ImGui::Checkbox("Enable", &bFov);

		if (bFov)
		{
			ImGui::SliderFloat("Value", &flFov, 1.f, 359.f, "%.1f");
		}

		ImGui::EndGroupPanel();
	}

	void Update()
	{
	}

	void Start()
	{
		CreateHook(UnityEngine::Camera::set_fieldOfView, set_fieldOfViewHandler);
	}
}