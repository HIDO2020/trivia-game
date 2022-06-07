#ifndef LoggedUser_HEADER
#define LoggedUser_HEADER

#include <iostream>
#include <string>

class LoggedUser
{
public:	
	LoggedUser(std::string m_username);
	LoggedUser getUser();
	std::string getUsername();

private:
	std::string m_username;
};
#endif