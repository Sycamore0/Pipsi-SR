#include "inputs.h"

namespace Inputs
{
	std::map<WPARAM, INPUT_> mCache = {
		{ VK_LBUTTON, { "LBUTTON" } },
		{ VK_RBUTTON, { "RBUTTON" } },
		{ VK_MBUTTON, { "MBUTTON" } },
		{ VK_XBUTTON1, { "XBUTTON1" } },
		{ VK_XBUTTON2, { "XBUTTON2" } },

		{ VK_BACK, { "BACK" } },
		{ VK_TAB, { "TAB" } },
		{ VK_RETURN, { "RETURN" } },
		{ VK_SHIFT, { "SHIFT" } },
		{ VK_CONTROL, { "CONTROL" } },
		{ VK_MENU, { "MENU" } },
		{ VK_PAUSE, { "PAUSE" } },
		{ VK_CAPITAL, { "CAPITAL" } },
		{ VK_ESCAPE, { "ESCAPE" } },
		{ VK_SPACE, { "SPACE" } },
		{ VK_PRIOR, { "PRIOR" } },
		{ VK_NEXT, { "NEXT" } },
		{ VK_END, { "END" } },
		{ VK_HOME, { "HOME" } },
		{ VK_LEFT, { "LEFT" } },
		{ VK_UP, { "UP" } },
		{ VK_RIGHT, { "RIGHT" } },
		{ VK_DOWN, { "DOWN" } },
		{ VK_SELECT, { "SELECT" } },
		{ VK_PRINT, { "PRINT" } },
		{ VK_EXECUTE, { "EXECUTE" } },
		{ VK_SNAPSHOT, { "SNAPSHOT" } },
		{ VK_INSERT, { "INSERT" } },
		{ VK_DELETE, { "DELETE" } },
		{ VK_HELP, { "HELP" } },
		{ VK_LCONTROL, { "LCONTROL" } },
		{ VK_RCONTROL, { "RCONTROL" } },
		{ VK_LMENU, { "LMENU" } },
		{ VK_RMENU, { "RMENU" } },

		{ VK_F1, { "F1" } },
		{ VK_F2, { "F2" } },
		{ VK_F3, { "F3" } },
		{ VK_F4, { "F4" } },
		{ VK_F5, { "F5" } },
		{ VK_F6, { "F6" } },
		{ VK_F7, { "F7" } },
		{ VK_F8, { "F8" } },
		{ VK_F9, { "F9" } },
		{ VK_F10, { "F10" } },
		{ VK_F11, { "F11" } },
		{ VK_F12, { "F12" } },

		{ VK_NUMLOCK, { "NUMLOCK" } },
		{ VK_NUMPAD0, { "NUMPAD0" } },
		{ VK_NUMPAD1, { "NUMPAD1" } },
		{ VK_NUMPAD2, { "NUMPAD2" } },
		{ VK_NUMPAD3, { "NUMPAD3" } },
		{ VK_NUMPAD4, { "NUMPAD4" } },
		{ VK_NUMPAD5, { "NUMPAD5" } },
		{ VK_NUMPAD6, { "NUMPAD6" } },
		{ VK_NUMPAD7, { "NUMPAD7" } },
		{ VK_NUMPAD8, { "NUMPAD8" } },
		{ VK_NUMPAD9, { "NUMPAD9" } },

		{ VK_MULTIPLY, { "*" } },
		{ VK_ADD, { "+" } },
		{ VK_SEPARATOR, { "|" } },
		{ VK_SUBTRACT, { "-" } },
		{ VK_DECIMAL, { "." } },

		{ 0x30, { "0" } },
		{ 0x31, { "1" } },
		{ 0x32, { "2" } },
		{ 0x33, { "3" } },
		{ 0x34, { "4" } },
		{ 0x35, { "5" } },
		{ 0x36, { "6" } },
		{ 0x37, { "7" } },
		{ 0x38, { "8" } },
		{ 0x39, { "9" } },
		{ 0x41, { "A" } },
		{ 0x42, { "B" } },
		{ 0x43, { "C" } },
		{ 0x44, { "D" } },
		{ 0x45, { "E" } },
		{ 0x46, { "F" } },
		{ 0x47, { "G" } },
		{ 0x48, { "H" } },
		{ 0x49, { "I" } },
		{ 0x4A, { "J" } },
		{ 0x4B, { "K" } },
		{ 0x4C, { "L" } },
		{ 0x4D, { "M" } },
		{ 0x4E, { "N" } },
		{ 0x4F, { "O" } },
		{ 0x50, { "P" } },
		{ 0x51, { "Q" } },
		{ 0x52, { "R" } },
		{ 0x53, { "S" } },
		{ 0x54, { "T" } },
		{ 0x55, { "U" } },
		{ 0x56, { "V" } },
		{ 0x57, { "W" } },
		{ 0x58, { "X" } },
		{ 0x59, { "Y" } },
		{ 0x5A, { "Z" } },
	};

