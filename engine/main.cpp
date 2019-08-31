#include <windows.h>
#include "Application.h"

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
    , LPSTR lpszCmdParam, int nCmdShow)
{
    Application app;
    app.Run();

    return 0;
}