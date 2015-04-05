/*****************************
 * Author: Ryan Cosby
 * Date Created: 10/16/2014
 * Last Modification Date: 10/16/2014
 * File name: loop.cpp
 *
 * Overview:
 * Compares characters from word using a loop and tells the user
 * if the words/characters are different
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

int main() 
{
string word1, word2; //storing each word
int loopCount = 0, numdiffChar = 0; //initialize variables at 0
cout << "Please enter a word: " << endl; // gathering input
cin >> word1;//storing input for first word
cout << "Please enter another word: "<< endl;// gathering input
cin >> word2;//storing input for second word

if (word1.length() >= word2.length())// find the shortest word
	{
	loopCount = word2.length();
	}
else
	{
	loopCount = word1.length();
	}
for (int i = 0; i < loopCount ; i++)//loop to compare characters
	{
		if (word1.at(i) == word2.at(i))
			{
			cout << word1.at(i) << "   " << word2.at(i) << endl;
			}
		else
			{
			cout << word1.at(i) << "   " << word2.at(i) << "   Characters are different!" << endl;
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
return 0;
}