#include "fileFilter.h"

#ifndef FILEUPPER_H
#define FILEUPPER_H
class fileUpper : public fileFilter
{
public:
	fileUpper(int inpKey);
	virtual char transform(char Ch);
};
#endif