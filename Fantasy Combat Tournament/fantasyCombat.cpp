/*********************************************************************
** Program Filename: fantasyCombat.cpp
** Author: Ryan Cosby
** Date: February 28, 2015
** Description: This is a fantasy combat game test driver. It generates
** combat simulations between teams of character objects with armor, attack,
** and defense mechanisms. Character objects can regain strength after winning
** a battle and resting till their next battle. Rankings of teams and characters
** in tournament can be sorted
** Input: User selects the two team names, number of characters, and can optionally
** select each character name and type
** Output: Shows user who won each tournament and ranks individual players
*********************************************************************/
#include "character.h"
#include "team.h"
#include "tournament.h"
using std::cout;
using std::cin;
using std::endl;
/*********************************************************************
** Function: print character menu function
** Description: prints menu to screen
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: prints menu to screen
*********************************************************************/
void printCharacterMenu()
{
	cout << "Enter <1> for Goblin" << endl;
	cout << "Enter <2> for Barbarian" << endl;
	cout << "Enter <3> for Reptile People" << endl;
	cout << "Enter <4> for Blue Men" << endl;
	cout << "Enter <5> for The Shadow" << endl;
}
int main()
{
	srand(time(NULL)); //seed random number generator
	int comm, comm2, numCreatures, gameMode; //storing user commands
	string inpName, inpName2, inpTeamName; //storing user string entries
	char gameStatus = 'Y'; //storing game status
	team *player1Team, *player2Team;//create pointers to team objects
	player1Team = NULL;//set team object to null
	player2Team = NULL;
	Character *Player1,*Player2; //create pointers to character objects
	Player1 = NULL; //set objects to null
	Player2 = NULL;
	while (gameStatus == 'Y')//outer loop to select characters
	{
		cout << "\n\nWelcome to the Fantasy Combat Game Simulator!" << endl;
		cout << "\nPlease enter the number of players for each team: " << endl;
		cin >> numCreatures;
		player1Team = new team();//Create new team 1
		player2Team = new team();//Create new team 2
		player1Team->setNumCreatures(numCreatures);//set the number of creatures
		player2Team->setNumCreatures(numCreatures);
		cout << "\nPlayer 1 Enter a name for your Team" << endl;
		cin >> inpTeamName;
		player1Team->setTeamName(inpTeamName);
		cout << "\nPlayer 2 Enter a name for your Team" << endl;
		cin >> inpTeamName;
		player2Team->setTeamName(inpTeamName);
		cout << "\nAutomatically Select Characters for each team?" << endl; //Switches game to auto mode
		cout << "Enter <1> for Yes or Enter <0> For No" << endl;
		cin >> gameMode;
		int round = 1;
		for (int i = 0; i < player1Team->getNumCreatures(); i++)
		{
			if (gameMode == 0)//Let players choose characters and names if not in Auto Mode
			{
				cout << "\nPlayer 1 Please Choose a Character\n\n" << endl;
				printCharacterMenu();
				cin >> comm;
				cout << "\nPlease enter a name for this Character: " << endl;
				cin >> inpName;
				cout << "\n\nPlayer 2 Please Choose a Character\n\n" << endl;
				printCharacterMenu();
				cin >> comm2;
				cout << "\nPlease enter a name for this Character: " << endl;
				cin >> inpName2;
			}
			else// If in Auto mode randomly select creature type and pass dummy name to constructor
			{
				comm = rand() % 5 + 1;
				comm2 = rand() % 5 + 1;
				inpName = "Tester1";
				inpName2 = "Tester2";
			}

			if (comm == 1 && comm2 == 1)//handles situation where both characters are goblins
			{
				Player1 = new Goblin(false, inpName);
				Player2 = new Goblin(false, inpName2);
			}
			else// Other wise it creates objects based on feeback from user
			{
				if (comm == 1)
					Player1 = new Goblin(inpName);
				else if (comm == 2)
					Player1 = new Barbarian(inpName);
				else if (comm == 3)
					Player1 = new Reptile(inpName);
				else if (comm == 4)
					Player1 = new BlueMen(inpName);
				else if (comm == 5)
					Player1 = new Shadow(inpName);
				else
					cout << "Invalid character selection, please try again." << endl;
				if (comm2 == 1)
					Player2 = new Barbarian(inpName2);
				else if (comm2 == 2)
					Player2 = new Barbarian(inpName2);
				else if (comm2 == 3)
					Player2 = new Reptile(inpName2);
				else if (comm2 == 4)
					Player2 = new BlueMen(inpName2);
				else if (comm2 == 5)
					Player2 = new Shadow(inpName2);
				else
					cout << "Invalid character selection, please try again." << endl;
			}
			Player1->setTeam(player1Team); //set team name for player 1
			Player2->setTeam(player2Team); //set team name for player 2
			player1Team->addChar2Team(Player1); //Add player to team roster
			player2Team->addChar2Team(Player2); //Add player to team roster
		}
		while (player1Team->getLoserPileSize() != player1Team->getNumCreatures() 
			&& player2Team->getLoserPileSize() != player2Team->getNumCreatures())
			/*Check to see if either team's loser pile is full*/
		{
			while (player1Team->getTopCharacter()->getStrengthPoints() > 0 
				   && player2Team->getTopCharacter()->getStrengthPoints() > 0) 
				   /*Check to see if player as lost all strengthpoints*/
			{
				cout << string(5, '\n');//printing combat results after each attack
				cout << "ROUND " << round << endl;
				Player1 = player1Team->getTopCharacter(); // Set Current Player to top of Player Team List
				Player2 = player2Team->getTopCharacter();
				if (gameMode == 0)
				{
					cout << "Player 1: " << Player1->getName() << " the " << Player1->getType() << " VS "
						 << "Player 2: " << Player2->getName() << " the " << Player2->getType() << endl;
				}
				else
				{
					cout << "Player 1: " << Player1->getType() << " VS "
						 << "Player 2: " << Player2->getType() << endl;
				}
				cout << "Player 1 Strength Remaining " << Player1->getStrengthPoints() << endl;
				cout << "Player 2 Strength Remaining " << Player2->getStrengthPoints() << endl;
				Player2->defense(Player1->attack()); //player attacks player
				if (Player2->getStrengthPoints() <= 0) //check to see if player is dead
				{
					cout << "Player 2 has kicked the bucket. Player 1 Wins" << endl;
					Player1->addRankPoints(Player2->getStartStrength()); // Add points to winner
					player1Team->winnerRotate(); //Rotate winner to bottom of roster
					player2Team->addChar2LP(); //Add loser to his team's loser pile
					round = 1; //Reset Rounds to 1
					break;
				}
				Player1->defense(Player2->attack()); //player attacks player
				if (Player1->getStrengthPoints() <= 0) //check to see if player is dead
				{
					cout << "Player 1 has kicked the bucket. Player 2 Wins" << endl;
					Player2->addRankPoints(Player1->getStartStrength()); //Add points to winner
					player2Team->winnerRotate();//Rotate winner to bottom of roster
					player1Team->addChar2LP();//Add loser to his team's loser pile
					round = 1; // Reset Rounds to 1
					break;
				}
				round++; //increment rounds
			}
		}
		while (player1Team->getLoserPileSize() != player1Team->getNumCreatures())
		{
			player1Team->addChar2LP(); //Flush out Team roster in to Loser Pile after tournament is finished
		}
		while (player2Team->getLoserPileSize() != player2Team->getNumCreatures())
		{
			player2Team->addChar2LP(); //Flush out Team roster in to Loser Pile after tournament is finished
		}
		player1Team->setTeamPoints(); //Sum all of the teams individual battle points
		player2Team->setTeamPoints(); //Sum all of the teams individual battle points
		tournament newTourn(player1Team, player2Team); //Add teams to tournament object
		newTourn.setRankings(); //Combine teams into one vector and sort by battle points
		newTourn.printtopRanking(gameMode); //Prints Vector (adds Chracter Names if in Manual Mode)
		newTourn.printWinningTeam(); //Compares total team points and prints winner
		cout << "\nEnter <1> to Run New Simulation" << endl;// ask to start to new simulation
		cout << "Enter <0> to exit" << endl;
		cin >> comm;
		if (comm != 1)
			gameStatus = 'N';
		delete player1Team;//delete dynamically allocated team object
		delete player2Team;//delete dynamically allocated team object
	}
	return 0;
}

