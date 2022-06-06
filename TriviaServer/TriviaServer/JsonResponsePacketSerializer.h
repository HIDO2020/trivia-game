#pragma once
//#pragma comment (lib, "ws2_32.lib")
#include "Communicator.h"
#include "json.hpp"
#include "requestStruct.h"
#include "responseStruct.h"
#include "vector"
using json = nlohmann::json;
enum codes{Error_, signup_, login_, logout_, join_, create_, getRoom_, getPlayers_, getHighScore_, getPersonalStats_};

class JsonResponsePacketSerializer
{
public:
	 static std::vector<unsigned char> serializeResponse(ErrorResponse err);
	 static std::vector<unsigned char> serializeResponse(SignupResponse sign);
	 static std::vector<unsigned char> serializeResponse(LoginResponse log);

	 static std::vector<unsigned char> serializeResponse(LogoutResponse log);
	 static std::vector<unsigned char> serializeResponse(GetRoomsResponse get_r);
	 static std::vector<unsigned char> serializeResponse(GetPlayersInRoomResponse get_p);
	 static std::vector<unsigned char> serializeResponse(JoinRoomResponse join);
	 static std::vector<unsigned char> serializeResponse(CreateRoomResponse create);
	 static std::vector<unsigned char> serializeResponse(GetHighScoreResponse get_h);
	 static std::vector<unsigned char> serializeResponse(GetPersonalStatsResponse get_ps);
private:
	static std::vector<unsigned char> helper(json j, int code);
};
