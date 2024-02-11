#include "ui_backend.hpp"
#include "userdata.hpp"

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	LoadData();
	RenderUi();
}