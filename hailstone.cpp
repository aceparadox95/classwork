/*****************************
 * Author: Ryan Cosby
 * Date Created: 10/30/2014
 * Last Modification Date: 10/30/2014
 * File name: hailstone.cpp
 *
 * Overview:
 * This program takes the input value an tries to reduce it down
 * to 1 by dividing the value by 2. If the value is even it divides
 * it directly. If its odd it has to multiply it by 3 then add 1,
 * before the division process begins.
 * 
 * Input:
 * Asks user for input integer
 *
 * Output:
 * Prints the sequence and the number of steps in the sequence to
 * get it back to 1.
 * **************************************************************/ 
#include <iostream>
using namespace std;

int hail(int i)
{
    static int count = 0; //need to use static value so that the count doesn't
						  // reset with each recursion
    if (i == 1) //check for base case of 1
    {
        cout << i << endl; // print sequence
        return count; // return count after satisfying base case
    }
    count++; // once it make it to this step increment the count
    if ((i % 2) == 0) // check for even number
    {
        cout << i << endl;
        hail(i / 2); //recursive call using half the original number
    }
    else // check for odd
    {
        cout << i << endl;
        hail((i * 3) + 1); //multiply by 3 and add 1
    }
}

int main()
{
    int num; //store number
    cout << "Enter a number: "; //prompt user
    cin >> num; //store input
    cout << endl << hail(num) << " steps.\n"; //print result
}