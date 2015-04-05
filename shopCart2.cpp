/***************************************************************
 * Author: Ryan Cosby
 * Date Created: 11/25/2014
 * Last Modification Date: 11/26/2014
 * File name: shopCart2.cpp
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
#include <vector>
#include <cctype>
using namespace std;

class Item //holds shopping cart item
{
	private:
		string name; //name of item
		double price; // price of item
		int quantity; // number of items
	public:
		void set_name(string);
		void set_price(double);
		void set_quantity(int);
		string get_name();
		double get_price();
		int get_quantity();
};
void Item::set_name(string inpName)
{
	name = inpName;
}
void Item::set_price(double inpPrice)
{
	price = inpPrice;
}
void Item::set_quantity(int inpQuant)
{
	quantity = inpQuant;
}
string Item::get_name()
{
	return name;
}
double Item::get_price()
{
	return price;
}
int Item::get_quantity()
{
	return quantity;
}

class ShoppingCart //holds shopping cart item
{
	private:
		vector<Item> shpCart; //vector of Items
	public:
		void addItems(Item); //add items member function
		void listItems(); //list items member function
		void totalPrice(); //print total price member function
};
void ShoppingCart::addItems(Item inpItem)
{
	string tempString; // temp string for input validation purposes
	char error = 'F';
	cout << "What is the name of your item? " << endl;
	cin >> tempString;
	inpItem.set_name(tempString);
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
			inpItem.set_price(atof(tempString.c_str())); // convert temp string back to double
			error = 'Q'; // set value to Q to make it possible to enter quantity loop
		}
	}
		while (error == 'Q')
	{
		int invChars = 0; // to check for invalid characters
		int decCheck = 0; // to check for decimal
		cout << "How many " << inpItem.get_name() << "(s) will you purchase? " << endl; // prompt user
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
		    int quant = atoi(tempString.c_str());
			inpItem.set_quantity(quant); // convert to integer
			error = 'T';
		}
	}
	shpCart.push_back(inpItem);
}

void ShoppingCart::listItems()
{
	for (int i = 0; i < shpCart.size(); i++) //print total number of items
	{
		cout << "Item: " << setw(20) << shpCart[i].get_name() << " Price: " << setw(8) << "$" << shpCart[i].get_price();
		cout << " Quantity: " << setw(8) << shpCart[i].get_quantity() << endl;
	}
}

void ShoppingCart::totalPrice()
{
	double total = 0;
	for (int i = 0; i < shpCart.size(); i++) // store total cost after iterating through all items
	{
		total+= shpCart[i].get_price() * shpCart[i].get_quantity();
	}
	
	cout << "You have $" << fixed << setprecision(2) << total << " worth of items in your shopping cart." << endl;
}

int main()
{
    Item aItem;
	ShoppingCart cart;
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
			cart.addItems(aItem);
		if (comm == 'L')
			cart.listItems();
		if (comm == 'P')
			cart.totalPrice();
	}
	return 0;
}
