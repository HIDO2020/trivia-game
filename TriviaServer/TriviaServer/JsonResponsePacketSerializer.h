#pragma once
//#pragma comment (lib, "ws2_32.lib")
#include "Communicator.h"
#include "json.hpp"
#include "ErrorResponse.h"
#include "LoginResponse.h"
#include "SignupResponse.h"
#include "vector"
using json = nlohmann::json;
enum codes{Error, signup, login};

class JsonResponsePacketSerializer
{
public:
	 static std::vector<unsigned char> serializeResponse(ErrorResponse err);
	 static std::vector<unsigned char> serializeResponse(SignupResponse sign);
	 static std::vector<unsigned char> serializeResponse(LoginResponse log);
private:
	static std::vector<unsigned char> helper(json j, int code);
};
