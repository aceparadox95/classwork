#include "locations.h"
/*********************************************************************
** Function: parent class constructor
** Description: does nothing
** Parameters: does nothing
** Pre-Conditions: none
** Post-Conditions: prints menu to screen
*********************************************************************/
Location::Location()
{

}

string Location::getLabel()
{
	return label;
}
/*********************************************************************
** Function: setMoves
** Description: Sets the Nodes of each location
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: nodes are created
*********************************************************************/
void Location::setMoves(Location *o1, Location *o2, Location *o3, Location *o4)
{
	option1 = o1;
	option2 = o2;
	option3 = o3;
	option4 = o4;
}
/*********************************************************************
** Function: Escape Requirements
** Description: In derived classes this functions is used to force 
** certain items to be in Andy's bag before he leaves the room. In
** the case of his cell this also forces him to have breached the wall.
** Parameters: Passes the andy object
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
bool Location::escRequire(Andy* AD)
{
	return false;
}
/*********************************************************************
** Function: List Available Actions
** Description: List Available Actions in Room
** Parameters: Andy Dufresne object
** Pre-Conditions: none
** Post-Conditions: prints menu to screen
*********************************************************************/
void Location::listAvailActions()
{
	cout << "Available Tasks:" << endl;
	if (action1 != "")
		cout << "1. " << action1 << endl;
	if (action2 != "")
		cout << "2. " << action2 << endl;
}
/*********************************************************************
** Function: List available movements
** Description: List available locations to go to
** Parameters: Andy Dufresne object
** Pre-Conditions: none
** Post-Conditions: prints menu to screen
*********************************************************************/
void Location::listAvailMovements()
{
	cout << "Change Locations:" << endl;
	if (option1 != NULL)
		cout << "A. " << option1->getLabel() << endl;
	if (option2 != NULL)
		cout << "B. " << option2->getLabel() << endl;
	if (option3 != NULL)
		cout << "C. " << option3->getLabel() << endl;
	if (option4 != NULL)
		cout << "D. " << option4->getLabel() << endl;
}
/*********************************************************************
** Function: Room Entry
** Description: Sets current room equal to the requested room based on command
** Parameters: Command from user
** Pre-Conditions: Current Location
** Post-Conditions: Current Location equals new location
*********************************************************************/
Location* Location::entry(char comm)
{
	if (comm == 'A')
		return option1;
	else if (comm == 'B')
		return option2;
	else if (comm == 'C')
		return option3;
	else if (comm == 'D')
		return option4;
}
/*********************************************************************
** Function: Do Action 1
** Description: After passing the requirements of action1Req performs
** the action requested by the user. This involves either getting rid
** of items from the pillowcase or adding items to the pillow case. In the
** case of Andy's room it also means altering the state of the wall.
** Parameters: Andy Dufresne object
** Pre-Conditions: no action taken
** Post-Conditions: action taken if requirements passed
*********************************************************************/
void Location::doAction1(Andy*)
{

}
/*********************************************************************
** Function: Do Action 2
** Description: After passing the requirements of action2Req performs
** the action requested by the user. This involves either getting rid
** of items from the pillowcase or adding items to the pillow case. In the
** case of Andy's room it also means altering the state of the wall.
** Parameters: Andy Dufresne object
** Pre-Conditions: no action taken
** Post-Conditions: action taken if requirements passed
*********************************************************************/
void Location::doAction2(Andy*)
{

}
/*********************************************************************
** Function: Action 1 Requirements
** Description: Checks Andy's pillowcase to see if certain items are 
** there and how many of those items there are. In the case of Andy's
** room it checks to see if a poster is on the wall.
** Parameters: Andy Dufresne object
** Pre-Conditions: none
** Post-Conditions: returns a boolean value
*********************************************************************/
bool Location::action1Req(Andy*)
{
	return true;
}
/*********************************************************************
** Function: Action 2 Requirements
** Description: Checks Andy's pillowcase to see if certain items are
** there and how many of those items there are. In the case of Andy's
** room it checks to see if a poster is on the wall.
** Parameters: Andy Dufresne object
** Pre-Conditions: none
** Post-Conditions: returns a boolean value
*********************************************************************/
bool Location::action2Req(Andy*)
{
	return true;
}

