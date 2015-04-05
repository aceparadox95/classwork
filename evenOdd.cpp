/*****************************
 * Author: Ryan Cosby
 * Date Created: 11/4/2014
 * Last Modification Date: 11/4/2014
 * File name: evenOdd.cpp
 *
 * Overview:
 * This program creates user defined array storing integers
 * and then prints the sum of the even minus odd integers
 * 
 * Input:
 * Asks user for input integer for list size
 * Asks user for input integers to store in array list
 *
 * Output:
 * Prints the sum of the even integers minus the odd integers
 * **************************************************************/ 
#include <iostream>

using namespace std;

int sumArr(int arr[],int arrSize)
{
	int sumEven = 0, sumOdd = 0;//temporary variable to
	for (int i = 0; i < arrSize; i++)//check each part of list for evens and odds
	{
		if (arr[i] % 2 == 0)
			sumEven+= arr[i];//summing even numbers
		else
			sumOdd+= arr[i];//summing odd numbers
	}
	return sumEven - sumOdd;//return the difference
}

int main()
{
	int arraySize; //store array size
	cout << "How many numbers do you want your list to hold? ";//array size input
	cin >> arraySize; //store input array size
	int numList[arraySize]; //declare array with input size
	for (int i = 0; i < arraySize; i++) //construct array one number at a time
	{
		cout << "Enter a number: ";//prompt user
		cin >> numList[i];//store input
	}
	cout << "The sum of the even numbers minus the odd is: " << sumArr(numList, arraySize) << endl;
	return 0;
}