#pragma once
#include <list>
#include <string>


class IDataAccess
{
public:
	virtual ~IDataAccess() = default;

	// queries
	virtual bool DoesUserExist(const std::string& name) = 0;
	virtual bool DoesPasswordMatch(const std::string& name, const std::string& pass) = 0;
	virtual void AddNewUser(const std::string& name, const std::string& pass, const std::string& email) = 0;

	//database related
	virtual bool open() = 0;
	virtual void close() = 0;
};
