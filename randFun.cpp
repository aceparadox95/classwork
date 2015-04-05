/*****************************
 * Author: Ryan Cosby
 * Date Created: 10/29/2014
 * Last Modification Date: 10/29/2014
 * File name: randFun.cpp
 *
 * Overview:
 * This program prints a list of specific numbers within a range
 * specified by the user. It also checks for valid input by the
 * user to make sure the value is a valid number
 *
 * Input:
 * Asks user for a maximum/minimum value on the random number generator
 * 
 *
 * Output:
 * Screen prints a list a list of numbers randomly generated. to test the 
 * random number generator it also outputs the average value of the
 * **************************************************************/ 
 
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cctype>
 
using namespace std;

void rand_int(const int &min, const int &max, int &val)
{
	srand(time(NULL));
	val = (rand() % (max-min) + min);
}

int main()
{
	int maxNum, minNum, val = 0; // initialize max and min numbers and number to store value
	char userState = 'Y';// use this later to ask player to play again
	cout << "What is the minimum random number you would like to assign? ";
	cin >> minNum; //record user min
	cout << "What is the maximum random number you would like to assign? ";
	cin >> maxNum; //record user max

	// VALIDATION SECTION *************************************************
	
	while (maxNum <= minNum)// check to see if max is larger
	{
	cout << "Your maximum number must be larger than your minimum"<< endl;
	cout << "Please enter a valid number: ";
	cin >> maxNum;
	}
	while (maxNum > 32767)// check to see if max is out of range
	{
	cout << "Your maximum number cannot be greater than 32767"<< endl;
	cout << "Please enter a valid number: ";
	cin >> maxNum;
	}
	while (minNum < -32767)//check to see if min is out of range
	{
	cout << "Your minimum number cannot be less than -32767"<< endl;
	cout << "Please enter a valid number: ";
	cin >> minNum;
	}

	// VALIDATION SECTION END**********************************************

	while (userState == 'Y')
	{
	rand_int(minNum, maxNum, val); //call the rand func
	cout << "The number that was randomly selected in the range " << minNum << " to ";
	cout << maxNum << " is " << val << endl; 
	cout << "Would you like to generate another random number in this range? (Y OR N) ";
	cin >> userState; //standardize user input
	userState = toupper(userState); //standardize user input
	}
	return 0;
}
 