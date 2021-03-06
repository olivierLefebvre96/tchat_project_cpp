#ifdef _WIN32
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <Windows.h>
#include <minwindef.h>
#endif

#include "Server.h"
#include "Global.h"

#ifdef _WIN32
#pragma comment(lib, "wsock32.lib")
#endif

using namespace global;

int main() {
#ifdef _WIN32
	const auto versionWanted = MAKEWORD(1, 1);
	WSADATA wsaData;
	WSAStartup(versionWanted, &wsaData);
#endif

	printf("Server is running!%s", newLine.c_str());

	Server server = Server{};

	// Main loop
	server.server_deployment();

#ifdef _WIN32
	WSACleanup();
#endif
	return 0;
}

