/*****************************
 * Author: Ryan Cosby
 * Date Created: 11/7/2014
 * Last Modification Date: 11/7/2014
 * File name: wordShift.cpp
 *
 * Overview:
 * This program allows a user to interact with a string that they enter.
 * Users can move the characters of the string to the right or left. They
 * can also reverse the order of the characters in the string as well.
 * Input:
 * User enters string they wants to manipulate.
 * User enters "L<num of integers>" to shift left.
 * User enters "R<num of integers>" to shift right.
 * User enters "rev" to reverse the string.
 * User enters "quit" to exit the program.
 * Output:
 * Prints the manipulated string after each command.
 * **************************************************************/ 

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>
using namespace std;


char *leftShift(char userString[], int shift) //Function for shifting to the left
{
    for (int s = 0; s < shift; s++)// Number of shifts specified by user
    {
        char firstChar = userString[0]; //store the variable that will get pushed off the array
        for (int i = 0; i < strlen(userString); i++)// Shift left 1 spot
        {
            if (i == (strlen(userString) - 1))
            userString[i] = firstChar;//replace the character on the last character
            else
            userString[i] = userString[i + 1]; //assign the variable from the right side to left side
        }
    }
    return userString;
}

char *rightShift(char userString[], int shift)//Function for shifting to the right
{
    for (int s = 0; s < shift; s++)// Number of shifts specified by user
    {
        char lastChar = userString[strlen(userString)-1];//store variable that will get pushed off the array
        for (int i = strlen(userString) - 1; i >= 0; i--)//shift right 1 spot
        {
            if (i == 0)
            userString[i] = lastChar; //replace the character on the first character
            else
            userString[i] = userString[i - 1]; //assign the variable from the left side to right side
        }
    }
    return userString;
}

char *revShift(char userString[])//function to reverse the string
{
    for (int i = 0; i < (strlen(userString)/2); i++)//iterate through half of the string
    {
        char swapChar; //temp value to store swap character
        swapChar = userString[i]; 
        userString[i] = userString[(strlen(userString)- 1 - i)]; //swap characters inward
        userString[(strlen(userString)- 1 - i)] = swapChar;//swap characters inward till middle
    }
    return userString;
}

char* command(char userString[], char comm[])//User Command Interpreter
{
    if (isalpha(comm[0]))
    {
		int invChars = 0; //int to store number of invalid characters
		char shiftWord[50]; //temp variable to store the shift word
		int shift = 0; //int to store the shift value
		char remWord[50];//string to hold the remainder of rev and quit commands after first character
		if ((strlen(comm)> 1) && ((comm[0] == 'L')||(comm[0] == 'R')||(comm[0] == 'r')||(comm[0] == 'q')))//Test for valid first character
		{
			
			if (comm[0] == 'r')//if 'r' check and see if the remainder of the word is "ev"
			{
				for (int i = 1; i < strlen(comm) + 1;i++)//iterate through all characters after the first letter
					remWord[i-1]= comm[i];
				if ((strlen(remWord)== 2) && (remWord[0] == 'e') && (remWord[1]=='v'))
					return revShift(userString);//call reverse function if it makes it this far
				else
				{
					cout << "Invalid Reverse Command. Enter rev to reverse" << endl;
					return userString;
				}
			}
			if (comm[0] == 'q')//if 'q' check and see if the remainder of the word is "uit"
			{
				for (int i = 1; i < strlen(comm) + 1;i++)//iterate through all characters after the first letter
					remWord[i-1]= comm[i];//store value in remainder word
				if ((strlen(remWord)== 3) && (remWord[0] == 'u') && (remWord[1]=='i')&& (remWord[2]=='t'))
					return comm; //returns word "quit" which ends the program
				else
				{
					cout << "Invalid Quit Command. Enter quit to quit." << endl;
					return userString;
				}
			}
			for (int i = 1; i < strlen(comm);i++)//iterate through characters after first letter
			{
				if (!(isdigit(comm[i])))//check for letters after first character
					invChars++;//increase invalid letter count
				else
					shiftWord[i-1]= comm[i];//store shift value as string
			}
			shift = atoi(shiftWord);//convert string value to integer
			if (invChars > 0)// check for invalid characters
			{
				cout << "Invalid Command. Your shift value can only have numbers in it." << endl;
				return userString;
			}
			if (comm[0] == 'L')//checks for capital L and calls the left shift function
				return leftShift(userString, shift);
			if (comm[0] == 'R')//checks for capital R and calls the right shift function
				return rightShift(userString, shift);
		}
		else
		{
			cout << "Invalid Command. Your first character was invalid" << endl;
			return userString;
		}
	}
    else
	{
		cout << "Invalid Command. Your first character must be a letter" << endl;
        return userString;
	}
}
int main()
{
	char inpString[50], commString[10]; //decalre variables to store the string and command from user
	cout << "Enter a string: " << endl;//prompt for string
	cin.getline(inpString, 50);//store string
	string normString;// temporary string variable
	while (normString != "quit")
	{
		cout<< "Enter a command: " <<endl;
		cin >> commString;
		normString = string(command(inpString, commString)); //call command function and convert to string
		if (normString !="quit")//check string for "quit"
			cout<< "Your string is " << inpString << endl;
	    for (int i = 0; i < strlen(inpString) + 1; i++) //have to make it loop one character long to hold the null terminator
	        inpString[i] = normString[i];//copy values back into c style string
	}
	return 0;
}