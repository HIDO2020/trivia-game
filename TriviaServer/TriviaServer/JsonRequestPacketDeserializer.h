#pragma once
#include "LoginRequest.h"
#include "SignupRequest.h"
#include <fstream>
#include <vector>
#include <bitset>
#include <string>

class JsonRequestPacketDeserializer
{
public:
	static LoginRequest deserializeLoginRequest(std::vector<unsigned char>);
	static SignupRequest deserializeSignupRequest(std::vector<unsigned char>);
};
