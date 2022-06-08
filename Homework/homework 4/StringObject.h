#ifndef STRINGOBJECT_H
#define STRINGOBJECT_H
#include "RawObject.h"
class StringObject: public RawObject
{
private:
	bool charIsPresent(const string& searchIn, char searchFor);
public:
	StringObject(string line, string outputFile);
	void writer();

};

#endif