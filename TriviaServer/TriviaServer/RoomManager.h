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
	void createRoom(LoggedUser name, RoomData data);
	void deleteRoom(int ID);
	unsigned int getRoomState(int ID);
	std::vector<RoomData> getRooms();
	std::map<int, Room*> getRoomInfo();


private:
	std::map<int, Room*> m_rooms;	//room ID 
	unsigned int _AmountOoRooms;
};

