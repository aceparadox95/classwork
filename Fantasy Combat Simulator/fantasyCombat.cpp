/*********************************************************************
** Program Filename: fantasyCombat.cpp
** Author: Ryan Cosby
** Date: February 13, 2015
** Description: This is a fantasy combat game test driver. It generates
** combat simulations between character objects with armor, attack,
** and defense mechanisms
** Input: User selects the two battle characters
** Output: Shows user who won each fight and who won all the simulations
*********************************************************************/

#include "character.h"
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
	int comm, comm2; //storing user commands
	char gameStatus = 'Y'; //storing game status
	Character *Player1,*Player2; //create pointers to chracter objects
	Player1 = NULL; //set objects to null
	Player2 = NULL;
	while (gameStatus == 'Y')//outer loop to select characters
	{
		int p1winCount = 0;//variables to store number of wins
		int p2winCount = 0;
		cout << string(40, '\n');
		cout << "Welcome to the Fantasy Combat Game!" << endl;
		cout << "Player 1 Please Choose a Character\n\n" << endl;
		printCharacterMenu();
		cin >> comm;
		cout << "\n\nPlayer 2 Please Choose a Character\n\n" << endl;
		printCharacterMenu();
		cin >> comm2;

		for (int i = 1; i <= 1000; i++)//inner loop to run combat simulations
		{
			int round = 1;
			if (comm == 1 && comm2 == 1)//handles situation where both characters are goblins
			{
				Player1 = new Goblin(false);
				Player2 = new Goblin(false);
			}
			else// Other wise it creates objects based on feeback from user
			{
				if (comm == 1)
					Player1 = new Goblin();
				else if (comm == 2)
					Player1 = new Barbarian();
				else if (comm == 3)
					Player1 = new Reptile();
				else if (comm == 4)
					Player1 = new BlueMen();
				else if (comm == 5)
					Player1 = new Shadow();
				else
					cout << "Invalid character selection, please try again." << endl;
				if (comm2 == 1)
					Player2 = new Barbarian();
				else if (comm2 == 2)
					Player2 = new Barbarian();
				else if (comm2 == 3)
					Player2 = new Reptile();
				else if (comm2 == 4)
					Player2 = new BlueMen();
				else if (comm2 == 5)
					Player2 = new Shadow();
				else
					cout << "Invalid character selection, please try again." << endl;
			}
			while (Player1->getStrengthPoints() > 0 && Player2->getStrengthPoints() > 0) //inner loop to run each individual combat
			{
				cout << string(5, '\n');//printing combat results after each attack
				cout << "ROUND " << round << endl;
				cout << "Player 1: " << Player1->getName() << " VS " << "Player 2: " << Player2->getName() << endl;
				cout << "Player 1 Strength Remaining " << Player1->getStrengthPoints() << endl;
				cout << "Player 2 Strength Remaining " << Player2->getStrengthPoints() << endl;
				Player2->defense(Player1->attack()); //player attacks player
				if (Player2->getStrengthPoints() <= 0) //check to see if player is dead
				{
					cout << "Player 2 has kicked the bucket. Player 1 Wins" << endl;
					p1winCount++;
					break;
				}
				Player1->defense(Player2->attack()); //player attacks player
				if (Player1->getStrengthPoints() <= 0) //check to see if player is dead
				{
					cout << "Player 1 has kicked the bucket. Player 2 Wins" << endl;
					p2winCount++;
					break;
				}
				round++; //increment rounds
			}
			delete Player1;//delete dynamically allocated character objects
			delete Player2;
		}
		cout << "\n\nPlayer 1 Wins: " << p1winCount << endl; //print final results
		cout << "Player 2 Wins: " << p2winCount << endl << endl;
		cout << "Enter <1> to Run Simulations again" << endl;// ask to start to new simulation
		cout << "Enter <0> to exit" << endl;
		cin >> comm;
		if (comm != 1)
			gameStatus = 'N';
	}
	return 0;
}

