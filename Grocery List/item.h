#include <iostream>
#include <string>
#include <fstream>
#ifndef RCOSBY_ITEM_H
#define RCOSBY_ITEM_H
using std::string;
class Item
{
private:
	string name;
	string unitType;
	double quantity;
	double unitPrice;
	double totalitemPrice;
public:
	Item();
	void setName(string inpName);
	string getName();
	void setUnitType(string inpType);
	string getUnitType();
	void setQuantity(double inpQuantity);
	double getQuantity();
	void setUnitPrice(double inpUnitPrice);
	double getUnitPrice();
	double getTotalItemPrice();
};
#endif