/***************************************************************
 * Author: Ryan Cosby
 * Date Created: 11/17/2014
 * Last Modification Date: 11/18/2014
 * File name: shopCart.cpp
 *
 * Overview:
 * This a shopping cart practice program. The user can add items of certain
 * prices and quantities to a shopping cart and then print the shopping cart
 * list and total cost.
 * Input:
 * User choose to list contents, add items, or print total cost. 
 * 
 *
 * Output:
 * Print Shopping Cart List or Total cost 
 * 
 * **************************************************************/ 

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct Item //holds shopping cart item
{
	string name; //name of item
	double price; // price of item
	int quantity; // number of items
};

void addItems(Item (&shpCart)[100])
{
	int countItems = 0;
	string tempString; // temp string for input validation purposes
	char error = 'F';
	while (shpCart[countItems].name.length() > 0) //counts number of items in cart 
		countItems++;
	cout << "What is the name of your item? " << endl;
	cin >> shpCart[countItems].name;
	while (error == 'F')
	{
		int invChars = 0; //to check for invalid characters
		int decCheck = 0; //to check for 1 decimal point
		cout << "How much does it cost? " << endl; // prompt user
		cin >> tempString; // store user input
		for (int i = 0; i < tempString.length(); i++) // loop through each character of the input
		{
			if (tempString[i] != '.' ) // check if not decimal
			{
				if (isalpha(tempString[i])) // check for letters
					invChars++; 
			}
			if (tempString[i] == '.' ) //check for decimal
				decCheck++;
		}
		if (invChars > 0 || decCheck != 1)// validate input
			cout << "Invalid price. Try again. Enter in format $.¢¢" << endl;
		else
		{
			shpCart[countItems].price = atof(tempString.c_str()); // convert temp string back to double
			error = 'Q'; // set value to Q to make it possible to enter quantity loop
		}
	}
		while (error == 'Q')
	{
		int invChars = 0; // to check for invalid characters
		int decCheck = 0; // to check for decimal
		cout << "How many " << shpCart[countItems].name << "(s) will you purchase? " << endl; // prompt user
		cin >> tempString; // store user input in string for validation purposes
		for (int i = 0; i < tempString.length(); i++)
		{
			if (tempString[i] != '.' ) //check if not decimal
			{
				if (isalpha(tempString[i])) // check for letters
					invChars++;
			}
			if (tempString[i] == '.' ) // check for decimal
				decCheck++;
		}
		if (invChars > 0 || decCheck != 0) // validate input
			cout << "Invalid price. Try again. Enter an Integer" << endl;
		else
		{
			shpCart[countItems].quantity = atoi(tempString.c_str()); // convert to integer
			error = 'T';
		}
	}
}

void listItems(Item (&shpCart)[100])
{
	int countItems = 0;
	while (shpCart[countItems].name.length() > 0) //count number of items in cart
		countItems++;
	for (int i = 0; i < countItems; i++) //print total number of items
	{
		cout << "Item: " << setw(20) << shpCart[i].name << " Price: " << setw(8) << "$" << shpCart[i].price;
		cout << " Quantity: " << setw(8) << shpCart[i].quantity << endl;
	}
}

void totalItems(Item (&shpCart)[100])
{
	int countItems = 0;
	double total = 0;
	while (shpCart[countItems].name.length() > 0) // count number of items
		countItems++;
	for (int i = 0; i < countItems; i++) // store total cost after iterating through all items
	{
		total+= shpCart[i].price * shpCart[i].quantity;
	}
	
	cout << "You have $" << fixed << setprecision(2) << total << " worth of items in your shopping cart." << endl;
}

int main()
{
	Item shoppingCart[100];
	char comm;
	while(comm != 'Q')
	{
		cout << "***********************************************************************"<< endl;
		cout << "Enter <A> to add item to your shopping cart" << endl;
		cout << "Enter <L> to List the items in your shopping cart" << endl;
		cout << "Enter <P> to display the price of all the items in your shopping cart" << endl;
		cout << "Enter <Q> to exit the program" << endl;
		cout << "***********************************************************************"<<endl;
		cin >> comm;
		if (comm == 'A')
			addItems(shoppingCart);
		if (comm == 'L')
			listItems(shoppingCart);
		if (comm == 'P')
			totalItems(shoppingCart);
	}
	return 0;
}