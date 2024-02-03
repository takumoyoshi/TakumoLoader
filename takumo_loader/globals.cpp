#include "globals.hpp"

namespace VarData
{
	int server = 0;
	char CustomPath[255] = "";
	char CustomServer[255] = "";

	int ActiveTheme = 0;
}

namespace ConstData
{
	const char* servers[10]
	{
		"Bancho (Patcher is not supported)",
		"<3 Okayu",
		"<3 ascension",
		"<3 destiny",
		"gatari",
		"akatsuki",
		"ez-pp farm",
		"realistik",
		"heia",
		"custom"
	};
	const char* DevserverFlag[9]
	{
		"",
		"okayu.pw",
		"ascension.wtf",
		"osudestiny.xyz",
		"gatari.pw",
		"akatsuki.pw",
		"ez-pp.farm",
		"ussr.pl",
		"heia.kim"
	};

	const char* themes[2]
	{
		"Dark purple",
		"White purple"
	};
}
