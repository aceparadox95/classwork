#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include "character.h"
#ifndef TEAM_H
#define TEAM_H
using std::string;
using std::vector;
using std::stack;
using std::rotate;
class team
{
	friend class tournament;
private:
	string teamName;
	vector<Character*> teamList;
	vector<Character*> loserPile;
	int teamPoints;
	int numCreatures;
public:
	team();
	void setTeamName(string inpteamName);
	string getTeamName();
	int getNumCreatures();
	void setNumCreatures(int inpNum);
	void winnerRotate();
	void addChar2Team(Character* inpCharacter);
	void addChar2LP();
	void setTeamPoints();
	int getTeamPoints();
	int getLoserPileSize();
	Character* getTopCharacter();
};
#endif