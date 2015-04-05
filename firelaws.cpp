/*****************************
 * Author: Ryan Cosby
 * Date Created: 10/10/2014
 * Last Modification Date: 10/10/2014
 * File name: firelaws.cpp
 *
 * Overview:
 * This program asks the user to input a number for the number of people a
 * room can hold and the number of people who be inside it. The program then
 * determines whether all the people can fit in the room or not.
 *
 * Input:
 * Integer value from user stored in two integer variables for room capacity
 * and number of people in the room.
 *
 * Output:
 * Integer value is printed on the screen. If the users enter a number equal to
 * or less than 0 for room capacity then the users are told that they need to
 * input a higher number and the program closes out. I realize this isnt the best
 * option but i'm not sure how to restart the main function from the top.
 * Once that condition is satisfied an if statement is used to determine if
 * the number in room fits the legal requirement and gives feedback to user
 * to let them know whether they are complying with the law or not.
 * **************************************************************/ 

#include <iostream>

using namespace std;

int main()
{
   int roomCapacity, numofPeople;//declare variables
   cout<< "Enter a whole number for the room capacity: ";//prompt user
   cin>> roomCapacity;
   cout<< "The room can now hold " << roomCapacity << " person(s)"<< endl;//give user feedback
   cout<< "Enter a whole number for the number of people in the room: " ;// prompt user
   cin>> numofPeople;
   cout<< "You entered " << numofPeople << " for the number of people in the room"<< endl; //give user feedback
   if (roomCapacity <= 0)
   {
      cout<< "The room capacity must be greater than 0" << endl;//test to see if room capacity is
   }	  //greater than zero
   else if(roomCapacity > numofPeople)//testing the condition where the law is not being broken
   {  
      cout<< "Your room can legally fit the number of people requested and has room for ";  
      cout<<roomCapacity - numofPeople<< " more person(s)" <<endl;
   }
   else if(numofPeople > roomCapacity)//testing the condition where the law is being broken
   {
      cout<< "Your room cannot not legally hold the number of people requested and you need to remove ";  
      cout<< numofPeople - roomCapacity<< " person(s)" <<endl;
   }
   return 0;
}
