/***************************************************************
 * Author: Ryan Cosby
 * Date Created: 11/21/2014
 * Last Modification Date: 11/21/2014
 * File name: carLot.cpp
 *
 * Overview:
 * This a car lot inventory program. The user can add car types and
 * then type in information associated with each car
 *
 * Input:
 * User chooses to list vehicles, add cars, or print total revenue
 * based on certain month and year.
 *
 * Output:
 * List Vehicles or Print Revenue
 * **************************************************************/ 

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <cctype>
using namespace std;

struct Date
{
	int day, month, year; // date members
};

struct Car //vehicle info
{
	string make, model;
	int year; 
	Date datePurchased, dateSold;
	double purchasePrice, salePrice;
	bool isSold;
};

int checkMonth(int month) //month validator
{
	if((month >= 1) && (month <= 12))//base case
		return month;
	else
	{
	   cout << "Please enter a valid month (1-12): ";
	   cin >> month;
	   cout << endl;
	   checkMonth(month);//function recursively called until fixed
	}
}

int checkDay(int month, int day) //day validator
{
	int maxDay = 0; //store maximum day of month
	if (day > 0)//checks for negative value
	{
		if((month == 1)||(month == 3)||(month == 5)||(month == 7)||(month == 8)||(month == 10)||(month == 12))
			maxDay = 31; //31 day months
		else if(month != 2)
			maxDay = 30; //30 day months
		else
			maxDay = 28; //February
		if (day > maxDay)//Checks for value larger than max day
		{
			cout << "Please enter a valid day: (1-" << maxDay << ")" << endl;
			cin >> day;
			checkDay(month,day);//function recursively called until fixed
		}
		else
			return day;
	}
	else
	{
		cout << "Please enter a valid date greater than 0" << endl;
		cin >> day;
		checkDay(month,day);//function recursively called until fixed
	}
}

void addCars(vector<Car> &cInv) //pass car vector by reference
{
	Car tempCar; //temporary car variable
	char testChar;
	cout << "What is the make of the car? " << endl; //gathering vehicle information↓↓↓↓
	cin >> tempCar.make;
	cout << "What is the model of the car? " << endl;
	cin >> tempCar.model;
	cout << "What is the model year of the car? " << endl;
	cin >> tempCar.year;
	cout << "What month was the car purchased? " << endl;
	cin >> tempCar.datePurchased.month;
	tempCar.datePurchased.month = checkMonth(tempCar.datePurchased.month);//validate month
	cout << "What day was the car purchased? " << endl;
	cin >> tempCar.datePurchased.day;
	tempCar.datePurchased.day = checkDay(tempCar.datePurchased.month,tempCar.datePurchased.day); // validate day
	cout << "What year was the car purchased? " << endl;
	cin >> tempCar.datePurchased.year;
	cout << "What was the purchase price?" << endl;
	cin >> tempCar.purchasePrice;
	cout << "Has the car been sold? (y or n)" << endl;
	cin >> testChar;
	if (testChar == 'y') //gathering sale information↓↓↓↓
	{
	    tempCar.isSold = true;
	    cout << "What month was the car sold?"<< endl;
	    cin >> tempCar.dateSold.month;
		tempCar.dateSold.month = checkMonth(tempCar.dateSold.month); //validate month
	    cout << "What day was the car sold?"<< endl;
	    cin >> tempCar.dateSold.day;
		tempCar.dateSold.day = checkDay(tempCar.dateSold.month,tempCar.dateSold.day); //validate day
	    cout << "What year was the car sold?"<< endl;
	    cin >> tempCar.dateSold.year;
	    cout << "What was the sale price?"<< endl;
	    cin >> tempCar.salePrice;
	}
	else
		tempCar.isSold = false;
	cInv.push_back(tempCar); // add to end of car vector
}
void listCars(vector<Car> &cInv)
{
	for (int i = 0; i < cInv.size(); i++) //print car listing
	{
		cout << "<<<<<CAR " << i+1 << " OF " << cInv.size() << ">>>>>" << endl; //listing header
		cout << "Make: " << setw(4) << cInv[i].make;
		cout << " Model: " << setw(4) << cInv[i].model;
		cout << " Model Year: " << setw(4) << cInv[i].year << endl;
		cout << "Purchase Date:" << setw(5) << cInv[i].datePurchased.month << "/" << cInv[i].datePurchased.day << "/" << cInv[i].datePurchased.year;
		cout << "   Purchase Price:" << setw(4) << "$" << fixed << setprecision(2) << cInv[i].purchasePrice << endl;
		if (cInv[i].isSold) // print sale information if its there
		{
			cout << "Sold Date:"<<  setw(9) <<  cInv[i].dateSold.month << "/" << cInv[i].dateSold.day << "/" << cInv[i].dateSold.year;
			cout << "   Sale Price: " << setw(7) << "$" << fixed << setprecision(2) << cInv[i].salePrice << endl;
		}
		else
			cout << "Car has not been sold \n";
		cout << endl;
	}
}

void monthQuery(vector<Car> &cInv)
{
	double monthProfit = 0;
	int month = 0, year = 0;
	cout << "What month of the year do you want the total profit report for? ";
	cin >> month;
	month = checkMonth(month);
	cout << "What year do you want the total profit report for? ";
	cin >> year;
	for (int i = 0; i < cInv.size(); i++) 
	{
	    if (cInv[i].isSold) // checks for only sold vehicles
	    {
		if ((month == cInv[i].dateSold.month) && (year == cInv[i].dateSold.year)) // checks for correct month/year
			monthProfit+= cInv[i].salePrice - cInv[i].purchasePrice; //collect profit values
	    }
	}
	cout << "Total Profit for " << month << "/" << year << " was: " << setw(2) << "$" << fixed << setprecision(2) << monthProfit << endl; // print profit
}

int main()
{
    char comm; //value to store command
	vector<Car> carInv; //vector of Cars
	while(comm != 'Q')
	{
		cout << "***********************************************************************"<< endl; //menu options
		cout << "Enter <A> to add a car to your car lot" << endl;
		cout << "Enter <L> to list the cars in your car lot" << endl;
		cout << "Enter <P> to display total profit during a certain month" << endl;
		cout << "Enter <Q> to exit the program" << endl;
		cout << "***********************************************************************"<<endl;
		cin >> comm;
		if (comm == 'A')
			addCars(carInv); //run add car function
		if (comm == 'L')
			listCars(carInv); // run list car function
		if (comm == 'P')
			monthQuery(carInv); // run profit month query
	}
	return 0;
}