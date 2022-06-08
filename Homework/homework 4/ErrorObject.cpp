#include "ErrorObject.h"

ErrorObject::ErrorObject(string line, string outputFile)
	:RawObject(line, outputFile) {}

void ErrorObject::writer()
{
	try
	{
		if (!isWriteOpen)
			throw (isWriteOpen);
		write << "error" << endl;
	}
	catch (bool)
	{
		cout << outputFileGetter() << " did not open when trying to write \"error\".\n";
	}
}