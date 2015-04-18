/* CS261- Assignment 2 - Calc.c*/
/* Name: Ryan Cosby
* Date: 4/17/2015
* Solution description:
* This program implements a stack container type as the
* backbone of a reverse polish notation calculator
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "dynamicArray.h"


/* param: s the string
   param: num a pointer to double
   returns: true (1) if s is a number else 0 or false.
   postcondition: if it is a number, num will hold
   the value of the number
*/
int isNumber(char *s, double *num)
{
	char *end;
	double returnNum;

	if(strcmp(s, "0") == 0)
	{
		*num = 0;
		return 1;
	}
	else 
	{
		returnNum = strtod(s, &end);
		/* If there's anythin in end, it's bad */
		if((returnNum != 0.0) && (strcmp(end, "") == 0))
		{
			*num = returnNum;
			return 1;
		}
	}
	return 0;  //if got here, it was not a number
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their sum is pushed back onto the stack.
*/
void add (struct DynArr *stack)
{
	double sum = 0.0;
	if (sizeDynArr(stack) == 2)
	{
		sum += topDynArr(stack);
		popDynArr(stack);
		sum += topDynArr(stack);
		popDynArr(stack);
		pushDynArr(stack, sum);
	}
	else
		printf("You may only add two values at a time\n");

}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack)
{
	double diff1 = 0.0;
	double diff2 = 0.0;
	if (sizeDynArr(stack) == 2)
	{
		diff2 = topDynArr(stack);
		popDynArr(stack);
		diff1 = topDynArr(stack);
		popDynArr(stack);
		pushDynArr(stack, diff1 - diff2);
	}
	else
		printf("You may only subtract two values at a time\n");
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack)
{
	double num = 0.0;
	double denom = 0.0;
	if (sizeDynArr(stack) == 2)
	{
		denom = topDynArr(stack);
		popDynArr(stack);
		num = topDynArr(stack);
		popDynArr(stack);
		pushDynArr(stack, num / denom);
	}
	else
		printf("You may only divide two values at a time\n");
}

/*	param: stack the stack being manipulated
pre: the stack contains at least two elements
post: the top two elements are popped and
their product is pushed back onto the stack.
*/
void multiply(struct DynArr *stack)
{
	double mult1 = 0.0;
	double mult2 = 0.0;
	if(sizeDynArr(stack) == 2)
	{
		mult1 = topDynArr(stack);
		popDynArr(stack);
		mult2 = topDynArr(stack);
		popDynArr(stack);
		pushDynArr(stack, mult1 * mult2);
	}
	else
		printf("You may only multiply two values at a time\n");
}

/*	param: stack the stack being manipulated
pre: the stack contains at least two elements
post: the top two elements are popped and
their the first element is raised to the power
of the second element
*/
void power(struct DynArr *stack)
{
	double base = 0.0;
	double exp = 0.0;
	if (sizeDynArr(stack) == 2)
	{
		exp = topDynArr(stack);
		popDynArr(stack);
		base = topDynArr(stack);
		popDynArr(stack);
		pushDynArr(stack, pow(base,exp));
	}
	else
		printf("You have entered an invalid power command. Base or Exponent Needed\n");
}

/*	param: stack the stack being manipulated
pre: the stack contains at least one element
post: the element is squared then added back
to the stack
*/
void squared(struct DynArr *stack)
{
	double square = 0.0;
	if (sizeDynArr(stack) == 1)
	{
		square = topDynArr(stack);
		popDynArr(stack);
		pushDynArr(stack, pow(square, 2.0));
	}
	else
		printf("You have entered an invalid square command. Only one value expected\n");
}

/*	param: stack the stack being manipulated
pre: the stack contains at least one element
post: the element is cubed then added back
to the stack
*/
void cubed(struct DynArr *stack)
{
	double cube = 0.0;
	if (sizeDynArr(stack) == 1)
	{
		cube = topDynArr(stack);
		popDynArr(stack);
		pushDynArr(stack, pow(cube, 3.0));
	}
	else
		printf("You have entered an invalid cube command. Only one value expected\n");
}

/*	param: stack the stack being manipulated
pre: the stack contains at least one element
post: the absolute value of element is added
to the stack
*/
void absolute(struct DynArr *stack)
{
	double absolute = 0.0;
	if (sizeDynArr(stack) == 1)
	{
		absolute = topDynArr(stack);
		popDynArr(stack);
		if (absolute > 0)
			pushDynArr(stack, absolute);
		else
			pushDynArr(stack, absolute * -1);
	}
	else
		printf("You have entered an invalid ABS command. Only one value expected\n");
}
/*	param: stack the stack being manipulated
pre: the stack contains at least one element
post: the square root of element is added
to the stack
*/
void squareroot(struct DynArr *stack)
{
	double root = 0.0;
	if (sizeDynArr(stack) == 1)
	{
		root = topDynArr(stack);
		popDynArr(stack);
		pushDynArr(stack, sqrt(root));
	}
	else
		printf("You have entered an invalid SQRT command. Only one value expected\n");
}
/*	param: stack the stack being manipulated
pre: the stack contains at least two elements
post: the first element is popped and is the
exponent of the E base
*/
void exponential(struct DynArr *stack)
{
	double exp = 0.0;
	if (sizeDynArr(stack) == 1)
	{
		exp = topDynArr(stack);
		popDynArr(stack);
		pushDynArr(stack, pow(2.7182818, exp));
	}
	else
		printf("You have entered an invalid EXP command. Only one value expected\n");
}

