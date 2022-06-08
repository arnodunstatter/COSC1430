#ifndef NUMOBJECT_CPP
#define NUMOBJECT_CPP
#include "NumObject.h"

template <typename T>
NumObject<T>::NumObject(string line, string outputFile)
	:RawObject(line, outputFile) {}

template <typename T>
void NumObject<T>::writer()
{
	T operator1 = stod(operand1Getter()); //if T is an integer, this should still work
	T operator2 = stod(operand2Getter());
	try
	{
		if (!isWriteOpen)
			throw (isWriteOpen);
		T finalOutput = 0;
		
		
		
		if (operAtorGetter() == "+")
			finalOutput += operator1 + operator2;

		else //we can assume operAtorGetter() would return "-"
			finalOutput += operator1 - operator2;

		if (type1Getter() == "double" || type2Getter() == "double")
		{
			write << setprecision(2) << fixed << finalOutput << endl;
		}

		else //they're integers
		write << finalOutput << endl;
	}
	catch (bool)
	{
		cout << outputFileGetter() << " did not open when trying to write a " << typeid(operator1).name() << "Object.\n";
	}
}

#endif