/*****************************
 * Author: Ryan Cosby
 * Date Created: 11/5/2014
 * Last Modification Date: 11/5/2014
 * File name: grades.cpp
 *
 * Overview:
 * Allows users to enter specified number of number grades and
 * keeps a total of the number of each grade entered
 * 
 * Input:
 * Asks user for number of grades they want to enter
 * user enters grades
 *
 * Output:
 * at end of grades prints total number of each grade type
 * **************************************************************/ 
#include <iostream>
#include <cctype>
using namespace std;

int main()
{

	int gradeVal = 0;
	int gradeList[6] = {0}; //declare array with input size
	while ((gradeVal >= 0) && (gradeVal <= 5))
	{
		cout << "Enter a grade (0 to 5): ";//prompt user
		cin >> gradeVal;
		gradeList[gradeVal]++;
	}
	for (int i = 0; i < 6;i++)
		cout << gradeList[i] << " grade(s) of " << i << endl;
	return 0;
}