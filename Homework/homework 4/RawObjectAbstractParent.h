#ifndef RAWOBJECTABSTRACTPARENT_H
#define RAWOBJECTABSTRACTPARENT_H
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <typeinfo>

using namespace std; 

class RawObjectAbstractParent
{
public:
	virtual void writer() = 0;
};

#endif
