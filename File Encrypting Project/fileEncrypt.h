#include "fileFilter.h"
#ifndef ENCRYPT_H
#define ENCRYPT_H
class fileEncrypt : public fileFilter
{
public:
	fileEncrypt(int inpKey);
	virtual char transform(char Ch);
};
#endif