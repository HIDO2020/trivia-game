#pragma once

#include <WinSock2.h>
#include <Windows.h>
#include <exception>
#include <iostream>
#include <string>
#include <thread>
#include <fstream>

#define USERSTART 5
#define NAMESTART 2
#define ASCI_TO_INT 48
#define LEN_OF_MESSAGE 50

#define min(a,b) ((a) < (b) ? (a) : (b))

class Communicator
{
public:
	Communicator();
	~Communicator();
	void handle_messages(int port);
	void startHandleRequest(SOCKET clientSocket);
	void bindAndListen(int port);
	std::string convertToString(char* a, int start, int end);

private:
	SOCKET _serverSocket;
};
