#pragma once
#include <iostream>
#include <string>


struct SignupResponse
{
    unsigned int status;
};

struct LoginResponse
{
    unsigned int status;
};

struct ErrorResponse
{
    std::string message;
};

