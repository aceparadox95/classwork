#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using std::ifstream;
using std::ofstream;

#ifndef FILEFILTER_H
#define FILEFILTER_H
class fileFilter
{
protected:
	int encKey;
public:
	fileFilter();
	fileFilter(int inpencKey);
	virtual void doFilter(ifstream &in, ofstream &out);
	virtual char transform(char ch);
	int getKey();
};
#endif