#include <iostream>
#ifndef STACK_H
#define STACK_H
using std::cout;
using std::endl;
using std::cin;
class stack
{
private:
	class Node
	{
		friend class stack;
		int num;
		Node *next;
		Node(int inpVal, Node *nextNode = NULL);
	};
	Node *top;
public:
	stack();
	void push(int inpNum);
	int peek();
	void pop();
	bool isEmpty();
};
#endif