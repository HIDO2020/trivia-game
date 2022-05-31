#include "SqliteDatabase.h"

//global variables
bool exist = false; // to check if user exist
int numSave = 0;
float dualSave = 0;
std::vector<std::string> namesSave;

//callback that check if ther feild exist bigger than 0
int callback_existUser(void* data, int argc, char** argv, char** azColName)
{
	for (int i = 0; i < argc; i++)
	{
		if (std::string(azColName[i]) == "EXIST")
		{
			//std::cout << azColName[i] << " = " << argv[i] << std::endl;
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
		pass + "\", \"" + email + "\");";

	std::cout << sqlCommand << std::endl;

	const char* sqlStatement = sqlCommand.c_str();

	res = sqlite3_exec(db, sqlStatement, nullptr, nullptr, errMessage);
	if (res != SQLITE_OK)
		return;
}


//callback that check get data of int/float
int callback_getData(void* data, int argc, char** argv, char** azColName)
{
	for (int i = 0; i < argc; i++)
	{
		if (std::string(azColName[i]) == "DataINT")
		{
			//std::cout << azColName[i] << " = " << argv[i] << std::endl;
			numSave = std::stoi(argv[i]);;
		}
		if (std::string(azColName[i]) == "DataFLOAT")
		{
			//std::cout << azColName[i] << " = " << argv[i] << std::endl;
			dualSave = std::stof(argv[i]);;
		}
	}
	std::cout << std::endl;
	return 0;
}

float SqliteDatabase::getPlayerAverageAnswerTime(const std::string& name)
{
	char** errMessage = nullptr;
	std::string sqlCommand;
	int res;

	sqlCommand = "SELECT avg_time as DataFLOAT FROM Stats WHERE username == \"" + name + "\";";

	std::cout << sqlCommand << std::endl;

	const char* sqlStatement = sqlCommand.c_str();

	res = sqlite3_exec(db, sqlStatement, callback_getData, nullptr, errMessage);
	return dualSave;
}

int SqliteDatabase::getNumOfCorrectAnswers(const std::string& name)
{
	char** errMessage = nullptr;
	std::string sqlCommand;
	int res;

	sqlCommand = "SELECT correct_answers as DataINT FROM Stats WHERE username == \"" + name + "\";";

	std::cout << sqlCommand << std::endl;

	const char* sqlStatement = sqlCommand.c_str();

	res = sqlite3_exec(db, sqlStatement, callback_getData, nullptr, errMessage);
	return numSave;
}

int SqliteDatabase::getNumOfTotalAnswers(const std::string& name)
{
	char** errMessage = nullptr;
	std::string sqlCommand;
	int res;

	sqlCommand = "SELECT total_answers as DataINT FROM Stats WHERE username == \"" + name + "\";";

	std::cout << sqlCommand << std::endl;

	const char* sqlStatement = sqlCommand.c_str();

	res = sqlite3_exec(db, sqlStatement, callback_getData, nullptr, errMessage);
	return numSave;
}

int SqliteDatabase::getNumOfPlayersGames(const std::string& name)
{
	char** errMessage = nullptr;
	std::string sqlCommand;
	int res;

	sqlCommand = "SELECT games_played as DataINT FROM Stats WHERE username == \"" + name + "\";";

	std::cout << sqlCommand << std::endl;

	const char* sqlStatement = sqlCommand.c_str();

	res = sqlite3_exec(db, sqlStatement, callback_getData, nullptr, errMessage);
	return numSave;
}

int SqliteDatabase::getPlayerScore(const std::string& name)
{
	char** errMessage = nullptr;
	std::string sqlCommand;
	int res;

	sqlCommand = "SELECT score as DataINT FROM Stats WHERE username == \"" + name + "\";";

	std::cout << sqlCommand << std::endl;

	const char* sqlStatement = sqlCommand.c_str();

	res = sqlite3_exec(db, sqlStatement, callback_getData, nullptr, errMessage);
	return numSave;
}

//callback that add to vector names by order
int callback_getRecords(void* data, int argc, char** argv, char** azColName)
{
	for (int i = 0; i < argc; i++)
	{
		if (std::string(azColName[i]) == "username")
		{
			namesSave.push_back(argv[i]);
		}
	}
	std::cout << std::endl;
	return 0;
}


std::vector<std::string> SqliteDatabase::getHighScores()
{
	namesSave.clear();
	char** errMessage = nullptr;
	std::string sqlCommand;
	int res;

	sqlCommand = "SELECT username FROM Stats ORDER BY score DESC; ";

	std::cout << sqlCommand << std::endl;

	const char* sqlStatement = sqlCommand.c_str();

	res = sqlite3_exec(db, sqlStatement, callback_getRecords, nullptr, errMessage);

	return namesSave;
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

		//Create User Table
		sqlStatement = R""""""(CREATE TABLE Stats(
			username TEXT PRIMARY KEY,
			games_played INTEGER,
			correct_answers INTEGER,
			total_answers INTEGER,
			avg_time REAL,
			score INTEGER,
			FOREIGN KEY (username) REFERENCES USER(username)
			);
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


