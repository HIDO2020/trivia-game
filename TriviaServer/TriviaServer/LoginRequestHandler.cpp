#include "LoginRequestHandler.h"
#include "JsonResponsePacketSerializer.h"

bool LoginRequestHandler::isRequestRelevant(RequestInfo info)
{
	if (info.id == signup || info.id == login)
		return true;
	return false;
}

RequestResult LoginRequestHandler::handleRequest(RequestInfo info) //need to change and return 
{
	SignupResponse sign_mes;
	sign_mes.status = 1;
	LoginResponse log_mes;
	log_mes.status = 1;
	ErrorResponse err_mes;
	err_mes.message = "Error!";

	//json j = json::parse(info.buffer); //?
	std::vector<unsigned char> vec;
	if (isRequestRelevant(info))
	{
		if (info.id == signup)
			vec = JsonResponsePacketSerializer::serializeResponse(sign_mes);
		else
			vec = JsonResponsePacketSerializer::serializeResponse(log_mes);
	}
	else
		vec = JsonResponsePacketSerializer::serializeResponse(err_mes);
	RequestResult result;
	result.response = vec;
	return result;
}
