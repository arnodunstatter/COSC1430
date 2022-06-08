#ifndef RAWOBJECT_H
#define RAWOBJECT_H

#include "RawObjectAbstractParent.h"


using namespace std;

class RawObject: public RawObjectAbstractParent
{
private:
	string line;
	string operand1, operAtor, operand2;
	string type1, type2; //"int", "double", "string", or "error"
	string outputFile;
	
	void lineParser(string line);
	string typeDeterminer(string operand);
	
public:
	RawObject(string line, string outputFile);
	~RawObject();

	ofstream write;
	bool isWriteOpen;

	const string& operand1Getter();
	const string& operand2Getter();
	string operAtorGetter();
	string type1Getter();
	string type2Getter();
	string outputFileGetter();

	void writer();
};


#endif