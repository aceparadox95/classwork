#include "stack.h"
stack::stack()
{
	top = NULL;
}
stack::Node::Node(int inpNum, Node *nextNode)
{
	num = inpNum;
	next = nextNode;
}
/*********************************************************************
** Function: Push
** Description: Adds value to top of stack
** Parameters: Input integer from user
** Pre-Conditions: the stack
** Post-Conditions: the stack with one extra number on top
*********************************************************************/
void stack::push(int inpNum)
{
	/*Dynamically constructs a new node and sets it equal to the top pointer
	with input value given by user. The node that is added points to the top
	node after creation so that each new node is added to the top of the stack*/
	top = new Node(inpNum, top);
}
/*********************************************************************
** Function: Peek
** Description: Views the value on the top of the stack
** Parameters: None
** Pre-Conditions: the stack
** Post-Conditions: printed number from top of stack
*********************************************************************/
int stack::peek()
{
	if (!top)//Check to see if the top node exists
	{
		cout << "Cannot peek! The stack is empty" << endl;
		return 0;
	}
	else // if it does then return the num value from the top node
		return top->num;
}
/*********************************************************************
** Function: Pop
** Description: Removes value from the top of the stack
** Parameters: None
** Pre-Conditions: the stack
** Post-Conditions: the stack with one link removed
*********************************************************************/
void stack::pop()
{
	Node *temp; //Create a temporary pointer to a node
	if (isEmpty()) //Checks to see if the stack is empty
	{
		cout << "Cannot pop! The stack is empty" << endl;
		return;
	}
	else // if not empty
	{
		temp = top; //store the pointer to the current top node in temporary pointer
		top = top->next; //set the top nodes pointer to point the node underneath it the stack
		delete temp; //delete the temporary pointer and removes the original top node
	}
}
/*********************************************************************
** Function: Is Empty
** Description: checks to see if stack is empty
** Parameters: None
** Pre-Conditions: the stack
** Post-Conditions: condition of stack reported
*********************************************************************/
bool stack::isEmpty()
{
	if (!top)//check to see if the top node is there
		return true;
	else
		return false;
}
