#include "RSA.h"

RSA::RSA(int key, int modulus)
	:key(key), modulus(modulus) {}

RSA::~RSA() {}

int RSA::modulo(int base, int power, int modulus) //used for improving calculation time when computing the modulus of a number raised to a power
{
	int temp = 1 % modulus;
	for (int i = 0; i < power; ++i) 
	{
		temp = (temp * (base % modulus) ) % modulus;
	}
	return temp;
}

void RSA::crypt(string inFile, string outFile)
{
	//next four lines establish our fstream objects and opens our input and output files
	ifstream read;
	read.open(inFile.c_str());
	ofstream write;
	write.open(outFile.c_str());

	if (read.is_open() && write.is_open()) 
	{
		string dataStr; //temp variable that will hold each block of data from inputFile
		int dataInt; //temp variable which will hold the interger version of dataStr

		//the next two variables are used to figure out if we need to output a " " after each write of data to outputFile
		int numOfInts = 0; //counts how many integers are in inFile
		int numOfOutputs = 0; //counts how many integers we've output

		while (read >> dataStr) //counts how many integers are in inFile
			++numOfInts;

		//next two lines resets the streampos pointer
		read.clear();
		read.seekg(0);
		
		while (read >> dataStr) //reads data in, converts to cypher, outputs to output file
		{
			dataInt = stoi(dataStr); //temporarily holds each block of data read from inputFile, held here as an int
			write << modulo(dataInt, key, modulus); 
			++numOfOutputs; //increments our counter
			if (numOfOutputs < numOfInts) //tests to see if we need to print a " " to our outputFile
				write << " ";			
		}

		//next two lines close files
		read.close();
		write.close();
	}
	else
		cout << "Either the input or output file did not properly open.\n"; //error message
}
