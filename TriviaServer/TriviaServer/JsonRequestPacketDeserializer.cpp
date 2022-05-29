#include "JsonRequestPacketDeserializer.h"
#include "json.hpp"
using json = nlohmann::json;

SignupRequest JsonRequestPacketDeserializer::deserializeSignupRequest(std::vector<unsigned char> request_vec)
{
	int code = request_vec.front();
	request_vec.erase(request_vec.begin());
	unsigned char size[4];
	for (int i = 0; i < 4; i++)
	{
		size[i] = request_vec.front();
		request_vec.erase(request_vec.begin());
	}
	//std::string message(request_vec.begin(), request_vec.end());
	json j = json::parse(request_vec.begin(), request_vec.end()); 
	std::string message = j.dump(); //deser
	return SignupRequest();
}
