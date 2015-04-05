#include "fullList.h"
using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::setprecision;
using std::fixed;
using std::left;
using std::ifstream;
using std::ofstream;
/*********************************************************************
** Function: grocery list contructor
** Description: creates empty grocery list
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: empty grocery list
*********************************************************************/
fullList::fullList()
{
	gList.reserve(100);
	totalListPrice = 0.0;
}
/*********************************************************************
** Function: addItem
** Description: Prompts user for information about grocery item and saves
** that item as part of the grocery list
** Parameters: none
** Pre-Conditions: grocery list object must be created first
** Post-Conditions: item added to grocery list
*********************************************************************/
void fullList::addItem()
{
	string tempString; // temp string for input validation purposes
	Item tempItem;
	char error = 'F';
	cout << "What is the name of your item? " << endl;
	cin >> tempString;
	tempItem.setName(tempString);
	cout << "What unit is it measured? " << endl;
	cin >> tempString;
	tempItem.setUnitType(tempString);
	while (error == 'F')
	{
		int invChars = 0; //to check for invalid characters
		int decCheck = 0; //to check for 1 decimal point
		cout << "How much does it cost? " << endl; // prompt user
		cin >> tempString; // store user input
		for (int i = 0; i < tempString.length(); i++) // loop through each character of the input
		{
			if (tempString[i] != '.') // check if not decimal
			{
				if (isalpha(tempString[i])) // check for letters
					invChars++;
			}
			if (tempString[i] == '.') //check for decimal
				decCheck++;
		}
		if (invChars > 0 || decCheck != 1)// validate input
			cout << "Invalid price. Try again. Enter in format $.¢¢" << endl;
		else
		{
			tempItem.setUnitPrice(atof(tempString.c_str())); // convert temp string back to double
			error = 'Q'; // set value to Q to make it possible to enter quantity loop
		}
	}
	while (error == 'Q')
	{
		int invChars = 0; // to check for invalid characters
		int decCheck = 0; // to check for decimal
		cout << "How many "<< tempItem.getUnitType() << " of " << tempItem.getName() << "(s) do you need? " << endl; // prompt user
		cin >> tempString; // store user input in string for validation purposes
		for (int i = 0; i < tempString.length(); i++)
		{
			if (tempString[i] != '.') //check if not decimal
			{
				if (isalpha(tempString[i])) // check for letters
					invChars++;
			}
			if (tempString[i] == '.') // check for decimal
				decCheck++;
		}
		if (invChars > 0 || decCheck > 1) // validate input
			cout << "Invalid Quantity. Try again. Enter an Valid Integer or Decimal" << endl;
		else
		{
			double quant = atof(tempString.c_str());
			tempItem.setQuantity(quant); // convert to integer
			error = 'P';
		}
	}
	gList.push_back(tempItem);
	setTotalListPrice();//reset total grocery list price
}
/*********************************************************************
** Function: removeItem
** Description: Prompts user for number of grocery item on list and then
** removes the item from the list
** Parameters: none
** Pre-Conditions: grocery list object must be created first and list must
** not be empty
** Post-Conditions: item removed from grocery list
*********************************************************************/
void fullList::removeItem()
{
	if (gList.empty())/*Check to see if list is empty*/
	{
		cout << "No items have been added to your grocery list yet." << endl;
	}
	else
	{
		listItems();
		int itemIndex;
		cout << "\n\nWhich item # would you like to remove from your list? ";
		cin >> itemIndex;
		if (itemIndex < 1 || itemIndex > gList.size()) //Check to see if item index is valid
		{
			cout << "Please enter a valid item number" << endl;
		}
		else
		{
			gList.erase(gList.begin() + (itemIndex - 1)); /*erase item from list vector*/
			cout << "You have removed item # " << itemIndex << " from your grocery list" << endl;
		}
		setTotalListPrice(); //reset total grocery list price
	}
}
/*********************************************************************
** Function: listItems
** Description: prints the grocery list as number items with information
** in formatted columns
** Parameters: none
** Pre-Conditions: grocery list object must be created first and list must
** not be empty
** Post-Conditions: grocery list printed to screen
*********************************************************************/
void fullList::listItems()
{
	if (gList.empty())/*check to see if list is empty*/
	{
		cout << "No items have been added to your grocery list yet." << endl;
	}
	else
	{
		cout << "   "; /*Column Headers*/
		cout << setw(10) << left << "Item:";
		cout << setw(15) << left << "Unit:";
		cout << setw(15) << left << "Unit Price:";
		cout << setw(15) << left << "Quantity:";
		cout << setw(15) << left << "Total Price:";
		cout << endl;
		for (int i = 0; i < gList.size(); i++) //iterate through list
		{
			cout << i + 1 << ". " << setw(10) << left << gList[i].getName();
			cout << setw(15) << left << gList[i].getUnitType();
			cout << "$" << setw(15) << left << fixed << setprecision(2) << gList[i].getUnitPrice();
			cout << setw(15) << left << fixed << setprecision(1) << gList[i].getQuantity();
			cout << "$" << setw(15) << left << fixed << setprecision(2) << gList[i].getTotalItemPrice();
			cout << endl;
		}
		cout << "Total Cost of Grocery List: " << setw(1) << "$" << fixed << setprecision(2) << getTotalListPrice();
		cout << endl;
	}
}
/*********************************************************************
** Function: setTotalListPrice
** Description: totals all of grocery list subtotals for overall price
** Parameters: none
** Pre-Conditions: grocery list object must be created first and list must
** not be empty
** Post-Conditions: sets the total list price variable
*********************************************************************/
void fullList::setTotalListPrice()
{
	totalListPrice = 0.0;
	if (!(gList.empty()))
	{
		for (int i = 0; i < gList.size(); i++) //iterate through list
		{
			totalListPrice += gList[i].getTotalItemPrice();
		}
	}
}
/*********************************************************************
** Function: getTotalListPrice
** Description: accesses groceryList total list price private variable
** Parameters: none
** Pre-Conditions: grocery list must be created first
** Post-Conditions: total list price returned to screen
*********************************************************************/
double fullList::getTotalListPrice()
{
	return totalListPrice;
}
/*********************************************************************
** Function: saveListtoFile
** Description: Exports current grocery list to a text file
** Parameters: none
** Pre-Conditions: grocery list object must be created first and list must
** not be empty
** Post-Conditions: grocery list saved in text file
*********************************************************************/
void fullList::saveListtoFile()
{
	ofstream grocListFile;
	grocListFile.open("groceryList.txt");
	if (gList.empty()) /*Check to see if list is empty*/
	{
		 cout << "No items have been added to your grocery list yet." << endl;
	}
	else /*Export list string by string*/
	{
		grocListFile << "   "; /*Column headers*/
		grocListFile << setw(10) << left << "Item:";
		grocListFile << setw(15) << left << "Unit:";
		grocListFile << setw(15) << left << "Unit Price:";
		grocListFile << setw(15) << left << "Quantity:";
		grocListFile << setw(15) << left << "Total Price:";
		grocListFile << endl;
		for (int i = 0; i < gList.size(); i++) /*Print each item list*/
		{
			grocListFile << i + 1 << ". " << setw(10) << left << gList[i].getName();
			grocListFile << setw(15) << left << gList[i].getUnitType();
			grocListFile << "$" << setw(15) << left << fixed << setprecision(2) << gList[i].getUnitPrice();
			grocListFile << setw(15) << left << fixed << setprecision(1) << gList[i].getQuantity();
			grocListFile << "$" << setw(15) << left << fixed << setprecision(2) << gList[i].getTotalItemPrice();
			grocListFile << endl;
		}
		grocListFile << "Total Cost of Grocery List: " << setw(1) << "$" << fixed << setprecision(2) << getTotalListPrice();
		grocListFile << endl;
	}
}
/*********************************************************************
** Function: readFile
** Description: Reads grocery list text file line by line to screen
** Parameters: none
** Pre-Conditions: grocery list text file must exist
** Post-Conditions: grocery list saved in text file
*********************************************************************/
void fullList::readFile()
{
	ifstream grocListFile;
	string tempString = "";
	grocListFile.open("groceryList.txt");
	if (grocListFile) /*Check to see that file exists*/
	{
		while (!(grocListFile.eof()))
		{
			getline(grocListFile, tempString); /*Print list string by string*/
			cout << tempString << endl;
		}
	}
	else
	{
		cout << "No list has been created. Please save a list first." << endl;
	}
	grocListFile.close();
}