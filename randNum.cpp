/*****************************
 * Author: Ryan Cosby
 * Date Created: 10/15/2014
 * Last Modification Date: 10/15/2014
 * File name: randNum.cpp
 *
 * Overview:
 * This program prints a list of specific numbers within a max range
 * specified by the user
 * Input:
 * Asks user for a maximum value on the random number generator
 * 
 *
 * Output:
 * Screen prints a list a list of numbers randomly generated
 * **************************************************************/ 
 
 #include <iostream>
 #include <cstdlib>
 #include <time.h>
 
 using namespace std;
 
 int main()
 {
	int maxNum;//variable for maximum number of range
	cout << " What is the maximum random number you would like to assign? "; //gather input
	cin >> maxNum; //store input
	maxNum++; //adding 1 to input
	srand(time(NULL));
	for (int i=0; i < 20; i++)// loop to print variable 20 times
	{
	int randomNumber = rand() % maxNum; //random number generator
	cout << randomNumber << endl; //print random number
	}
	return 0;
 }
 