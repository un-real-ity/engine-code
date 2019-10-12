#pragma once
#include <Windows.h>
#include <string>
#include "Renderer/Renderer.h"

class Application
{
public:
    void Init();
    void Run();
    LRESULT CALLBACK WndProc(UINT iMessage, WPARAM wParam, LPARAM lParam);

    HWND getWindowHandle()
    {
        return hWnd;
    }

private:
    void MakeWindow(const std::wstring& title, int width, int height);
    void GameLoop();
    HWND hWnd;
	Renderer renderer;
};
