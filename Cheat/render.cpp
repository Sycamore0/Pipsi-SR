#include "render.h"

#include "globals.h"
#include "cheats.h"

#include "hooks.h"

#include "imgui_internal.h"
#include "imgui_impl_dx11.h"
#include "imgui_impl_win32.h"

BOOL bInitialized = FALSE;

PVOID lpWndProcHandler = NULL;
PVOID lpRenderProcHandler = NULL;

ID3D11Device* lpDevice = NULL;
ID3D11DeviceContext* lpContext = NULL;
ID3D11Texture2D* lpBackBuffer = NULL;
ID3D11RenderTargetView* lpMainRenderTargetView = NULL;

BOOL GetFunctionPointers(PVOID* Present, PVOID* Resize)
{
	WNDCLASSEXA Wc = {};

	Wc.cbSize = sizeof(Wc);
	Wc.lpfnWndProc = DefWindowProcA;
	Wc.lpszClassName = "WndClass";

	if (!RegisterClassExA(&Wc))
		return FALSE;

	HWND hWnd = CreateWindowA(Wc.lpszClassName, "WndName", WS_DISABLED, 0, 0, 0, 0, NULL, NULL, NULL, NULL);

	DXGI_SWAP_CHAIN_DESC Sd = {};

	Sd.BufferCount = 1;
	Sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	Sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	Sd.OutputWindow = hWnd;
	Sd.SampleDesc.Count = 1;
	Sd.Windowed = TRUE;
	Sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	Sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	Sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

	IDXGISwapChain* lpSwapchain = NULL;

	D3D_FEATURE_LEVEL dwFeatureLevel = {};

	if (FAILED(D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_WARP, NULL, 0, NULL, 1, D3D11_SDK_VERSION, &Sd, &lpSwapchain, &lpDevice, &dwFeatureLevel, &lpContext)) && FAILED(D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, 0, NULL, 0, D3D11_SDK_VERSION, &Sd, &lpSwapchain, &lpDevice, &dwFeatureLevel, &lpContext)))
	{
		DestroyWindow(Sd.OutputWindow);
		UnregisterClassA(Wc.lpszClassName, GetModuleHandleA(NULL));

		return FALSE;
	}

	PVOID* lpVtable = *reinterpret_cast<PVOID**>(lpSwapchain);

	*Present = lpVtable[8];
	*Resize = lpVtable[13];

	lpDevice->Release();
	// lpContext->Release();
	lpSwapchain->Release();

	DestroyWindow(Sd.OutputWindow);
	UnregisterClassA(Wc.lpszClassName, GetModuleHandleA(NULL));

	return TRUE;
}

HRESULT PresentHandler(IDXGISwapChain* lpSwapchain, UINT dwSyncInterval, UINT dwFlags)
{
	if (!bInitialized) {
		HRESULT hResult = lpSwapchain->GetDevice(__uuidof(lpDevice), (PVOID*)&lpDevice);

		if (SUCCEEDED(hResult)) {
			DXGI_SWAP_CHAIN_DESC Sd = {};

			lpSwapchain->GetDesc(&Sd);

			lpDevice->GetImmediateContext(&lpContext);

			ImGui::CreateContext();

			lpWndProc = (WNDPROC)(SetWindowLongPtrA(Sd.OutputWindow, GWLP_WNDPROC, (LONG_PTR)lpWndProcHandler));

			ImGui_ImplWin32_Init(Sd.OutputWindow);
			ImGui_ImplDX11_Init(lpDevice, lpContext);

			lpSwapchain->GetBuffer(0, __uuidof(ID3D11Texture2D), (PVOID*)&lpBackBuffer);

			if (lpBackBuffer) {
				lpDevice->CreateRenderTargetView(lpBackBuffer, NULL, &lpMainRenderTargetView);

				lpBackBuffer->Release();
			}

			// io.SetPlatformImeDataFn = NULL;

			Cheats::Start();

			bInitialized = TRUE;
		}
	}

	if (bInitialized) {
		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();

		ImGui::NewFrame();

		if (lpRenderProcHandler)
			((VOID(*)())(lpRenderProcHandler))();

		ImGui::EndFrame();
		ImGui::Render();

		lpContext->OMSetRenderTargets(1, &lpMainRenderTargetView, NULL);

		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	}

	return CALL_ORIGIN(PresentHandler, lpSwapchain, dwSyncInterval, dwFlags);
}

HRESULT ResizeHandler(IDXGISwapChain* lpSwapchain, UINT dwBufferCount, UINT dwWidth, UINT dwHeight, DXGI_FORMAT dwNewFormat, UINT dwFlags)
{
	if (lpContext && lpMainRenderTargetView) {
		lpContext->OMSetRenderTargets(0, 0, 0);

		lpMainRenderTargetView->Release();
		lpMainRenderTargetView = NULL;
	}

	HRESULT hResult = CALL_ORIGIN(ResizeHandler, lpSwapchain, dwBufferCount, dwWidth, dwHeight, dwNewFormat, dwFlags);

	lpSwapchain->GetBuffer(0, __uuidof(ID3D11Texture2D), (PVOID*)&lpBackBuffer);

	if (lpBackBuffer) {
		lpDevice->CreateRenderTargetView(lpBackBuffer, NULL, &lpMainRenderTargetView);

		lpContext->OMSetRenderTargets(1, &lpMainRenderTargetView, NULL);

		D3D11_VIEWPORT Vp = {};

		Vp.Width = (FLOAT)dwWidth;
		Vp.Height = (FLOAT)dwHeight;
		Vp.MinDepth = 0.0f;
		Vp.MaxDepth = 1.0f;
		Vp.TopLeftX = 0.f;
		Vp.TopLeftY = 0.f;

		lpContext->RSSetViewports(1, &Vp);

		lpBackBuffer->Release();
	}

	return hResult;
}

BOOL RenderSetup(PVOID WndProcHandler, PVOID RenderProcHandler)
{
	PVOID Present = NULL;
	PVOID Resize = NULL;

	if (!GetFunctionPointers(&Present, &Resize))
		return FALSE;

	lpWndProcHandler = WndProcHandler;
	lpRenderProcHandler = RenderProcHandler;

	CreateHook(Present, PresentHandler);
	CreateHook(Resize, ResizeHandler);

	return TRUE;
}