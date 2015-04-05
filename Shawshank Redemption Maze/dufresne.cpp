#include  "dufresne.h"
/*********************************************************************
** Function: Andy Cosntructor
** Description: Creates andy dufresne. Pillow case status is initially set
** disabled
** Parameters: executes when prison is created
** Pre-Conditions: none
** Post-Conditions: andy is created in prison
*********************************************************************/
Andy::Andy()
{
	pillowCaseLimit = 10;
	pillowCaseStatus = false;
	pillowCaseisFull = false;
	pillowCase.reserve(10);
}
/*********************************************************************
** Function: Add items
** Description: adds items to andy's pillow case up to certain limit
** Parameters: item string
** Pre-Conditions: andy's pillowcase must be enabled
** Post-Conditions: new item added to pillowcase
*********************************************************************/
void Andy::addItems(string item)
{
	if (pillowCaseStatus)
	{
		if (pillowCaseisFull == false)
		{
			pillowCase.push_back(item);
			setPCisfull();
		}
		else
		{
			cout << "ERROR: You cannot add " << item << " you're pillowcase is full" << endl;
			cout << "       You can get rid of wall chunks at the graveyard" << endl;
			cout << "       You can get rid of extra maggots at the loading dock" << endl;
			cout << "       You can get rid of extra cigarettes at the library" << endl;
		}
	}
	else
		cout << "ERROR: You have not acquired the pillow case yet, so you cant store "  << item << endl;
}
/*********************************************************************
** Function: Remove items
** Description: Removes a certain time of item until it cant be found 
** anymore
** Parameters: item string
** Pre-Conditions: pillowcase must be enabled
** Post-Conditions: item removed from pillowcase
*********************************************************************/
void Andy::removeItems(string item)
{
	if (pillowCaseStatus)
	{
		for (int i = 0; i < pillowCase.size(); i++)
		{
			if (pillowCase[i] == item)
			{
				pillowCase.erase(pillowCase.begin() + i);
				break;
			}
		}
		setPCisfull();
	}
	else
		cout << "ERROR: You have not acquired the pillow case yet, so you cant remove anything" << endl;
}
/*********************************************************************
** Function: List Items
** Description: Lists the contents of the pillowcase
** Parameters: pillowcase must be enabled
** Pre-Conditions: items are unknown
** Post-Conditions: prints items to screen
*********************************************************************/
void Andy::listItems()
{
	cout << "Pillow case contents: " << endl;
	if (pillowCaseStatus )
	{
		if (pillowCase.size() > 0)
		{
			for (int i = 0; i < pillowCase.size(); i++)
			{
				if (i == (pillowCase.size() - 1))
					cout << pillowCase[i];
				else
					cout << pillowCase[i] << ", ";
				if (i > 0 && i % 3 == 0)
					cout << endl;
			}
		}
		else
			cout << "You have no items in your pillow case" << endl;
	}
	else
		cout << "ERROR: You have not acquired the pillow case yet to hold items" << endl;
	cout << endl;
}
bool Andy::getPCStatus()
{
	return pillowCaseStatus;
}
void Andy::setPCStatus()
{
	pillowCaseStatus = true;
}
bool Andy::getPCisfull()
{
	return pillowCaseisFull;
}
/*********************************************************************
** Function: sets the pillowcase status if its full
** Description: prints menu to screen
** Parameters: pillow case must be enabled
** Pre-Conditions: pillowcase not full
** Post-Conditions: pillowcase is full
*********************************************************************/
void Andy::setPCisfull()
{
	if (pillowCaseStatus)
	{
		if (pillowCase.size() == pillowCaseLimit)
		{
			pillowCaseisFull = true;
		}
		else
			pillowCaseisFull = false;
	}
	else
		cout << "ERROR: You have not found the pillow case yet to hold items" << endl;
}
/*********************************************************************
** Function: search pillow case
** Description: looks in the pillowcase for a certain item and reports
** the count of that item back to the user
** Parameters: item search term
** Pre-Conditions: not known how many of certain item is in pillowcase
** Post-Conditions: returns the number of items
*********************************************************************/
int Andy::searchPillowCase(string searchTerm)
{
	int itemCount = 0;
	if (pillowCaseStatus)
	{
		for (int i = 0; i < pillowCase.size(); i++)
		{
			if (pillowCase[i] == searchTerm)
			{
				itemCount++;
			}
		}
	}
	else
		cout << "" << endl;
	return itemCount;
}