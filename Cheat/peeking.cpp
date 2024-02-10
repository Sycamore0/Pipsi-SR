#include "peeking.h"

#include "engine.h"
#include "globals.h"
#include "hooks.h"

#include "utils.h"

#include "imgui_internal.h"

namespace Peeking
{
	static void* SetElevationDitherAlphaValueHandler(void* _this, float EOBOBKJIJFA)
	{
		if (bPeeking)
			return NULL;

		return CALL_ORIGIN(SetElevationDitherAlphaValueHandler, _this, EOBOBKJIJFA);
	}

	void Render()
	{
		ImGui::BeginGroupPanel("Peeking");

		ImGui::Checkbox("Enable", &bPeeking);

		ImGui::EndGroupPanel();
	}

	void Update()
	{
	}

	void Start()
	{
		CreateHook(RPG::Client::BaseShaderPropertyTransition::SetElevationDitherAlphaValue, SetElevationDitherAlphaValueHandler);
	}
}