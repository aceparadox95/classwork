/*****************************
 * Author: Ryan Cosby
 * Date Created: 10/11/2014
 * Last Modification Date: 10/11/2014
 * File name: numGuess.cpp
 *
 * Overview:
 * This program is a game game with two players where the first player
 * enters a number between 0 and 100. The second player then guesses the
 * value. The second player has 5 guesses to get it right.
 * 
 * Input:
 * Integer value between 0 and 100 for each player. Player also has choice
 * play again or end the game if they want to and entering yes or no.
 *
 * Output:
 * The game give both players instructions. It also provided useful feedback
 * after each guess.
 * **************************************************************/ 
 
 #include <iostream>
 #include <cmath> //needed for absolute values
 
 using namespace std;
 
 int main()
 {
	char gameState = 'y';// sets initial game state to yes... allowing player 1 to start
	while (gameState == 'y')
	{
	float correctAnswer = 0;//had to be a float because std::abs wont work without it
	float guess = 0;//had to be a float because std::abs wont work without it
	int maxGuess = 100;//storing the high guess
	int minGuess = 0;//storing the low guess
	float bestGuess = 100;//had to be a float because std::abs wont work without it
	cout << "\n\n";
	cout << "Welcome to the Number Guessing Game!!"<< endl;//intro to game
	cout << "Please enter a number between 0 and 100 for Player 2 to guess: ";//inst.
	cin >> correctAnswer;//player 1 input
	if (!((correctAnswer >= 0) && (correctAnswer <=100)))//checking for valid number
	{
		cout << "You entered an invalid number. Please enter a value in between 0 and 100"<<endl;
		cout << "Game will start over now.\n"<< endl;
		gameState = 'i';//puts game in "invalid" state and skips to the end
	}
	else// where the majority of the game takes place
	{
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		int numGuesses = 5;
		while (numGuesses > 0)
		{
		if (numGuesses == 5)//gives introduction to Player 2 if its first guess
		{
			cout <<"Welcome to the Number Guessing Game Player 2!"<< endl;
			cout <<"Player 1 has chosen a number between 0 and 100"<< endl;
		}
		cout <<"You have " << numGuesses << " guesses remaining" << endl;
		cout <<"Choose a number between "<< minGuess << " and " << maxGuess << endl;
		cin >> guess; //store player 2 guess
		cout <<"\n\n"; //clears some space in between instructions and player input
		numGuesses-= 1;//guess decrements
		if (guess > correctAnswer)
		{
			cout << "Your guess was too high" << endl;
			maxGuess = guess;
		}
		else if(guess < correctAnswer)
		{
			cout << "Your guess was too low"<< endl;
			minGuess = guess;
		}
		else
		{
			cout <<"Your guess was correct! Congratulations!"<<endl;
			gameState = 'i';//sets game to invalid state as trick to move to line 92
			break;
		}
		if (abs(correctAnswer - guess) < bestGuess)//finds out what the best guess is
		{
			bestGuess = guess;
		}
		
		//end of inner loop
		}
	//end of main else statement
	}
	if (gameState != 'i')//if game is not invalid the following text occurs
	{
	cout << "The correct answer was " << correctAnswer << endl; //telling player results
	cout << "Your closest guess was " << bestGuess << " which was ";
	cout << abs(correctAnswer - bestGuess);//calculate distance
	cout << " away from the correct answer."<<endl;//distance from correct value
	}
	cout << "\n\n\n\n"<< "Do you want to play again? (y or n)" <<endl;
	cin >> gameState; // changes game state
	//end of outer loop
	}
 return 0;
 }