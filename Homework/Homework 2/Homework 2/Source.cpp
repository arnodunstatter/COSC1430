#include <fstream>
#include <string>
#include <iostream>
#include "ArgumentManager.h"
#include "Countster.h"

using namespace std;

int main(int argc, char** argv)
{
	string completeInput = "";
	string chunk; //will act as temp variable that will be itaritively loaded into completeInput


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


	//this block gets the input from the file and stores all content in completeInput
	{
		ifstream read; //establishes the read object
		read.open(inputFile.c_str()); //opens the inputFile	
	
		if (read.is_open())
		{
			while (read >> chunk)
			{
				completeInput += chunk;
			}

			read.close(); //closes inputFile
		}
		else
		{
			cout << "File did not open correctly. Program ending.\n";
			return 0;
		}
	}


	Countster ourCount; //initializes our Countster object

	ourCount.count(completeInput); //this will count all the numbers and letters and store them in the private data members alphaCount and numCount


	//this block outputs our data to our outputFile
	{
		ofstream write;
		write.open(outputFile.c_str()); //opens our outputFile 
		if (write.is_open())
		{
			write << ourCount.getNum() << endl; //outputs our number of numeric characters to the file and an endline
			write << ourCount.getAlpha() << endl; //outputs our number of alphabetic characters to the file and an endline
			write.close(); //closes file
		}
	}
	
		

	return 0;

}