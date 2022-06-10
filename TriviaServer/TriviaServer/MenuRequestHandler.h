#pragma once
#include "RequestHandlerFactory.h"
#include "RoomAdminRequestHandler.h"
#include "Communicator.h"
#include "LoggedUser.h"
#include "IRequestHandler.h"
#include "LoginManager.h"
class LoggedUser;
class RequestHandlerFactory;
class IRequestHandler;

class MenuRequestHandler : public IRequestHandler
{
public:
	MenuRequestHandler(RequestHandlerFactory& fact,LoginManager& manage, LoggedUser user, RoomManager& room);
	virtual bool isRequestRelevant(RequestInfo info);
	virtual RequestResult handleRequest(RequestInfo info);

private:
	LoginManager& m_loginManager;
	RoomManager& m_roomManager;
	RequestHandlerFactory& m_handleFactory;
	LoggedUser m_user;

	RequestResult logout(RequestInfo);
	RequestResult getRooms(RequestInfo);
	RequestResult getPlayersInRooms(RequestInfo);
	RequestResult getPersonalStats(RequestInfo);
	RequestResult getHighScore(RequestInfo);
	RequestResult joinRoom(RequestInfo);
	RequestResult createRoom(RequestInfo);
};