#include "LoadedDice.h"
#include <cstdlib>
#include <time.h>
/*********************************************************************
** Function: loaded dice constructor
** Description: creates specific number of sides on die
** Parameters: Integer number of sides
** Pre-Conditions: none
** Post-Conditions: New die created with number of sides specified
*********************************************************************/
LoadedDice::LoadedDice(int inpSides)
{
	numSides = inpSides;
}
/*********************************************************************
** Function: rollDice function
** Description: Forces value to be the highest value 50% of the time
** otherwise it generates random number greater than 0 and less than
** or equal to the number of sides.
** Parameters: No parameters needed
** Pre-Conditions: Die object must be created
** Post-Conditions: value returned
*********************************************************************/
int LoadedDice::rollDice() const
{
	int randNum;
	randNum = (rand() % 2) + 1; //generate random number between 1 and 2
	if (randNum == 1) // if 1 return value like normal dice
		return (rand() % numSides) + 1;
	else //if 2 return value like loaded dice
		return numSides;
}
