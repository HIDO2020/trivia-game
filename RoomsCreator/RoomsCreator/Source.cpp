#include <iostream>
#include "Room.h"
#include "RoomManager.h"
#include "IDataAccess.h"
#include "SqliteDatabase.h"
#include "sqlite3.h"
#include "StatisticsManager.h"
#include <math.h>

int main()
{
	SqliteDatabase db;
	//db.open();
	//std::cout << db.getNumOfCorrectAnswers("nativ");
	//std::cout << db.getPlayerAverageAnswerTime("ido");
	/*std::vector<std::string> namesSave =  db.getHighScores();
	for (auto i : namesSave)
		std::cout << i << std::endl;*/
	//std::list<Question> quiz = db.getQuestions(5);
	//for (auto i : quiz) {
	//	std::cout << i.getQuestion() << std::endl;
	//}
	StatisticsManager s1(db);
	
	std::vector<std::string> namesSave = s1.getUserStatistics("nativ");
	for (auto i : namesSave)
		std::cout << i << std::endl; 
}