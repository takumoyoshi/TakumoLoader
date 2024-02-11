#pragma once

#include <string>
#include <vector>

namespace VarData
{
	extern int server;
	extern char CustomPath[255];
	extern char CustomServer[255];

	extern int ActiveTheme;

	extern std::string username;
	extern std::string password;
}

namespace ConstData
{
	extern const int TotalServers;
	extern const char* servers[11];
	extern const char* DevserverFlag[10];

	extern const char* themes[2];
}
