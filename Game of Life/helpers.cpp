#include <iostream>
#include <string>
#include "cellLife.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

/*********************************************************************
 ** Function: shiftCoordinates
 ** Description: Takes user coordinates and shift them
 ** Parameters: User x and y coordinates integers
 ** Pre-Conditions: unshifted coordinates
 ** Post-Conditions: coordinates shifted to show on game board
 *********************************************************************/
void shiftCoordinates(int* x, int* y)
{
	*x = *x + 9; /* add 9 to x and y coordinates */
	*y = *y + 9;
}
/*********************************************************************
 ** Function: checkvalidCoordinates
 ** Description: Checks to see that the starting point of user selected
 ** pattern will fit onto the visible part of the game board
 ** Parameters: user selected pattern number, x and y coordinate integers
 ** Pre-Conditions: Unknown if pattern will fit on visible board
 ** Post-Conditions: Boolean returned to user that it will fit on the board
 *********************************************************************/
bool checkvalidCoordinates(string userCommand, int x, int y)
{
	if (userCommand == "1")
	{
		if (x + 15 > 90) /* Height of oscillator is 15 */
			return false;
		if (y + 15 > 32) /* Width of oscillator is 15 */
			return false;
	}
	if (userCommand == "2") 
	{
		if (x + 3 > 90) /* Height of glider is 3 */
			return false;
		if (y + 3 > 32) /* Width of glider is 3 */
			return false;
	}
	if (userCommand == "3")
	{
		if (x + 36 > 90) /* Height of glider is 36 */
			return false;
		if (y + 9 > 32) /* width of glider is 9 */
			return false;
	}
	return true;
}
/*********************************************************************
 ** Function: prepBoard
 ** Description: Populates game board with empty cells
 ** Parameters: Current 2D array game board
 ** Pre-Conditions: current game board with null values
 ** Post-Conditions: each cell of game board now specified as empty
 *********************************************************************/
void prepBoard(char(&currentBoard)[42][100])
{
	for (int r = 0; r < 42; r++)
		for (int c = 0; c < 100; c++)
			currentBoard[r][c] = '-';
}
/*********************************************************************
 ** Function: printBoard
 ** Description: Prints the visible part of the board
 ** Parameters: Current 2D array game board
 ** Pre-Conditions: none
 ** Post-Conditions: visible part of game board printed to screen
 *********************************************************************/
void printBoard(char(&currentBoard)[42][100])
{
	cout << string(50, '\n');
	for (int r = 10; r < 32; r++)
	for (int c = 10; c < 90; c++)
		cout << currentBoard[r][c];
}
/*********************************************************************
 ** Function: transferBoard
 ** Description: Moves future generation board to current after each 
 ** simulation
 ** Parameters: Current and Future 2D array
 ** Pre-Conditions: Current and Future Boards after simulation
 ** Post-Conditions: Current and Future Boards prepped for next simulation
 *********************************************************************/
void transferBoard(char(&currentBoard)[42][100], char(&futureBoard)[42][100])
{
	for (int r = 0; r < 42; r++)
	for (int c = 0; c < 100; c++)
		currentBoard[r][c] = futureBoard[r][c];
}