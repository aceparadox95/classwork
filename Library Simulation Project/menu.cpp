/***************************************************************
 * Author: Ryan Cosby
 * Date Created: 12/5/2014
 * Last Modification Date: 12/6/2014
 * File name: menu.cpp
 *
 * Overview:
 * This is a library simulator. The user is a library clerk. The
 * clerk can add new books, add patrons, remove books, checkout books, return
 * books, request books, pay fines, and view book and patron info using prompts
 * from a menu.
 * Input:
 * The library clerk uses menu commands, fine amounts, patron IDs, and book IDs
 * Output:
 * The library clerks sees the various outputs from the menu commands
 * **************************************************************/ 
#include "Book.h"
#include "Patron.h"
#include "Library.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
//main function
int main()
{
	int comm = -1; //value to store command
	Library newLib;
	string patID, bookID;
	double payAmount;
	while (comm != 0)
	{
		cout << "***********************************************************************" << endl; //menu options
		cout << "Enter 1 to add a new Book to the library" << endl;
		cout << "Enter 2 to add a new patron to the library" << endl;
		cout << "Enter 3 to check out a book from the library" << endl;
		cout << "Enter 4 to return a book to the library" << endl;
		cout << "Enter 5 to request a hold on a book in the library" << endl;
		cout << "Enter 6 to pay fine for overdue amount on books" << endl;
		cout << "Enter 7 to increment the current date" << endl;
		cout << "Enter 8 to view patron information" << endl;
		cout << "Enter 9 to view book information" << endl;
		cout << "Enter 10 to quit program" << endl;
		cout << "***********************************************************************" << endl;
		cin >> comm;
		if (comm == 1) // Execute appropriate functions based on command value
			newLib.addBook();
		if (comm == 2)
			newLib.addMember();
		if (comm == 3)
		{
			cout << "Enter Patron ID: " << endl;
			cin >> patID;
			cout << "Enter Book ID: " << endl;
			cin >> bookID;
			newLib.checkOutBook(patID, bookID);
		}
		if (comm == 4)
		{
			cout << "Enter Book ID: " << endl;
			cin >> bookID;
			newLib.returnBook(bookID);
		}
		if (comm == 5)
		{
			cout << "Enter Patron ID: " << endl;
			cin >> patID;
			cout << "Enter Book ID: " << endl;
			cin >> bookID;
			newLib.requestBook(patID, bookID);
		}
		if (comm == 6)
		{
			cout << "Enter Patron ID: " << endl;
			cin >> patID;
			cout << "Current Fine Amount: " << newLib.retrievePatronFine(patID) << endl; // display current fine amount
			if (newLib.retrievePatronFine(patID) <= 0.0) // if the patron fine is less than zero then dont allow them to pay a fine
			{
				newLib.payFine(patID, 0.0);
				cout << "No fine payment necessary. Balance is zero." << endl;
			}
			else// if the patron fine is greater than zero then execute as normal
			{
				cout << "Enter Payment Amount: " << endl;
				cin >> payAmount;
				newLib.payFine(patID,payAmount);
			}
		}
		if (comm == 7)
			newLib.incrementCurrentDate();
		if (comm == 8)
		{
			cout << "Enter Patron ID: " << endl;
			cin >> patID;
			newLib.viewPatronInfo(patID);
		}
		if (comm == 9)
		{
			cout << "Enter Book ID: " << endl;
			cin >> bookID;
			newLib.viewBookInfo(bookID);
		}
		if (comm == 10)
			comm = 0;//set the command value to 0 to exit loop
	}
	return 0;
}//end of main

