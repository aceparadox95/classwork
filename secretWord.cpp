/*****************************
 * Author: Ryan Cosby
 * Date Created: 10/23/2014
 * Last Modification Date: 10/25/2014
 * File name: secretWord.cpp
 *
 * Overview:
 * This is a word guessing game that allows Player 1 to set a word
 * for player 2 to guess. For both player 1 and player 2 it asks the
 * user to input a valid letter or word. Player 2 has 10 guesses to 
 * guess a letter in the word. For each correct guess that letter shows
 * up in the word. After each letter guess player 2 is asked if they
 * want to guess the secret word. After 10 guesses player must guess the
 * secret word no matter what.
 
 * Input:
 * Player 1 is asked for a word
 * Player 2 can guess letters or words
 *
 * Output:
 * The program tells player 2 what guess they are on, and what letters
 * have been correct or incorrect to that point in the game.
 * **************************************************************/ 

#include <iostream>
#include <string>
#include <cctype>
using namespace std;
//FUNCTION FOR CHECKING VALID INPUT*************************************
bool checkalpha(string test)
{
	int invCharacters = 0;
	for (int i = 0; i < test.length(); i++)
		{
			if (!(isalpha(test.at(i)))) //check for letters in each character
				invCharacters++; // count number of invalid characters
		}
	if (invCharacters > 0) //check for invalid characters
	{
		return true;
	}
	else
	{
		return false;
	}
}
//*********************************************************************
int main ()
{
	char userState = 'Y';
	while (userState == 'Y') //OUTER LOOP FOR INTIALIZING GAME SETTINGS
	{
		int numGuesses = 1; //INITIALIZING VARIABLES ↓↓↓↓
		int numdiffChars = 0;
		string correctWord;
		string guessLetter;
		string guessWord;
		string updateWord;
		string corrLetters;
		string inCorrLetters;
		char guessWordState;
		//PLAYER 1 INPUT****************************************************
		cout << string(50, '\n');// Clear screen before input
		cout << "Enter a word for player 2 to guess: ";
		cin >> correctWord;
		//VALIDATING PLAYER 1 INPUT*****************************************
		while (checkalpha(correctWord))
		{
			cout << "You have entered an invalid word\n";
			cout << "Please enter a valid word (can only contain letters): ";
			cin >> correctWord; //FORCE collection of valid word
		}
		cout << string (50, '\n');// Clear screen after player 1 input
		updateWord = string (correctWord.length(), '*'); // Create blank word
		while (numGuesses <= 10)// INNER LOOP for PLAYER 2 GUESSING
		{
			int corrLettCount = 0;
			if (numGuesses != 1)
			{
				cout << string (50, '\n');//Clearn screen after each guess
				cout << string (80, '*'); // divider line for easier readability
				cout << "You are on GUESS #" << numGuesses << " of 10";
				cout << "\nCorrect letter guesses: " << corrLetters << endl;
				cout << "Incorrect letter guesses: " << inCorrLetters<< endl;
			}
			cout << "The secret word is: " << updateWord << endl;
			// PLAYER 2 LETTER INPUT***********************************************
			cout << "Please guess a letter in the secret word: ";
			cin >> guessLetter;
			// VALIDATING PLAYER 2 LETTER INPUT************************************
			while (checkalpha(guessLetter))
			{
				cout << "You have entered an invalid character\n";
				cout << "Please enter a valid letter (A to Z): ";
				cin >> guessLetter;
			}
			//Building updated word and correct/incorrect letter guesses**********
			for (int i = 0; i < correctWord.length(); i++)
			{
				if (correctWord.at(i) == guessLetter.at(0))
				{
					updateWord[i] = guessLetter.at(0);
				}
			}
			for (int i = 0; i < correctWord.length(); i++)// Count num of correct letters
			{
				if (correctWord.at(i) == guessLetter.at(0))
				{
					corrLettCount++;
				}
			}
			if (corrLettCount > 0) // build correct letters string
			{
				if (corrLetters.length() == 0)// no comma if first letter guessed
					corrLetters = guessLetter;
				else
					corrLetters = corrLetters + ", " + guessLetter;
			}
			else // build incorrect letters string
			{
				if (inCorrLetters.length() == 0)// no comma if first letter guessed
					inCorrLetters = guessLetter;
				else
					inCorrLetters = inCorrLetters + ", " + guessLetter;
			}
		cout << string(50, '\n');//Clear screen after each guess
		cout << "\n\n\n\nWith the letters you guessed the word now looks like: "<<updateWord;
		if (numGuesses == 10)// asking player 2 guess word after running out of guesses
		{
			cout << "\nYou have run out of letter guesses\n";
			guessWordState = 'Y';
		}
		else// Asking player 2 if they want to guess word after each letter guess
		{
			cout << "\nWould you like to guess the word? (Y or N) ";
			cin >> guessWordState;
		}
		guessWordState = toupper(guessWordState); //Standardizing input
		// PLAYER 2 Word Guess Input**********************************************
		if (guessWordState == 'Y')
		{
			cout << "Please enter your word guess: ";
			cin >> guessWord;
			// VALIDATING Player 2 Word Input*************************************
			while (checkalpha(guessWord))// Check for non letters
			{
				cout << "You have entered an invalid word\n";
				cout << "Please enter a valid word (can only contain letters): ";
				cin >> guessWord;
			}
			while (guessWord.length() != correctWord.length()) // check mismatched length
			{
				cout << "Your word has more characters than the correct word."<< endl;
				cout << "Please enter a word with the same number of characters: ";
				cin >> guessWord;
			}
			for (int i = 0; i < correctWord.length() ; i++)//loop to compare characters
			{
				if (guessWord.at(i) != correctWord.at(i))
				{
				numdiffChars++;
				}
			}
			if (numdiffChars++ > 0) // counting number of different characters
			{
				cout << "\nYour guess is incorrect. You lost"<<endl; // notify if lost
				cout << "The correct word was: " << correctWord << endl;
				break;
			}
			else // notify if won
			{
				cout << "\nYour guess was correct. You won!"<<endl;
				cout << "The correct word was: " << correctWord << endl;
				cout << "You guessed " << numGuesses << " time(s)"<< endl;
				break;
			}
		}
		numGuesses++;
		}
	cout << "\nWould you like to play again (Y or N)? ";// offer option to play again
	cin >> userState;
	userState = toupper(userState);
	}
	return 0;
}