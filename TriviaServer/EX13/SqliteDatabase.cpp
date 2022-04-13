#include "SqliteDatabase.h"

//global variable to check if user exist
bool exist = false;

//callback that check if ther feild exist bigger than 0
int callback_existUser(void* data, int argc, char** argv, char** azColName)
{
	for (int i = 0; i < argc; i++)
	{
		if (std::string(azColName[i]) == "EXIST")
		{
			std::cout << azColName[i] << " = " << argv[i] << std::endl;
			if (*argv[i] == '0')
			{
				exist = false;
			}
			else
			{
				exist = true;
			}
			return 0;
		}
	}
	std::cout << std::endl;
	return 0;
}

/*
check if ther user with that name
*/
bool SqliteDatabase::DoesUserExist(const std::string& name)
{
	char** errMessage = nullptr;
	std::string sqlCommand;
	int res;

	sqlCommand = "SELECT count(username) AS EXIST FROM User WHERE username == \"" +
		name + "\";";

	const char* sqlStatement = sqlCommand.c_str();

	res = sqlite3_exec(db, sqlStatement, callback_existUser, nullptr, errMessage);
	return exist;
}

/*
check if there user with that name and the password is belong to him
*/
bool SqliteDatabase::DoesPasswordMatch(const std::string& name, const std::string& pass)
{
	char** errMessage = nullptr;
	std::string sqlCommand;
	int res;

	sqlCommand = "SELECT count(username) AS EXIST FROM User WHERE username == \"" +
		name + "\" and user_password == \"" + pass + "\";";

	const char* sqlStatement = sqlCommand.c_str();

	res = sqlite3_exec(db, sqlStatement, callback_existUser, nullptr, errMessage);
	return exist;
}

/*
insert user (with name, passwoed, email)
*/
void SqliteDatabase::AddNewUser(const std::string& name, const std::string& pass, const std::string& email)
{
	char** errMessage = nullptr;
	std::string sqlCommand;
	int res;

	sqlCommand = "INSERT INTO User VALUES(\"" + name + "\", \"" +
		pass + "\", \"" + email  + "\";";

	const char* sqlStatement = sqlCommand.c_str();

	res = sqlite3_exec(db, sqlStatement, nullptr, nullptr, errMessage);
	if (res != SQLITE_OK)
		return;
}

bool SqliteDatabase::open()
{
	//open the database by file name
	std::string dbFileName = "UserData.sqlite";
	int file_exist = _access(dbFileName.c_str(), 0);
	int res = sqlite3_open(dbFileName.c_str(), &db);
	//check if exist
	if (res != SQLITE_OK) {
		db = nullptr;
		std::cout << "Failed to open DB" << std::endl;
		return -1;
	}
	if (file_exist == 0)
	{
		//close db
		std::cout << "The file already exists" << std::endl;
	}
	else if (file_exist != 0)
	{
		// init database
		std::cout << "Create new database.." << std::endl;

		char** errMessage = nullptr;
		const char* sqlStatement;

		//Create User Table
		sqlStatement = R""""""(CREATE TABLE User(
			username TEXT PRIMARY KEY,
			user_password TEXT,
			email TEXT);
			 )"""""";

		res = sqlite3_exec(db, sqlStatement, nullptr, nullptr, errMessage);
		if (res != SQLITE_OK)
			return false;
	}
}

void SqliteDatabase::close()
{
	sqlite3_close(db);
	db = nullptr;
}


