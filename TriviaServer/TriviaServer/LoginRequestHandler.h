#pragma once
#include "RequestInfo.h"
#include "RequestResult.h"
#include "JsonResponsePacketSerializer.h"
#include "ErrorResponse.h"
#include "LoginResponse.h"
#include "SignupResponse.h"
#include <vector>
//#define SIGNUP false
//#define LOGIN true

class LoginRequestHandler : public IRequestHandler
{
public:
	virtual bool isRequestRelevant(RequestInfo info);
	virtual RequestResult handleRequest(RequestInfo info);
};