/****************************************************************
 * Author: Ryan Cosby
 * Date Created: 10/29/2014
 * Last Modification Date: 10/29/2014
 * File name: sortFun.cpp
 *
 * Overview:
 * This program takes three numbers and sorts them into the correct
 * order from smallest to largest.
 *
 * Input:
 * User enters 3 different numbers
 * 
 * Output:
 * Numbers are printed to the screen in numerical order
 * 
 * **************************************************************/ 

#include <iostream>
using namespace std;

void sort(int &val1, int &val2, int &val3)
{
	int min, mid, max; // temporary variables
	//Setting the first value
	if ((val1 >= val2) && (val1 >= val3))
		max = val1;
	else if ((val1 >= val2) || (val1>= val3))
		mid = val1;
	else
		min = val1;
	// Setting the second value
	if ((val2 >= val1) && (val2 >= val3))
		max = val2;
	else if ((val2 >= val1) || (val2>= val3))
		mid = val2;
	else
		min = val2;
	// Setting the third value
	if ((val3 >= val2) && (val3 >= val1))
		max = val3;
	else if ((val3 >= val1) || (val3 >= val2))
		mid = val3;
	else
		min = val3;
	val1 = min; //resetting reference variables
	val2 = mid;
	val3 = max;
}

int main()
{
	int a, b, c;
	// Gathering user input
	cout << "Please input integer 1: ";
	cin >> a;
	cout << "\nPlease input integer 2: ";
	cin >> b;
	cout << "\nPlease input integer 3: ";
	cin >> c;
	sort(a, b, c);// Pass values to the function
	cout << "\nSorted: " << a << ", " << b << ", " << c << endl;
	return 0;
}