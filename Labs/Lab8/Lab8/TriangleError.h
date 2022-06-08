#ifndef TRIANGLEERROR_H
#define TRIANGLEERROR_H
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;

class TriangleError: public invalid_argument
{
private:
	int errorType;
public:
	TriangleError(int errorType);
	string message();
};

#endif
