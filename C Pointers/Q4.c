/* CS261- Assignment 1 - Q.4*/
/* Name: Ryan Cosby
 * Date: 4/11/2015
 * Solution description:
 * This solution combines the functionality found in both Q1.c
 * and Q3.c. The purpose is see how you can sort struct arrays
 * based on one of its members.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct student{
	int id;
	int score;
};
/**************************************************************
* Entry: A pointer to a student array, and the size of the array.
* 
* Exit: Array is sorted in ascending order of student scores
* using the selection sort method.
* 
* Purpose: To show how struct arrays can be sorted in C language
*
***************************************************************/
void sort(struct student* students, int n){
     /*Sort the n students based on their score*/
	/*Selection Sort taken from this source:*/
	/*http://www.programmingsimplified.com/c/source-code/c-program-selection-sort*/
	int position;
	struct student swap;
	for (int i = 0; i < (n - 1); i++)
	{
		position = i;
		for (int q = i + 1; q < n; q++)
		{
			if (students[position].score > students[q].score)
				position = q;
		}
		if (position != i)
		{
			swap = students[i];
			students[i] = students[position];
			students[position] = swap;
		}
	}
}

int main(){
    /*Declare an integer n and assign it a value.*/
	int n = 5;
    /*Allocate memory for n students using malloc.*/
	struct student *stud5 = malloc(n * sizeof(struct student));
    /*Generate random IDs and scores for the n students, using rand().*/
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		stud5[i].id = rand() % 10 + 1;
		stud5[i].score = rand() % 100 + 1;
	}
    /*Print the contents of the array of n students.*/
	printf("Before Sort: \n");
	for (int i = 0; i < n; i++)
	{
		printf("Student: %d", stud5[i].id);
		printf(" Score: %d\n", stud5[i].score);
	}
    /*Pass this array along with n to the sort() function*/
	sort(stud5, n);
    /*Print the contents of the array of n students.*/

	printf("\nAfter Sort: \n");
	for (int i = 0; i < n; i++)
	{
		printf("Student: %d", stud5[i].id);
		printf(" Score: %d\n", stud5[i].score);
	}
    return 0;
}
