#include "globals.hpp"

namespace VarData
{
	int server = 0;
	char CustomPath[255] = "";
	char CustomServer[255] = "";

	int ActiveTheme = 0;

	std::string username = "takumoyoshi";
	std::string password = "banana";
}

namespace ConstData
{
	const int TotalServers = 10;

	const char* servers[TotalServers + 1]
	{
		"Bancho (Patcher is not supported)",
		"<3 Okayu",
		"<3 Ascension",
		"<3 Destiny",
		"Gatari",
		"Akatsuki",
		"Ez-pp farm",
		"Realistik",
		"Heia",
		"Turu",
		"custom"
	};
	const char* DevserverFlag[TotalServers]
	{
		"",
		"okayu.pw",
		"ascension.wtf",
		"osudestiny.xyz",
		"gatari.pw",
		"akatsuki.pw",
		"ez-pp.farm",
		"ussr.pl",
		"heia.kim",
		"turuturuone.xyz"
	};

	const char* themes[2]
	{
		"Dark purple",
		"White purple"
	};
}
