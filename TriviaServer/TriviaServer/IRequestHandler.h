#pragma once
#include "RequestInfo.h"
#include "RequestResult.h"
struct RequestResult;
struct RequestInfo;
//RequestInfo info;

class IRequestHandler
{
public: 
	virtual bool isRequestRelevant(RequestInfo info) = 0;
	virtual RequestResult handleRequest(RequestInfo info) = 0;
};