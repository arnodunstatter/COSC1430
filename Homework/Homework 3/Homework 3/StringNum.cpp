#include "StringNum.h"

StringNum::StringNum(string inputData) //parameter constructor
	: inputData(inputData), numType(setNumType()) {};

string StringNum::getInputData() { return inputData; }

int StringNum::setNumType()
{
	numType = 1; //default

	for (int i = 0; i < inputData.length(); ++i)
	{
		if (inputData[i] == '+') //type 3, a sum equation
		{
			numType = 3;
			break;
		}

		else if (inputData[i] == '-') //type 4, a difference equation
		{
			numType = 4;
			break;
		}

		else if (inputData[i] == 'w')
		{
			if (inputData[i + 1] == 'o' && inputData[i + 2] == 'r' && inputData[i + 3] == 'd') //type 2, written form
			{
				numType = 2;
				break;
			}
		}
	}

	return numType;
}

int StringNum::getNumType() { return numType; }