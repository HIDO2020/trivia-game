#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>


typedef struct {
	unsigned int _RoomId;
	std::string _RoomName;
	unsigned int _MaxPlayers;
	unsigned int _AvgTime;
	unsigned int _Active;
}RoomData;

class Room
{
public:
	Room(unsigned int RoomId, std::string RoomName, unsigned int MaxPlayers, unsigned int AvgTime, unsigned int Active);
	~Room();
	void addUser(std::string user);
	void removeUser(std::string user);
	std::vector<std::string> getAllUsers();
	unsigned int getRoomState();
	RoomData getRoomData();

private:
	RoomData m_metadata;
	std::vector<std::string> m_users;		//change to LoggedUser

};
