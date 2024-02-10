#pragma once
#include <windows.h>

LRESULT WndProcHandler(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

BOOL RenderTabs();
BOOL RenderHandler(PVOID lpRenderParameter);

