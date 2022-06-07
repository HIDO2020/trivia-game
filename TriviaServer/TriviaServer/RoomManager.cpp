#include "RoomManager.h"
extern int id_count;

RoomManager::RoomManager()
{
	this->_AmountOoRooms = 0;
	this->m_rooms.clear();
}

RoomManager::~RoomManager()
{
	this->_AmountOoRooms = 0;
	this->m_rooms.clear();
}

void RoomManager::createRoom(std::string name, RoomData data)
{
	Room r(data._RoomId, data._RoomName, data._MaxPlayers, data._AvgTime, data._Active);
	this->m_rooms.insert(std::pair<unsigned int, Room>(this->_AmountOoRooms, r));
	this->_AmountOoRooms++;
	id_count++;
}

void RoomManager::deleteRoom(int ID)
{
	this->m_rooms.erase(ID);
	this->_AmountOoRooms--;
}

unsigned int RoomManager::getRoomState(int ID)
{
	auto it = this->m_rooms.find(ID);
	return it->second.getRoomState();
}

std::vector<RoomData> RoomManager::getRooms()
{
	std::vector<RoomData> copy;
	auto iter = this->m_rooms.begin();
	while (iter != this->m_rooms.end())
	{
		copy.push_back(iter->second.getRoomData());
		++iter;
	}
	return copy;
}

std::map<unsigned int, Room> RoomManager::getRoomInfo()
{
	return this->m_rooms;
}
