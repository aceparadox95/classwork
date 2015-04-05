#include "fibfactFuncs.h"
//Code Source: http://www.codeproject.com/Tips/109443/Fibonacci-Recursive-and-Non-Recursive-C
long fibR(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	return fibR(n - 1) + fibR(n - 2);
}
//Code Source: http://forum.codecall.net/topic/41540-fibonacci-with-no-recursion-for-fun/
long fibNR(int n)
{
	int prev = -1;
	int result = 1;
	int sum;
	for (int i = 0; i <= n; ++i)
	{
		sum = result + prev;
		prev = result;
		result = sum;
	}
	return result;
}
//Code Source Lab Requirements
long rfactorial(int n)
{
	if (n == 1)
		return 1;
	else
		return n * rfactorial(n-1);
}
//Code Source Lab Requirements
long factorialHelper(int n, int result) 
{ 
	if (n == 1)
		return result;
	else
		return factorialHelper(n-1, n * result);
}
//Code Source Lab Requirements
long factorial(int n)
{
	return factorialHelper(n, 1);
}