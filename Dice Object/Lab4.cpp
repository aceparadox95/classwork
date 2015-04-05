/*********************************************************************
** Program Filename: Lab 4.cpp
** Author: Ryan Cosby
** Date: January 31, 2015
** Description: This program simulates rolling dice. It also allows the
** user to roll loaded dice which add a 50% likelihood of rolling the high
** number on a dice.
** Input: User specifies number of sides on a dice, type of dice, and number 
** of roles
** Output: Generates text files based on the type of dice chosen
*********************************************************************/
#include "Dice.h"
#include "LoadedDice.h"
#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;


// Take two dice objects, roll them, and return the sum
int rollTwoDice(const Dice& die1, const Dice& die2)
{
	return die1.rollDice() + die2.rollDice();
}

int main()
{

	int diceSides = 0; //Initialize dice sides value
	char comm = 'N';
	while (comm != 'Q')
	{
		/*Ask user what kind of dice they want to roll*/
		cout << "Would you like to roll a normal dice (enter N) or loaded dice (enter L)?" << endl;
		cout << "You may enter Q to quit"<< endl;
		cin >> comm;
		comm = toupper(comm); /*Standardize user input*/
		if (comm != 'Q')
		{
			cout << "How many sides does the dice have? " << endl; /*Number of sides input*/
			cin >> diceSides;
			if (comm == 'N')
			{
				ofstream normDice; /*Create output filestream*/
				normDice.open("normDiceOutput.txt");/*Output filename*/
				Dice die1(diceSides);
				Dice die2(diceSides);
				int rollNum = 2;
				while (rollNum != 0)
				{
					/*Ask user for input on number of roles*/
					cout << "How many times would you like to roll a normal die (enter 0 to exit)? ";
					cin >> rollNum;
					for (int i = 0; i < rollNum; i++)/*iterate through normal die roll function 100 times*/
					{
						normDice << rollTwoDice(die1, die2) << endl;
					}
				}
				cout << "Output File Generated: normDiceOutput.txt" << endl; 
				normDice.close();
			}
			if (comm == 'L')
			{
				ofstream loadDice; /*Create output filestream*/
				loadDice.open("LoadedDiceOutput.txt"); /*Output filename*/
				LoadedDice die1(diceSides);
				LoadedDice die2(diceSides);
				int rollNum = 2;
				while (rollNum != 0)
				{
					/*Ask user for input on number of roles*/
					cout << "How many times would you like to roll a loaded die (enter 0 to exit)? ";
					cin >> rollNum;
					for (int i = 0; i < rollNum; i++)/*iterate through loaded die roll function 100 times*/
					{
						loadDice << rollTwoDice(die1, die2) << endl;
					}
				}
				cout << "Output File Generated: LoadedDiceOutput.txt" << endl; 
				loadDice.close();
			}
		}
	}
	return 0;
}

