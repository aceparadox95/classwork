/*********************************************************************
** Program Filename: .cpp
** Author: Ryan Cosby
** Date: March 3, 2015
** Description: This is a driver program to help identify the different
** functionality of a linked lists in a stack or queue format
** Input: User enters the amount of numbers to put in the stack/queue
** then enters that amount of numbers individually.
** Output: After each number is entered the number at the top of the stack
** and queue is revealed. Then the program pops or removes each member of 
** the stack or queue one number at a time and tells what the top of the 
** stack or queue is after each iteration
** Additional Note: Needed to refer to the textbook to clear up some 
** confusion in some spots
*********************************************************************/

#include <iostream>
#include "stack.h"
#include "queue.h"
int main()
{
	int stackSize, inpNum; // Variable to store user input
	stack *newStack;//Pointer to stack
	queue *newQueue;//Pointer to queue
	cout << "How many values will the stack and queue contain?" << endl; //Ask user for size of stack and queue
	cin >> stackSize; //store user input
	newStack = new stack(); //Dynamically allocate a new stack
	newQueue = new queue(); //Dynamically allocate a new queue
	cout << endl;
	for (int i = 0; i < stackSize; i++) // Iterate through stack and queue and add values
	{
		cout << "\nEnter a number to add to the stack/queue: ";
		cin >> inpNum; // Store input value from user
		newStack->push(inpNum); // Add value to stack
		newQueue->add(inpNum); // Add value to queue
		cout << "Top of stack: " << newStack->peek();//Display to user the front of the stack
		cout << "     Front of queue: " << newQueue->getFront() << endl; //Display to user front of the queue
	}
	/*After adding values to the stack/queue tell the user that values will now be removed*/
	cout << "\n\n\nWe are now popping from the stack and removing from the queue..." << endl;
	for (int i = 0; i < stackSize; i++)
	{ 
		cout << i + 1 << ". "; //Show the user the number of iterations
		cout << "Top of stack: " << newStack->peek(); //Display to user the top of the stack before removal
		cout << "     Front of queue: " << newQueue->getFront() << endl; //Display to user the front of the queue before removal
		newStack->pop();//Remove value from top of stack
		newQueue->removeFront();//remove value from the front of the queue
	}
	cout << "\n\nAttempting to peek at empty stack..." << endl;
	newStack->peek(); // Tries to peek at empty stack and prints error
	cout << "\n\nAttempting to pop from empty stack..." << endl;
	newStack->pop(); // Tries to remove a value from empty stack and prints error
	cout << "\n\nAttempting to look at front of empty queue..." << endl;
	newQueue->getFront(); //Tries to  look at front of empty queue and prints error
	cout << "\n\nAttempting to remove from empty queue..." << endl;
	newQueue->removeFront();//Tries to remove value from front of queue and prints error
	delete newStack;//Delete Allocated stack
	delete newQueue;//Delete Allocated Queue
	return 0;
}

