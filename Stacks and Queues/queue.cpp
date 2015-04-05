#include "queue.h"

queue::queue()
{
	front = NULL;
	back = NULL;
}
queue::Node::Node(int inpVal, Node *nextNode)
{
	num = inpVal;
	next = nextNode;
}
/*********************************************************************
** Function: Add
** Description: Adds value to the queue
** Parameters: Input integer from user
** Pre-Conditions: the queue
** Post-Conditions: the queue with one extra number added
*********************************************************************/
void queue::add(int inpVal)
{
	if (isEmpty()) // Checks to see if front node is empty
	{
		/*Dynamically allocates a new node with the input value from user, the "next" pointer
		value in the new node is null by default. The front node of queue is set
		to point at the newly created node. The back node of the queue is also set
		to point at the front node. In this case the front and the back node are
		the same node, which is true with one value queue.*/
		front = new Node(inpVal);
		back = front; // This sets up the circular structure of the queue
	}
	else //If the front node is not empty
	{
		/*Dynamically allocates a new node based on user input value, then sets the "next" 
		pointer of the current back node to point to the new allocated node. After this the
		current back node is set to the value of its own newly created back pointer. This
		action will cause the back pointer node to stop pointing to the front after a second
		node is added. In essence this forces the value to back of the original back pointer*/
		back->next = new Node(inpVal);
		back = back->next;
	}
}
/*********************************************************************
** Function: Get Front
** Description: Views the value at the front of the queue
** Parameters: None
** Pre-Conditions: queue
** Post-Conditions: printed number from front of queue
*********************************************************************/
int queue::getFront()
{
	if (front) //Checks to see if the front node is empty is it isnt then it returns the number
		return front->num;
	else// if its empty then a message is printed a dummy value is returned
	{
		cout << "Cannot view first number! The queue is empty" << endl;
		return 0;
	}
}
/*********************************************************************
** Function: Remove Front
** Description: Removes value from the front of the queue
** Parameters: None
** Pre-Conditions: the queue
** Post-Conditions: the queue with one of the values removed
*********************************************************************/
void queue::removeFront()
{
	Node *temp;//Create temporary node
	if (isEmpty())//check to see if front node is empty
	{
		cout << "Cannot remove! The queue is empty" << endl;
	}
	else//if front node is not empty then
	{
		temp = front; //store the front node in temporary node
		front = front->next; //set the front node to point to the next node in the queue
		delete temp; //remove the original front node and send it to oblivion
	}
}
/*********************************************************************
** Function: Is Empty
** Description: checks to see if queue is empty
** Parameters: None
** Pre-Conditions: the stack
** Post-Conditions: condition if queue reported
*********************************************************************/
bool queue::isEmpty()
{
	if (front == NULL)
		return true;
	else
		return false;
}