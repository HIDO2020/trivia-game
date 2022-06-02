#pragma once
#include "IRequestHandler.h"

class MenuRequestHandler : public IRequestHandler
{
public:
	virtual bool isRequestRelevant(RequestInfo info);
	virtual RequestResult handleRequest(RequestInfo info);
};