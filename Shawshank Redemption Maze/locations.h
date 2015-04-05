#include <vector>
#include <string>
#include "dufresne.h"
#ifndef LOCATIONS_H
#define LOCATIONS_H
using std::string;
using std::vector;
class Location
{
protected:
	string label;
	string action1, action2;
	string item1, item2;
	Location *option1, *option2, *option3, *option4;
public:
	Location();
	string getLabel();
	void setMoves(Location *o1,Location *o2, Location *o3, Location *o4);
	void listAvailActions();
	void listAvailMovements();
	Location* entry(char comm);
	virtual bool escRequire(Andy*);
	virtual void doAction1(Andy*);
	virtual void doAction2(Andy*);
	virtual bool action1Req(Andy*);
	virtual bool action2Req(Andy*);
};

class AndyCell : public Location
{
protected:
	int wallStrength;
public:
	AndyCell();
	bool posterWall;
	int getWallStrength();
	void setWallStrength();
	bool escRequire(Andy*);
	void doAction1(Andy*);
	void doAction2(Andy*);
	bool action1Req(Andy*);
	bool action2Req(Andy*);
};

class MessHall : public Location
{
public:
	MessHall();
	void doAction1(Andy*);
	void doAction2(Andy*);
	bool action1Req(Andy*);
	bool action2Req(Andy*);
};
class Laundry : public Location
{
public:
	Laundry();
	void doAction1(Andy*);
	void doAction2(Andy*);
	bool action1Req(Andy*);
	bool action2Req(Andy*);
};
class Cemetery : public Location
{
public:
	Cemetery();
	void doAction1(Andy*);
	void doAction2(Andy*);
	bool action1Req(Andy*);
	bool action2Req(Andy*);
};
class Library : public Location
{
public:
	Library();
	void doAction1(Andy*);
	void doAction2(Andy*);
	bool action1Req(Andy*);
	bool action2Req(Andy*);
};
class WardenOff : public Location
{
public:
	WardenOff();
	void doAction1(Andy*);
	void doAction2(Andy*);
	bool action1Req(Andy*);
	bool action2Req(Andy*);
};
class SewerPipe : public Location
{
public:
	SewerPipe();
	bool escRequire(Andy*);
	void doAction1(Andy*);
	void doAction2(Andy*);
	bool action1Req(Andy*);
	bool action2Req(Andy*);
};
class River : public Location
{
public:
	River();
	bool escRequire(Andy*);
	void doAction1(Andy*);
	void doAction2(Andy*);
	bool action1Req(Andy*);
	bool action2Req(Andy*);
};
class Bank : public Location
{
public:
	Bank();
	bool escRequire(Andy*);
	void doAction1(Andy*);
	void doAction2(Andy*);
	bool action1Req(Andy*);
	bool action2Req(Andy*);
};
class Paradise : public Location
{
public:
	Paradise();
	void doAction1(Andy*);
	void doAction2(Andy*);
	bool action1Req(Andy*);
	bool action2Req(Andy*);
};
class LoadingDock : public Location
{
public:
	LoadingDock();
	void doAction1(Andy*);
	void doAction2(Andy*);
	bool action1Req(Andy*);
	bool action2Req(Andy*);
};
class PrisonYard : public Location
{
public:
	PrisonYard();
	void doAction1(Andy*);
	void doAction2(Andy*);
	bool action1Req(Andy*);
	bool action2Req(Andy*);
};
#endif