/*********************************************************************
** Program Filename: groceryList.cpp
** Author: Ryan Cosby
** Date: January 29, 2015
** Description: This program simulates a grocery list. It allows the user
** to add new items, save items to a list, read items from a list, and
** remove items from a list.
** Input: User selects commands from the main menu and also inputs info
** about each grocery item
** Output: Grocery List prints to the screen with prices and total price
*********************************************************************/

#include "fullList.h"
#include "item.h"

using std::cin;
using std::cout;
using std::endl;
int main()
{
	fullList groceryList;
	char comm = 'x';
	while (comm != 'Q') /*Menu List for User to choose from*/
	{
		cout << "***********************************************************************" << endl;
		cout << "Enter <A> to add item to your grocery list" << endl;
		cout << "Enter <R> to remove item from your grocery list" << endl;
		cout << "Enter <L> to list the items in your grocery list" << endl;
		cout << "Enter <S> to save the items in your grocery list to a file" << endl;
		cout << "Enter <I> to read the items from your grocery list file" << endl;
		cout << "Enter <Q> to exit the program" << endl;
		cout << "***********************************************************************" << endl;
		cin >> comm;
		comm = toupper(comm); /*Standardizes User Input*/
		if (comm == 'A') /*Executes command based on item chosen by user*/
			groceryList.addItem();
		if (comm == 'R')
			groceryList.removeItem();
		if (comm == 'L')
			groceryList.listItems();
		if (comm == 'S')
			groceryList.saveListtoFile();
		if (comm == 'I')
			groceryList.readFile();
	}
	return 0;
}

