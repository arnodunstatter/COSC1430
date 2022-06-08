#ifndef COUNSTER_H
#define COUNSTER_H
#include <iostream>
using namespace std;

class Countster
{
private: 
	int alphaCount, numCount;
public: 
	Countster(); //we only want a default constructor
	~Countster();
	
	void count(string text);

	int getAlpha();
	int getNum();
};

#endif