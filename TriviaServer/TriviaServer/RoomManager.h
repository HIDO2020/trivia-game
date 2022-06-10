#ifndef ROOMMANAGER_HEADER
#define ROOMMANAGER_HEADER

#include <iostream>
#include <string>
#include <vector>
#include "Room.h"
#include <map>
class Room;

class RoomManager
{
public:
	RoomManager();
	~RoomManager();
	Room createRoom(std::string name, RoomData data);
	void deleteRoom(int ID);
	unsigned int getRoomState(int ID);
	std::vector<RoomData> getRooms();
	std::map<unsigned int, Room*> getRoomInfo();


private:
	std::map<unsigned int, Room*> m_rooms;	//room ID 
	unsigned int _AmountOoRooms;
};

#endif