#include "tournament.h"
#include "team.h"
tournament::tournament(team* inpTeam, team* inpTeam2)
{
	team1 = *inpTeam;
	team2 = *inpTeam2;
	rankings.reserve(team1.loserPile.size() + team2.loserPile.size());
}
/*********************************************************************
** Function: Set Tournament Rankings
** Description: Combines both teams loser piles into one vector, then
** sorts the vector based on the character battle points
** Parameters: None
** Pre-Conditions: Populated team loser piles
** Post-Conditions: Combined sorted loser piles
*********************************************************************/
void tournament::setRankings()
{
	Character* tempChar; //Temporary Hold spot for Creature object
	rankings.insert(rankings.end(), team1.loserPile.begin(), team1.loserPile.end());
	/*Insert First teams list into rankings vector*/
	rankings.insert(rankings.end(), team2.loserPile.begin(), team2.loserPile.end());
	/*Insert Second teams list into rankings vector*/
	for (int i = 0; i < rankings.size(); i++) //Descending Bubble Sort based on battle points
	{
		for (int r = 0; r < (rankings.size()-1); r++)
		{
			if (rankings[r]->getRankPoints() < rankings[r+1]->getRankPoints())
			{
				tempChar = rankings[r];
				rankings[r] = rankings[r+1];
				rankings[r+1] = tempChar;
			}
		}
	}
}
/*********************************************************************
** Function: Print Tournament Rankings
** Description: Prints Rankings Vector and stops when players dont
** have more than 5 points
** Parameters: None
** Pre-Conditions: populated rankings vector
** Post-Conditions: printed rankings vector
*********************************************************************/
void tournament::printtopRanking(int gameMode)
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\nFinal Tournament Rankings: " << endl;
	for (int i = 0; i < (rankings.size() / 2); i++) // Prints out Ranking List after sort
	{
		team* temp;
		temp = rankings[i]->getTeam();
		if (gameMode == 0)
		{
			cout << i + 1 << ". " << rankings[i]->getName()
				<< " the " << rankings[i]->getType();
		}
		else
		{
			cout << i + 1 << ". " << rankings[i]->getType(); 
		}
			cout << " from team " << temp->getTeamName()
			<< " with " << rankings[i]->getRankPoints()
			<< " points." << endl;
	}
	cout << "\nAll other players had 0 Points" << endl;
}
/*********************************************************************
** Function: Print Winning Team
** Description: Compates total team points and prints winner
** Parameters: None
** Pre-Conditions: Team points need to be summed for each team
** Post-Conditions: Printed winner
*********************************************************************/
void tournament::printWinningTeam()
{
	cout << "\n" << endl;
	if (team1.getTeamPoints() > team2.getTeamPoints())
	{
		cout << "Team " << team1.getTeamName() << " is the winner " << " with "
			<< team1.getTeamPoints() << " points" << endl;
	}
	else if (team2.getTeamPoints() > team1.getTeamPoints())
	{
		cout << "Team " << team2.getTeamName() << " is the winner " << " with "
			<< team2.getTeamPoints() << " points" << endl;
	}
	else
	{
		cout << "The teams tied at " << team2.getTeamPoints() << " each." << endl;
	}
}