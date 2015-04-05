/*****************************
 * Author: Ryan Cosby
 * Date Created: 10/10/2014
 * Last Modification Date: 10/10/2014
 * File name: arcade.cpp
 *
 * Overview:
 * This program ask the user to use coupons to purchase candy bars and
 * gumballs. Candy bars cost 10 coupons and gumballs cost 3 coupons. The
 * user must use all their coupons on candy bars until there is not enough
 * to purchase candy bars anymore. The remaining coupons are used to purchase
 * gumballs.
 *
 * Input:
 * Integer value from user stored in integer variable for number of coupons
 *
 * Output:
 * Number of candy bars and gumballs that were purchased
 * **************************************************************/ 
 
#include <iostream>

using namespace std;

int main()
{
   int coupons;// variable to store number of coupons
   cout <<"How many coupons do you have? ";//ask user for input
   cin >> coupons;// store input from user in variable
   cout << "You just bought " <<coupons / 10 <<" candy bars and ";//report to user number
   //of candy bars
   cout << (coupons % 10) / 3 <<" gumballs." <<endl;//report to user number of gumballs
   
return 0;
}