#pragma once
#include <windows.h>

#include <map>

#define CALL_ORIGIN(function, ...) \
	CallHookOrigin(function, __func__, __VA_ARGS__)

PVOID GetHookOrigin(PVOID lpHandler, LPCSTR caller_name = NULL);

VOID CreateHook(PVOID lpFunction, PVOID lpHandler);
VOID DeleteHook(PVOID lpHandler);

template <typename T, typename... P>
static T CallHookOrigin(T(*lpHandler)(P...), LPCSTR lsCallerName = NULL, P... lpParams)
{
	PVOID lpOrigin = GetHookOrigin(lpHandler, lsCallerName);

	if (lpOrigin != NULL)
		return ((T(*)(P...))(lpOrigin))(lpParams...);

	return T();
}

VOID DeleteHooks();