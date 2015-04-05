#include "fileEncrypt.h"

fileEncrypt::fileEncrypt(int Key)//default constructor
{
	encKey = Key;
}
char fileEncrypt::transform(char ch)
{
	if (ch >= 65 && ch <=90)//Capital Letters
		return (ch + encKey) % 26 + 65;
	else if (ch >= 97 && ch <= 122)//Lowercase Letters
		return (ch + encKey) % 26 + 97;
	else if (ch == 10) //No encryption of new line numbers
		return ch;
	else
		return (ch + encKey) % 26;
}