#include "team.h"
team::team()//Constructor
{
	teamName = "";
}
void team::setTeamName(string inpteamName)//simple set function
{
	teamName = inpteamName;
}
string team::getTeamName()//simple get function
{
	return teamName;
}
int team::getNumCreatures()//simple get function
{
	return numCreatures;
}
void team::setNumCreatures(int inpNum)//simple set function
{
	numCreatures = inpNum;
}
int team::getTeamPoints()//simple get function
{
	return teamPoints;
}
/*********************************************************************
** Function: Add character to team
** Description: Adds character to team vector
** Parameters: Character Pointer
** Pre-Conditions: vector must be initialized
** Post-Conditions: character adds to back of vector
*********************************************************************/
void team::addChar2Team(Character* inpCharacter)
{
	teamList.push_back(inpCharacter); // Add character to the back of vector
}
/*********************************************************************
** Function: Rotates Winner
** Description: Rotates winning team roster and executes recover function
** Parameters: none
** Pre-Conditions: team chracters needs to have just won battle
** Post-Conditions: winning character adds to back of vector
*********************************************************************/
void team::winnerRotate()
{
	teamList[0]->recover(); //recovers the winning player
	rotate(teamList.begin(), teamList.begin() + 1, teamList.end()); //moves winning player to back of list
}
/*********************************************************************
** Function: Add Character to Loser Piles
** Description: Add losing character to its team's loser pile and deletes
** player from team roster
** Parameters: none
** Pre-Conditions: Losing Character
** Post-Conditions: Losing character added to loser pile
*********************************************************************/
void team::addChar2LP()
{
	loserPile.push_back(teamList[0]); //moves losing player to the loser pile
	teamList.erase(teamList.begin()); //remove player from roster
}
/*********************************************************************
** Function: Calculate Team Points
** Description: Adds battle points of all players on the team
** Parameters: none
** Pre-Conditions: Team Points value is zero
** Post-Conditions: Team Points value is set to the sum of team battle points
*********************************************************************/
void team::setTeamPoints()
{
	for (int i = 0; i < loserPile.size(); i++)
	{
		teamPoints += loserPile[i]->getRankPoints();
	}
}
int team::getLoserPileSize()
{
	return loserPile.size(); //returns size of loser pile
}
Character* team::getTopCharacter()
{
	return teamList[0]; // returns top of vector player
}