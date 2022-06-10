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

void Room::addUser(LoggedUser user) //void Room::addUser(LoggedUser user, SOCKET s)
{
	this->m_users.push_back(user);
	//this->m_socket.insert(std::make_pair(s, user.getUsername()));
}

void Room::removeUser(LoggedUser user)
{
	int j = 0;
	int size = m_users.size();
	//LoggedUser l(user.getUsername());

	for (auto& i : m_users)
	{
		if (i.getUsername() == user.getUsername())
		{
			m_users.erase(m_users.begin() + j);
			break;
		}
		j++;
	}

	/*for (auto it = m_socket.begin(); it != m_socket.end(); ++it) {
		if (it->second == user.getUsername())
		{
			m_socket.erase(it);
			return;
		}
	}*/
}

std::vector<std::string> Room::getAllUsers()
{
	std::vector<std::string> copy;
	for (auto i : this->m_users)
		copy.push_back(i.getUsername());
	return copy;
}

unsigned int Room::getRoomState()
{
	return this->m_metadata._Active;
}

RoomData Room::getRoomData()
{
	return this->m_metadata;
}

//std::map<SOCKET, std::string> Room::get_socket()
//{
//	return m_socket;
//}

