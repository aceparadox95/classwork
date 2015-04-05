#include "Dice.h"
/*********************************************************************
** Function: dice constructor
** Description: creates default die with 6 sides
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: New die created with 6 sides
*********************************************************************/
Dice::Dice()
{
	numSides = 6;
	srand(time(NULL)); // Seeds random number generator
}
/*********************************************************************
** Function: side specified dice constructor
** Description: creates specific number of sides on die
** Parameters: Integer number of sides
** Pre-Conditions: none
** Post-Conditions: New die created with number of sides specified
*********************************************************************/
Dice::Dice(int numSides)
{
	this->numSides = numSides;
	srand(time(NULL)); // Seeds random number generator
}
/*********************************************************************
** Function: rollDice function
** Description: Generates random number greater than 0 and less than
** or equal to the number of sides.
** Parameters: No parameters needed
** Pre-Conditions: Die object must be created
** Post-Conditions: value returned
*********************************************************************/
int Dice::rollDice() const
{
	return (rand() % numSides) + 1;
}
