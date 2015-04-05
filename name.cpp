/*****************************
 * Author: Ryan Cosby
 * Date Created: 10/15/2014
 * Last Modification Date: 10/15/2014
 * File name: Names.cpp
 *
 * Overview:
 * This program is for practice interacting with a string variable.
 * it takes the users name in the FIRST MIDDLE LAST format and outputs
 * it in the LAST, M. FIRST format. It also accounts for when people
 * Don't have a middle name
 * Input:
 * The user is asked for their full name
 * 
 *
 * Output:
 * Screen prints the full name in the Last, M. First Format
 * **************************************************************/ 
 
#include <iostream>
#include <string>

using namespace std;

int main()
{
string fullName, firstName, middleName, lastName; // string variables
int firstSpace;// storing the index of the first space in the string
int secondSpace;// storing the index of the second space in the string
cout << "Please Enter Your Full Name (First Middle Last): ";//instruct user
getline(cin,fullName); //gathering user input
for(int i = 0; i < fullName.length(); i++)
	{
	firstName = firstName + fullName.at(i);
	if (fullName.at(i) != ' ')// searches for first space
	{
	firstSpace++; // increments till it finds the first space
	}
	else
	{
	break;//if space is found break out of the loop
	}
	}
for(int i = (firstSpace + 1); i < fullName.length(); i++)
	{
	middleName = middleName + fullName.at(i);
	if (fullName.at(i) != ' ')// searches for second space
	{
	secondSpace++;// increments till it finds the second space
	}
	else
	{
	break;//if space is found break out of the loop
	}
	}
// adds two index values together to set the starting point of next loop
secondSpace = firstSpace + secondSpace; 
for(int i = (secondSpace + 2); i < fullName.length(); i++)
	{
	lastName = lastName + fullName.at(i);
	}
if (lastName != "" && firstName !="" && middleName !="") // checks to see if each variable is not empty
{
cout << lastName << ", " << firstName << "" << middleName.at(0) << "." << endl;
}
else
{
cout << middleName << ", " << firstName << endl;
}
return 0;
}