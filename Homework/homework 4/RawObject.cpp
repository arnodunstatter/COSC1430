#include "RawObject.h"

RawObject::RawObject(string line, string outputFile)
	:outputFile(outputFile)
{
	lineParser(line);
	type1 = typeDeterminer(operand1);
	type2 = typeDeterminer(operand2);
	write.open(outputFile.c_str(), ostream::app);
	isWriteOpen = write.is_open();
}

RawObject::~RawObject()
{
	write.close();
	//cout << "Destructor called.\n";
}

void RawObject::lineParser(string line) //will split our line into operand1, operAtor, and operand2
{
	string temp = "";
	for (int i = 0; i < line.length(); ++i)
	{
		if (line[i] == '+' || line[i] == '-') //temp is done accumulating operand1
		{
			if (line[i] == '+') //sets our operAtor 
				operAtor = '+';
			else //sets our operAtor
				operAtor = '-';
			operand1 = temp; //sets operand1 to temp
			temp = ""; //resets temp to empty
			++i; //shifts i past the operAtor character
		}
		temp += line[i];

		if (i == line.length() - 1) //temp is done accumulating operand2
		{
			operand2 = temp;
		}

	}
}


string RawObject::typeDeterminer(string operand)
{
	string type;
	int decimalCounter = 0;
	for (int i = 0; i < operand.length(); ++i)
	{
		if (operand[i] == 'a' || operand[i] == 'b' || operand[i] == 'c' || operand[i] == 'd' || operand[i] == 'e'
			|| operand[i] == 'f' || operand[i] == 'g' || operand[i] == 'h' || operand[i] == 'i' || operand[i] == 'j'
			|| operand[i] == 'k' || operand[i] == 'l' || operand[i] == 'm' || operand[i] == 'n' || operand[i] == 'o'
			|| operand[i] == 'p' || operand[i] == 'q' || operand[i] == 'r' || operand[i] == 's' || operand[i] == 't'
			|| operand[i] == 'u' || operand[i] == 'v' || operand[i] == 'w' || operand[i] == 'x' || operand[i] == 'y'
			|| operand[i] == 'z')
		{
			type = "string";
			break;
		}

		else if (operand[i] == '.')
		{
			++decimalCounter;
		}

	}

	if (type != "string")
	{
		if (decimalCounter > 1)
			type = "error";
		else if (decimalCounter == 1)
			type = "double";
		else //decimalCounter must still be 0
			type = "int";
	}

	return type;
}

const string& RawObject::operand1Getter() { return operand1; }

const string& RawObject::operand2Getter() { return operand2; }

string RawObject::operAtorGetter() { return operAtor;  }

string RawObject::type1Getter() { return type1;  }

string RawObject::type2Getter() { return type2; }

string RawObject::outputFileGetter() { return outputFile; }

void RawObject::writer() {};