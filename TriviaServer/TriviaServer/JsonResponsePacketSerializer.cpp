#include "JsonResponsePacketSerializer.h"
using json = nlohmann::json;

std::vector<unsigned char> JsonResponsePacketSerializer::serializeResponse(ErrorResponse err)
{
	json j = { {"message", err.message} };
	unsigned char code = (unsigned char)Error;
	return JsonResponsePacketSerializer::helper(j, code);
}

std::vector<unsigned char> JsonResponsePacketSerializer::serializeResponse(SignupResponse sign)
{
	json j = { {"status", sign.status} };
	unsigned char code = (unsigned char)signup;
	return JsonResponsePacketSerializer::helper(j, code);
}

std::vector<unsigned char> JsonResponsePacketSerializer::serializeResponse(LoginResponse log)
{
	json j = { {"status", log.status} };
	unsigned char code = (unsigned char)login;
	return JsonResponsePacketSerializer::helper(j, code);
}

std::vector<unsigned char> JsonResponsePacketSerializer::helper(json j, int code)
{
	//unsigned char zer = '0';
	std::vector<unsigned char> res;
	res.push_back((unsigned char)code);
	std::string str_res = j.dump();

	int size = str_res.size();
	/*std::string size = std::to_string(str_res.size());
	for (int i = 0; i < size.size(); i++)
		res.push_back(size[i]);*/
	res.push_back(size);
	while (res.size() < 5)
		res.push_back(NULL);

	res.insert(res.end(), str_res.begin(), str_res.end());
	return res;
}
