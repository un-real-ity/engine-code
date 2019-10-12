#pragma once
#include <Windows.h>
#include <d2d1.h>
#include "Utils/Vector2.h";

#ifdef _DEBUG
#pragma comment(lib, "d2d1.lib") 
#pragma comment(lib, "dwrite.lib")
#else // RELEASE
#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "dwrite.lib")
#endif

class Renderer
{
public:
	bool Init();
	bool LoadResource(HWND hWnd);
	Vector2 GetDPI();

	void Render(HWND hWnd);

private:
	ID2D1Factory * factory;
	ID2D1HwndRenderTarget* renderTarget;
};
