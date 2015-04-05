/*****************************************************************
 * Author: Ryan Cosby
 * Date Created: 10/24/2014
 * Last Modification Date: 10/24/2014
 * File name: finalist.cpp
 *
 * Overview:
 * This program prints a list of 4 specific numbers within a range
 * of 1 to 25 It also checks for valid input by the
 * user to make sure the value is a valid number. The numbers cannot repeat. 
 *
 * Input:
 * No input necessary. The program just needs to be executed
 * 
 *
 * Output:
 * Screen prints a list a list of numbers randomly generated from 1 to 25
 * **************************************************************/ 
 
#include <iostream>
#include <cstdlib>
#include <time.h>
 
using namespace std;

int rand25() // special function for generating random number 1-25
{
	int randomNumber;
	srand(time(NULL)); // seed the random number generator
	randomNumber = rand() % 24 + 1;
	//cout << randomNumber << endl; <---- use this to test random number
	return randomNumber;
}

int main()
{
	int fin1, fin2, fin3, fin4;
	fin1 = rand25(); // set each variable equal to random number
	fin2 = rand25();
	fin3 = rand25();
	fin4 = rand25();
	while (fin2 == fin1) // test if first two are equal
		fin2 = rand25();
	while ((fin3 == fin2) || (fin3 == fin1)) // test if first 3 are equal
		fin3 = rand25();
	while ((fin4 == fin3) || (fin4 == fin2) || (fin4 == fin1)) // test if all 4 are equal
		fin4 = rand25();
	cout << "The finalists are: " << fin1 << ", " << fin2 << ", ";
	cout << fin3 << ", " << fin4 << endl;// print solution
	return 0;
}