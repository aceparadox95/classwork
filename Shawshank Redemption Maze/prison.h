#include "dufresne.h"
#include "locations.h"
#include <ctime>
#ifndef PRISON_H
#define PRISON_H
class Prison
{
private:
	clock_t startTime;
	clock_t newTime;
	Location *Lib;
	Location *Laund;
	Location *MessH;
	Location *SewerP;
	Location *WardensO;
	Location *Prdise;
	Location *Cmtry;
	Location *PBank;
	Location *LDock;
	Location *PYard;
	Location *Rvr;
	Location *AndyC;
public:
	Andy *andyDufresne;
	Location *Curr;
	Prison();
	int checkTime();
};
#endif