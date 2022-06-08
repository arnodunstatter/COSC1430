#include "hw0.h"


/*this will take two inputs (NUM_OF_HASHES, and CHARS_BETWEEN), print out the NUM_OF_HASHES, then *s, for a total of 10 characters per line.
Each new line will begin its #s with CHARS_BETWEEN characters between where the #s started on the previous line and where the #s begin on the new line,
using *s to fill in the space before the #s. If the #s would start past the 10 character limit then the program ends.*/
int main(int argc, char** argv)
{
	int NUM_OF_HASHES, CHARS_BETWEEN;
	int start = 0; //this will be the start position of the hashes

	/*to test this in Visual Studio go to Project, Properties, Configuration Properties, Debugging, Command Arguments and then enter in the parameters*/

	if (argc >= 3)
	{
		NUM_OF_HASHES = atoi(argv[1]);
		CHARS_BETWEEN = atoi(argv[2]);
	}
	else
	{
		cout << "Not enough inputs. Exiting program.\n";
		return 0;
	}
	

	/*cout << "How many hashes shall I attempt to print on each line? "; //prompts for NUM_OF_HASHES
	cin >> NUM_OF_HASHES;

	cout << "How many characters between where the hashes began on the previous line and where the hashes begin on the next line? "; //prompts for CHARS_BETWEEN
	cin >> CHARS_BETWEEN;*/

	while (start < 10) {
		int first_set_of_asterisks = 0;
		int hashes_to_print = NUM_OF_HASHES; //we want to be able to decrement hashes_to_print without changing NUM_OF_HASHES
		for (int col = 0; col < 10; ++col) //this for loop will print each row
		{
			//this will print the first set of *s that comes before the #s
			while (first_set_of_asterisks < start && col < 10)
			{
				cout << "*";
				col++; //keeps the col loop-control variable correct
				first_set_of_asterisks++;
			}

			//this will print our #s
			while (hashes_to_print > 0 && col < 10)
			{
				cout << "#";
				col++; //keeps the col loop-control variable correct
				hashes_to_print--;
			}

			//prints the last set of *s
			if (col < 10)
			{
				cout << "*";
			}

		}

		start += CHARS_BETWEEN; //updates the start position of the #s
		cout << endl; //moves each new row to the next line



	}

	return 0;
}