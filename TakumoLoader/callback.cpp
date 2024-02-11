#pragma warning(disable : 4996)

#include "callback.hpp"
#include "globals.hpp"
#include "userdata.hpp"

#include <imgui.h>
#include <imgui_impl_win32.h>
#include <imgui_impl_dx11.h>
#include <imgui_internal.h>
#include <string>
#include <cstring>
#include <windows.h>
#include <fstream>

namespace button
{
	void play(bool patcher)
	{
		STARTUPINFOA StartInfo = { 0 };
		StartInfo.cb = sizeof(StartInfo);
		PROCESS_INFORMATION ProcOsuInfo = { 0 };
		std::string LocalAppdata = getenv("Localappdata");

		std::string DevserverFlag = "";
		if (VarData::server != ConstData::TotalServers)
		{
			DevserverFlag = ConstData::DevserverFlag[VarData::server];
		}
		else
		{
			DevserverFlag = VarData::CustomServer;
		}

		std::string OsuPath;
		if (strcmp(VarData::CustomPath, ""))
		{
			OsuPath = std::string(VarData::CustomPath) + "\\osu!.exe";
		}
		else
		{
			OsuPath = LocalAppdata + "\\osu!\\osu!.exe";
		}

		std::string cLine1 = "code /v /t -devserver " + DevserverFlag;
		char cLine[100];
		strncpy(cLine, cLine1.c_str(), 100);

		CreateProcessA(OsuPath.c_str(), cLine, NULL, NULL, 0, 0, NULL, NULL, &StartInfo, &ProcOsuInfo);

		if (patcher)
		{
			std::string PatcherPath;
			if (std::strcmp(VarData::CustomPath, ""))
			{
				PatcherPath = std::string(VarData::CustomPath) + "\\Patcher\\osu!.patcher.exe";
			}
			else
			{
				PatcherPath = LocalAppdata + "\\osu!\\Patcher\\osu!.patcher.exe";
			}

			PROCESS_INFORMATION ProcPatcherInfo = { 0 };
			CreateProcessA(PatcherPath.c_str(), NULL, NULL, NULL, 0, 0, NULL, NULL, &StartInfo, &ProcPatcherInfo);
			CloseHandle(ProcPatcherInfo.hProcess);
			CloseHandle(ProcPatcherInfo.hThread);
		}

		CloseHandle(ProcOsuInfo.hProcess);
		CloseHandle(ProcOsuInfo.hThread);

		SaveData();
		exit(1);
	}

	void up_load()
	{

	}
}

// 142 149