AndyCell::AndyCell()
{
	label = "Your Cell";
	action1 = "Put poster on wall";
	action2 = "Chip wall with rock hammer";
	posterWall = false;
	item1 = "wall chunks";
	item2 = "";
	option1 = NULL;
	option2 = NULL;
	option3 = NULL;
	option4 = NULL;
	wallStrength = 10;
}
int AndyCell::getWallStrength()
{
	return wallStrength;
}
void AndyCell::setWallStrength()
{
	wallStrength--;
	if (getWallStrength() <= 0)
	{
		cout << "You have broke through the wall!!" << endl;
	}
}
bool AndyCell::escRequire(Andy* AD)
{
	int searchSum = 0;
	searchSum += AD->searchPillowCase("rock hammer");
	searchSum += AD->searchPillowCase("financial documents");
	searchSum += AD->searchPillowCase("dress suit");
	searchSum += AD->searchPillowCase("large rock");
	searchSum += AD->searchPillowCase("large plastic bag");
	searchSum += AD->searchPillowCase("rope");
	if (searchSum == 6)
	{
		if (getWallStrength() <= 0)
		{
			cout << "You have climbed through the wall, slid down the rope," << endl
				 << "and cracked the sewer pipe with the large rock" << endl;
			AD->removeItems("rope");
			return true;
		}
		else
		{
			cout << "You can't escape yet, you haven't breached the other side of the " << endl 
			     << "wall. Keep chippin away at it with the rock hammer" << endl;
			return false;
		}
	}
	else
	{
		cout << "You don't have all the items you need to make a clean escape" << endl;
		return false;
	}
}
void AndyCell::doAction1(Andy* AD)
{
	if (posterWall == false)
	{
		if (action1Req(AD) == true)
		{
			posterWall = true;
			cout << "You have put the poster on the wall, you'll now be able to hide the " << endl
				<< "hole in the wall" << endl;
			AD->removeItems("poster");
		}
	}
	else
	{
		cout << "You already put the poster on the wall" << endl;
	}
}
void AndyCell::doAction2(Andy* AD)
{
	if (action2Req(AD))
	{
		if (AD->getPCisfull() == false)
		{
			cout << "You just tore some chunks from the wall" << endl
				<< "You need to take the chunks out to the graveyard so the guards don't get " << endl
				<< " suspicious. This will also help clear your pillow case" << endl;
			AD->addItems(item1);
			setWallStrength();
		}
		else
		{
			cout << "You need to clear some space in your pillow case for wall chunks" << endl;
		}
	}
}
bool AndyCell::action1Req(Andy* AD)
{
	if (AD->searchPillowCase("poster") == 1)
		return true;
	else
	{
		cout << "You need to get the poster from Red in the Prison Yard first" << endl;
		return false;
	}

}
bool AndyCell::action2Req(Andy* AD)
{
	if (AD->searchPillowCase("rock hammer") == 1)
	{
		if (posterWall)
			return true;
		else
			cout << "That's great that you have the rock hammer, but you won't be able to hide" << endl
			     << "the hole you're making without putting up the poster" << endl;
			return false;
	}
	else
	{
			cout << "You need to get the rock hammer from Red in the Prison Yard first" << endl;
			return false;
	}
}
Library::Library()
{
	label = "The Library";
	action1 = "Trade maggots for Brooks's bird Jake for 1 pack of cigarettes";
	action2 = "Give extra packs of cigarettes back to Brooks";
	item1 = "1 pack of cigarettes";
	item2 = "";
	option1 = NULL;
	option2 = NULL;
	option3 = NULL;
	option4 = NULL;
}
void Library::doAction1(Andy* AD)
{
	if (action1Req(AD))
	{
		AD->removeItems("maggots");
		AD->addItems(item1);
		cout << "Brooks gave you " << item1 << endl;
	}
}
void Library::doAction2(Andy* AD)
{
	if (action2Req(AD))
	{
		cout << "Brooks says thanks for the pack of cigarettes!" << endl;
		AD->removeItems("1 pack of cigarettes");
	}
}
bool Library::action1Req(Andy* AD)
{
	if (AD->searchPillowCase("maggots") >= 1)
		return true;
	else
	{
		cout << "You don't have any maggots to trade" << endl;
		return false;
	}
}
bool Library::action2Req(Andy* AD)
{
	if (AD->searchPillowCase("1 pack of cigarettes") <= 0)
	{
		cout << "You don't have any cigarettes to give" << endl;
		return false;
	}
	else
		return true;
}
Laundry::Laundry()
{
	label = "The Laundry Room";
	action1 = "Get a pillow case";
	action2 = "";
	item1 = "";
	item2 = "";
	option1 = NULL;
	option2 = NULL;
	option3 = NULL;
	option4 = NULL;
}
void Laundry::doAction1(Andy* AD)
{
	if (action1Req(AD))
	{
		AD->setPCStatus();
		cout << "You picked up a pillowcase, now you can store your items" << endl;
	}
}
void Laundry::doAction2(Andy*)
{
	cout << "ERROR: Invalid action command" << endl;
}
bool Laundry::action1Req(Andy* AD)
{
	if (AD->getPCStatus())
	{
		cout << "You do not need another pillowcase, you already have one to store your items" << endl;
		return false;
	}
	else
	{
		return true;
	}
}
bool Laundry::action2Req(Andy*)
{
	return true;
}
MessHall::MessHall()
{
	label = "The Mess Hall";
	action1 = "Pull maggots from garbage can";
	action2 = "Take a large plastic bag";
	item1 = "maggots";
	item2 = "large plastic bag";
	option1 = NULL;
	option2 = NULL;
	option3 = NULL;
	option4 = NULL;
}
void MessHall::doAction1(Andy* AD)
{
	cout << "You took some maggots from the garbage can" << endl;
	AD->addItems(item1);
}
void MessHall::doAction2(Andy* AD)
{
	if (action2Req(AD))
	{
		cout << "You took a large plastic bag" << endl;
		AD->addItems(item2);
	}
}
bool MessHall::action1Req(Andy*)
{
	return true;
}
bool MessHall::action2Req(Andy* AD)
{
	if (AD->searchPillowCase(item2) == 1)
	{
		cout << "You do not need more than one plastic bag to keep the dress suit and "
			 << endl << "financial documents clean" << endl;
		return false;
	}
	else
	{
		return true;
	}
}
SewerPipe::SewerPipe()
{
	label = "The Sewer Pipe";
	action1 = "Get rid of large rock";
	action2 = "";
	item1 = "";
	item2 = "";
	option1 = NULL;
	option2 = NULL;
	option3 = NULL;
	option4 = NULL;
}
bool SewerPipe::escRequire(Andy* AD)
{
	int searchSum = 0;
	searchSum += AD->searchPillowCase("large rock");
	if (searchSum != 1)
		return true;
	else
	{
		cout << "You need to pitch the large rock so you can move through the sewer pipe quickly" << endl;
		return false;
	}
}
void SewerPipe::doAction1(Andy* AD)
{
	if (action1Req(AD))
	{
		cout << "You just got rid of the large rock, that should help you move a little faster in the sewer pipe" << endl;
		AD->removeItems("large rock");
	}
}
void SewerPipe::doAction2(Andy*)
{
	cout << "ERROR: Invalid task command" << endl;
}
bool SewerPipe::action1Req(Andy* AD)
{
	if (AD->searchPillowCase("large rock") == 1)
		return true;
	else
	{
		cout << "You already got rid of the rock" << endl;
		return false;
	}
}
bool SewerPipe::action2Req(Andy*)
{
	return true;
}
WardenOff::WardenOff()
{
	label = "Warden Norton's Office";
	action1 = "Steal Warden's financial documents";
	action2 = "Steal Warden's dress suit";
	item1 = "financial documents";
	item2 = "dress suit";
	option1 = NULL;
	option2 = NULL;
	option3 = NULL;
	option4 = NULL;
}
void WardenOff::doAction1(Andy* AD)
{
	if (action1Req(AD))
	{
		cout << "You have stolen the Warden's financial documents, it's okay...he deserved it" << endl;
		AD->addItems(item1);
	}

}
void WardenOff::doAction2(Andy* AD)
{
	if (action2Req(AD))
	{
		cout << "You have stolen the Warden's dress suit, you'll look good walking into the Bank" << endl;
		AD->addItems(item2);
	}

}
bool WardenOff::action1Req(Andy* AD)
{
	if (AD->searchPillowCase(item1) == 1)
	{
		cout << "You'll only need one nice suit on the outside, you don't need another one" << endl;
		return false;
	}
	else
		return true;
}
bool WardenOff::action2Req(Andy* AD)
{
	if (AD->searchPillowCase(item2) == 1)
	{
		cout << "You already stole the Warden's financial documents" << endl;
		return false;
	}
	else
		return true;
}
Paradise::Paradise()
{
	label = "Zihuatanejo, Mexico";
	action1 = "";
	action2 = "";
	item1 = "";
	item2 = "";
	option1 = NULL;
	option2 = NULL;
	option3 = NULL;
	option4 = NULL;
}
void Paradise::doAction1(Andy*)
{

}
void Paradise::doAction2(Andy*)
{

}
bool Paradise::action1Req(Andy*)
{
	return true;
}
bool Paradise::action2Req(Andy*)
{
	return true;
}
Cemetery::Cemetery()
{
	label = "The Shawshank Graveyard";
	action1 = "Pick up large rock off the ground";
	action2 = "Get rid of wall chunks";
	item1 = "large rock";
	item2 = "";
	option1 = NULL;
	option2 = NULL;
	option3 = NULL;
	option4 = NULL;
}
void Cemetery::doAction1(Andy* AD)
{
	if (action1Req(AD))
	{
		cout << "You picked up the rock off the ground" << endl;
		AD->addItems(item1);
	}
}
void Cemetery::doAction2(Andy* AD)
{
	if (action2Req(AD))
	{
		cout << "You secretly got rid of pieces of the wall from your cell" << endl;
		AD->removeItems("wall chunks");
	}
}
bool Cemetery::action1Req(Andy* AD)
{
	if (AD->searchPillowCase(item1) == 1)
	{
		cout << "You'll only need one large rock to brake into the sewer pipe and escape to freedom" << endl;
		return false;
	}
	else
		return true;
}
bool Cemetery::action2Req(Andy* AD)
{
	if (AD->searchPillowCase("wall chunks") <= 0)
	{
		cout << "You don't have any wall chunks to get rid of" << endl;
		return false;
	}
	else
		return true;
}
Bank::Bank()
{
	label = "The Bank in Portland, Maine";
	action1 = "Withdraw $250,000 from Warden Norton's account";
	action2 = "Purchase Repossessed Car from Bank";
	item1 = "$250,000";
	item2 = "Car";
	option1 = NULL;
	option2 = NULL;
	option3 = NULL;
	option4 = NULL;
}
bool Bank::escRequire(Andy* AD)
{
	int searchSum = 0;
	searchSum += AD->searchPillowCase("Car");
	searchSum += AD->searchPillowCase("$250,000");
	if (searchSum == 2)
		return true;
	else
	{
		cout << "You'll some need some money and a car to get to Zihuatenejo" << endl;
		return false;
	}
}
void Bank::doAction1(Andy* AD)
{
	if (action1Req(AD))
	{
		cout << "You just got $250,000 of Warden Norton's Money" << endl;
		AD->addItems(item1);
	}
}
void Bank::doAction2(Andy* AD)
{
	if (action2Req(AD))
	{
		cout << "You have a fancy new car now" << endl;
		AD->addItems(item2);
	}
}
bool Bank::action1Req(Andy* AD)
{
	if (AD->searchPillowCase(item1) == 1)
	{
		cout << "$250,000 will be enough, you don't need more" << endl;
		return false;
	}
	else
		return true;
}
bool Bank::action2Req(Andy* AD)
{
	if (AD->searchPillowCase(item2) == 1)
	{
		cout << "You'll only need one car to get down to Zihautenejo" << endl;
		return false;
	}
	else
		return true;
}
LoadingDock::LoadingDock()
{
	label = "The Loading Dock";
	action1 = "Trade 1 pack of cigarettes for some rope from Heywood";
	action2 = "Dump some extra maggots";
	item1 = "rope";
	item2 = "";
	option1 = NULL;
	option2 = NULL;
	option3 = NULL;
	option4 = NULL;
}
void LoadingDock::doAction1(Andy* AD)
{
	if (action1Req(AD))
	{
		cout << "You traded 1 pack of cigarettes for a rope" << endl;
		AD->removeItems("1 pack of cigarettes");
		AD->addItems(item1);
	}
}
void LoadingDock::doAction2(Andy* AD)
{
	if (action2Req(AD))
	{
		cout << "You dumped some maggots" << endl;
		AD->removeItems("maggots");
	}
}
bool LoadingDock::action1Req(Andy* AD)
{
	if (AD->searchPillowCase("rope") == 1)
	{
		cout << "One rope is enough, you don't need another one" << endl;
		return false;
	}
	else
	{
		if (AD->searchPillowCase("1 pack of cigarettes") >= 1)
			return true;
		else
		{
			cout << "You don't have enough cigarette packs to trade with Red" << endl;
			return false;
		}
	}
}
bool LoadingDock::action2Req(Andy* AD)
{
	if (AD->searchPillowCase("maggots") <= 0)
	{
		cout << "You don't have any maggots to get rid of" << endl;
		return false;
	}
	else
		return true;
}
PrisonYard::PrisonYard()
{
	label = "The Prison Yard";
	action1 = "Trade Red 3 packs of cigarettes for poster of Raquel Welch";
	action2 = "Trade Red 5 packs of cigarettes for a rock hammer";
	item1 = "poster";
	item2 = "rock hammer";
	option1 = NULL;
	option2 = NULL;
	option3 = NULL;
	option4 = NULL;
}
void PrisonYard::doAction1(Andy* AD)
{
	if (action1Req(AD))
	{
		cout << "You traded 3 packs of cigarettes for a poster of Raquel Welch" << endl;
		for (int i = 0; i < 3; i++)
		{
			AD->removeItems("1 pack of cigarettes");
		}
		AD->addItems(item1);
	}
}
void PrisonYard::doAction2(Andy* AD)
{
	if (action2Req(AD))
	{
		cout << "You traded 5 packs of cigarettes for a rock hammer" << endl;
		for (int i = 0; i < 5; i++)
		{
			AD->removeItems("1 pack of cigarettes");
		}
		AD->addItems(item2);
	}
}
bool PrisonYard::action1Req(Andy* AD)
{
	if (AD->searchPillowCase("poster") == 1)
	{
		cout << "One poster is enough, you don't need another one" << endl;
		return false;
	}
	else
	{
		if (AD->searchPillowCase("1 pack of cigarettes") >= 3)
			return true;
		else
		{
			cout << "You don't have enough cigarette packs to trade with Red" << endl;
			return false;
		}
	}
}
bool PrisonYard::action2Req(Andy* AD)
{
	if (AD->searchPillowCase("rock hammer") == 1)
	{
		cout << "One rock hammer is enough, you don't need another one" << endl;
		return false;
	}
	else
	{
		if (AD->searchPillowCase("1 pack of cigarettes") >= 5)
			return true;
		else
		{
			cout << "You don't have enough cigarette packs to trade with Red" << endl;
			return false;
		}
	}
}
River::River()
{
	label = "The River at the end of the Sewer Pipe";
	action1 = "Get rid of the rock hammer";
	action2 = "";
	item1 = "rock hammer";
	item2 = "";
	option1 = NULL;
	option2 = NULL;
	option3 = NULL;
	option4 = NULL;
}
bool River::escRequire(Andy* AD)
{
	int searchSum = 0;
	searchSum += AD->searchPillowCase("rock hammer");
	if (searchSum != 1)
		return true;
	else
	{
		cout << "You need to pitch the rock hammer to show off a little bit" << endl;
		return false;
	}
}
void River::doAction1(Andy* AD)
{
	if (action1Req(AD))
	{
		cout << "You just threw the instrument of your freedom into the river!" << endl;
		AD->removeItems(item1);
	}
}
void River::doAction2(Andy*)
{
	cout << "ERROR: Invalid task command" << endl;
}
bool River::action1Req(Andy* AD)
{
	if (AD->searchPillowCase(item1) == 1)
	{
		return true;
	}
	else
	{
		cout << "You already threw the hammer in the river" << endl;
		return false;
	}
}
bool River::action2Req(Andy*)
{
	return true;
}