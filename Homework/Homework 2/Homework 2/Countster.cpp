#include "Countster.h"


Countster::Countster()
	: alphaCount(0), numCount(0) //and we want both values set to 0
{}

Countster::~Countster()
{}

void Countster::count(string text) //just adds one to alphaCount
{
	for (int i = 0; i < text.length(); ++i)
	{
		if (text[i] == 'a' || text[i] == 'A' || text[i] == 'b' || text[i] == 'B' || text[i] == 'c' || text[i] == 'C' 
			|| text[i] == 'd' || text[i] == 'D' || text[i] == 'e' || text[i] == 'E' || text[i] == 'f' || text[i] == 'F'
			|| text[i] == 'g' || text[i] == 'G' || text[i] == 'h' || text[i] == 'H' || text[i] == 'i' || text[i] == 'I'
			|| text[i] == 'j' || text[i] == 'J' || text[i] == 'k' || text[i] == 'K' || text[i] == 'l' || text[i] == 'L'
			|| text[i] == 'm' || text[i] == 'M' || text[i] == 'n' || text[i] == 'N' || text[i] == 'o' || text[i] == 'O'
			|| text[i] == 'p' || text[i] == 'P' || text[i] == 'q' || text[i] == 'Q' || text[i] == 'r' || text[i] == 'R'
			|| text[i] == 's' || text[i] == 'S' || text[i] == 't' || text[i] == 'T' || text[i] == 'u' || text[i] == 'U'
			|| text[i] == 'v' || text[i] == 'V' || text[i] == 'w' || text[i] == 'W' || text[i] == 'x' || text[i] == 'X'
			|| text[i] == 'y' || text[i] == 'Y' || text[i] == 'z' || text[i] == 'Z')
			++alphaCount;
		else if (text[i] == '1' || text[i] == '2' || text[i] == '3' || text[i] == '4' || text[i] == '5' || 
			text[i] == '6' || text[i] == '7' || text[i] == '8' || text[i] == '9' || text[i] == '0')
			++numCount;
	}
}

int Countster::getAlpha() //just returns alphaCount
{
	return alphaCount;
}


int Countster::getNum() //just returns numCount
{
	return numCount;
}