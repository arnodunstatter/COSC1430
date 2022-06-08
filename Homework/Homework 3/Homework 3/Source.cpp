#include <iostream>
#include <fstream>
#include <string>
#include "ArgumentManager.h"
#include "StringNum.h"
#include "Num.h"

using namespace std;


int main(int argc, char** argv)
{
	if (argc < 3)
	{
		cout << "You must call this program with at least two arguments after main. Specifically you should pass an input-file name, and an output-file name.\n" << endl;
		cout << "Program ending. Try again.\n";
		return 0;
	}
	
	ArgumentManager am(argc, argv); //creates our ArgumentManager object, 'am'

	//these will get the input and output file names
	string inputFile = am.get("input");
	string outputFile = am.get("output");
	
	ifstream read; //establishes our ifstream object for reading data in
	read.open(inputFile.c_str()); //attempts to open our inputFile

	bool isMatch = 0; //default is false
	int numLines = 0;

	

	string temp; //will temporarily hold each line from our inputFile
	if (read.is_open())
	{
		int index = 0; //the while loop will load Num.num values into a values
		
		//finding our number of lines
		while (getline(read, temp))
			++numLines;
		
		int* values = new int[numLines]; //array of our integer values from the input file, stored in the heap

		//next two lines are to reset our reading pointer back to beginning
		read.close(); 
		read.open(inputFile.c_str()); 

		while (getline(read, temp)) //loads our dynamic array named values with an integer representation of each number in the file
		{
			Num* standIn = new Num(temp); //dummy object
			*(values + index) = standIn->getNum(); //loads each int representation into our dynamic array
			
			delete standIn; //deletes our dummy object
			++index; //this will execute one more time at the very end, so it will be size(values) + 1, we must decrement it
		}
	


		//now we determine if all the values in our array are the same:
		
		if (index > 1) 
		{
			for (int i = 0; i < index; ++i)
			{
				if (*values != *(values + i))
				{
					isMatch = 0;
					break;
				}
				else
					isMatch = 1;
			}
		}
		

		delete [] values; //deallocates memory in our heap

		read.close();
		
	}
	else
		cout << inputFile << " was not opened properly.\n";

	read.close();

	if (isMatch)
		cout << "Match!";
	else
		cout << "No match!";

	ofstream write;
	write.open(outputFile.c_str());
	if (write.is_open())
	{
		if (isMatch)
			write << "match";
		else if (!isMatch)
			write << "not match";
		write.close();
	}
	else
		cout << "Error. File could not be opened for writing to.\n";
	
	return 0;
}
