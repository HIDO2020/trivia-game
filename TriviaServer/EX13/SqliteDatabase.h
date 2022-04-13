#pragma once
#include <list>
#include "IDataAccess.h"
#include "sqlite3.h"
#include <io.h>
#include <string>
#include <vector>
#include <iostream>

class SqliteDatabase : public IDataAccess
{

public:
	SqliteDatabase() = default;
	virtual ~SqliteDatabase() = default;

	// queries
	bool DoesUserExist(const std::string& name);
	bool DoesPasswordMatch(const std::string& name, const std::string& pass);
	void AddNewUser(const std::string& name, const std::string& pass, const std::string& email);

	bool open() override;
	void close() override;

private:
	sqlite3* db;
};
