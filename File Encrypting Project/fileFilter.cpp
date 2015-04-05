#include "fileFilter.h"
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;
fileFilter::fileFilter()//default constructor
{
	encKey = 1;
}
fileFilter::fileFilter(int inpencKey)//constructor with input key
{
	encKey = inpencKey;
}
void fileFilter::doFilter(ifstream &in, ofstream &out)
{
	if (!in)
	{
		cout << "The input file does not exist" << endl;
	}
	if (!out)
	{
		cout << "The output file does not exist" << endl;
	}
	char ch;
	in.get(ch);//read first character
	while (!in.fail())
	{
		ch = transform(ch);//run transform function
		out.put(ch);
		in.get(ch);
	}
}
char fileFilter::transform(char ch)
{
	return ch;
}
int fileFilter::getKey()
{
	return encKey;
}

