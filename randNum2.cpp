/*****************************
 * Author: Ryan Cosby
 * Date Created: 10/15/2014
 * Last Modification Date: 10/15/2014
 * File name: randNum.cpp
 *
 * Overview:
 * This program prints a list of specific numbers within a range
 * specified by the user. It also checks for valid input by the
 * user to make sure the value is a valid number
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
 
using namespace std;
 
int main()
{
	int maxNum, minNum, aveNum;
	cout << "What is the minimum random number you would like to assign? ";
	cin >> minNum;
	cout << "What is the maximum random number you would like to assign? ";
	cin >> maxNum;
	srand(time(NULL));
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
	/*while (isalpha(maxNum))//check to see if string was entered
	{
	cout << "Your number must be an integer"<<endl;
	cout << "Please enter a valid number: ";
	cin >> maxNum;
	}
	while (isalpha(minNum))
	{
	cout << "Your number must be an integer"<<endl;
	cout << "Please enter a valid number: ";
	cin >> minNum;
	}
	*/
	// VALIDATION SECTION END**********************************************

	int randomNumber = rand() % (maxNum-minNum) + minNum;
	cout << "The number that was randomly selected in the range " << minNum << " to ";
	cout << maxNum << " is " << randomNumber;
	for (int i=0; i < 49; i++)
		{
		int randomNumber = rand() % (maxNum-minNum) + minNum;
		aveNum = aveNum + randomNumber;
		}
	cout << "\nThe average number when this random number is processed in ";
	cout<< "this range 50 times is " << (aveNum / 50) << endl;
	return 0;
}
 