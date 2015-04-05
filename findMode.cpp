/***************************************************************
 * Author: Ryan Cosby
 * Date Created: 11/18/2014
 * Last Modification Date: 11/19/2014
 * File name: findMode.cpp
 *
 * Overview:
 * This programs allows the user to enter multiple integer values
 * then outputs the mode of those values. If there is more than one
 * mode then it prints all of them.
 * 
 * Input:
 * User enters integer values.
 *
 * Output:
 * Mode Vector
 * **************************************************************/ 
#include <iostream>
#include <vector>
#include <cctype>
#include <cstdlib>
#include <string>
using namespace std;

vector<int> modeFind(vector<int> inpVect)
{
	int tempVar = 0; // variable to store temporary array
	for (int i = 0; i < inpVect.size(); i++)// this loop sorts the vector array
	{
		for (int c = 0; c < inpVect.size(); c++)// compares value at index to rest of array
		{
			if (inpVect[c] >= inpVect[i])// check to see if value at index is larger
			{
				tempVar = inpVect[i]; //holds value being compared to
				inpVect[i] = inpVect[c]; // switches the value
				inpVect[c] = tempVar; // restores the switched value
			}
		}
	}
	int freqCount = 1, maxCount = 0;// values to hold current frequency count and max count
	vector<int> modeVect; // create new vector to store mode values
	for (int i = 0; i < inpVect.size(); i++) // reviews sorted vector from previous loop
	{
		if (inpVect[i] == inpVect[i+1]) // checks to see if value is equal to the next value in array
			freqCount++; // increments frequency count if it is equal
		else // if the value is not equal
		{
			if (freqCount == maxCount) //check to see if the frequency count is equal to the max count
				modeVect.push_back(inpVect[i]); // store value in mode vector
			if (freqCount > maxCount) //check to see if the frequency count is greater than the max count
			{
				maxCount = freqCount; // set the new max count equal to the frequency count so it can be compared later
				while (!modeVect.empty()) // This small loop removes anything in the mode vector that may have been placed there previously
					modeVect.pop_back(); // if the program has made it this far that means the value being considered is probably one of the
										 // modes.
				modeVect.push_back(inpVect[i]); // store value at index in mode vector
			}
				freqCount = 1; //reset the frequency count
		}
	}
	return modeVect; //return the mode vector
}

int main()
{
	vector<int> nums; //create vector to hold user input values
	char userState = 'Y'; //value to check user state
	string tempString; //value to hold input
	while (userState == 'Y')
	{
		int tempInp = 0, invChars = 0, decCheck = 0;
		cout<< "Please enter an integer: "; //prompt user
		cin >> tempString; // store user input
		for (int i = 0; i < tempString.length(); i++) //validation loop
		{
			if (tempString[i] != '.' ) //check if not decimal
			{
				if (!isdigit(tempString[i])) // check for letters
					invChars++;
			}
			if (tempString[i] == '.' ) // check for decimal
				decCheck++;
		}
		if (invChars > 0 || decCheck != 0) // validate input
			cout << "Invalid Entry. Try again!" << endl; //warn user
		else
		{
			tempInp = atoi(tempString.c_str()); // convert to integer
			nums.push_back(tempInp);//store value in vector once its made it to this point
			cout << "Would you like to enter another integer? (Y or N)"; // allow user to enter more values as desired
			cin >> userState; // set value to user state character
			userState = toupper(userState); // convert lower case to upper if needed
		}
	}
	nums = modeFind(nums); //sets original input vector equal to the mode vector returned by function
	cout << "Mode: "; // beginning of final output
	for (int i = 0; i < nums.size(); i++) //print mode vector
	{
	    cout << nums[i]; // print mode
		if ((nums.size() - i) > 1)
			cout << ", "; // print comma if more than one mode
	}
	cout<<endl;
	return 0;
}
