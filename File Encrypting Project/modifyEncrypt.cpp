#include "modifyEncrypt.h"

using std::cout;
using std::endl;

modifyEncrypt::modifyEncrypt(int Key)
{
	encKey = Key;
}
void modifyEncrypt::doFilter(ifstream &in, ofstream &out)
{
	if (!in) //check to see if file exists
	{
		cout << "The input file does not exist" << endl;
	}
	if (!out)
	{
		cout << "The output file does not exist" << endl;
	}
	char ch;
	in.get(ch);//grab first character from input file
	int count = 0;
	while (!in.fail())//go through file until the end
	{
		if (ch == ' ')//if character is a space skip it
			in.get(ch);
		else
		{
			count++;
			if (count % 6 == 0)//creates extra space for blocks of 5 letters
				out.put(' ');
			else
			{
				if (ch == 10)//restart count if a newline character is found
					count = 0;
				ch = transform(ch);
				out.put(ch);
				in.get(ch);
			}
		}
	}
}
char modifyEncrypt::transform(char ch)
{
	ch = toupper(ch);
	if (ch >= 65 && ch <= 90) // Capital Letters in ASCII table
		return (ch + encKey) % 26 + 65;
	else if (ch >= 97 && ch <= 122) //Lowercase Letters in ASCII table
		return (ch + encKey) % 26 + 97;
	else if (ch == 10) //No encryption of new line numbers decided to keep them in
		return ch;
	else // if the value isnt a letter then just return
		return (ch + encKey) % 26;
}