#include <iostream>

using namespace std;

//this will print out all numbers from 0 to the given input, each on a new line. Valid inputs are positive and less than 100,000
int main() {
	int n;
	cout << "I shall print all numbers from 0 to whatever value you give me. Just be reasonable. \n";
	cout << "What value do you wish for me to stop printing at? ";
	cin >> n;

	while (n < 0 || n > 100000) //input validation
	{
		if (n < 0)
		{
			cin.clear(); //this clears the previous entry from the cin buffer and resets it to take genuinely new input. Without this the program can get stuck printing the next line whenever an n value is given which is less than -2147483648
			cout << "I cannot print in reverse. Please give me a positive value: ";
			cin >> n;
		}

		if (n > 100000)
		{
			cin.clear(); //this clears the previous entry from the cin buffer and resets it to take genuinely new input. Without this the program can get stuck printing the next line whenever an n value is given which is greater than 2147483647
			cout << "I said be reasonable! Printing all the way to that high of a value would take a long time and bore the heck out of me! Quit trying to break me and just give me a smaller number: ";
			cin >> n;
		}
	}


	//this for loop does the printing
	for (int i = 0; i <= n; ++i) {
		cout << i << endl;
	}

	return 0;
}