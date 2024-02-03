#pragma once

#include <imgui.h>
#include <imgui_impl_win32.h>
#include <imgui_impl_dx11.h>
#include <imgui_internal.h>
#include <string>
#include <cstring>

namespace GuiSettings
{
	extern float WindowWidth;
	extern float WindowHeight;
	extern wchar_t AppName[255];
	extern char AppNameImGui[255];

	extern std::string CurrentTheme;
	extern std::string CurrentPage;

	extern ImVec4 AccentColor;

	extern ImVec2 ButtonSize;
}

namespace Pages {
	void Main();
	void Settings();
}

namespace Themes {
	void DarkPurple();
	void WhitePurple();
}

void fonts();
void ui();
