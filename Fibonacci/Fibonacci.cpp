/*********************************************************************
** Program Filename: Fibonacci.cpp
** Author: Ryan Cosby
** Date: March 10, 2015
** Description: This is a driver program to help identify processing
** speeds of recursive, double recursive, tail recursive, and iterative
** functions
** Input: User enters term to pass to each formula once
** Output: Returns the results of each formula and well the processing
** speed
*********************************************************************/

#include "fibfactFuncs.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;
int main()
{
	//using namespace std::chrono;
	char userState = 'Y';
	while (userState == 'Y')
	{
			//clock_t timeTest;
			int testTerm; 
			cout << "Input value for Fibonacci/Factorial Formulas: ";
			cin >> testTerm;
			for (int i = 1; i <= 4; i++) // Iterate through different function calls
			{
				//timeTest = clock();
				high_resolution_clock::time_point t1 = high_resolution_clock::now(); // create high resolution clock time point
				if (i == 1)
					cout << "\nRecursive Fibonacci(" << testTerm << "): " << fibR(testTerm) << endl;
				if (i == 2)
					cout << "\nNon Recursive Fibonacci(" << testTerm << "): " << fibNR(testTerm) << endl;
				if (i == 3)
					cout << "\nTail Recursive Factorial(" << testTerm << "): " << factorial(testTerm) << endl;
				if (i == 4)
					cout << "\nNon Tail Recursive Factorial(" << testTerm << "): " << rfactorial(testTerm) << endl;
				high_resolution_clock::time_point t2 = high_resolution_clock::now();// create high resolution clock time point
				duration<double> time_span = duration_cast<duration<double>>(t2 - t1);//difference between time points
				//timeTest = clock() - timeTest;
				//cout << "Operation took " << ((float)timeTest / CLOCKS_PER_SEC) << " seconds" << endl;
				cout << "Operation took " << time_span.count() << " seconds" << endl;
			}
			cout << "\nDone!!!!" << endl;
			cout << "\nWould you like to do another test? (Y or N)" << endl;
			cin >> userState;
			userState = toupper(userState);
	}
	return 0;
}



