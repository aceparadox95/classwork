#include <vector>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "item.h"
#ifndef RCOSBY_FULLLIST_H
#define RCOSBY_FULLLIST_H
using std::vector;
class fullList
{
private:
	vector<Item> gList;
	double totalListPrice;
public:
	fullList();
	void addItem();
	void removeItem();
	void listItems();
	void setTotalListPrice();
	double getTotalListPrice();
	void saveListtoFile();
	void readFile();
};
#endif