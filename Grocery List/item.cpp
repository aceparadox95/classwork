#include "item.h"
/*********************************************************************
** Function: item constructor
** Description: creates empty item
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: empty item
*********************************************************************/
Item::Item()
{
	name = "";
	unitType = "";
	quantity = 0.0;
	unitPrice = 0.0;
	totalitemPrice = 0.0;
}
/*********************************************************************
** Function: setName
** Description: mutates private item name variable
** Parameters: input name from user
** Pre-Conditions: item object must be created first
** Post-Conditions: item has name
*********************************************************************/
void Item::setName(string inpName)
{
	name = inpName;
}
/*********************************************************************
** Function: getName
** Description: accesses private item name variable
** Parameters: none
** Pre-Conditions: item object must be created first
** Post-Conditions: name is accessed and returned
*********************************************************************/
string Item::getName()
{
	return name;
}
/*********************************************************************
** Function: setUnitType
** Description: mutates private item unit type variable
** Parameters: input unit type from user
** Pre-Conditions: item object must be created first
** Post-Conditions: item has unit type
*********************************************************************/
void Item::setUnitType(string inpType)
{
	unitType = inpType;
}
/*********************************************************************
** Function: getUnitType
** Description: accesses private item unit type variable
** Parameters: none
** Pre-Conditions: item object must be created first
** Post-Conditions: unit type is accessed and returned
*********************************************************************/
string Item::getUnitType()
{
	return unitType;
}
/*********************************************************************
** Function: setQuantity
** Description: mutates private item quantity variable
** Parameters: input quantity from user
** Pre-Conditions: item object must be created first
** Post-Conditions: item has quantity
*********************************************************************/
void Item::setQuantity(double inpQuantity)
{
	quantity = inpQuantity;
}
/*********************************************************************
** Function: getQuantity
** Description: accesses private item quantity variable
** Parameters: none
** Pre-Conditions: item object must be created first
** Post-Conditions: unit type is accessed and returned
*********************************************************************/
double Item::getQuantity()
{
	return quantity;
}
/*********************************************************************
** Function: setUnitPrice
** Description: mutates private item unit price variable
** Parameters: input unit price from user
** Pre-Conditions: item object must be created first
** Post-Conditions: item has unit price
*********************************************************************/
void Item::setUnitPrice(double inpUnitPrice)
{
	unitPrice = inpUnitPrice;
}
/*********************************************************************
** Function: getUnitPrice
** Description: accesses private item unit price variable
** Parameters: none
** Pre-Conditions: item object must be created first
** Post-Conditions: unit price is accessed and returned
*********************************************************************/
double Item::getUnitPrice()
{
	return unitPrice;
}
/*********************************************************************
** Function: getTotalItemPrice
** Description: accesses private item total unit price variable
** Parameters: none
** Pre-Conditions: item object must be created first
** Post-Conditions: total unit price is accessed and returned
*********************************************************************/
double Item::getTotalItemPrice()
{
	return unitPrice * quantity;
}