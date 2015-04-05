#include "fileFilter.h"
#ifndef FILEUNCHANGED_H
#define FILEUNCHANGED_H
class fileUnchanged : public fileFilter
{
public:
	fileUnchanged(int inpKey);
	virtual char transform(char Ch);
};
#endif