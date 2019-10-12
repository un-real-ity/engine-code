#include "Renderer.h"

bool Renderer::Init() {
	HRESULT hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &factory);
	if (hr != S_OK)
	{
		return false;
	}
	return true;
}

bool Renderer::LoadResource(HWND hWnd) {
	RECT rt;
	GetClientRect(hWnd, &rt);
	D2D1_SIZE_U size = D2D1::SizeU(rt.right - rt.left, rt.bottom - rt.top);

	HRESULT hr = factory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(hWnd, size, D2D1_PRESENT_OPTIONS_IMMEDIATELY),
		&renderTarget);

	if (hr != S_OK)
	{
		return false;
	}
	return true;
}

Vector2 Renderer::GetDPI()
{
	FLOAT x, y;
	factory->GetDesktopDpi(&x, &y);
	return Vector2(x, y);
}

void Renderer::Render(HWND hWnd)
{
	RECT rc;
	GetClientRect(hWnd, &rc);
	ID2D1SolidColorBrush* pBlackBrush = NULL;
	renderTarget->CreateSolidColorBrush(
		D2D1::ColorF(D2D1::ColorF::Blue),
		&pBlackBrush
	);
	renderTarget->BeginDraw();

	renderTarget->DrawRectangle(
		D2D1::RectF(
			rc.left + 100.0f,
			rc.top + 100.0f,
			rc.right - 100.0f,
			rc.bottom - 100.0f),
		pBlackBrush);

	renderTarget->EndDraw();
}
