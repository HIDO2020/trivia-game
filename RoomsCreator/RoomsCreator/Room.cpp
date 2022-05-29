#include "Room.h"

Room::Room(unsigned int RoomId, std::string RoomName, unsigned int MaxPlayers, unsigned int AvgTime, unsigned int Active)
{
	this->m_metadata._AvgTime = AvgTime;
	this->m_metadata._Active = Active;
	this->m_metadata._MaxPlayers = MaxPlayers;
	this->m_metadata._RoomId = RoomId;
	this->m_metadata._RoomName = RoomName;
	this->m_users.clear();
}

Room::~Room()
{
	this->m_metadata._AvgTime = 0;
	this->m_metadata._Active = 0;
	this->m_metadata._MaxPlayers = 0;
	this->m_metadata._RoomId = 0;
	this->m_metadata._RoomName = "";
	this->m_users.clear();
}

void Room::addUser(std::string user)
{
	this->m_users.push_back(user);
}

void Room::removeUser(std::string user)
{
	this->m_users.erase(std::remove(this->m_users.begin(), this->m_users.end(), user), this->m_users.end());
}

std::vector<std::string> Room::getAllUsers()
{
	return this->m_users;
}

unsigned int Room::getRoomState()
{
	return this->m_metadata._Active;
}

RoomData Room::getRoomData()
{
	return this->m_metadata;
}

