#include "team.h"
#include <vector>
#ifndef TOURNAMENT_H
#define TOURNAMENT_H
using std::string;
using std::vector;
using std::cout;
using std::endl;
class tournament
{
private:
	team team1;
	team team2;
	vector<Character*>rankings;
public:
	tournament(team*,team*);
	void setRankings();
	void printtopRanking(int gameMode);
	void printWinningTeam();
};
#endif