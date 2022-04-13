#pragma comment (lib, "ws2_32.lib")

#include "WSAInitializer.h"
#include <iostream>
#include <exception>
#include "Server.h"
#include <thread>
#include <vector>
#include "IDataAccess.h"
#include "SqliteDatabase.h"

void handle_stop()
{
	std::string input;

	while (true)
	{
		std::cin >> input;
		if (input == "EXIT")
		{
			std::cout << "STOP!";
			break;
		}
	}
	system("STOP");
}

int main()
{
	SqliteDatabase database;
	WSAInitializer wsaInit;
	Server myServer(database);
	std::thread connect(&Server::handle_messages, myServer, 8826);
	std::thread stop(handle_stop);
	std::this_thread::sleep_for(std::chrono::seconds(600));			//GET TIME OUT AFTER 10 MIN
	std::cout << "TIMEOUT" << std::endl;
	connect.detach();
	system("PAUSE");
	return 0;
}
