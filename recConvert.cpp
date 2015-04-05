/*****************************
 * Author: Ryan Cosby
 * Date Created: 10/30/2014
 * Last Modification Date: 10/30/2014
 * File name: hailstone.cpp
 *
 * Overview:
 * Binary to Decimal / Decimal to Binary Number Converting Program
 * 
 * Input:
 * Asks user for input binary number or decimal number.
 *
 * Output:
 * Prints the converted number
 * **************************************************************/ 

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

double binToDec(string binString) //double so its more compatible with the pow function
{
    static double decVal = 0;// static variable so its not overwritten
    if (binString.length() == 0)
		return decVal;
    else
    {
        double a = binString[0] - '0'; //convert first character to string.. learned this at cplusplus.com
        decVal += a * (pow(2.0,((binString.length()-1)))); // (0 or 1 * 2 ^ N)
        binToDec(binString.substr(1,binString.length())); // return binary string with first
		                                                  // character remove
    }
}
string decToBin (int decimal)
{
	string remainder;
	if (decimal % 2 == 0)
		remainder = "0"; //set to string value to help construct string
	else
		remainder = "1"; //set to string value to help construct string
	if (decimal == 1)
		return "1"; //set to string value to help construct string
	if (decimal == 0)
		return "0"; //set to string value to help construct string
	else
		return decToBin(decimal / 2) + remainder; //call recursion
}
bool checkBin(string test)
{
	int invCharacters = 0;
	for (int i = 0; i < test.length(); i++)
		{
			if ((test.at(i) != '0') && (test.at(i) != '1'))
				invCharacters++;//count invalid characters
		}
	if (invCharacters > 0) //check for invalid characters
		return true;
	else
		return false;
}
bool checkDec(string test)
{
	int invCharacters = 0;
	for (int i = 0; i < test.length(); i++)
		{
			if (!(isdigit(test.at(i)))) //check for non-digits
				invCharacters++; // count number of invalid characters
		}
	if (invCharacters > 0) //check for invalid characters
		return true;
	else
		return false;
}
int main()
{
    
	int userState = 0; //set initial game state
	while (userState != 3) // excutes loop as long as userState is not 3
	{
		cout << string(40, '*') << endl; //separator on screen
		cout << "Enter <1> to do a binary to decimal value conversion"<< endl;
		cout << "Enter <2> to do a decimal to binary value conversion" << endl;
		cout << "Enter <3> to exit the program" << endl;
		cin >> userState;
		while (userState == 1) //binary to dec conversion state
		{
			string binNum;
			cout << ("\nEnter a binary number: ");
			cin >> binNum;
			if (checkBin(binNum))
			{
				cout << "Error: Your binary number can only contain 0's and 1's\n";
				break;
			}
			cout << "The decimal value of the binary number ";
			cout << binNum << " is " << binToDec(binNum) <<endl;
			userState = 0;
		}
		while (userState == 2) //dec to binary conversion state
		{
			string decString;
			int decNum;
			cout << ("\nEnter a decimal number: ");
			cin >> decString;
			if (checkDec(decString))
			{
				cout << "Error: Your decimal number can only contain numbers 0 to 9\n";
				break;
			}
			decNum = atoi(decString.c_str()); // convert to decimal if it gets past validation
			cout << "The binary value of the decimal number ";
			cout << decNum << " is " << decToBin(decNum)<<endl;
			userState = 0;
		}
	}
}
