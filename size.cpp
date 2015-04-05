/*****************************
 * Author: Ryan Cosby
 * Date Created: 10/22/2014
 * Last Modification Date: 10/22/2014
 * File name: size.cpp
 *
 * Overview:
 * This program generates a hat, jacket, and waist size
 * based on age, height (in inches), and weight
 * Input:
 * Asks user for age, height, and weight
 * 
 *
 * Output:
 * Tells user hat, jacket, and waist size
 * **************************************************************/ 

#include <iostream>
#include <cctype>
using namespace std;

float hat_size(float pounds, float inches) // Hat Size Function
{
return ((pounds / inches) * 2.9); // Hat Size Formula
}

float jacket_size(float inches, float pounds, float years) // Jacket Size Function
{
float jacketsize;
jacketsize = (inches * pounds) / 288;
while (((years-30) / 10) >= 1)//loop to add 1/8 inches for every 10 years over 30
{
	years -= 10;
	jacketsize += 0.125;
}
return jacketsize;
}

float waist_size(float pounds, float years) // Waist Size Function
{
float waistsize;
waistsize = pounds / 5.7;
while (((years-28) / 2) >= 1)// loop to add .1 inches for every 2 years over 28
{
	years -= 2;
	waistsize += 0.1;
}
return waistsize; //return final value
}

int main()
{
float height, weight, age; //decimal value storage of height, weight, age
char userState = 'Y';

while (userState == 'Y')
{
	cout << "How tall are you(inches)?  "; // user prompt for height
	cin >> height;
	cout << "\nHow much do you weigh(lbs)? "; // user prompt for weight
	cin >> weight;
	cout << "\nWhat is your age(years)? "; // user prompt for age
	cin >> age;
	cout << "\nYour hat size is: "<< hat_size(weight,height);
	cout << "\nYour jacket size is: "<< jacket_size(height,weight,age);
	cout << "\nYour waist size is: "<< waist_size(weight,age);
	cout << "\nWould you like to do another calculation (Y or N)? ";
	cin >> userState; // change user state based on input
	userState = toupper(userState); //standardize user input
}
return 0;
}