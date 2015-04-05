#include "fileUnchanged.h"

fileUnchanged::fileUnchanged(int Key)//default constructor
{
	encKey = Key;
}
char fileUnchanged::transform(char ch)
{
	return ch;//dont change character and return it
}