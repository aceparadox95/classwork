#include "searchsortAlgs.h"
#include <cstdlib>

/*********************************************************************
** Function: Load File to Vector
** Description: Takes input file stream and loads values into vector
** Parameters: input file stream from file, input empty vector
** Pre-Conditions: empty vector
** Post-Conditions: vector loaded with values from file stream
*********************************************************************/
void loadFiletoVect(ifstream &inFile, vector<int> &inpVect)
{
	int tempVal;
	if (inFile)
	{
		while (!inFile.eof())
		{
			inFile >> tempVal;
			inpVect.push_back(tempVal);
		}
		inFile.close();
	}
	else
	{
		cout << "File does not exist" << endl;
	}
}
/*********************************************************************
** Function: genFile
** Description: Takes vector and outputs to user specified file
** Parameters: populated vector and fileName for output
** Pre-Conditions: empty text file
** Post-Conditions: populated text file
*********************************************************************/
void genFile(int totNums, int zeroIndex, string fileName)
{
	
	ofstream outFile;
	outFile.open(fileName.c_str());
	srand(time(NULL));
	//int zeroIndex = rand() % totNums + 1;
	//int zeroIndex = 
	for (int i = 0; i < totNums; i++)
	{
		if (zeroIndex == 1 && i == 0)
			outFile << 0 << endl;
		else if (zeroIndex == 2 && i == totNums / 2)
			outFile << 0 << endl;
		else if (zeroIndex == 3 && i == totNums - 1)
			outFile << 0 << endl;
		else
			outFile << rand() % 9 + 1 << endl;
	}
	outFile.close();
}
/*********************************************************************
** Function: Output Vector to File
** Description: Takes vector and outputs to user specified file
** Parameters: populated vector and fileName for output
** Pre-Conditions: empty text file
** Post-Conditions: populated text file
*********************************************************************/
void vect2outFile(vector<int> &inpVect, string fileName)
{
	ofstream outFile;
	outFile.open(fileName.c_str());
	for (int i = 0; i < inpVect.size(); i++)
	{
		outFile << inpVect[i] << endl;
	}
	outFile.close();
}
/*********************************************************************
** Function: Linear Search
** Description: searches for value in vector
** Parameters: vector to be searched and integer search value
** Pre-Conditions: populated vector
** Post-Conditions: returns index of value in list if found
*********************************************************************/
int search(vector<int> &inpVect, int searchVal)
{
	for (int i = 0; i < inpVect.size(); i++)
	{
		if (inpVect[i] == searchVal)
			return i+1;
	}
	return -1;
}
/*********************************************************************
** Function: Bubble Sort
** Description: Sorts values in input vector in ascending order
** Parameters: vector to be searched and integer search value
** Pre-Conditions: populated vector
** Post-Conditions: returns index of value in list if found
*********************************************************************/
void bubbleSort(vector<int> &inpVect)
{
	for (int i = (inpVect.size() - 1); i > 0; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			if (inpVect[j - 1] > inpVect[j])
			{
				int temp = inpVect[j - 1];
				inpVect[j - 1] = inpVect[j];
				inpVect[j] = temp;
			}
		}
	}
}
/*********************************************************************
** Function: Binary Search
** Description: searches for value in vector using binary method
** Parameters: vector to be searched and integer search value
** Pre-Conditions: populated vector
** Post-Conditions: returns index of value in list if found
*********************************************************************/
int binarySearch(vector<int> &inpVect, int searchVal)
{
	int low = 0;
	int high = inpVect.size() - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		int diff = inpVect[mid] - searchVal;
		if (diff == 0)
			return mid + 1;
		else if (diff < 0)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}