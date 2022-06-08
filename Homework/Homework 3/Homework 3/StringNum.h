#ifndef STRINGNUM_H
#define STRINGNUM_H

#include <string>

using namespace std;

class StringNum
{
private:
	string inputData;
	int numType; //type 1 will be int, type 2 will be written form, type 3 will be a sum, type 4 will be a difference
	int setNumType(); //only accessed by constructor

public:
	StringNum(string); //parameter constructor

	string getInputData();

	
	virtual int getNumType();
};

#endif
