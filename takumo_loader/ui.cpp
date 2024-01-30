#include "ui.hpp"
#include "ui_backend.hpp"
#include "globals.hpp"
#include "callback.hpp"

namespace GuiSettings
{
	extern float WindowWidth = 501.0f;
	extern float WindowHeight = 202.0f;
	extern wchar_t AppName[255] = L"Takumo Loader";

	extern std::string CurrentTheme = "DarkPurple";
	extern std::string CurrentPage = "Main";

	extern ImVec4 AccentColor = { 0.0f, 0.0f, 0.0f, 0.0f };
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
		ImGui::PushStyleColor(ImGuiCol_Text, GuiSettings::AccentColor);
		ImGui::Text("Takumo Loader");
		ImGui::PopStyleColor();

		ImGui::Separator();

		 ImGui::Text("Takumo Loader is a tool that run osu with on devserver server.");

		ImGui::PushItemWidth(469);
		ImGui::Combo("", &VarData::server ,ConstData::servers, 10, 3);
		ImGui::PopItemWidth();

		if (VarData::server != 9) ImGui::BeginDisabled();
		ImGui::PushItemWidth(371);
		ImGui::InputTextWithHint("Custom server", "okayu.pw", VarData::CustomServer, sizeof(VarData::CustomServer));
		ImGui::PopItemWidth();
		if (VarData::server != 9) ImGui::EndDisabled();

		if (VarData::server == 0) ImGui::BeginDisabled();
		if (ImGui::Button("Play with patcher", ImVec2(469, 18))) button::play(true);
		if (VarData::server == 0) ImGui::EndDisabled();

		if (ImGui::Button("Play without patcher", ImVec2(469, 18))) button::play(false);

		if (ImGui::Button("Settings", ImVec2(469, 18))) GuiSettings::CurrentPage = "Settings";
	}
	void Settings()
	{
		ImGui::PushStyleColor(ImGuiCol_Text, GuiSettings::AccentColor);
		ImGui::Text("Settings");
		ImGui::PopStyleColor();

		ImGui::Separator();

		ImGui::PushItemWidth(328);
		ImGui::InputTextWithHint("Custom path to osu!", "D:\\osu!", VarData::CustomPath, sizeof(VarData::CustomPath));
		ImGui::PopItemWidth();

		ImGui::PushItemWidth(425);
		ImGui::Combo("Theme", &VarData::ActiveTheme, ConstData::themes, 2, 2);
		ImGui::PopItemWidth();

		ImGui::SetCursorPos({ 8, 136 });
		if (ImGui::Button("Back", ImVec2(469, 18))) GuiSettings::CurrentPage = "Main";
	}
}

namespace Themes {
	void DarkPurple()
	{
		ImGuiStyle* style = &ImGui::GetStyle();

		style->WindowBorderSize = 0.0f;
		style->FrameRounding = 4.0f;
		style->PopupRounding = 4.0f;

		GuiSettings::AccentColor = { 0.55f, 0.41f, 0.90f, 1.00f };
		style->Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		style->Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.05f, 0.05f, 1.00f);
		style->Colors[ImGuiCol_Button] = ImVec4(0.55f, 0.41f, 0.90f, 0.75f);
		style->Colors[ImGuiCol_ButtonHovered] = ImVec4(0.63f, 0.52f, 0.90f, 1.00f);
		style->Colors[ImGuiCol_ButtonActive] = ImVec4(0.55f, 0.41f, 0.90f, 1.00f);
		style->Colors[ImGuiCol_FrameBg] = ImVec4(0.43f, 0.43f, 0.43f, 0.39f);
		style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.47f, 0.47f, 0.69f, 0.40f);
		style->Colors[ImGuiCol_FrameBgActive] = ImVec4(0.42f, 0.41f, 0.64f, 0.69f);
		style->Colors[ImGuiCol_Header] = ImVec4(0.55f, 0.41f, 0.90f, 0.45f);
		style->Colors[ImGuiCol_HeaderHovered] = ImVec4(0.55f, 0.41f, 0.90f, 0.80f);
		style->Colors[ImGuiCol_HeaderActive] = ImVec4(0.68f, 0.55f, 0.98f, 0.80f);
	}

	void WhitePurple()
	{
		ImGuiStyle* style = &ImGui::GetStyle();

		style->WindowBorderSize = 0.0f;
		style->FrameRounding = 4.0f;
		style->PopupRounding = 4.0f;

		GuiSettings::AccentColor = { 0.55f, 0.41f, 0.90f, 1.00f };
		style->Colors[ImGuiCol_Text] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
		style->Colors[ImGuiCol_WindowBg] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		style->Colors[ImGuiCol_Button] = ImVec4(0.55f, 0.41f, 0.90f, 0.75f);
		style->Colors[ImGuiCol_ButtonHovered] = ImVec4(0.63f, 0.52f, 0.90f, 1.00f);
		style->Colors[ImGuiCol_ButtonActive] = ImVec4(0.55f, 0.41f, 0.90f, 1.00f);
		style->Colors[ImGuiCol_FrameBg] = ImVec4(0.43f, 0.43f, 0.43f, 0.39f);
		style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.47f, 0.47f, 0.69f, 0.40f);
		style->Colors[ImGuiCol_FrameBgActive] = ImVec4(0.42f, 0.41f, 0.64f, 0.69f);
		style->Colors[ImGuiCol_Header] = ImVec4(0.55f, 0.41f, 0.90f, 0.45f);
		style->Colors[ImGuiCol_HeaderHovered] = ImVec4(0.55f, 0.41f, 0.90f, 0.80f);
		style->Colors[ImGuiCol_HeaderActive] = ImVec4(0.68f, 0.55f, 0.98f, 0.80f);
		style->Colors[ImGuiCol_PopupBg] = ImVec4(1.000f, 1.000f, 1.000f, 0.900f);
	}
}
