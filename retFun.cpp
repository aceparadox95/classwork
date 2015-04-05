/*****************************
 * Author: Ryan Cosby
 * Date Created: 10/29/2014
 * Last Modification Date: 10/29/2014
 * File name: retFun.cpp
 *
 * Overview:
 * Compares characters from word using by calling a function that uses a
 * loop and tells the user if the words/characters are different
 * 
 *
 *
 * Input:
 * User enters two words. They can be different or the same and can't
 * have spaces in them
 *
 * Output:
 * Print each of character of each string side by side and notifies
 * user if they are different
 * **************************************************************/ 
#include <iostream>
#include <string>

using namespace std;
void sameString(string &string1, string &string2)
{
int loopCount = 0, numdiffChar = 0; //initialize variables at 0
if (string1.length() != string2.length())// find the shortest word
	{
	cout << "The two strings you entered are different lengths";
	cout << " so they cannot be the same" << endl;
	return;
	}

for (int i = 0; i < string1.length() ; i++)//loop to compare characters
	{
		if (string1.at(i) == string2.at(i))
			{
			cout << string1.at(i) << "   " << string2.at(i) << endl;
			}
		else
			{
			cout << string1.at(i) << "   " << string2.at(i) << "   Characters are different!" << endl;
			numdiffChar++;
			}
	}
if (numdiffChar > 0)// giving final results on difference between words
	{
	cout << "These two words are not the same and have " << numdiffChar;
	cout << " character(s) that are different from each other" << endl;
	}
	else
	{
	cout << "These two words are identical"<< endl;
	}
}
int main() 
{
string word1, word2; //storing each word
cout << "Please enter a word: " << endl; // gathering input
getline(cin,word1);//storing input for first word
cout << "Please enter another word: "<< endl;// gathering input
getline(cin,word2);//storing input for second word
sameString(word1, word2);
return 0;
}