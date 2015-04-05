#include "Dice.h"

#ifndef LOADEDDICE_H
#define LOADEDDICE_H
class LoadedDice: public Dice
{
public:
	LoadedDice(int inpSides);
	virtual int rollDice() const;
};
#endif