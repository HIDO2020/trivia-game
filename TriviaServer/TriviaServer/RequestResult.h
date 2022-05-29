#pragma once
#include "IRequestHandler.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

struct RequestResult
{
    std::vector<unsigned char> response;
    IRequestHandler* newHandler;
};