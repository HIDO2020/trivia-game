#include "LoginRequestHandler.h"
#include <algorithm>

LoginRequestHandler::LoginRequestHandler()
{
    this->_names;
}

LoginRequestHandler::~LoginRequestHandler()
{
    this->_names.clear();
    delete this;
}

void LoginRequestHandler::SignIn(std::string name, SOCKET s)
{
    if (!(this->_names.find(name) == this->_names.end()))
        std::cout << "Name already exist" << std::endl;
    else
        this->_names.insert(std::pair<std::string, SOCKET>(name, s));
}

void LoginRequestHandler::SignOut(std::string name, SOCKET s)
{
    if (!(this->_names.find(name) == this->_names.end()))
        this->_names.erase(name);
    else
        std::cout << "Name don't exist" << std::endl;

}

void LoginRequestHandler::ConnectedUsers()
{
    std::string word = "";
    std::map<std::string, SOCKET> ::iterator itr;
    for (itr = this->_names.begin(); itr != this->_names.end(); itr++)
    {
        //word = itr->first;
        std::cout << word << std::endl;
    }
}

void LoginRequestHandler::ShowMenu()
{
    std::cout << "1. Sign In" << std::endl;
    std::cout << "2. Sign Out" << std::endl;
    std::cout << "3. Connected Users" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << std::endl;
}

std::map<std::string, SOCKET> LoginRequestHandler::getUsers()
{
    return this->_names;
}
