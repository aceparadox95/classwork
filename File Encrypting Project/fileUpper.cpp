#include "fileUpper.h"

fileUpper::fileUpper(int Key)
{
	encKey = Key;
}
char fileUpper::transform(char ch)
{
	return toupper(ch);//change to upper case
}