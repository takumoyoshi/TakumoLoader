#pragma warning(disable : 4996)

#include "userdata.hpp"
#include "globals.hpp"

#include <nlohmann/json.hpp>
#include <Windows.h>
#include <fstream>

using json = nlohmann::json;

void LoadData()
{
	std::string LocalAppdata = getenv("Localappdata");

	std::ifstream file((LocalAppdata + "\\TakumoLoader\\user.data").c_str());

	if (!file)
	{
		CreateDirectory((LocalAppdata + "\\TakumoLoader").c_str(), NULL);
		std::ofstream CreatedFile((LocalAppdata + "\\TakumoLoader\\user.data").c_str());
		json Data = { {"server", VarData::server}, {"path", ""}, {"CustomServer", ""}, {"ActiveTheme", VarData::ActiveTheme} };
		CreatedFile << Data.dump();
		return;
	}

	json Data = json::parse(file);
	VarData::server = Data["server"].get<int>();
	memcpy(VarData::CustomPath, Data["path"].get<std::string>().c_str(), Data["path"].get<std::string>().size());
	memcpy(VarData::CustomServer, Data["CustomServer"].get<std::string>().c_str(), Data["CustomServer"].get<std::string>().size());
	VarData::ActiveTheme = Data["ActiveTheme"].get<int>();
}

void SaveData()
{
	std::string LocalAppdata = getenv("Localappdata");

	std::remove((LocalAppdata + "\\TakumoLoader\\user.data").c_str());

	std::ofstream CreatedFile((LocalAppdata + "\\TakumoLoader\\user.data").c_str());
	json Data = { {"server", VarData::server}, {"path", ""}, {"CustomServer", ""}, {"ActiveTheme", VarData::ActiveTheme} };
	CreatedFile << Data.dump();
}

void EditCfg()
{


	std::ifstream inputFile("in.txt");
	std::vector<std::string> lines;
	std::string line;

	while (std::getline(inputFile, line)) {
		lines.push_back(line);
	}
	inputFile.close();

	lines[141] = "";

	std::ofstream outputFile("in.txt");
	for (const std::string& l : lines) {
		outputFile << l << std::endl;
	}
	outputFile.close();
}
