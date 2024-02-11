#include "ui.hpp"
#include "ui_backend.hpp"
#include "globals.hpp"
#include "callback.hpp"
#include "fonts.hpp"

ImFont* Bold;
ImFont* Medium;

namespace GuiSettings
{
	extern float WindowWidth = 500.0f;
	extern float WindowHeight = 183.0f;
	extern wchar_t AppName[255] = L"Takumo Loader";
	extern char AppNameImGui[255] = "Takumo Loader";

	extern std::string CurrentTheme = "DarkPurple";
	extern std::string CurrentPage = "Main";

	extern ImVec4 AccentColor = { 0.0f, 0.0f, 0.0f, 0.0f };

	extern ImVec2 ButtonSize = { 485, 18 };
}

void fonts()
{
	auto config = ImFontConfig();
	config.FontDataOwnedByAtlas = false;

	ImGuiIO& io = ImGui::GetIO();
	// ImFont* font_def = io.Fonts->AddFontDefault();
	ImFont* Medium = io.Fonts->AddFontFromMemoryTTF(&MontserratMedium, sizeof(MontserratMedium), 13, &config);
	ImFont* Bold = io.Fonts->AddFontFromMemoryTTF(&MontserratBold, sizeof(MontserratBold), 13, &config);
}

void ui()
{
	CheckTheme();
	if (GuiSettings::CurrentTheme == "DarkPurple") Themes::DarkPurple();
	if (GuiSettings::CurrentTheme == "WhitePurple") Themes::WhitePurple();

	if (GuiSettings::CurrentPage == "Main") Pages::Main();
	if (GuiSettings::CurrentPage == "Settings") Pages::Settings();
}

namespace Pages {
	void Main()
	{
		ImGui::PushFont(Bold);
		{
			ImGui::PushStyleColor(ImGuiCol_Text, GuiSettings::AccentColor);
			ImGui::Text("Takumo Loader");
			ImGui::PopStyleColor();
		}
		ImGui::PopFont();

		ImGui::Separator();

		ImGui::PushFont(Medium);
		{
			ImGui::Text("Takumo Loader is a tool that runs osu! with dev server.");

			ImGui::PushItemWidth(GuiSettings::ButtonSize.x);
			ImGui::Combo("", &VarData::server, ConstData::servers, 11, 3);
			ImGui::PopItemWidth();

			if (VarData::server != ConstData::TotalServers) ImGui::BeginDisabled();
			ImGui::PushItemWidth(398);
			ImGui::InputTextWithHint("Custom server", "okayu.pw", VarData::CustomServer, sizeof(VarData::CustomServer));
			ImGui::PopItemWidth();
			if (VarData::server != ConstData::TotalServers) ImGui::EndDisabled();

			if (VarData::server == 0) ImGui::BeginDisabled();
			if (ImGui::Button("Play with patcher", GuiSettings::ButtonSize)) button::play(true);
			if (VarData::server == 0) ImGui::EndDisabled();

			if (ImGui::Button("Play without patcher", GuiSettings::ButtonSize)) button::play(false);

			if (ImGui::Button("Settings", GuiSettings::ButtonSize)) GuiSettings::CurrentPage = "Settings";
		}
		ImGui::PopFont();
	}
	void Settings()
	{
		ImGui::PushStyleColor(ImGuiCol_Text, GuiSettings::AccentColor);
		ImGui::Text("Settings");
		ImGui::PopStyleColor();

		ImGui::Separator();

		ImGui::PushItemWidth(370);
		ImGui::InputTextWithHint("Custom path to osu!", "D:\\osu!", VarData::CustomPath, sizeof(VarData::CustomPath));
		ImGui::PopItemWidth();

		ImGui::PushItemWidth(442);
		ImGui::Combo("Theme", &VarData::ActiveTheme, ConstData::themes, 2, 2);
		ImGui::PopItemWidth();

		ImGui::SetCursorPos({ 8, 155 });
		if (ImGui::Button("Back", GuiSettings::ButtonSize)) GuiSettings::CurrentPage = "Main";
	}
}

