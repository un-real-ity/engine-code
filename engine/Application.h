#pragma once
#include <Windows.h>
#include <string>
#include <chrono>

class Scene;

class Application
{
public:
    void Init(Scene* startScene);
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
    Scene* nowScene;
    std::chrono::high_resolution_clock::time_point lastFrame;
};
