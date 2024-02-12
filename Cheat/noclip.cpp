#include "noclip.h"

#include "globals.h"
#include "engine.h"

#include "inputs.h"

#include "utils.h"

#include "imgui_internal.h"

namespace Noclip
{
	void Render()
	{
		ImGui::BeginGroupPanel("Noclip");

		ImGui::Checkbox("Enable", &bNoclip);

		ImGui::SameLine();

		ImGui::Hotkey(&dwNoclipKey);

		if (bNoclip)
		{
			ImGui::SliderFloat("Speed", &flNoclipSpeed, 0.01f, 100.f, "%.2f");
		}

		ImGui::EndGroupPanel();
	}

	void Update()
	{
		if (!bNoclip || !Inputs::GetState(dwNoclipKey, INPUT_TYPE_TOGGLE))
			return;

		__try
		{
			PVOID lpLocalPlayer = RPG::GameCore::AdventureStatic::GetLocalPlayer();

			if (!lpLocalPlayer)
				return;

			PVOID lpGameObject = RPG::GameCore::GameEntity::get_UnityGO(lpLocalPlayer);

			if (!lpGameObject)
				return;

			PVOID lpTransform = UnityEngine::GameObject::get_transform(lpGameObject);

			if (!lpTransform)
				return;

			Vector3 Position = {};
			Vector3 Direction = {};

			UnityEngine::Transform::get_position_Injected(lpTransform, &Position);


			if (Inputs::GetState('W', INPUT_TYPE_HOLD)
				|| Inputs::GetState('A', INPUT_TYPE_HOLD)
				|| Inputs::GetState('S', INPUT_TYPE_HOLD)
				|| Inputs::GetState('D', INPUT_TYPE_HOLD))
			{
				UnityEngine::Transform::get_forward(&Direction, lpTransform);
			}

			if (Inputs::GetState(VK_SPACE, INPUT_TYPE_HOLD))
				UnityEngine::Transform::get_up(&Direction, lpTransform);

			if (Inputs::GetState(VK_SHIFT, INPUT_TYPE_HOLD))
			{
				UnityEngine::Transform::get_up(&Direction, lpTransform);

				Direction = -Direction;
			}

			Position += Direction * flNoclipSpeed * UnityEngine::Time::get_deltaTime();

			UnityEngine::Transform::set_position_Injected(lpTransform, &Position);
		}
		__except (EXCEPTION_EXECUTE_HANDLER)
		{
			printf("Noclip::Update(), exception 0x%X\n", GetExceptionCode());
		}
	}

	void Start()
	{

	}
}