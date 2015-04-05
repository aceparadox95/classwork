/***************************************************************
 * Author: Ryan Cosby
 * Date Created: 11/16/2014
 * Last Modification Date: 11/17/2014
 * File name: sameSum.cpp
 *
 * Overview:
 * This is a ticTacToe game. The user specifies the number of games
 * they want to play at the beginning command line argument
 *
 * Input:
 * User enters number of games they want to play in original command 
 * line execution. Each user enters coordinate pairs to fill game board
 *
 * Output:
 * Prints the game board after each player move and prints results 
 * after each game.
 * **************************************************************/ 

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cctype>
using namespace std;

bool checkWinner(char gameArr[][3])
{
	string row1,row2,row3,col1,col2,col3,diag1,diag2; // strings for all 8 possible winning methods
	for (int r = 0; r < 3; r++)// iterating through game array and constructing winning "XXX" or "OOO" strings.
	{
		for(int c = 0; c < 3; c++)
		{
			if (r == 0)
				row1+= gameArr[r][c];
			if (c == 0)
				col1+= gameArr[r][c];
			if (r == 1)
				row2+= gameArr[r][c];
			if (c == 1)
				col2+= gameArr[r][c];
			if (r == 2)
				row3+= gameArr[r][c];
			if (c == 2)
				col3+= gameArr[r][c];
			if (r==c) // stores the forwards diagonal value
				diag1+=gameArr[r][c];
			if (r==(2-c)) //stores the backwards diagonal value
				diag2+=gameArr[r][c];
		}
	}
	if ((row1 == "XXX")||(row2 == "XXX")||(row3 == "XXX")||(col1 == "XXX")||(col2 == "XXX")||(col3 == "XXX")||(diag1 == "XXX")||(diag2 == "XXX"))//check for X winning string
		return true;
	else if ((row1 == "OOO")||(row2 == "OOO")||(row3 == "OOO")||(col1 == "OOO")||(col2 == "OOO")||(col3 == "OOO")||(diag1 == "OOO")||(diag2 == "OOO"))// check for O winning string
		return true;
	else
		return false;
}

void printGame(char gameArr[][3])// function to print game board after each player move and before and after each player wins
{
	cout<< "\n  0 1 2" << endl; // adds the column coordinate numbers above the tic tac toe grid
	for (int r = 0; r < 3; r++)
	{
		cout << r << " "; // adds the row coordinate numbers to the side of each row
		for(int c = 0; c < 3; c++)
		{
			cout << gameArr[r][c] << " "; //print player entries and add space to make it clearer to read
		}
	cout << endl; //starts each new row on a new line
	}	
}

int main(int argc, char *argv[])
{
	int numGames, games = 0;
	if (argc == 1)// checks if only the program name argument was supplied by the user
		numGames = 1;// if so the user is defaulted to play only one game
	else
		numGames = atoi(argv[1]);// otherwise the player plays the number of games they specified
	int playerXWins = 0, playerOWins = 0;//initialize the number of wins for each player
	char activePlayer = 'X'; //set the active player to 'X' to start the game
	char gameArray[3][3]; // declare gameboard 2D array
	string playerInput; // variable to store coordinate pairs from player
	cout << "You have chosen to play " << numGames << " game(s)." << endl; // notify the user of their command line argument value
	while (games < numGames)// Outer Loop for each tic Tac Toe game
	{
		int validInputs = 0;// variable to store number of valid input coordinate pairs from the user
		for (int r = 0; r < 3; r++)
		{
			for(int c = 0; c < 3; c++)
			{
				gameArray[r][c] = '.'; // pre-populate the game board with dots
			}
		}
		while(validInputs < 9) // loop to control the single tic tac toe game environment
		{
			printGame(gameArray); // call the print gameArray functions
			cout << "Player " << activePlayer << ", please enter your move." << endl; // prompt the active player to play
			getline(cin,playerInput); // store user input
			if (gameArray[playerInput.at(0) - '0'][playerInput.at(2) - '0'] != '.') // check to see if there is a free space at the coordinate pair
			{
				cout << "That square is already taken, try again." << endl; // returns to beginning inner loop
			}
			else // if the player enters a valid entry then execute the majority of the code
			{
				validInputs++; //increment valid user inputs moving it closer to 9 each time
				gameArray[playerInput.at(0) - '0'][playerInput.at(2) - '0'] = activePlayer; //sets the value on the gameboard to active players value
				if (validInputs >= 5)//checks to see if number of valid inputs is greater than or equal to five, its not possible for there to be a winner till 5 inputs have occurred
				{
					if (checkWinner(gameArray))// call the checkWinner function
					{
						if (activePlayer == 'X')//checks to see if winner was Player X
						{
							printGame(gameArray); // prints the winning game board
							cout << "Player X Wins Game " << games + 1 << " of " << numGames << endl; // notifies player X of win
							playerXWins++; // increments final win tally for player X
						}
						else //checks to see if winner was Player O
						{
							printGame(gameArray);// prints the winning game board
							cout << "Player O Wins Game " << games + 1 << " of " << numGames << endl; // notifies player O of win
							playerOWins++;// increments final win tally for player O
						}
						validInputs = 9; //sets valid inputs to 9 to get out of the loop
					}
					else // executes if no winner has been determined yet
					{
						if (validInputs == 9) // executes if it is the last turn of the game and no winner has been declared
						{
							printGame(gameArray); // prints the tied game board							
							cout << "Cat's Game!" << endl;//notifies players of results
						}
					}
				}
				if (activePlayer == 'X') //switches the player after each input
					activePlayer = 'O';
				else
					activePlayer = 'X';								
			}
		}
	games++; // increment the number of games played
	}
	if (playerXWins > playerOWins) // checks to see if player X had more total wins
		cout << "Player X won " << playerXWins << " to " << playerOWins<<endl;
	else if (playerOWins > playerXWins) // checks to see if player O had more total wins
		cout << "Player O won " << playerOWins << " to " << playerXWins<<endl;
	else // prints if tied
		cout << "Tied Match! " << playerOWins << " to " << playerXWins<<endl;
	return 0;
}
