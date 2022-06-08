#ifndef RSA_H
#define RSA_H
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
class RSA
{
private:
	int key; //will act as the power in modulo function
	int modulus;
	int modulo(int base, int power, int modulus); //used for improving calculation time when computing the modulus of a number raised to a power


public:
	RSA(int key, int modulus);
	~RSA();
	void crypt(string inFile, string outFile);
};
#endif
