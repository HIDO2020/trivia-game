#pragma once

#include <WinSock2.h>
#include <Windows.h>
#include <exception>
#include "IRequestHandler.h"
#include <iostream>
#include <string>
#include <thread>
#include <fstream>
#include <map>

#define USERSTART 5
#define NAMESTART 2
#define ASCI_TO_INT 48
#define LEN_OF_MESSAGE 100

#define min(a,b) ((a) < (b) ? (a) : (b))

class Communicator
{
public:
	Communicator();
	~Communicator();
	void handle_messages(int port);
	void startHandleRequest(SOCKET clientSocket);
	std::string convertToString(char* a, int start, int end);

private:
	void bindAndListen(int port);
	void handleNewClient(SOCKET clientSocket);

	std::map<SOCKET, IRequestHandler*> m_clients;
	SOCKET _serverSocket;
};
