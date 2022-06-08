#ifndef NUMOBJECT_H
#define NUMOBJECT_H
#include "RawObject.h"

template<typename T>
class NumObject: public RawObject
{
public:
	NumObject <T> (string line, string outputFile);
	void writer();
};

#endif