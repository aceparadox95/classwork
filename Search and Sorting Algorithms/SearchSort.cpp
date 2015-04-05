/*********************************************************************
** Program Filename: SearchSort.cpp
** Author: Ryan Cosby
** Date: February 14, 2015
** Description: Performs basic search and sorting functions on input
** files. Writes sorted outputs to new files
** Input: User selects the input file and sort or search commands
** Output: Generates search index values or sorted text files
*********************************************************************/
#include "searchsortAlgs.h"
#include <fstream>
#include <string>
#include <cstdlib>
using std::cin;
int main()
{
	int comm, searchVal, searchIndex, numInts;
	clock_t timeTest;
	string comm2, inFileName, outFileName;
	char filegenStat = 'Y', userState = 'Y';
	ifstream inFile;
	ofstream outFile;
	vector<int> listVect; //empty vector to store lists
	vector<string> fileVect;

	while (userState == 'Y')
	{
		while (filegenStat == 'Y')
		{

			if (fileVect.size() == 4)
			{
				cout << "Sorry you can only generate 4 files total" << endl;
				break;
			}
			else
			{
				cout << "Enter a name for the randomly generated file: " << endl;
				cin >> inFileName;
				inFileName = inFileName + ".txt";
				fileVect.push_back(inFileName);
				cout << "How many integers do you want in your file? " << endl;
				cin >> numInts;
				genFile(numInts, fileVect.size(), inFileName);
				cout << "File: " << inFileName << " generated." << endl;
				cout << "Would you like to generate another file? (Enter y or n) " << endl;
				cin >> filegenStat;
				filegenStat = toupper(filegenStat);
			}

		}
		cout << "Enter the number of the random file you want to use: " << endl;
		for (int i = 0; i < fileVect.size(); i++)
		{
			cout << i + 1 << ". " << fileVect[i] << endl;
		}
		cin >> comm; //store input from user
		inFileName = fileVect[comm - 1]; // convert user input to text file name
		inFile.open(inFileName.c_str()); //open the file into file stream
		loadFiletoVect(inFile, listVect); //load file values into vector
		cout << "\nPress 1 to search for value in file using a linear search" << endl;
		cout << "Press 2 to sort values in file and save it to a new file" << endl;
		cin >> comm; //store input from user
		if (comm == 1)
		{
			cout << "\nWhat value do you want to search for?" << endl;
			cin >> searchVal; //store input search value from user
			timeTest = clock();
			searchIndex = search(listVect, searchVal); //finds index of value and stores it in variable
			timeTest = clock() - timeTest;
			if (searchIndex == -1) // report if found or not
				cout << "Value not found in file" << endl;
			else
				cout << "Value found at #" << searchIndex << " in the list." << endl;
			cout << "Linear search operation took " << ((float)timeTest / CLOCKS_PER_SEC) << " seconds" << endl;
		}
		else if (comm == 2)
		{
			cout << "\nEnter the name for your output file (don't include file extension): " << endl;
			cin >> outFileName;
			outFileName = outFileName + ".txt"; // adds extension to output sorted filename
			timeTest = clock();
			bubbleSort(listVect); //sorts in the input vector
			timeTest = clock() - timeTest;
			cout << "Sorting file" << endl;//reports to user it has sorted
			vect2outFile(listVect, outFileName); // writes new sorted values to output file
			cout << "Writing list to output file: " << outFileName << endl; //report to user that file has been created
			cout << "Bubble sort operation took " << ((float)timeTest / CLOCKS_PER_SEC) << " seconds" << endl;
			cout << "\nWould you like to do a binary search on your sorted list?" << endl;
			cout << "(Enter y or n)" << endl; //only lets user do binary search if vector has been sorted
			cin >> userState;
			userState = toupper(userState);
			if (userState == 'Y')
			{
				cout << "\nWhat value do you want to search for?" << endl;
				cin >> searchVal; // ask user for binary search value
				timeTest = clock();
				searchIndex = binarySearch(listVect, searchVal); //perform binary search
				timeTest = clock() - timeTest;
				if (searchIndex == -1) //report to user if found or not
					cout << "Value not found in file" << endl;
				else
					cout << "Value found at #" << searchIndex << " in the list." << endl;
				cout << "Binary search operation took " << timeTest << " clicks " << "or "<< ((float)timeTest / CLOCKS_PER_SEC) << " seconds" << endl;
			}
		}
		cout << "\nWould you like to run program again? " << endl; //lets user operate on other file if desired
		cout << "(Enter y or n)" << endl;
		cin >> userState;
		userState = toupper(userState);
		if (userState == 'Y')
		{
			cout << "Would you like to search or sort the same files? " << endl;
			cout << "(Enter y or n)" << endl;
			cin >> filegenStat;
			filegenStat = toupper(filegenStat);
			if (filegenStat == 'Y')
				filegenStat = 'N';
			else
			{
				filegenStat = 'Y';
				fileVect.clear();
			}

		}
		listVect.clear();
		cout << endl;
	}
	return 0;
}

