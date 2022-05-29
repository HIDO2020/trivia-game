#include <iostream>
#include <string>
#include <vector>
#include "Room.h"
#include <map>


class RoomManager
{
public:
	RoomManager();
	~RoomManager();
	void createRoom(std::string name, RoomData data);
	void deleteRoom(int ID);
	unsigned int getRoomState(int ID);
	std::vector<RoomData> getRooms();


private:
	std::map<unsigned int, Room> m_rooms;	//room ID 
	unsigned int _AmountOoRooms;
};

