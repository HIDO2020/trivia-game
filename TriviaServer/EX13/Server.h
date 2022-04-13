#pragma once

#include <WinSock2.h>
#include <Windows.h>
#include "Server.h"
#include <exception>
#include <iostream>
#include <string>
#include <thread>
#include <string>
#include "LoginManager.h"
//#include "fileHandle.h"
#include <fstream>


class Server
{
public:
	Server();
	~Server();
	void handle_messages(int port);
	void serve(int port);
	void clientHandler(SOCKET clientSocket);
	void acceptClient();
	std::string convertToString(char* a, int start, int end);

private:
	SOCKET _serverSocket;
	LoginManager _user;
};
