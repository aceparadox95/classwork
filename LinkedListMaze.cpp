/*********************************************************************
** Program Filename: LinkedListMaze.cpp
** Author: Ryan Cosby
** Date: February 28, 2015
** Description: Used linked list to create a 6 room maze for the user to
** navigate through. There is only one spot to exit the maze. The user
** can choose whether each room is labeled or not.
** Input: User enters compass directions or label off/on mode
** Output: User receives feedback about whether each direction entered
** is a wall or not.
*********************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
using std::string;
using std::cout;
using std::cin;
using std::endl;
struct mazeNode
{
private:
	string label;
	mazeNode *north;
	mazeNode *south;
	mazeNode *west;
	mazeNode *east;
public:
	mazeNode();
	void setNode(string label, mazeNode*, mazeNode*, mazeNode*, mazeNode*);
	string getlabel();
	mazeNode* getNorth();
	mazeNode* getSouth();
	mazeNode* getWest();
	mazeNode* getEast();
	mazeNode* checkRoom(char dir);
};
void mazeNode::setNode(string lbl, mazeNode *N, mazeNode *S, mazeNode *W, mazeNode *E)
{
	label = lbl;
	north = N;
	south = S;
	west = W;
	east = E;
}
mazeNode::mazeNode()
{
	label = "";
	north = NULL;
	south = NULL;
	west = NULL;
	east = NULL;
}
string mazeNode::getlabel()
{
	return label;
}
mazeNode* mazeNode::checkRoom(char dir)
{
	if (dir == 'N')
		return north;
	if (dir == 'S')
		return south;
	if (dir == 'W')
		return west;
	if (dir == 'E')
		return east;
}
int main()
{
	mazeNode *startRoom,*midTop,*midBottom, //Room Nodes
		     *farTop,*farBottom,*endRoom,
			 *exit;
	mazeNode *curr; //Pointer to hold current position in maze
	char comm, comm2, direct;
	/*Initialize Room Nodes*/
	midTop = new mazeNode();
	midBottom = new mazeNode();
	farTop = new mazeNode();
	farBottom = new mazeNode();
	endRoom = new mazeNode();
	exit = new mazeNode();
	startRoom = new mazeNode();
	/*Set Room Node Wall Values*/
	startRoom->setNode("Start Room", NULL, NULL, NULL, midTop);
	midTop->setNode("Middle Top Room", NULL, midBottom, startRoom, farTop);
	midBottom->setNode("Middle Bottom Room", midTop, NULL, endRoom, NULL);
	farTop->setNode("Far Top Room", NULL, farBottom, midTop, NULL);
	farBottom->setNode("Far Bottom Room", farTop, NULL, NULL, NULL);
	endRoom->setNode("End Room", NULL, exit, NULL, midBottom);
	exit->setNode("End", NULL, NULL, NULL, NULL);
	curr = startRoom; // Set Current Position to Start Room
	cout << "Do you want the room labels to be shown? (Y or N)" << endl; //Label Mode
	cin >> comm; // User Input
	comm = toupper(comm); //Standardize User Input
	while (curr->getlabel() != "End") // Check to see if the current room is outside the maze
	{
		if (comm == 'Y') // Show room label or not
			cout << "\n\nYou are in the " << curr->getlabel() << endl;
		else
			cout << "\n\nYou are in a room" << endl;
		cout << "Which direction do you want to go?" << endl; // Ask player which direction they want to go
		cout << "N = North | South = S | West = W | East =  E" << endl;
		cin >> direct; //User Input
		direct = toupper(direct); //Standardize User Input
		if (curr->checkRoom(direct) == NULL) // Check to see if the direction selected is a wall
			cout << "\nYou just ran into a wall. Try a different direction" << endl;
		else // if its not a wall then set the current position to the next room over
			curr = curr->checkRoom(direct);
		if (curr->getlabel() == "End") // Let's player go back into the maze at the beginning
		{
			cout << "\n\nCongratulations you've made it out of the maze!" << endl;
			cout << "Do you want to go back in? (Y or N)" << endl;
			cin >> comm2;
			comm2 = toupper(comm2);
			if (comm2 == 'Y')
				curr = startRoom;
		}
	}
	delete startRoom;
	delete midTop;
	delete midBottom;
	delete farTop;
	delete farBottom;
	delete endRoom;
	delete exit;
	return 0;
}

