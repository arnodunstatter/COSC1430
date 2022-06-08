#include <iostream>

using namespace std;

//this will extract the second to last digit of an integer. Ex: input: 12345, output: 4
int main()
{
	int given; //our input
	int last_two_digits; //the last two digits
	int last_digit; //the last digit
	int second_to_last_digit; //what we will return

	cout << "Please enter your integer: ";
	cin >> given; //gets our input
	while (given < 0 || given >=  2147483647)
	{
		cout << "Valid inputs are between 0 and 2147483646, inclusive. Please enter a valid input: ";
		cin.clear();
		cin >> given;
	}

	last_two_digits = given % 100;
	last_digit = given % 10;

	second_to_last_digit = (last_two_digits - last_digit) / 10; //gets the value in the tens-place, then divides by ten to get the digit

	cout << "The second to last digit is " << second_to_last_digit << "." << endl; //prints output

	return 0;

}