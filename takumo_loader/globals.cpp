#include "globals.hpp"

namespace VarData
{
	extern int server = 0;
	extern char CustomPath[255] = "";
	extern char CustomServer[255] = "";

	extern int ActiveTheme = 0;
}

namespace ConstData
{
	extern const char* servers[10]
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
	extern const char* DevserverFlag[9]
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

	extern const char* themes[2]
	{
		"Dark purple",
		"White purple"
	};
}
