/* CS261- Assignment 1 - Q.1*/
/* Name: Ryan Cosby
 * Date: 4/11/2015
 * Solution description:
 * This program helps the user undersstand how to allocate memory for a struct,
 * how to assign values to struct members, and how to access members of a struct.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student{
	int id;
	int score;
};

/**************************************************************
* Entry: None
* 
* Exit: Allocates an array of 10 students
* 
* Purpose: To create na array which later  be used throughout
* the program
*
***************************************************************/
struct student* allocate(){
     /*Allocate memory for ten students*/
	struct student *stud10 = malloc(10 * sizeof(struct student));
     /*return the pointer*/
	return stud10;
}

/**************************************************************
* Entry: A pointer to a student struct array is needed
* 
* Exit: ID and Score members of struct elements are assigned
* a value
* 
* Purpose: To generate random scores and ID for students
*
***************************************************************/
void generate(struct student* students){
     /*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		students[i].id = rand() % 10 + 1;
		students[i].score = rand() % 100 + 1;
	}
}
/**************************************************************
* Entry: A pointer to a student struct array is needed
* 
* Exit: Prints the ID and Score struct student array values
* 
* Purpose: To display content of array elements (students)
*
***************************************************************/
void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
	for (int i = 0; i < 10; i++)
	{
		printf("%d", students[i].id);
		printf(" %d\n", students[i].score);
	}
}
/**************************************************************
* Entry: A pointer to a student struct array is needed
* 
* Exit: Prints the average, max, and min of student array scores
* 
* Purpose: To display average, max, and min
*
***************************************************************/
void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
	int min = students[0].score, max = students[0].score, checkScore = students[0].score, sum = 0;
	float average;
	//checkScore = students[0].score;
	for (int i = 0; i < 10; i++)
	{
		checkScore = students[i].score;
		sum+= checkScore;
		if (checkScore < min)
			min = checkScore;
		else if(checkScore > max)
			max = checkScore;	
	}
	average = (float)sum / 10;
	printf("Average Score: %g\n", average);
	printf("Maximum Score: %d\n", max);
	printf("Minimum Score: %d\n", min);
}
/**************************************************************
* Entry: A pointer to a student struct array is needed
* 
* Exit: Struct is removed from memory
* 
* Purpose: To clean the memory before exiting the program
*
***************************************************************/
void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
	if (stud != 0)
	{
		free(stud);
		stud = 0;
	}
}

int main(){
    struct student* stud = NULL;
    /*call allocate*/
	stud = allocate();
    /*call generate*/
	generate(stud);
    /*call output*/
	output(stud);
    /*call summary*/
	summary(stud);
	/*call deallocate*/
	deallocate(stud);
    return 0;
}
