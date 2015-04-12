/* CS261- Assignment 1 - Q.3*/
/* Name:Ryan Cosby
 * Date:4/11/2015
 * Solution description:
 * Pratice with sorting an array of integer values
 */
 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/**************************************************************
* Entry: A pointer to a int array, and the size of the array.
* 
* Exit: Array is sorted in ascending order using the selection
* sort method.
* 
* Purpose: To show how arrays can be sorted in C language
*
***************************************************************/
void sort(int* number, int n){
     /*Sort the given array number , of length n*/
	/*Selection Sort taken from this source:*/
	/*http://www.programmingsimplified.com/c/source-code/c-program-selection-sort*/
	int position, swap;
	for (int i = 0; i < (n - 1); i++) 
	{
		position = i;
		for (int q = i + 1; q < n; q++)
		{
			if (number[position] > number[q])
				position = q;
		}
		if (position != i)
		{
			swap = number[i];
			number[i] = number[position];
			number[position] = swap;
		}
	}
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
	int n = 20;
    /*Allocate memory for an array of n integers using malloc.*/
	int *arr = malloc(n * (sizeof(n)));
    /*Fill this array with random numbers, using rand().*/
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 100 + 1;
    /*Print the contents of the array.*/
	for (int i = 0; i < n; i++)
		printf("%d: %d\n", i+1, arr[i]);
    /*Pass this array along with n to the sort() function of part a.*/
	sort(arr, n);
    /*Print the contents of the array.*/
	printf("\n\nNow sorted: \n");
	for (int i = 0; i < n; i++)
		printf("%d: %d\n", i+1, arr[i]);
    return 0;
}
