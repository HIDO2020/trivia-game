#include "RequestHandlerFactory.h"

RequestHandlerFactory::RequestHandlerFactory(IDataAccess& dataAccess) : m_database(&dataAccess), m_loginManager(dataAccess)
{
	m_database->open();
}

//RequestHandlerFactory::~RequestHandlerFactory()
//{
//	m_database->close();
//}

LoginRequestHandler* RequestHandlerFactory::createLoginRequestHandler()
{
	LoginRequestHandler login_han(*this, m_loginManager);
	LoginRequestHandler* login_ptr = &login_han;
	return login_ptr;
}

LoginManager& RequestHandlerFactory::getLoginManager()
{
	return m_loginManager;
}
