/* CS261- Assignment 1 - Q.2*/
/* Name: Ryan Cosby
 * Date: 4/11/2015
 * Solution description:
 * This solution is meant to help you understand the difference between
 * passing by value and passing by reference
 */
 
#include <stdio.h>
#include <stdlib.h>

/**************************************************************
* Entry: Two pointers to ints and an int
* 
* Exit: Takes the first parameter and multiplies it by 2. Takes
* the second parameter and divides it by 2. Add the two parameters
* together and returns the value.
* 
* Purpose: To display the difference between passing by value and reference
*
***************************************************************/
int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
	*a = *a * 2;
    /*Set b to half its original value*/
	*b = *b / 2;
    /*Assign a+b to c*/
	c = *a + *b;
    /*Return c*/
	return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
	int x = 5, y = 6, z = 7;
    /*Print the values of x, y and z*/
	printf("x = %d y = %d z = %d\n", x, y, z);
    /*Call foo() appropriately, passing x,y,z as parameters*/
    /*Print the value returned by foo*/
	printf("Value Returned by Foo = %d\n", foo(&x, &y, z));
    /*Print the values of x, y and z again*/
	printf("x = %d y = %d z = %d\n", x, y, z);
    /*Is the return value different than the value of z?  Why?*/
	/*The return value is different than the value of z because foo creates a copy of c, 
	  the value of c is then set equal to the sum of a the values that the a and b
	  pointers point to. c is passed to foo not as an address, so the change is
	  only made to the copy of the value*/
    return 0;
}

    
    
