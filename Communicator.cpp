#include "Communicator.h"
#include <exception>
#include <iostream>
#include <string>
#include <thread>
#include <string>
#include <queue>
#include <mutex>
#include <fstream>
#include <iomanip>
#include <algorithm>    
#include <vector>
#include <map>
#include <fstream>

//the queue of the messages
std::queue <std::string> msg;


Communicator::Communicator()
{

	// this server use TCP. that why SOCK_STREAM & IPPROTO_TCP
	// if the server use UDP we will use: SOCK_DGRAM & IPPROTO_UDP
	_serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (_serverSocket == INVALID_SOCKET)
		throw std::exception(__FUNCTION__ " - socket");
}

Communicator::~Communicator()
{
	try
	{
		// the only use of the destructor should be for freeing 
		// resources that was allocated in the constructor
		closesocket(_serverSocket);
	}
	catch (...) {}
}

void Communicator::handle_messages(int port)
{
	std::string s = "";
	std::thread th(&Communicator::bindAndListen, this, 8826);
	while (true)
	{
		if (!msg.empty())
		{
			//get from queue
			s = msg.front();
			msg.pop();
			//get the socket
			std::string soc = s.substr(0, 3);
			SOCKET tmp = (stoi(soc));
			s = s.substr(3);
			std::cout << s << std::endl;
			//send message to client
			send(tmp, s.c_str(), s.size(), 0);
		}
	}

	th.detach();
}

void Communicator::bindAndListen(int port)
{
	struct sockaddr_in sa = { 0 };

	sa.sin_port = htons(port); // port that server will listen for
	sa.sin_family = AF_INET;   // must be AF_INET
	sa.sin_addr.s_addr = INADDR_ANY;    // when there are few ip's for the machine. We will use always "INADDR_ANY"

	// Connects between the socket and the configuration (port and etc..)
	if (bind(_serverSocket, (struct sockaddr*)&sa, sizeof(sa)) == SOCKET_ERROR)
		throw std::exception(__FUNCTION__ " - bind");

	// Start listening for incoming requests of clients
	if (listen(_serverSocket, SOMAXCONN) == SOCKET_ERROR)
		throw std::exception(__FUNCTION__ " - listen");
	std::cout << "Listening on port " << port << std::endl;

	while (true)
	{
		// the main thread is only accepting clients 
		// and add then to the list of handlers
		std::cout << "Waiting for client connection request" << std::endl;
		// this accepts the client and create a specific socket from server to this client
		// the process will not continue until a client connects to the server
		SOCKET client_socket = accept(_serverSocket, NULL, NULL);
		if (client_socket == INVALID_SOCKET)
			throw std::exception(__FUNCTION__);

		std::cout << "Client accepted. Server and client can speak" << std::endl;
		// the function that handle the conversation with the client
		std::thread t(&Communicator::startHandleRequest, this, client_socket);
		t.detach();
	}
	
}

/*
convert to string by index
*/
std::string Communicator::convertToString(char* a, int start, int end)
{
	int i;
	std::string s = "";
	for (i = start; i < end; i++) {
		s = s + a[i];
	}
	return s;
}


void Communicator::startHandleRequest(SOCKET clientSocket)
{
	std::cout << "NEW CLIENT\n";
	std::string msg_socket = std::to_string(clientSocket);
	int len = 0;
	char m[LEN_OF_MESSAGE];

	while (true)
	{
		msg.push(msg_socket + "hello");
		recv(clientSocket, m, LEN_OF_MESSAGE, 0);
		len = (m[3] - 48) * 10 + (m[4] - 48);		//ASCI to len of name
		std::cout << "receaved: " << m << std::endl;
	}
}
