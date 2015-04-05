/***************************************************************
 * Author: Ryan Cosby
 * Date Created: 11/26/2014
 * Last Modification Date: 11/28/2014
 * File name: carLot2.cpp
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

class Date
{
	private:
		int day; // date member variables
		int month;
		int year; 
	public:
		Date(); //default constructor
		Date(int,int,int); // populate constructor
		void set_day(int); // set functions
		void set_month(int);
		void set_year(int);
		int get_day();// get functions
		int get_month();
		int get_year();
};
Date::Date() //default constructor
{
	day = 0;
	month = 0;
	year = 0;
}
Date::Date(int inpDay, int inpMonth, int inpYear) // populate constructor with user input
{
	day = inpDay;
	month = inpMonth;
	year = inpYear;
}
void Date::set_day(int inpDay) //set function
{
	day = inpDay;
}
void Date::set_month(int inpMonth)//set function
{
	month = inpMonth;
}
void Date::set_year(int inpYear)//set function
{
	day = inpYear;
}
int Date::get_day()//get function
{
	return day;
}
int Date::get_month()//get function
{
	return month;
}
int Date::get_year()//get function
{
	return year;
}
class Car //vehicle info
{
	private: // member variables
		string make;
		string model;
		int modelyear; 
		Date datePurchased;
		Date dateSold;
		double purchasePrice;
		double salePrice;
		bool isSold;
	public:
		void set_make(string); // set variables
		void set_model(string);
		void set_modelyear(int);
		void set_datePurchased(Date);
		void set_dateSold(Date);
		void set_purchasePrice(double);
		void set_salePrice(double);
		void set_isSold(bool);
		string get_make(); //get variables
		string get_model();
		int get_modelyear(); 
		Date get_datePurchased();
		Date get_dateSold();
		double get_purchasePrice();
		double get_salePrice();
		bool get_isSold();		
};
void Car::set_make(string inpMake)//set function
{
	make = inpMake;
}
void Car::set_model(string inpModel)//set function
{
	model = inpModel;
}
void Car::set_modelyear(int inpModYear)//set function
{
	modelyear = inpModYear;
}
void Car::set_datePurchased(Date purchDate)//set function
{
	datePurchased = purchDate;
}
void Car::set_dateSold(Date soldDate)//set function
{
	dateSold = soldDate;
}
void Car::set_purchasePrice(double inpPurchPrice)//set function
{
	purchasePrice = inpPurchPrice;
}
void Car::set_salePrice(double inpSalePrice)//set function
{
	salePrice = inpSalePrice;
}
void Car::set_isSold(bool soldBool)//set function
{
	isSold = soldBool;
}
string Car::get_make()//get function
{
	return make;
}
string Car::get_model()//get function
{
	return model;
}
int Car::get_modelyear()//get function
{
	return modelyear;
}
Date Car::get_datePurchased()//get function
{
	return datePurchased;
}
Date Car::get_dateSold()//get function
{
	return dateSold;
}
double Car::get_purchasePrice()//get function
{
	return purchasePrice;
}
double Car::get_salePrice()//get function
{
	return salePrice;
}
bool Car::get_isSold()//get function
{
	return isSold;
}

class CarLot
{
	private: // member car vector
		vector<Car> cInv;
	public:
		void addCar(Car); //member functions
		void listCurrentInv();
		void getMonthProfit();
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

void CarLot::addCar(Car newCar) //add car function
{
	char testChar; // for testing data sts
	int tempInt, tempDay, tempMo, tempYear;
	double tempDoub;
	string tempString;
	cout << "What is the make of the car? " << endl; //gathering vehicle information using set functions↓↓↓↓
	cin >> tempString;
	newCar.set_make(tempString);
	cout << "What is the model of the car? " << endl;
	cin >> tempString;
	newCar.set_model(tempString);
	cout << "What is the model year of the car? " << endl;
	cin >> tempInt;
	newCar.set_modelyear(tempInt);
	cout << "What month was the car purchased? " << endl;
	cin >> tempMo;
	tempMo = checkMonth(tempMo);//validate month
	cout << "What day was the car purchased? " << endl;
	cin >> tempDay;
	tempDay = checkDay(tempMo,tempDay); // validate day
	cout << "What year was the car purchased? " << endl;
	cin >> tempYear;
	Date pDate(tempDay, tempMo, tempYear); //create purchase date object
	newCar.set_datePurchased(pDate); //assign purchase date to car
	cout << "What was the purchase price?" << endl;
	cin >> tempDoub;
	newCar.set_purchasePrice(tempDoub);
	cout << "Has the car been sold? (y or n)" << endl;
	cin >> testChar;
	if (testChar == 'y') //gathering sale information using set functions↓↓↓↓
	{
	    newCar.set_isSold(true);
	    cout << "What month was the car sold?"<< endl;
	    cin >> tempMo;
		tempMo = checkMonth(tempMo);
	    cout << "What day was the car sold?"<< endl;
	    cin >> tempDay;
		tempDay = checkDay(tempMo,tempDay); //validate day
	    cout << "What year was the car sold?"<< endl;
	    cin >> tempYear;
		Date sDate(tempDay, tempMo, tempYear);//create sold date object
		newCar.set_dateSold(sDate);// assign sold date object to car
	    cout << "What was the sale price?"<< endl;
	    cin >> tempDoub;
		newCar.set_salePrice(tempDoub);
	}
	else
		newCar.set_isSold(false);
	cInv.push_back(newCar); // add to end of car vector
}
void CarLot::listCurrentInv()
{
	for (int i = 0; i < cInv.size(); i++) //print car listing
	{
		cout << "<<<<<CAR " << i+1 << " OF " << cInv.size() << ">>>>>" << endl; //listing header
		cout << "Make: " << setw(4) << cInv[i].get_make(); // retrieve car information using get functions ↓↓↓
		cout << " Model: " << setw(4) << cInv[i].get_model(); 
		cout << " Model Year: " << setw(4) << cInv[i].get_modelyear() << endl; //
		cout << "Purchase Date:" << setw(5) << cInv[i].get_datePurchased().get_month() << "/" << cInv[i].get_datePurchased().get_day() << "/" << cInv[i].get_datePurchased().get_year();
		cout << "   Purchase Price:" << setw(4) << "$" << fixed << setprecision(2) << cInv[i].get_purchasePrice() << endl;
		if (cInv[i].get_isSold()) // print sale information if its there
		{
			cout << "Sold Date:"<<  setw(9) <<  cInv[i].get_dateSold().get_month() << "/" << cInv[i].get_dateSold().get_day() << "/" << cInv[i].get_dateSold().get_year();
			cout << "   Sale Price: " << setw(7) << "$" << fixed << setprecision(2) << cInv[i].get_salePrice() << endl;
		}
		else
			cout << "Car has not been sold \n";
		cout << endl;
	}
}

void CarLot::getMonthProfit()
{
	double monthProfit = 0; //variable to store profit
	int month = 0, year = 0; //temporary variables to user input
	cout << "What month of the year do you want the total profit report for? ";
	cin >> month;
	month = checkMonth(month);
	cout << "What year do you want the total profit report for? ";
	cin >> year;
	for (int i = 0; i < cInv.size(); i++) 
	{
	    if (cInv[i].get_isSold()) // checks for only sold vehicles
	    {
		if ((month == cInv[i].get_dateSold().get_month()) && (year == cInv[i].get_dateSold().get_year())) // checks for correct month/year
			monthProfit+= cInv[i].get_salePrice() - cInv[i].get_purchasePrice(); //collect profit values
	    }
	}
	cout << "Total Profit for " << month << "/" << year << " was: " << setw(2) << "$" << fixed << setprecision(2) << monthProfit << endl; // print profit
}

int main()
{
    char comm; //value to store command
	Car tempCar; //vector of Cars
	CarLot cLot;
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
			cLot.addCar(tempCar); //run add car function, pass it an empty car object
		if (comm == 'L')
			cLot.listCurrentInv(); // run list car function
		if (comm == 'P')
			cLot.getMonthProfit(); // run profit month query
	}
	return 0;
}