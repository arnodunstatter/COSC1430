#include "StringObject.h"


bool StringObject::charIsPresent(const string& searchIn, char searchFor)
{
	bool present = false;

	for (int i = 0; i < searchIn.length(); ++i)
	{
		if (searchIn[i] == searchFor)
			present = true;
	}

	return present;
}




StringObject::StringObject(string line, string outputFile)
	:RawObject(line, outputFile) {};


void StringObject::writer() //we create our finalOutput and then write it to our outputFile
{
	try
	{
		if (!isWriteOpen)
			throw (isWriteOpen);
		string finalOutput = "";

		if (operAtorGetter() == "+") //if a character is in operand1 and operand2 we duplicate it at every position in operand1,
									 //otherwise we just accumulate each character in operand1 into finalOutput
		{
			for (int i = 0; i < operand1Getter().length(); ++i) //loads our finalOutput
			{
				if (charIsPresent(operand2Getter(), operand1Getter()[i])) //if the character at i in operand1 is in both...
				{
					finalOutput += operand1Getter()[i];  //we add to our finalOutput twice
					finalOutput += operand1Getter()[i];
				}
				else //the character is not in operand2 so we add it only once to our finalOutput
					finalOutput += operand1Getter()[i];
			}
		}

		else //we can assume operAtorGetter() would return "-" we accumulate all values which are in operand1 but not in operand2, into finalOutput
		{
			for (int i = 0; i < operand1Getter().length(); ++i) //loads our finalOutput
			{
				if (!charIsPresent(operand2Getter(), operand1Getter()[i])) //if the character at i in operand1 but not in operand2...
				{
					finalOutput += operand1Getter()[i]; //we add it to the finalOutput
				}
			}
		}

		write << finalOutput << endl;
	}
	catch (bool)
	{
		cout << outputFileGetter() << " did not open when trying to write a StringObject.\n";
	}

}