/*****************************
 * Author: Ryan Cosby
 * Date Created: 10/14/2014
 * Last Modification Date: 10/14/2014
 * File name: strings.cpp
 *
 * Overview:
 * This program is for practice interacting with string variable. In particular
 * printing strings to the screen and reviewing each individual character of a
 * string
 *
 *
 * Input:
 * The user is asked for a word
 * 
 *
 * Output:
 * Screen prints the characters of the string one character at a 
 * time forwards and then backwards. Then reports to the user the 
 * number of letters in the string
 * **************************************************************/ 
 
#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main()
{
string my_str;
cout << "\n\nPlease enter a string: ";
//cin >> my_str; I commented this out to test "getline"
getline(cin, my_str);
cout << "You entered: " << my_str << endl;

cout << "\nPrinting one letter at a time left to right:\n" << endl;
// Loop for printing each letter of the string left to right
for(int i = 0; i < my_str.length(); i++)
	{
	cout << my_str.at(i) << endl;
	}
cout << "\nPrinting one letter at a time right to left:\n" << endl;
// Loop for printing each letter of the string right to left
for(int i = (my_str.length() - 1); i >= 0; i--)
	{
	cout << my_str.at(i) << endl;
	}
int numLetters;// variable to store number of letters

//Loop for counting letters in string
for(int i = 0; i < my_str.length(); i++)
	{
	if (isalpha(my_str.at(i))) // used a link on cplusplus.com to figure out
		{
		numLetters++;
		}
	}
cout << "\nThe number of letters in this string is: " << numLetters << endl;
return 0;
}
