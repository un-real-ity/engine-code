#include <unordered_map>
#include "Application.h"
#include "Object/Scene.h"

std::unordered_map<HWND, Application*> applications;

LRESULT CALLBACK GlobalWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
    if (applications[hWnd] == nullptr)
        return DefWindowProc(hWnd, iMessage, wParam, lParam);

    return applications[hWnd]->WndProc(iMessage, wParam, lParam);
}

LRESULT CALLBACK Application::WndProc(UINT iMessage, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;

    switch (iMessage)
    {
    case WM_CREATE:
        return 0;
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        EndPaint(hWnd, &ps);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_SIZE:
        return 0;
    }

    return DefWindowProc(hWnd, iMessage, wParam, lParam);
}

void Application::MakeWindow(const std::wstring& title, int width, int height)
{
    auto instance = GetModuleHandle(nullptr);

    WNDCLASS WndClass;

    WndClass.cbClsExtra = 0;
    WndClass.cbWndExtra = 0;
    WndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    WndClass.hInstance = instance;
    WndClass.lpfnWndProc = GlobalWndProc;
    WndClass.lpszClassName = L"ENGINE";
    WndClass.lpszMenuName = NULL;
    WndClass.style = CS_HREDRAW | CS_VREDRAW;
    RegisterClass(&WndClass);

    hWnd = CreateWindow(L"ENGINE", title.c_str(),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        width, height, NULL, (HMENU)NULL, instance, NULL);

    applications[hWnd] = this;

    ShowWindow(hWnd, SW_SHOWNORMAL);
}

void Application::GameLoop()
{
	auto now = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> delta = now - lastFrame;

	nowScene->Update(delta.count());

	lastFrame = now;
}

void Application::Init(Scene* startScene)
{
    MakeWindow(L"test", 100, 100);
	nowScene = startScene;
}

void Application::Run()
{
	lastFrame = std::chrono::high_resolution_clock::now();
    while (true)
    {
        MSG message;

        if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
        {
            if (message.message == WM_QUIT)
                break;

            TranslateMessage(&message);
            DispatchMessage(&message);
        }
        else
        {
            GameLoop();
        }
    }
}