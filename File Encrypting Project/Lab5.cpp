/*********************************************************************
** Program Filename: Lab5.cpp
** Author: Ryan Cosby
** Date: February 6, 2015
** Description: This program allows users to create encrypted output versions
** of text files. The files are encrypted using a cypher text
** Input: User specifies the conversion type and the cypher key
** Output: Generates text files with the conversion type
*********************************************************************/

#include "fileFilter.h"
#include "fileUnchanged.h"
#include "fileUpper.h"
#include "fileEncrypt.h"
#include "modifyEncrypt.h"
using std::cout;
using std::cin;
using std::endl;


int main()
{
	int inpKey, comm;
	char command;
	ifstream inFile;
	ofstream outFile;
	inFile.open("inpTestFile2.txt");//open input stream
	outFile.open("outTestFile.txt");//open output stream
	cout << "Enter 1 to Create Copy of input file" << endl; //ask user for conversion type
	cout << "Enter 2 to encrypt input file into output file" << endl;
	cout << "Enter 3 to capitalize all letters in output file" << endl;
	cout << "Enter 4 to encrypt file into 5 character blocks" << endl;
	cin >> comm;//store conversion type in variable
	cout << "Input your file filter key # " << endl;
	cin >> inpKey;//store filter key in variable
	if (comm == 1)//Execute copy conversion
	{
		fileUnchanged testFile(inpKey);
		testFile.doFilter(inFile, outFile);
		cout << "Output file created" << endl;
	}
	if (comm == 2)//Execute encrypt conversion
	{
		fileEncrypt testFile2(inpKey);
		testFile2.doFilter(inFile, outFile);
		cout << "Output file created" << endl;
	}
	if (comm == 3)//Execute all caps conversion
	{
		fileUpper testFile3(inpKey);
		testFile3.doFilter(inFile, outFile);
		cout << "Output file created" << endl;
	}
	if (comm == 4)//Execute 5 letter block conversion
	{
		modifyEncrypt testFile4(inpKey);
		testFile4.doFilter(inFile, outFile);
		cout << "Output file created" << endl;
	}
	inFile.close();
	outFile.close();
	return 0;
}

