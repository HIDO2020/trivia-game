#pragma once
#include "LoginRequestHandler.h"
#include "IDataAccess.h"
#include "LoginManager.h"
#include "SqliteDatabase.h"
class LoginRequestHandler;

class RequestHandlerFactory
{
public:
	RequestHandlerFactory(IDataAccess& dataAccess);
	//~RequestHandlerFactory();
	LoginRequestHandler* createLoginRequestHandler(); //
	LoginManager& getLoginManager(); //
private:
	IDataAccess* m_database;
	LoginManager m_loginManager;
};