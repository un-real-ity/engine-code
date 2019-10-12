#include <windows.h>
#include "Application.h"
#include "Object/Scene.h"

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
    , LPSTR lpszCmdParam, int nCmdShow)
{
    Application app;
	Scene* start = new Scene();
	app.Init(start);
    app.Run();

    return 0;
}