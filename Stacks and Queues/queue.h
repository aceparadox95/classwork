#include <iostream>
#ifndef QUEUE_H
#define QUEUE_H
using std::cout;
using std::endl;
using std::cin;
class queue
{
private:
	class Node
	{
		friend class queue;
		int num;
		Node *next;
		Node(int inpVal, Node *nextNode = NULL);
	};
	Node *front;
	Node *back;
public:
	queue();
	void add(int inpVal);
	int getFront();
	void removeFront();
	bool isEmpty();
};
#endif