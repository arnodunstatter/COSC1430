#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int choice, a, b; //choice will navigate the calculator menu, a will be the first number, b will be the second
	cout << "Menu: \n";
	cout << setw(4) << "" << "1. Addition\n";
	cout << setw(4) << "" << "2. Subtraction\n";
	cout << setw(4) << "" << "3. Multiplication\n";
	cout << setw(4) << "" << "4. Division\n";
	cout << setw(4) << "" << "5. Remainder\n";
	cin >> choice;

	while (choice < 1 || choice > 5)
	{
		cout << "Please enter a value of 1, 2, 3, 4, or 5 to select from the menu: ";
		cin.clear(); //prevents infinite looping if the value entered is really large or really small
		cin >> choice;
	}

	cout << "Enter the value of the first number: ";
	cin >> a;

	cout << "Enter the value of the second number: ";
	cin >> b;
	
	switch (choice) {
	case 1:
		cout << a << " + " << b << " = " << a + b;
		break;
	case 2: 
		cout << a << " - " << b << " = " << a - b;
		break;
	case 3:
		cout << a << " * " << b << " = " << a * b;
		break;
	case 4:
		cout << a << " / " << b << " = " << a / b;
		break;
	case 5:
		cout << a << " % " << b << " = " << a % b;
		break;
	}

	return 0;
}