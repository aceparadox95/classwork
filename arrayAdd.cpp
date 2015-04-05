/*****************************
 * Author: Ryan Cosby
 * Date Created: 11/5/2014
 * Last Modification Date: 11/5/2014
 * File name: arrayAdd.cpp
 *
 * Overview:
 * This program adds the values of two integer arrays and
 * stores them in a third array
 * 
 * Input:
 * User enters size of array and list of values for each array
 *
 * Output:
 * prints the sum of the values from the first two arrays
 * **************************************************************/ 
 
#include <iostream>
using namespace std;

int *addArrays(int arr1[],int arr2[], int sumArr[],int arrSize)
{
	int *numPtr = arr1, *numPtr2 = arr2, *addPtr = sumArr;
	for (int i = 0; i < arrSize; i++)
	{
		*addPtr = *numPtr + *numPtr2;
		addPtr++;
		numPtr++;
		numPtr2++;
	}
	return sumArr;
}

int main()
{
	int arraySize; //store array size
	cout << "How many numbers do you want your two lists to hold? ";//array size input
	cin >> arraySize; //store input array size
	int numList[arraySize]; //declare array with input size
	int numList2[arraySize]; //declare second array with input size
	int addList[arraySize];
	int *numPtr = numList, *numPtr2 = numList2;
	for (int i = 0; i < arraySize; i++) //construct array one number at a time
	{
		cout << "Enter number " << i+1 << " of " << arraySize << " for first list: ";//prompt user
		cin >> *numPtr;//store input in first array
		numPtr++;
	}
	cout << "End of first list"<< endl;
	for (int i = 0; i < arraySize; i++) //construct array one number at a time
	{
		cout << "Enter number " << i+1 << " of " << arraySize << " for second list: ";//prompt user
		cin >> *numPtr2;//store input in second array
		numPtr2++;
	}
	cout << "End of second list"<< endl;
	cout << "Addition of the elements from both lists: "<< endl;
	int *sumPtr = addArrays(numList, numList2, addList, arraySize);
	for (int i = 0; i < arraySize; i++) //construct array one number at a time
	{
		cout << *sumPtr << endl;
		sumPtr++;
	}
	return 0;
}