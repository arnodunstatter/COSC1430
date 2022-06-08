#include "TriangleError.h"

TriangleError::TriangleError(int err)
	:errorType(err), invalid_argument("")
{}

// Definition of message function	
string TriangleError::message()
{
	if (errorType == 1)
	{
		return "Side lengths must be positive.\n";
	}
	else if (errorType == 2)
	{
		return "Must obey triangle inequality to be a triangle.\n";
	}
	else
	{
		return "This doesn't appear to be a triangle.\n";
	}
}
