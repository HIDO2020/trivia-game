#include "LoggedUser.h"

LoggedUser::LoggedUser(std::string m_username)
{
	this->m_username = m_username;
}

LoggedUser LoggedUser::getUser()
{
	return *this;
}

std::string LoggedUser::getUsername()
{
	return this->m_username;
}
