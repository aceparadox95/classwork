/*****************************
 * Author: Ryan Cosby
 * Date Created: 11/16/2014
 * Last Modification Date: 11/16/2014
 * File name: sameSum.cpp
 *
 * Overview:
 * This program allows the user to create a square shaped array
 * The values of the rows, columns, and diagonals are summed and
 * compared for equal values
 *
 * Input:
 * User enters size of array and values for each row of the ray
 * separated by white spaces
 *
 * Output:
 * Prints the values of the array and the sums of each row/columns
 * and reports to the user if values are equal
 * **************************************************************/ 

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

bool sumCheck(int sqArr[10][10], int arrSize)//Function takes 2D array and Array size as parameters
{
	int sumLRDiagonal = 0;//initialize diagonal variable
	int sumRLDiagonal = 0;// initialize diagonal variable
	int sumRow[10] = {0};// initialize Row Sum Array
	int sumCol[10] = {0};// iniitalize Column Sum array
	
	for (int r = 0; r < arrSize; r++)
	{
		for (int c = 0; c < arrSize; c++)
		{
			if (r==c)//To sum the values of diagonal LT to RB
				sumLRDiagonal+= sqArr[r][c];
			if(r==(arrSize-1)-c)//To sum the values of diagonal RT to LB
				sumRLDiagonal+= sqArr[r][c];
			sumRow[r]+=sqArr[r][c]; //summing row values and storing in row sum array
			sumCol[r]+=sqArr[c][r]; //summing column values and storing in column sum array
			cout<< sqArr[r][c]<< " "; //print array
		}
	cout<< "= " << sumRow[r] << endl; //add equal sign to end of each row along with sum of row
	}
	for (int i = 0; i < arrSize; i++)
	    cout << "= ";
	cout << endl;
	for (int i = 0; i < arrSize; i++)
	    cout << sumCol[i] << " "; //add equal sign to end of each column along with sum of column
    for (int i = 1; i < arrSize; i++) //Validation for equal rows and columns
    {
        if (sumRow[i-1] != sumRow[i]) //compare each row sum to sum in previous row
            return false;
        if (sumCol[i-1] != sumCol[i]) //compare each column sum to sum in previous column
            return false;
        if ((sumRow[i] != sumCol[i]) || (sumRow[i-1] != sumCol[i-1]))//check that row and column sums are equal
            return false;
        if ((sumRow[i] != sumLRDiagonal) || (sumRow[i] != sumRLDiagonal))//check that column and row sums equal diagonal
            return false;
        if ((sumCol[i] != sumLRDiagonal) || (sumCol[i] != sumRLDiagonal))//check that column and row sums equal diagonal
            return false;
    }
    if (sumRLDiagonal != sumLRDiagonal)// check that two diagonals are equal
        return false;
	return true;// if it makes it to this point were good!
}

int main()
{
	int arraySize; //variable to store square array size
	cout << "Size of 2D square array" << endl;// prompt user
	cin >> arraySize; // store array size
	int sqArray[10][10]; //Construct Array at full size
    cin.ignore(); // clear c input
	
	for (int r = 0; r < arraySize; r++) // interate only through the rows/columns specified by user
	{
	    char rowString[50]; // array to store string of values with white spaces
        cout << "Enter Values for Row " << r+1 << ": "<< endl; // prompt user
        cin.getline(rowString,50); // store input
        string delimiters = " ";
        size_t current;
        size_t next = -1;
        string convRow = string(rowString);
        for (int c = 0; c < arraySize; c++) // interate through user input and store values in array splitting at " " delimiter
		{
            string tempString;
            current = next + 1;
            next = convRow.find_first_of( delimiters, current );
            tempString = convRow.substr( current, next - current );
			sqArray[r][c] = atoi(tempString.c_str());
		}
	}
	// Utilized information from http://www.cplusplus.com/faq/sequences/strings/split/ for the main function for splitting at whitespace
	
	cout << endl;
	if (sumCheck(sqArray,arraySize))// call the sum check function
	    cout <<"\nAll rows, columns, and diagonals sum to the same value"<< endl; //print if true
	else
	    cout <<"\nAll rows, columns, and diagonals are not equal"<< endl; // print if false
	return 0;
}