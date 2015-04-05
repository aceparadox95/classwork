#include "character.h"
using std::cout;
using std::endl;
/*********************************************************************
** Function: abstract class constructor
** Description: does nothing
** Parameters: none
** Pre-Conditions: does nothing
** Post-Conditions: does nothing just helps with compile
*********************************************************************/
Character::Character()
{
}
/*********************************************************************
** Function:  virtual base class attack function
** Description: rolls dice based on number of sides and returns number
** to the function
** Parameters: none
** Pre-Conditions: base or derived class must be initialized
** Post-Conditions: attack value interger generated
*********************************************************************/
int Character::attack()
{
	int rollVal = 0; //temp variable
	Dice *atkDice; //create dice pointer
	atkDice = new Dice(attNumSides, attNumDice); //dynamic allocation
	rollVal = atkDice->sumRollDice(); //run role dice function
	delete atkDice; //delete dynamic allocation of dice
	return rollVal; // return value of dice sum
}
/*********************************************************************
** Function: virtual base class defense function
** Description: rolls dice based on number of sides and changes strength
** member variable if the overall damage score is great than 0
** Parameters: attack value from opponent
** Pre-Conditions: base or derived class must be initialized
** Post-Conditions: strength Value altered
*********************************************************************/
void Character::defense(int oppAttackVal)
{
	int damage = 0; //temp variable
	Dice *defDice; //create dice pointer
	defDice = new Dice(defNumSides, defNumDice); //dynamic allocation
	damage = oppAttackVal - (defDice->sumRollDice()) - armorPoints;
	if (damage > 0) //check to see if damage value is greater than one
		strengthPoints -= damage; //if so subtract it from the strength
	delete defDice;
}
int Character::getStrengthPoints()//simple get function
{
	return strengthPoints;
}
string Character::getName()//simple get function
{
	return Name;
}
/*********************************************************************
** Function: derived barbarian character class constructor
** Description: sets members variable for barbarian
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Barbarian Object created
*********************************************************************/
Barbarian::Barbarian()
{
	strengthPoints = 12;
	armorPoints = 0;
	attNumDice = 2;
	attNumSides = 6;
	defNumDice = 2;
	defNumSides = 6;
	Name = "Barbarian";
}
/*********************************************************************
** Function: derived Reptile Person character class constructor
** Description: sets members variable for barbarian
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Reptile Person Object created
*********************************************************************/
Reptile::Reptile()
{
	strengthPoints = 18;
	armorPoints = 7;
	attNumDice = 3;
	attNumSides = 6;
	defNumDice = 1;
	defNumSides = 6;
	Name = "Reptile Person";
}
/*********************************************************************
** Function: derived Blue Men character class constructor
** Description: sets members variable for barbarian
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Blue Men Object created
*********************************************************************/
BlueMen::BlueMen()
{
	strengthPoints = 12;
	armorPoints = 3;
	attNumDice = 2;
	attNumSides = 10;
	defNumDice = 3;
	defNumSides = 6;
	Name = "Blue Man";
}
/*********************************************************************
** Function: derived Goblin character class constructor
** Description: sets members variable for barbarian
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Goblin Object created
*********************************************************************/
Goblin::Goblin()
{
	strengthPoints = 8;
	armorPoints = 3;
	attNumDice = 2;
	attNumSides = 6;
	defNumDice = 1;
	defNumSides = 6;
	achillesVal = 1; //special achilles mode value
	achillesMode = true; //special achilles mode flag
	Name = "Goblin";
}
/*********************************************************************
** Function: derived Goblin character class secondary constructor
** Description: sets members variable for barbarian
** Parameters: boolean achilles mode
** Pre-Conditions: two goblins must be battling to create this
** Post-Conditions: Goblin Object created
*********************************************************************/
Goblin::Goblin(bool achMode)
{
	strengthPoints = 8;
	armorPoints = 3;
	attNumDice = 2;
	attNumSides = 6;
	defNumDice = 1;
	defNumSides = 6;
	achillesVal = 1;
	achillesMode = achMode;//turn achilles mode off
	Name = "Goblin";
}
/*********************************************************************
** Function: goblin derived attack override function
** Description: rolls dice based on number of sides and returns number
** to the function, uses achilles mode when 12 is rolled
** Parameters: none
** Pre-Conditions: base or derived class must be initialized
** Post-Conditions: attack value interger generated
*********************************************************************/
int Goblin::attack()
{
	int rollVal = 0;
	Dice *atkDice;
	atkDice = new Dice(attNumSides, attNumDice);
	rollVal = atkDice->sumRollDice();
	delete atkDice;
	if (rollVal == 12) //initialize achilles mode
		achillesVal = 2;
	return rollVal;
}
/*********************************************************************
** Function: derived goblin class defense function
** Description: rolls dice based on number of sides and changes strength
** member variable if the overall damage score is great than 0. Takes into
** achilles mode if its been activated previously
** Parameters: attack value from opponent
** Pre-Conditions: base or derived class must be initialized
** Post-Conditions: strength Value altered
*********************************************************************/
void Goblin::defense(int oppAttackVal)
{
	int damage = 0;
	if (achillesMode)
		oppAttackVal = oppAttackVal / achillesVal;
	Dice *defDice;
	defDice = new Dice(defNumSides, defNumDice);
	damage = oppAttackVal - (defDice->sumRollDice()) - armorPoints;
	if (damage > 0)
		strengthPoints -= damage;
	delete defDice;
}
/*********************************************************************
** Function: derived Shadow character class constructor
** Description: sets members variable for barbarian
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Shadow Object created
*********************************************************************/
Shadow::Shadow()
{
	strengthPoints = 12;
	armorPoints = 0;
	attNumDice = 2;
	attNumSides = 10;
	defNumDice = 1;
	defNumSides = 6;
	Name = "The Shadow";
}
/*********************************************************************
** Function: derived shadown class defense function
** Description: rolls dice based on number of sides and changes strength
** member variable if the overall damage score is great than 0. Shadow will
** dodge opponent 50% of the time using random number. In this case the strength
** points arent altered
** Parameters: attack value from opponent
** Pre-Conditions: base or derived class must be initialized
** Post-Conditions: strength Value altered
*********************************************************************/
void Shadow::defense(int oppAttackVal)
{
	int damage = 0;
	int randNum;
	randNum = (rand() % 100) + 1;
	if (randNum % 2 == 0)
		cout << "The Shadow has deceived you, your attack missed" << endl;
	else
	{
		Dice *defDice;
		defDice = new Dice(defNumSides, defNumDice);
		damage = oppAttackVal - (defDice->sumRollDice()) - armorPoints;
		if (damage > 0)
			strengthPoints -= damage;
		delete defDice;
	}
}