namespace Themes {
	void DarkPurple()
	{
		ImGuiStyle* style = &ImGui::GetStyle();

		style->WindowRounding = 4.0f;
		style->WindowBorderSize = 2.0f;
		style->FrameRounding = 4.0f;
		style->PopupRounding = 4.0f;
		style->WindowTitleAlign = ImVec2(0.5f, 0.5f);
		style->FrameBorderSize = 1.0f;

		GuiSettings::AccentColor = { 0.55f, 0.41f, 0.90f, 1.00f };
		style->Colors[ImGuiCol_TitleBgActive] = ImVec4(0.45f, 0.36f, 0.70f, 1.00f);
		style->Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		style->Colors[ImGuiCol_WindowBg] = ImVec4(0.12f, 0.12f, 0.12f, 1.00f);
		style->Colors[ImGuiCol_Button] = ImVec4(0.55f, 0.41f, 0.90f, 0.75f);
		style->Colors[ImGuiCol_ButtonHovered] = ImVec4(0.63f, 0.52f, 0.90f, 1.00f);
		style->Colors[ImGuiCol_ButtonActive] = ImVec4(0.55f, 0.41f, 0.90f, 1.00f);
		style->Colors[ImGuiCol_FrameBg] = ImVec4(0.43f, 0.43f, 0.43f, 0.39f);
		style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.47f, 0.47f, 0.69f, 0.40f);
		style->Colors[ImGuiCol_FrameBgActive] = ImVec4(0.42f, 0.41f, 0.64f, 0.69f);
		style->Colors[ImGuiCol_Header] = ImVec4(0.55f, 0.41f, 0.90f, 0.45f);
		style->Colors[ImGuiCol_HeaderHovered] = ImVec4(0.55f, 0.41f, 0.90f, 0.80f);
		style->Colors[ImGuiCol_HeaderActive] = ImVec4(0.68f, 0.55f, 0.98f, 0.80f);
		style->Colors[ImGuiCol_PopupBg] = ImVec4(0.15f, 0.15f, 0.15f, 1.00f);
	}

	void WhitePurple()
	{
		ImGuiStyle* style = &ImGui::GetStyle();

		style->WindowRounding = 4.0f;
		style->WindowBorderSize = 2.0f;
		style->FrameRounding = 4.0f;
		style->WindowTitleAlign = ImVec2(0.5f, 0.5f);

		GuiSettings::AccentColor = { 0.55f, 0.41f, 0.90f, 1.00f };
		style->Colors[ImGuiCol_TitleBgActive] = ImVec4(0.60f, 0.47f, 0.94f, 1.00f);
		style->Colors[ImGuiCol_Text] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
		style->Colors[ImGuiCol_WindowBg] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		style->Colors[ImGuiCol_Button] = ImVec4(0.55f, 0.41f, 0.90f, 0.75f);
		style->Colors[ImGuiCol_ButtonHovered] = ImVec4(0.78f, 0.68f, 0.95f, 1.00f);
		style->Colors[ImGuiCol_ButtonActive] = ImVec4(0.55f, 0.41f, 0.90f, 1.00f);
		style->Colors[ImGuiCol_FrameBg] = ImVec4(0.43f, 0.43f, 0.43f, 0.39f);
		style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.47f, 0.47f, 0.69f, 0.40f);
		style->Colors[ImGuiCol_FrameBgActive] = ImVec4(0.42f, 0.41f, 0.64f, 0.69f);
		style->Colors[ImGuiCol_Header] = ImVec4(0.55f, 0.41f, 0.90f, 0.45f);
		style->Colors[ImGuiCol_HeaderHovered] = ImVec4(0.55f, 0.41f, 0.90f, 0.80f);
		style->Colors[ImGuiCol_HeaderActive] = ImVec4(0.68f, 0.55f, 0.98f, 0.80f);
		style->Colors[ImGuiCol_PopupBg] = ImVec4(0.95f, 0.95f, 0.95f, 1.00f);
	}
}
