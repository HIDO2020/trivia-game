#pragma once
#include "LoginRequestHandler.h"
#include "IDataAccess.h"
#include "LoginManager.h"
#include "SqliteDatabase.h"
#include "RoomManager.h"
#include "StatisticsManager.h"
#include "MenuRequestHandler.h"
class LoginRequestHandler;
class MenuRequestHandler;

class RequestHandlerFactory
{
public:
	RequestHandlerFactory(IDataAccess& dataAccess, StatisticsManager stats);
	//~RequestHandlerFactory();
	LoginRequestHandler* createLoginRequestHandler(); //
	LoginManager& getLoginManager(); //

	MenuRequestHandler* createMenuRequestHandler(LoggedUser logged);
	StatisticsManager& getStatisticsManager();
	RoomManager& getRoomManager();
private:
	IDataAccess* m_database;
	LoginManager m_loginManager;
	RoomManager m_roomManager;
	StatisticsManager m_StatisticsManager;
};