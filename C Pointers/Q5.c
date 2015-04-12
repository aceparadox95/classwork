/* CS261- Assignment 1 - Q.5*/
/* Name: Ryan Cosby
 * Date: 4/11/2015
 * Solution description:
 * This assignment is meant to help practice with C style strings and
 * altering individual characters of the strings to the STICKY case.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*converts ch to upper case, assuming it is in lower case currently*/
 /*This function is not used in my program*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
/*This function is not used in my program*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}
/**************************************************************
* Entry: A pointer to a C style string
* 
* Exit: Alternating characters of string are capitalized or lowercased
* 
* Purpose: To alter a string and to show how it can be edited
*
***************************************************************/
void sticky(char* word){
     /*Convert to sticky caps*/
	int length = strlen(word); //finds the length of the string
	for (int i = 0; i < length; i++) // iterates through string
	{
		if (i % 2 == 0) //if string is even index its capitalized, otherwise its not
			word[i] = toupper(word[i]);
		else
			word[i] = tolower(word[i]);
	}
}

int main(){
    /*Read word from the keyboard using scanf*/
	char str[30]; //allocate a string
	scanf("%s", &str); //read keyboard input
    /*Call sticky*/
	sticky(&str);
    /*Print the new word*/
	printf("%s\n", str);
    return 0;
}
