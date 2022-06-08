#include "ArgumentManager.h"
#include "ErrorObject.h"
#include "StringObject.h"
#include "NumObject.cpp"

using namespace std;

void processor(string, string); //will take each line and process it into output

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

	//reads in data
	ifstream read(inputFile.c_str());

	bool isReadOpen = read.is_open();

	string readLine; //will temporarily hold each line from the inputfile.

	try 
	{
		if (!isReadOpen)
			throw (isReadOpen);

		while (getline(read, readLine))
		{
			//for each data chunk we will call our processor
			processor(readLine, outputFile);
		}

		read.close();
		
	} 
	catch (bool)
	{
		cout << "InputFile did not open.\n";
	}
}

void processor(string line, string outputFile)
{
	typedef NumObject<int> IntObject;
	typedef NumObject<double> DoubleObject;
	RawObject* tempLine = new RawObject(line, outputFile);

	if (tempLine->type1Getter() == "string" || tempLine->type2Getter() == "string")
	{
		delete tempLine;
		tempLine = new StringObject(line, outputFile);
	}

	else if (tempLine->type1Getter() == "error" || tempLine->type2Getter() == "error")
	{
		delete tempLine;
		tempLine = new ErrorObject(line, outputFile);
	}

	else if (tempLine->type1Getter() == "double" || tempLine->type2Getter() == "double")
	{
		delete tempLine;
		tempLine = new DoubleObject(line, outputFile);
	}

	else //we can assume both operands have type int
	{
		delete tempLine;
		tempLine = new IntObject(line, outputFile);
	}


	tempLine->writer();
	delete tempLine;
}