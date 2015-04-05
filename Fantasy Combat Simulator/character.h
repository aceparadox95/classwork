#include "Dice.h"
#include <string>
#ifndef CHARACTER_H
#define CHARACTER_H
using std::string;
class Character
{
protected:
	int strengthPoints;
	int armorPoints;
	string Name;
	int attNumSides, defNumSides;
	int attNumDice, defNumDice;
public:
	Character();
	virtual int attack();
	virtual void defense(int oppAttackVal);
	int getStrengthPoints();
	string getName();
};
class Barbarian : public Character
{
public:
	Barbarian();
};
class Reptile : public Character
{
public:
	Reptile();
};
class BlueMen : public Character
{
public:
	BlueMen();
};
class Goblin : public Character
{
protected:
	int achillesVal;
	bool achillesMode;
public:
	Goblin();
	Goblin(bool achMode);
	int attack();
	void defense(int oppAttackVal);
};
class Shadow : public Character
{
public:
	Shadow();
	void defense(int oppAttackVal);
};

#endif // !CHARACTER_H
