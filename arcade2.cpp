/*****************************
 * Author: Ryan Cosby
 * Date Created: 10/10/2014
 * Last Modification Date: 10/10/2014
 * File name: arcade2.cpp
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
   int candybars; // variable to store number of candy bars
   int gumballs; // variable to store number of gumballs
   cout <<"How many coupons do you have? ";//ask user for input
   cin >> coupons;// store input from user in variable

   while (coupons >= 10)// while loop to count candy bars
   {
      coupons-= 10;//decrementing coupons
      candybars+= 1;// incrementing candybars
   }
   while (coupons >= 3)//while loop to count gumballs
   {
      coupons-= 3;//decrementing remaining coupons
      gumballs+= 1;// incrementing gumballs
   } 
   cout << "You just bought " << candybars <<" candy bars and ";//report to user number
   //of candy bars
   cout << gumballs <<" gumballs." <<endl;//report to user number of gumballs
   
return 0;
}
