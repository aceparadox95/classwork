#include "fileFilter.h"

#ifndef MODIFYENCRYPT_H
#define MODIFYENCRYPT_H
class modifyEncrypt : public fileFilter
{
public:
	modifyEncrypt(int inpKey);
	void doFilter(ifstream &in, ofstream &out);
	virtual char transform(char Ch);
};
#endif