/*	param: stack the stack being manipulated
pre: the stack contains at least two elements
post: the first element is popped and its natural
log is added to the stack
*/
void ln(struct DynArr *stack)
{
	double natLog = 0.0;
	if (sizeDynArr(stack) == 1)
	{
		natLog = topDynArr(stack);
		popDynArr(stack);
		pushDynArr(stack, log(natLog));
	}
	else
		printf("You have entered an invalid Log command. Only one value expected\n");
}
/*	param: stack the stack being manipulated
pre: the stack contains at least two elements
post: the first element is popped and its base 10
log is added to the stack
*/
void commonlog(struct DynArr *stack)
{
	double baseLog = 0.0;
	if (sizeDynArr(stack) == 1)
	{
		baseLog = topDynArr(stack);
		popDynArr(stack);
		pushDynArr(stack, log10(baseLog));
	}
	else
		printf("You have entered an invalid Log command. Only one value expected\n");
}
double calculate(int numInputTokens, char **inputString)
{
	int i;
	double result = 0.0;
	char *s;
	struct DynArr *stack;

	//set up the stack
	stack = createDynArr(20);

	// start at 1 to skip the name of the calculator calc
	for(i=1;i < numInputTokens;i++) 
	{
		s = inputString[i];

		// Hint: General algorithm:
		// (1) Check if the string s is in the list of operators.
		//   (1a) If it is, perform corresponding operations.
		//   (1b) Otherwise, check if s is a number.
		//     (1b - I) If s is not a number, produce an error.
		//     (1b - II) If s is a number, push it onto the stack

		if(strcmp(s, "+") == 0)
			add(stack);
		else if(strcmp(s,"-") == 0)
			subtract(stack);
		else if(strcmp(s, "/") == 0)
			divide(stack);
		else if(strcmp(s, "x") == 0)
			/* FIXME: replace printf with your own function */
			multiply(stack);
		else if(strcmp(s, "^") == 0)
			/* FIXME: replace printf with your own function */
			power(stack);
		else if(strcmp(s, "^2") == 0)
			/* FIXME: replace printf with your own function */
			squared(stack);
		else if(strcmp(s, "^3") == 0)
			/* FIXME: replace printf with your own function */
			cubed(stack);
		else if(strcmp(s, "abs") == 0)
			/* FIXME: replace printf with your own function */
			absolute(stack);
		else if(strcmp(s, "sqrt") == 0)
			/* FIXME: replace printf with your own function */
			squareroot(stack);
		else if(strcmp(s, "exp") == 0)
			/* FIXME: replace printf with your own function */
			exponential(stack);
		else if(strcmp(s, "ln") == 0)
			/* FIXME: replace printf with your own function */
			ln(stack);
		else if(strcmp(s, "log") == 0)
			/* FIXME: replace printf with your own function */
			commonlog(stack);
		else 
		{
			if (strcmp(s, "pi") == 0)
				pushDynArr(stack, 3.14159265);
			else if (strcmp(s, "e") == 0)
				pushDynArr(stack, 2.7182818);
			else
			{
				double tempNum;
				if (isNumber(s, &tempNum))
					pushDynArr(stack, tempNum);
				else
				{
					printf("You have entered an invalid command: %s\n",s);
					break;
				}

			}
		}
	}	//end for 

	/* FIXME: You will write this part of the function (2 steps below) 
	 * (1) Check if everything looks OK and produce an error if needed.
	 * (2) Store the final value in result and print it out.
	 */
	if (sizeDynArr(stack) == 1)
	{
		result = topDynArr(stack);
		popDynArr(stack);
	}
	else
	{
		result = 0.0;
		printf("Invalid Command:");
		for (int i = 0; i < sizeDynArr(stack); i++)
			printf(" %g", getDynArr(stack, i));
		printf(" %s\n", s);
	}
	deleteDynArr(stack);
	return result;
}

int main(int argc , char** argv)
{
	// assume each argument is contained in the argv array
	// argc-1 determines the number of operands + operators
	if (argc == 1)
		return 0;
	double calc = 0.0;
	calc = calculate(argc, argv);
	printf("Calculation: %g\n" ,calc);
	return 0;
}
