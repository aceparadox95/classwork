/*****************************
 * Author: Ryan Cosby
 * Date Created: 10/22/2014
 * Last Modification Date: 10/22/2014
 * File name: mpg.cpp
 *
 * Overview:
 * This program generates a miles per gallon calculation based on user input
 * Input:
 * Asks user for number of liters used and miles traveled
 * 
 *
 * Output:
 * Tells user Miles Per Gallon and asks them if they want to calculate again
 * **************************************************************/ 

#include <iostream>
#include <cctype>
using namespace std;

float mpg(float liters, float miles) // Miles Per Gallon Function
{
return (miles / (liters * 0.264179)); // MPG Formula
}

int main()
{
float numLiters; //decimal value storage of liters
float numMiles; // 
char userState = 'Y';

while (userState == 'Y')
{
	cout << "How many liters did your car use? "; // user prompt for liters
	cin >> numLiters;
	cout << "\nHow many miles did you travel? "; // user prompt for miles
	cin >> numMiles;
	cout << "\nYour car traveled at "<< mpg(numLiters,numMiles) <<" miles per gallon\n\n";
	cout << "Would you like to do another MPG calculation (Y or N)? ";
	cin >> userState; // change user state based on input
	userState = toupper(userState); //standardize user input
}
return 0;
}
