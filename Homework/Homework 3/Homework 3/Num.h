#ifndef NUM_H
#define NUM_H
#include "StringNum.h"

class Num :
	public StringNum
{
private:
	int num;
public:
	Num(string);
	int setNum(string);
	int getNum();
};

#endif