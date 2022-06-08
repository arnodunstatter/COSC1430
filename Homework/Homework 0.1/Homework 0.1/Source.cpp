#include <iostream>

using namespace std;


int main(int argc, char* argv[])
{
	/*int NUM_OF_HASHES, CHARS_BETWEEN;
	int start = 0; //this will be the start position of the hashes

	NUM_OF_HASHES = atoi(argv[1]); //these will not work for some reason, but if you comment them out and de-comment out lines 21-25 the program will work
	CHARS_BETWEEN = atoi(argv[2]);*/

	int a, b; //dummies

	//in order for this to work go to Project, Properties, Configuration Properties, Debugging, and change Command Arguments
	a = (argv[1][0] - '0');
	b = (argv[2][0] - '0');

	//a = atoi(argv[1]);
	//b = atoi(argv[2]);

	cout << "a was set to " << a << endl;
	cout << "b was set to " << b << endl;
}