#include "Dice.h"
#include <string>
#ifndef CHARACTER_H
#define CHARACTER_H
using std::string;
class team;
class Character
{
protected:
	int strengthPoints;
	int armorPoints;
	team* teamName;
	string Name;
	string Type;
	int rankPoints;
	int startStrength;
	int attNumSides, defNumSides;
	int attNumDice, defNumDice;
public:
	Character();
	virtual int attack();
	virtual void defense(int oppAttackVal);
	void recover();
	void addRankPoints(int oppStrength);
	int getStrengthPoints();
	int getRankPoints();
	string getName();
	string getType();
	team* getTeam();
	void setTeam(team* t);
	int getStartStrength();
};
class Barbarian : public Character
{
public:
	Barbarian(string inpName);
};
class Reptile : public Character
{
public:
	Reptile(string inpName);
};
class BlueMen : public Character
{
public:
	BlueMen(string inpName);
};
class Goblin : public Character
{
protected:
	int achillesVal;
	bool achillesMode;
public:
	Goblin(string inpName);
	Goblin(bool achMode, string inpName);
	int attack();
	void defense(int oppAttackVal);
};
class Shadow : public Character
{
public:
	Shadow(string inpName);
	void defense(int oppAttackVal);
};
#endif
