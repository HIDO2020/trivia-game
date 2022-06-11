#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
//#include communicator //makes 282 fucking errors :)
#include "LoggedUser.h"


struct RoomData{
	unsigned int _RoomId;
	std::string _RoomName;
	unsigned int numOfQuestionsInGame;
	unsigned int _MaxPlayers;
	unsigned int _AvgTime;
	unsigned int _Active;
};

class Room
{
public:
	Room(unsigned int RoomId, std::string RoomName, unsigned int MaxPlayers, unsigned int AvgTime, unsigned int Active);
	~Room();

	void addUser(LoggedUser user);
	void removeUser(LoggedUser user);
	std::vector<std::string> getAllUsers();

	unsigned int getRoomState();
	RoomData getRoomData();
	//std::map<SOCKET, std::string> get_socket();
	std::vector<LoggedUser> get_sockets();

private:
	RoomData m_metadata;
	std::vector<LoggedUser> m_users;		//change to LoggedUser
	//std::map<SOCKET, std::string> m_socket;
};
