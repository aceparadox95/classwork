/*********************************************************************
 ** Program Filename: gameofLife.cpp
 ** Author: Ryan Cosby	
 ** Date: January 16, 2015
 ** Description: This program is a take on Conway's Game of Life. The 
 ** user can place pattern on the game board and run generation iterations
 ** one generation at a time
 ** Input: User can select pattern types and the starting coordinates on 
 ** the board
 ** Output: User can output select awesomeness
 *********************************************************************/
 
#include <iostream>
#include <string>
#include "helpers.h"
#include "cellLife.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	char userState = 'Y'; /* temp variable to let use quite program */
	char currentBoard[42][100]; /* 2D array to store current game board */
	char futureBoard[42][100]; /* 2D array to store next generation game board */
	int coordX, coordY; /* coordinate variables for starting position of patterns*/
	string userCommand; /* variable to store user commands */
	while (userState == 'Y') /* Outer Loop with main menu options */
	{
		cout << "Choose a pattern you would like to add to the Game of Life Board:" << endl; /* Menu choices */
		cout << "Enter <1> for an Oscillator" << endl;
		cout << "Enter <2> for a glider" << endl;
		cout << "Enter <3> for a glider gun" << endl;
		cin >> userCommand; /* Store user command */
		cout << "Enter the X Coordinate for the Starting Point: ";
		cin >> coordX; /* Store user command */
		cout << "Enter the Y Coordinate for the Starting Point: ";
		cin >> coordY; /* Store user command */
		shiftCoordinates(&coordX, &coordY); /* shift user input coordinates 10 spots to fit on board */
		prepBoard(currentBoard); /* create an empty game board */
		if (checkvalidCoordinates(userCommand, coordX, coordY)) /* check to make sure pattern fits on board */
		{
			userState = 'P'; /* set the userState to allow access into inner loop */
			if (userCommand == "1") /* adds pattern selected to board */
				addOscillator(coordX, coordY, currentBoard);
			if (userCommand == "2")
				addGlider(coordX, coordY, currentBoard);
			if (userCommand == "3")
				addGliderGun(coordX, coordY, currentBoard);
		}
		else /* if pattern doesn't fit on board restart loop */
		{
			cout << "The pattern will not fit on the board with the coordinates you have entered";
			cout << "Please try again" << endl << endl;
		}
		while (userState == 'P') /* inner loop for running generations */
		{
			printBoard(currentBoard); /* prints current game board*/
			cout << "Would you like to run an iteration? (y or n)" << endl; 
			cin >> userCommand; 
			if (userCommand == "y")
			{
				conway(currentBoard, futureBoard); /* run iteration*/
				transferBoard(currentBoard, futureBoard); /* transfer future board to current board */
			}
			else
			userState = 'E'; /* allows user to exit */
		}
	}
	return 0;
}

