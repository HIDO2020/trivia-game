#pragma comment (lib, "ws2_32.lib")

#include "WSAInitializer.h"
#include <iostream>
#include <exception>
#include "Communicator.h"
#include <stdlib.h>
#include <thread>
#include <vector>;
#include "sqlite3.h"
#include "IDataAccess.h"
#include "SqliteDatabase.h"
#include "JsonResponsePacketSerializer.h"
#include "JsonRequestPacketDeserializer.h"


void handle_stop()
{
	std::string input;

	while (true)
	{
		std::cin >> input;
		if (input == "EXIT")
		{
			exit(3);
		}
	}
	system("STOP"); //add an actual exit instead of a pop up message
}

int main()
{
	SqliteDatabase dataAccess;
	//.open();
	RequestHandlerFactory fact(dataAccess);
	SignupResponse message1;
	message1.status = 100;
	std::vector<unsigned char> test = JsonResponsePacketSerializer::serializeResponse(message1);

	//SignupRequest test2 = JsonRequestPacketDeserializer::deserializeSignupRequest(test);
	WSAInitializer wsaInit;
	Communicator myServer(dataAccess, fact);
	std::thread connect(&Communicator::handle_messages, myServer, 8826);
	std::thread stop(handle_stop);
	std::this_thread::sleep_for(std::chrono::seconds(600));			//GET TIME OUT AFTER 10 MIN
	std::cout << "TIMEOUT" << std::endl;
	connect.detach();
	system("PAUSE");
	return 0;
}
