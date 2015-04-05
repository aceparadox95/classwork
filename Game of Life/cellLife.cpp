#include <iostream>
#include <string>
#include "helpers.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
/*********************************************************************
 ** Function: addOscillator
 ** Description: Adds live cells in Pulsar Oscillator Pattern at starting
 ** point specified by user
 ** Parameters: starting coordinates from user and current game board
 ** Pre-Conditions: empty game board
 ** Post-Conditions: live cells add to game board
 *********************************************************************/
void addOscillator(int x, int y, char(&currentBoard)[42][100])
{
	for (int r = 0; r < 42; r++)/* Iterates through game board and adds live cells */
	for (int c = 0; c < 100; c++)
	{
		if (r - y == 1 ||
			r - y == 6 || 
			r - y == 8 || 
			r - y == 13)
		{
			currentBoard[r][3 + x] = 'O';
			currentBoard[r][4 + x] = 'O';
			currentBoard[r][5 + x] = 'O';
			currentBoard[r][9 + x] = 'O';
			currentBoard[r][10 + x] = 'O';
			currentBoard[r][11 + x] = 'O';
		}
		if ((r - y >= 3 &&
			r - y <= 5)||
			(r - y >= 9 &&
			r - y <= 11))
		{
			currentBoard[r][1 + x] = 'O';
			currentBoard[r][6 + x] = 'O';
			currentBoard[r][8 + x] = 'O';
			currentBoard[r][13 + x] = 'O';
		}
	}	
}
/*********************************************************************
 ** Function: addOscillator
 ** Description: Adds live cells in glider Pattern at starting
 ** point specified by user
 ** Parameters: starting coordinates from user and current game board
 ** Pre-Conditions: empty game board
 ** Post-Conditions: live cells add to game board
 *********************************************************************/
void addGlider(int x, int y, char(&currentBoard)[42][100])
{
	for (int r = 0; r < 42; r++)/* Iterates through game board and adds live cells */
	for (int c = 0; c < 100; c++)
	{
		if (r - y == 0)
		{
			currentBoard[r][0 + x] = 'O';
			currentBoard[r][2 + x] = 'O';
		}
		if (r - y == 1)
		{
			currentBoard[r][1 + x] = 'O';
			currentBoard[r][2 + x] = 'O';
		}
		if (r - y == 2)
		{
			currentBoard[r][1 + x] = 'O';
		}
	}
}
/*********************************************************************
 ** Function: addOscillator
 ** Description: Adds live cells in Glider Gun Pattern at starting
 ** point specified by user
 ** Parameters: starting coordinates from user and current game board
 ** Pre-Conditions: empty game board
 ** Post-Conditions: live cells add to game board
 *********************************************************************/
void addGliderGun(int x, int y, char(&currentBoard)[42][100])
{
	for (int r = 0; r < 42; r++) /* Iterates through game board and adds live cells */
	for (int c = 0; c < 100; c++)
	{
		if (r - y == 0)
		{
			currentBoard[r][24 + x] = 'O';
		}
		if (r - y == 1)
		{
			currentBoard[r][22 + x] = 'O';
			currentBoard[r][24 + x] = 'O';
		}
		if (r - y == 2)
		{
			currentBoard[r][12 + x] = 'O';
			currentBoard[r][13 + x] = 'O';
			currentBoard[r][20 + x] = 'O';
			currentBoard[r][21 + x] = 'O';
			currentBoard[r][34 + x] = 'O';
			currentBoard[r][35 + x] = 'O';
		}
		if (r - y == 3)
		{
			currentBoard[r][11 + x] = 'O';
			currentBoard[r][15 + x] = 'O';
			currentBoard[r][20 + x] = 'O';
			currentBoard[r][21 + x] = 'O';
			currentBoard[r][34 + x] = 'O';
			currentBoard[r][35 + x] = 'O';
		}
		if (r - y == 4)
		{
			currentBoard[r][0 + x] = 'O';
			currentBoard[r][1 + x] = 'O';
			currentBoard[r][10 + x] = 'O';
			currentBoard[r][16 + x] = 'O';
			currentBoard[r][20 + x] = 'O';
			currentBoard[r][21 + x] = 'O';
		}
		if (r - y == 5)
		{
			currentBoard[r][0 + x] = 'O';
			currentBoard[r][1 + x] = 'O';
			currentBoard[r][10 + x] = 'O';
			currentBoard[r][14 + x] = 'O';
			currentBoard[r][16 + x] = 'O';
			currentBoard[r][17 + x] = 'O';
			currentBoard[r][22 + x] = 'O';
			currentBoard[r][24 + x] = 'O';
		}
		if (r - y == 6)
		{
			currentBoard[r][10 + x] = 'O';
			currentBoard[r][16 + x] = 'O';
			currentBoard[r][24 + x] = 'O';
		}
		if (r - y == 7)
		{
			currentBoard[r][11 + x] = 'O';
			currentBoard[r][15 + x] = 'O';
		}
		if (r - y == 8)
		{
			currentBoard[r][12 + x] = 'O';
			currentBoard[r][13 + x] = 'O';
		}
	}
}
/*********************************************************************
 ** Function: conway
 ** Description: Checks cells surrounding current cell for live cells
 ** and stores a count variable, cells are either killed or born based
 ** on the count. The changes to cells are stored in the future board
 ** Parameters: current game board and future game board arrays
 ** Pre-Conditions: empty game board
 ** Post-Conditions: live cells add to game board
 *********************************************************************/
void conway(char(&currentBoard)[42][100], char(&futureBoard)[42][100])
{
	prepBoard(futureBoard);
	int aliveCells = 0;
	for (int r = 0; r < 42; r++)
	for (int c = 0; c < 100; c++)
	{
		if (currentBoard[r - 1][c - 1] == 'O') /* Top Left */
			aliveCells++;
		if (currentBoard[r][c - 1] == 'O')/* Left */
			aliveCells++;
		if (currentBoard[r + 1][c - 1] == 'O')/* Bottom Left */
			aliveCells++;
		if (currentBoard[r - 1][c] == 'O')/* Top */
			aliveCells++;
		if (currentBoard[r + 1][c] == 'O')/* Bottom */
			aliveCells++;
		if (currentBoard[r - 1][c + 1] == 'O')/* Top Right */
			aliveCells++;
		if (currentBoard[r][c + 1] == 'O')/* Right */
			aliveCells++;
		if (currentBoard[r + 1][c + 1] == 'O')/* Bottom Right */
			aliveCells++;

		if (currentBoard[r][c] == 'O') /* Checks if current cell is alive */
		{
			if (aliveCells <= 1) /* Cell is killed if there is 1 or less live cells surrounding it */
				futureBoard[r][c] = '-';
			else if (aliveCells >= 4) /* Cell is killed if there is 4 or more live cells surrounding it */
				futureBoard[r][c] = '-';
			else /* Otherwise the live cell remains */
				futureBoard[r][c] = currentBoard[r][c];
		}
		if (currentBoard[r][c] == '-') /* Checks if current cell is empty */
			if (aliveCells == 3) /* New cell born if it surrounded by exactly 3 cells*/
				futureBoard[r][c] = 'O';
		aliveCells = 0;
	}
}