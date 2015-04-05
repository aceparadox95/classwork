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
	rankPoints = 0;
	teamName = NULL;
	Name = "";
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
int Character::getRankPoints()//simple get function
{
	return rankPoints;
}
/*********************************************************************
** Function: Add Battle Points
** Description: Adds battle points to winner of battle based on the 
** starting strength level of the opposing player. Stronger player win
** less points over weaker players and vice verse
** Parameters: oppenent starting strength value
** Pre-Conditions: Winning characters
** Post-Conditions: Winning Characters battle points are increased
*********************************************************************/
void Character::addRankPoints(int oppStrength)//simple get function
{
	if (startStrength >= oppStrength) // less points to player with greater strength
		rankPoints += ((startStrength - oppStrength) / 2) + 2;
	else //more points to player with less strength
		rankPoints += ((oppStrength - startStrength) * 2) + 2;
}
/*********************************************************************
** Function: Recover Strength
** Description: Mimics the character's defense function except it
** only gives half of the defense value back, this is executes when the
** character wins
** Parameters: None
** Pre-Conditions: Winning Character
** Post-Conditions: Winning Character's strength value increases
*********************************************************************/
void Character::recover()//simple get function
{
	Dice *defDice; //create dice pointer
	defDice = new Dice(defNumSides, defNumDice); //dynamic allocation
	strengthPoints += (defDice->sumRollDice() / 2);
	delete defDice;
}
team* Character::getTeam()//simple get function
{
	return teamName;
}
void Character::setTeam(team* inpTeam)//simple get function
{
	teamName = inpTeam;
}
string Character::getName()//simple get function
{
	return Name;
}
string Character::getType()//simple get function
{
	return Type;
}
int Character::getStartStrength()//simple get function
{
	return startStrength;
}
/*********************************************************************
** Function: derived barbarian character class constructor
** Description: sets members variable for barbarian
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Barbarian Object created
*********************************************************************/
Barbarian::Barbarian(string inpName)
{
	strengthPoints = 12;
	startStrength = 12;
	armorPoints = 0;
	attNumDice = 2;
	attNumSides = 6;
	defNumDice = 2;
	defNumSides = 6;
	Type = "Barbarian";
	Name = inpName;
}
/*********************************************************************
** Function: derived Reptile Person character class constructor
** Description: sets members variable for barbarian
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Reptile Person Object created
*********************************************************************/
Reptile::Reptile(string inpName)
{
	strengthPoints = 18;
	startStrength = 18;
	armorPoints = 7;
	attNumDice = 3;
	attNumSides = 6;
	defNumDice = 1;
	defNumSides = 6;
	Type = "Reptile Person";
	Name = inpName;
}
/*********************************************************************
** Function: derived Blue Men character class constructor
** Description: sets members variable for barbarian
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Blue Men Object created
*********************************************************************/
BlueMen::BlueMen(string inpName)
{
	strengthPoints = 12;
	startStrength = 12;
	armorPoints = 3;
	attNumDice = 2;
	attNumSides = 10;
	defNumDice = 3;
	defNumSides = 6;
	Type = "Blue Man";
	Name = inpName;
}
/*********************************************************************
** Function: derived Goblin character class constructor
** Description: sets members variable for barbarian
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Goblin Object created
*********************************************************************/
Goblin::Goblin(string inpName)
{
	strengthPoints = 8;
	startStrength = 8;
	armorPoints = 3;
	attNumDice = 2;
	attNumSides = 6;
	defNumDice = 1;
	defNumSides = 6;
	achillesVal = 1; //special achilles mode value
	achillesMode = true; //special achilles mode flag
	Type = "Goblin";
	Name = inpName;
}
/*********************************************************************
** Function: derived Goblin character class secondary constructor
** Description: sets members variable for barbarian
** Parameters: boolean achilles mode
** Pre-Conditions: two goblins must be battling to create this
** Post-Conditions: Goblin Object created
*********************************************************************/
Goblin::Goblin(bool achMode, string inpName)
{
	strengthPoints = 8;
	startStrength = 8;
	armorPoints = 3;
	attNumDice = 2;
	attNumSides = 6;
	defNumDice = 1;
	defNumSides = 6;
	achillesVal = 1;
	achillesMode = achMode;//turn achilles mode off
	Type = "Goblin";
	Name = inpName;
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
Shadow::Shadow(string inpName)
{
	strengthPoints = 12;
	startStrength = 12;
	armorPoints = 0;
	attNumDice = 2;
	attNumSides = 10;
	defNumDice = 1;
	defNumSides = 6;
	Type = "The Shadow";
	Name = inpName;
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
