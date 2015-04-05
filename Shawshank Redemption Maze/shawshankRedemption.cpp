/*********************************************************************
** Program Filename: shawshankRedemption.cpp
** Author: Ryan Cosby
** Date: March 14, 2015
** Description: This is a game based on the best picture (1994) film
** Shawshank Redemption. Similar to the movie Andy Dufresne has to use
** a rock hammer to tunnel through the wall in his cell. Before making 
** his esacpe he has to get a poster, a rock, a plastic bag, the warden's
** financial information, his clothes, and some rope.
** Input: User can select from 6 commands within the games main menu. One
** of the commands allows them to quit. The others allows them to continue on
** to other locations in the prison or to exit the prison.
** Output: User will see the result of each command reported back to them
*********************************************************************/

#include "locations.h"
#include "dufresne.h"
#include "prison.h"
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;
int checkTime(high_resolution_clock::time_point t1)
{
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	duration<int> time_span = duration_cast<duration<int>>(t2 - t1);
	return time_span.count(); // returns difference between start and current time
}
int main()
{
	char comm, userStatus = 'Y';
	while (userStatus == 'Y')
	{
		cout << string(50, '\n') << endl; // Print initial instructions
		cout << "Your name is Andy Dufresne, you have just been wrongfully sentenced to" << endl
			<< "life in Shawshank Prison for a crime you didn't commit. To escape you'll" << endl
			<< "need to tunnel through the wall with a rock hammer to the sewer pipe." << endl
			<< "You'll need to go to many places throughout the prison grounds to find the" << endl
			<< "items you need to make a clean escape. The first thing you'll need" << endl
			<< "is a pillow case to hold your items. Check the laundry..." << endl
			<< "This game is based on the events of the movie Shawshank Redemption" << endl
			<< "You have 15 minutes to win the game. Good luck!" << endl << endl;
		cout << "Do you want to play the game? (Y or N)" << endl; // allow user to not play game if they dont want to
		cin >> comm;
		comm = toupper(comm); //standardize input if needed
		if (comm == 'Y')
		{
			Prison *shawshankPrison;
			shawshankPrison = new Prison(); // create a new prison pointer
			high_resolution_clock::time_point startTime = high_resolution_clock::now();
			while (shawshankPrison->Curr->getLabel() != "Zihuatanejo, Mexico") // Check to see if you won!
			{
				if (checkTime(startTime) <= 900) // check to see if time limite has been exceed
				{
					cout << "\nLOCATION: " << shawshankPrison->Curr->getLabel() << " (" // show player what location they are at
						<< (checkTime(startTime) / 60) << " minutes and " // show player how much time has passed since beginning of game
						<< (checkTime(startTime) % 60) << " seconds elapsed)" << endl;
					cout << "**************************************************************************" << endl; // print menu
					shawshankPrison->Curr->listAvailActions(); //show available actions
					cout << endl;
					shawshankPrison->Curr->listAvailMovements(); //show location changes
					cout << "\nOther Options: " << endl; // show other options to quit or list pillowcase elements
					if (shawshankPrison->andyDufresne->getPCStatus()) // check to see if pillow case has been activated
						cout << "L. View the list of your items" << endl;
					cout << "Q. Quit the game" << endl;
					cout << "**************************************************************************" << endl;
					cout << "Enter a Command: " << endl; // Ask player for a command
					cin >> comm; //User Input
					comm = toupper(comm); //Standardize User Input
					while (comm != 'A' && comm != 'B' && comm != 'C' && comm != 'D' && comm != 'L' && comm != 'Q'
						&& comm != '1' && comm != '2') // validating user entry
					{
						cout << "You have entered an invalid command, please enter a valid command " << endl;
						cin >> comm;
						comm = toupper(comm);
					}
					if (comm == '1' || comm == '2' || comm == 'L') // checking for action commands
					{
						cout << string(50, '\n') << endl;
						if (comm == '1') // perform action 1
							shawshankPrison->Curr->doAction1(shawshankPrison->andyDufresne);
						if (comm == 'L')// perform list items
							shawshankPrison->andyDufresne->listItems();
						if (comm == '2')//perform action 2
							shawshankPrison->Curr->doAction2(shawshankPrison->andyDufresne);
					}
					else if (comm == 'A' || comm == 'B' || comm == 'C' || comm == 'D') // check for location commands
					{
						cout << string(50, '\n') << endl;
						if (shawshankPrison->Curr->entry(comm) == NULL) // Check to see if the location selected is not valid
						{
							cout << "ERROR: Invalid command, you cannot go to a NULL location" << endl;
						}
						else if (shawshankPrison->Curr->getLabel() == "Your Cell" && comm == 'C')//check for special scenario of leaving cell
						{
							if (shawshankPrison->Curr->escRequire(shawshankPrison->andyDufresne))
							{
								cout << "You have changed locations" << endl;
								shawshankPrison->Curr = shawshankPrison->Curr->entry(comm);
							}
						}
						else if (shawshankPrison->Curr->getLabel() == "The Sewer Pipe" && comm == 'A')// check for special scenario of leaving sewer pipe
						{
							if (shawshankPrison->Curr->escRequire(shawshankPrison->andyDufresne))
							{
								cout << "You have changed locations" << endl;
								shawshankPrison->Curr = shawshankPrison->Curr->entry(comm);
							}
						}
						else if (shawshankPrison->Curr->getLabel() == "The River at the end of the Sewer Pipe" && comm == 'A')// check for scenario of leaving river
						{
							if (shawshankPrison->Curr->escRequire(shawshankPrison->andyDufresne))
							{
								cout << "You have changed locations" << endl;
								shawshankPrison->Curr = shawshankPrison->Curr->entry(comm);
							}
						}
						else if (shawshankPrison->Curr->getLabel() == "The Bank in Portland, Maine" && comm == 'A')// check for scenario of leaving bank
						{
							if (shawshankPrison->Curr->escRequire(shawshankPrison->andyDufresne))
							{
								cout << "You have changed locations" << endl;
								shawshankPrison->Curr = shawshankPrison->Curr->entry(comm);
							}
						}
						else //otherwise perform the location change requested
						{
							cout << "You have changed locations" << endl;
							shawshankPrison->Curr = shawshankPrison->Curr->entry(comm);
						}
					}
					else // allow user to exit game
					{
						userStatus = 'N';
						break;
					}
				}
				else // if 15 minutes have passed then the game is over
				{
					cout << "You ran out of time. Game Over." << endl;
					userStatus = 'T';
					break;
				}
			}
			delete shawshankPrison;
			if (comm != 'Q' || userStatus == 'T') // prints exit message based on whether player won or if time is up
			{
				if (userStatus != 'T')
				{
					cout << "Congratulations! You escaped Shawshank and made it to Mexico" << endl;
				}
				cout << "\nDo you want to play again? (Y or N)" << endl;
				cin >> userStatus;
				userStatus = toupper(userStatus);
			}
		}
		else// user can leave game before it starts if they want
			userStatus = 'N';
	}
	cout << "Thanks for playing... goodbye!" << endl;
	return 0;
}
