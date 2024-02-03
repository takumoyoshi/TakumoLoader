#pragma once

#include <imgui.h>
#include <imgui_impl_win32.h>
#include <imgui_impl_dx11.h>
#include <imgui_freetype.h>
#include <d3d11.h>
#include <tchar.h>
#include <dwmapi.h>

int RenderUi();
void ChangeWindowSize(int width, int height);
void CheckTheme();
