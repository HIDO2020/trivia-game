#include "RequestHandlerFactory.h"

RequestHandlerFactory::RequestHandlerFactory(IDataAccess* dataAccess, StatisticsManager stats) : m_database(dataAccess)
	, m_StatisticsManager(stats)
{
	this->m_loginManager = LoginManager(dataAccess);
}

//RequestHandlerFactory::~RequestHandlerFactory()
//{
//	m_database->close();
//}

LoginRequestHandler* RequestHandlerFactory::createLoginRequestHandler() //
{
	LoginRequestHandler* login_han = new LoginRequestHandler(*this, this->getLoginManager());
	return login_han;
}

LoginManager& RequestHandlerFactory::getLoginManager()
{
	return m_loginManager;
}

MenuRequestHandler* RequestHandlerFactory::createMenuRequestHandler(LoggedUser logged)
{
	MenuRequestHandler* menu_han = new MenuRequestHandler(*this, this->m_loginManager, logged, this->m_roomManager);
	return menu_han;
}

StatisticsManager& RequestHandlerFactory::getStatisticsManager()
{
	return this->m_StatisticsManager;
}

RoomManager& RequestHandlerFactory::getRoomManager()
{
	return this->m_roomManager;
}
