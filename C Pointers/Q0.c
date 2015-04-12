/* CS261- Assignment 1 - Q. 0*/
/* Name:Ryan Cosby
 * Date: 4/11/2015
 * Solution description:
 * This program is for help in understand the difference between pointers, values
 * being pointed to, addresses of those values, and the address of the pointer
 * iteself
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
	printf("Value pointed to by pointer: %d \n",*iptr);
     /*Print the address pointed to by iptr*/
	printf("Address pointed to by pointer: %p \n", iptr);
     /*Print the address of iptr itself*/
	printf("Address of pointer: %p\n", &iptr);
}

int main(){
    
    /*declare an integer x*/
	int x;
    /*print the address of x*/
	printf("Address of x: %p \n", &x);
    /*Call fooA() with the address of x*/
	fooA(&x);
    /*print the value of x*/
	printf("Value of x: %d \n", x);
    return 0;
}
