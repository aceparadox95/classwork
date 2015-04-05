
/*********************************************************************
** Program Filename: compare2Lists.cpp
** Author: Ryan Cosby
** Date: January 23, 2015
** Description: This program takes two input files containing any sized
** list of sequential numbers and then outputs those numbers to an output 
** txt file in sequential order
** 
** Input: No user input however, two files with sequential numbers are needed
** Output: Combined output of sequential numbers
*********************************************************************/

#include <iostream>
#include <fstream>

using std::ofstream;
using std::ifstream;
using std::endl;
using std::cout;
using std::cin;

/*********************************************************************
** Function: mergeSort
** Description: Merges two input files with sequential numbers into
** one output file containing the sequence of numbers.
** Parameters: Two input files, blank output file
** Pre-Conditions: Needs open filestreams to work
** Post-Conditions: Closed filestreams.
*********************************************************************/

void mergeSort(ifstream &list1, ifstream &list2, ofstream &outList)
{
	int num1, num2, tempNum = 50000; /*Initialize the tempNum as high number*/
	list2 >> num2; /*Read first number from list 2*/
	while (list1 >> num1) /*Iterate through list one file*/
	{
		/*Compare list 1 to list2 value, if list 2 is smaller then read through list 2 till
		 value is larger than list 1 value*/
		while (num2 <= num1 && !(list2.eof())) 
		{
			outList << num2 << '\n'; /*Output list 2 value*/
			if (!(list2 >> num2)) /*if we haven't reached the end of the file then read the next line*/
				list2 >> num2;
			if (list2.eof()) /*Catches last value of List 2 before end file is reached*/
				tempNum = num2; /*Overwrite tempNum with last list 2 value*/
		}
		if (tempNum <= num1) /*only insert list 2 value into output if it is smaller than current list 1 value*/
		{
			outList << tempNum << '\n';
			tempNum = 50000; /*Reset tempNum value so it doesn't insert itself more than once*/
		}
		outList << num1 << '\n'; /*Always insert list 1 value into output if it reaches this points*/
	}
	while (!list2.eof())/*this condition will only execute if list 2 is longer than list 1*/
	{
		outList << num2 << '\n';
		list2 >> num2;
	}
	if (num2 > num1) /*Output trailing list 2 value only if its bigger than list 2*/
	{
		outList << num2 << '\n';
	}
	/*This is error code that i wanted to keep to test out later*/
	/*while (!(list1.eof()) || !(list2.eof()))
	{
		while (num1 <= num2)
		{
			outList << num1 << endl;
			list1 >> num1;
		}
		while (num2 <= num1)
		{
			outList << num2 << endl;
			list2 >> num2;
		}
	}
	*/
	cout << "Merging Lists together..." <<endl;
}
int main()
{

	ifstream inFile1, inFile2; /*Two input files*/
	ofstream outFile; /*Output file*/
	inFile1.open("numList1.txt"); /*Open Text File*/
	inFile2.open("numList2.txt"); /*Open Text File 2*/
	outFile.open("combList.txt"); /*Create Output file*/
	if (inFile1 && inFile2 && outFile) /*Checks for errors when opening*/
	{
		mergeSort(inFile1, inFile2, outFile); /*pass filestreams to the function*/
		inFile1.close();/*Close files after they have bee accessed*/
		inFile2.close();
		outFile.close();
	}
	else /*Warn user that one of files did not open correctly*/
	{
		cout << "One of the files did not open correctly." << endl;
		cout << "Check for correct filenames!" << endl;
	}
	return 0;
}

