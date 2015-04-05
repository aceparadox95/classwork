/*****************************
 * Author: Ryan Cosby
 * Date Created: 10/2/2014
 * Last Modification Date: 10/2/2014
 * File name: echo.cpp
 *
 * Overview:
 * This program asks the user to input a number and prints that number 
 * on the console screen
 *
 * Input:
 * Integer value from user stored in integer variable.
 *
 * Output:
 * Integer value is printed on the screen. If the user enters a value
 * that is not a number the programs prints the original value of "42"
 * that was assigned to the variable prior to user entry
 * **************************************************************/ 

 # include <iostream>// This is a code library used to print code to the screen

int main()   //This is a special  function of the int
{// Begin function
   int input_value; //declare integer variable
   input_value = 42; //asigns value of 42 to variable
   std::cout << "Please enter a number to be printed: ";//instruct the user
   std::cin >> input_value; //stores input from user in the input value variable
   std::cout << "You entered: "<< input_value<< std::endl;  // this is a statement using the "output stream"
   return 0; //returns false with no errors
}//end function
