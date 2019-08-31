#include <map>
#include "Application.h"

std::map<HWND, Application*> applications;

LRESULT CALLBACK GlobalWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
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

    ShowWindow(hWnd, SW_SHOWNORMAL);
}

void Application::GameLoop()
{

}

void Application::Init()
{
    MakeWindow(L"test", 100, 100);
    applications[hWnd] = this;
}

void Application::Run()
{
    Init();

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