	WPARAM wWaitInput = 0xFFFFFFFF;

	VOID OnMessage(UINT uMsg, WPARAM wParam)
	{
		if (mCache.count(wParam) == 0)
			return;

		switch (uMsg)
		{
		case WM_KEYDOWN:
			mCache[wParam].bHold = TRUE;
			break;
		case WM_KEYUP:
			mCache[wParam].bHold = FALSE;
			mCache[wParam].bToggle = !mCache[wParam].bToggle;
			break;
		default:
			return;
		}

		if (wWaitInput == 0)
			wWaitInput = wParam;
	}

	VOID OnMouseMessage(UINT uMsg, WPARAM wParam)
	{
		UINT uState = 0;
		WPARAM wKey = 0;

		switch (uMsg) {
		case WM_MBUTTONDOWN:
		case WM_MBUTTONUP:
		case WM_MBUTTONDBLCLK:
			uState = uMsg == WM_MBUTTONUP ? WM_KEYUP : WM_KEYDOWN;
			wKey = VK_MBUTTON;
			break;
		case WM_RBUTTONDOWN:
		case WM_RBUTTONUP:
		case WM_RBUTTONDBLCLK:
			uState = uMsg == WM_RBUTTONUP ? WM_KEYUP : WM_KEYDOWN;
			wKey = VK_RBUTTON;
			break;
		case WM_LBUTTONDOWN:
		case WM_LBUTTONUP:
		case WM_LBUTTONDBLCLK:
			uState = uMsg == WM_LBUTTONUP ? WM_KEYUP : WM_KEYDOWN;
			wKey = VK_LBUTTON;
			break;
		case WM_XBUTTONDOWN:
		case WM_XBUTTONUP:
		case WM_XBUTTONDBLCLK:
			uState = uMsg == WM_XBUTTONUP ? WM_KEYUP : WM_KEYDOWN;
			wKey = wParam == XBUTTON1 ? VK_XBUTTON1 : VK_XBUTTON2;
			break;
		default:
			return;
		}

		return OnMessage(uState, wKey);
	}

	VOID OnKeyboardMessage(UINT uMsg, WPARAM wParam)
	{
		// printf("OnKeyboardMessage: 0x%I64X\n", wParam);

		UINT uState = 0;
		WPARAM wKey = 0;

		switch (uMsg)
		{
		case WM_KEYDOWN:
		case WM_SYSKEYDOWN:
			uState = WM_KEYDOWN;
			wKey = wParam;
			break;
		case WM_KEYUP:
		case WM_SYSKEYUP:
			uState = WM_KEYUP;
			wKey = wParam;
			break;
		default:
			return;
		}

		return OnMessage(uState, wKey);
	}

	VOID OnWindowMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
		case WM_MBUTTONDBLCLK:
		case WM_RBUTTONDBLCLK:
		case WM_LBUTTONDBLCLK:
		case WM_XBUTTONDBLCLK:
		case WM_MBUTTONDOWN:
		case WM_RBUTTONDOWN:
		case WM_LBUTTONDOWN:
		case WM_XBUTTONDOWN:
		case WM_MBUTTONUP:
		case WM_RBUTTONUP:
		case WM_LBUTTONUP:
		case WM_XBUTTONUP:
			OnMouseMessage(uMsg, wParam);
			break;
		case WM_KEYDOWN:
		case WM_KEYUP:
		case WM_SYSKEYDOWN:
		case WM_SYSKEYUP:
			OnKeyboardMessage(uMsg, wParam);
			break;
		default:
			return;
		}
	}

	LPCSTR GetName(UINT uId)
	{
		if (mCache.count(uId) == 0)
			return NULL;

		return mCache[uId].lpName;
	}

	BOOL GetState(UINT uId, INT iType)
	{
		if (mCache.count(uId) == 0)
			return FALSE;

		if (iType == INPUT_TYPE_HOLD)
			return mCache[uId].bHold;

		else if (iType == INPUT_TYPE_TOGGLE)
			return mCache[uId].bToggle;

		else
			return TRUE;

		return FALSE;
	}

	VOID SetToggleState(UINT uId, BOOL bValue)
	{
		if (mCache.count(uId) == 0)
			return;

		mCache[uId].bToggle = bValue;
	}

	VOID SetWaitInput(WPARAM wValue)
	{
		wWaitInput = wValue;
	}
}