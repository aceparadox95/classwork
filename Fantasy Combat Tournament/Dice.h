#include <iostream>
#include <cstdlib>
#include <ctime>
#ifndef DICE_H
#define DICE_H
class Dice
{
public:
	Dice();
	Dice(int numSides, int numDice);
	int sumRollDice();
protected:
	int numSides;
	int numDice;
};
#endif
