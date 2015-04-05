#include <string>
#include <iostream>
#include <vector>
#ifndef DUFRESNE_H
#define DUFRESNE_H
using std::string;
using std::vector;
using std::cout;
using std::endl;

class Andy
{
private:
	int pillowCaseLimit;
	bool pillowCaseStatus;
	bool pillowCaseisFull;
	vector<string> pillowCase;
public:
	Andy();
	void addItems(string item);
	void removeItems(string item);
	void listItems();
	bool getPCStatus();
	void setPCStatus();
	bool getPCisfull();
	void setPCisfull();
	int searchPillowCase(string searchTerm);
};
#endif