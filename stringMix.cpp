/*****************************
 * Author: Ryan Cosby
 * Date Created: 11/5/2014
 * Last Modification Date: 11/5/2014
 * File name: stringMix.cpp
 *
 * Overview:
 * Takes an input string and shuffles the letter
 * 
 * Input:
 * Asks user for input string
 * 
 *
 * Output:
 * Outputs string in random order of characters
 * **************************************************************/ 

#include <iostream>
#include <cstring>
#include <time.h>
#include <stdlib.h>
using namespace std;

char * shuffle(char userString[],char emptyString[])//function returns array pointer
{
	srand (time(NULL));
	for (int i = 0; i < strlen(userString) + 1; i++) //have to make it loop one character long to hold the null terminator
	    emptyString[i] = userString[i];
	for (int i = 0; i < strlen(userString); i++)
	{
	    int randNum = rand() % (strlen(userString)); //generate random index number
	    char temp;//temp value to store index being changed
	    temp = emptyString[i];//store original index of character
	    emptyString[i] = emptyString[randNum];//assign index value to new index
	    emptyString[randNum] = temp;//save the index value that was switched into the original index
	}
	return emptyString;
}
//Some of my ideas for shuffling the string above came from: 
//http://www.geeksforgeeks.org/shuffle-a-given-array/

int main()
{
	char userState = 'Y';//for the user to generate as many shuffled words as they want
	char inpString[50];//initialize string
	cout<< "Enter a string: " <<endl;//prompt user for string
	cin.getline(inpString, 50);//gather input
	char empString[50];//populate empty string with length of first string
	while (userState == 'Y')
	{
		cout << shuffle(inpString,empString);//call the shuffle function
		cout << "\nDo you want to shuffle the word again?(Y or N) ";
		cin >> userState;
		userState = toupper(userState);//standardize user input
	}
	return 0;
}