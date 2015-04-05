/*****************************
 * Author: Ryan Cosby
 * Date Created: 10/30/2014
 * Last Modification Date: 10/30/2014
 * File name: recFun.cpp
 *
 * Overview:
 * This program prints a term from the fibonacci sequence as specified by
 * the user.
 *
 *
 * Input:
 * Asks user for the numbered term in the fibonacci sequence
 * 
 *
 * Output:
 * Prints the term specified by the user 
 * **************************************************************/ 
 
#include <iostream>
using namespace std;

int fibonacci(int num)
{
	if (num <= 0)//check for base case of 0
	{
		//cout << num << endl;// I used this line to see what the code was doing
		return 0;
	}
	else if (num == 1) //check for base case of 1
	{
		//cout << num << endl;// I used this line to see what the code was doing
		return 1;
	}
	else // do the recursion
	{
		//cout << num << endl;// I used this line to see what the code was doing
		return fibonacci(num - 1) + fibonacci(num - 2);
	}
}

int main()
{
	int nthTerm; //variable to be passed to fibonacci sequence
	cout << "Enter the Nth term of the Fibonacci Sequence: ";
	cin >> nthTerm;
	cout << "The " << nthTerm << " term of the Fibonacci Sequence is: ";
	cout << fibonacci(nthTerm) << endl;
	return 0;
}