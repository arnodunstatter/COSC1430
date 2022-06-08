#ifndef ERROROBJECT_H
#define ERROROBJECT_H
#include "RawObject.h"
class ErrorObject: public RawObject
{
public:
	ErrorObject(string line, string outputFile);
	void writer();
};

#endif