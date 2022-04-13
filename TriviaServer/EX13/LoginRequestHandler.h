#pragma once

#include <WinSock2.h>
#include <Windows.h>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <exception>

#define ASCI_TO_INT 48;
#define LEN_OF_MESSAGE 49

enum options {
    zero,
    sign_in,
    sign_out,
    account_print,
    EXIT
};

class LoginRequestHandler
{
public:
    LoginRequestHandler();
    ~LoginRequestHandler();
    void SignIn(std::string name, SOCKET s);
    void SignOut(std::string name, SOCKET s);
    void ConnectedUsers();
    void ShowMenu();

    std::map<std::string, SOCKET> getUsers();

private:
    std::map<std::string, SOCKET> _names;
};