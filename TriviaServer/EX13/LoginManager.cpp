#include "LoginManager.h"

LoginManager::LoginManager()
{
    this->m_loggedUsers;
    /*TO FIX*/
    //m_database->open();
}

LoginManager::~LoginManager()
{
    this->m_loggedUsers.clear();
    m_database->close();
    delete this;
}

void LoginManager::SignUp(std::string name, std::string pass, std::string email)
{
    if (m_database->DoesUserExist(name))
    {
        std::cout << "User does already exist!" << std::endl;
    }
    else
    {
        m_database->AddNewUser(name, pass, email);
    }
}

void LoginManager::LogIn(std::string name, std::string pass)
{
    if (!(m_database->DoesPasswordMatch(name, pass)))
    {
        std::cout << "No existing user" << std::endl;
    }
    else
    {
        this->m_loggedUsers.push_back(LoggedUser(name));
    }
}

void LoginManager::LogOut(std::string name)
{
    /*
    TODO
    */

   /* int size = m_loggedUsers.size();
    LoggedUser l(name);

    std::cout << "User does not exist" << std::endl;*/

}

std::vector<LoggedUser> LoginManager::getUsers()
{
    return this->m_loggedUsers;
}
