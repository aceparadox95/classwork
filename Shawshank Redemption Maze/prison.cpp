#include "prison.h"
/*********************************************************************
** Function: Prison constructor
** Description: Constructs shawshank prison with 11 locations sets the
** current location to andy's cell to start the game
** Parameters: none
** Pre-Conditions: no prison
** Post-Conditions: prison constructed
*********************************************************************/
Prison::Prison()
{
	startTime = clock(); // timer is started
	andyDufresne = new Andy();
	AndyC = new AndyCell();
	Lib = new Library();
	Laund = new Laundry();
	MessH = new MessHall();
	SewerP = new SewerPipe();
	WardensO = new WardenOff();
	Prdise = new Paradise();
	Cmtry = new Cemetery();
	PBank = new Bank();
	LDock = new LoadingDock();
	PYard = new PrisonYard();
	Rvr = new River();
	Curr = AndyC;

	AndyC->setMoves(PYard, Laund, SewerP, NULL);
	Lib->setMoves(PYard, WardensO, MessH, LDock);
	Laund->setMoves(PYard, LDock, Cmtry, MessH);
	MessH->setMoves(PYard, Cmtry, Laund, LDock);
	SewerP->setMoves(Rvr, NULL, NULL, NULL);
	WardensO->setMoves(Lib, NULL, NULL , NULL);
	Prdise->setMoves(NULL, NULL, NULL, NULL);
	Cmtry->setMoves(PYard, LDock, MessH, Laund);
	PBank->setMoves(Prdise, NULL, NULL, NULL);
	LDock->setMoves(PYard, Cmtry, Lib, MessH);
	PYard->setMoves(AndyC, Lib, MessH, Cmtry);
	Rvr->setMoves(PBank, NULL, NULL, NULL);
}
/*********************************************************************
** Function: check time
** Description: checks to see how much time has passed since start of 
** game
** Parameters: Prison must be constructed
** Pre-Conditions: none
** Post-Conditions: returns number of second since beginning of game
*********************************************************************/
int Prison::checkTime()
{
	newTime = clock(); //creates a current time stamp
	return ((int)(newTime - startTime) / CLOCKS_PER_SEC); // returns difference between start and current time
}