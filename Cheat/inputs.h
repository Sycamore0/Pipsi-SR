#pragma once
#include <windows.h>
#include <map>

struct INPUT_
{
	LPCSTR lpName;
	BOOL bHold;
	BOOL bToggle;
};

enum INPUT_TYPE_
{
	INPUT_TYPE_HOLD = 0,
	INPUT_TYPE_TOGGLE = 1,
	INPUT_TYPE_ALWAYS = 2
};

namespace Inputs
{
	VOID OnMessage(UINT uMsg, WPARAM wParam);
	VOID OnMouseMessage(UINT uMsg, WPARAM wParam);
	VOID OnKeyboardMessage(UINT uMsg, WPARAM wParam);
	VOID OnWindowMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

	LPCSTR GetName(UINT uId);
	BOOL GetState(UINT uId, INT iType);
	WPARAM GetLastInput();

	VOID SetToggleState(UINT uId, BOOL bValue);
	VOID SetWaitInput(WPARAM wValue);
}