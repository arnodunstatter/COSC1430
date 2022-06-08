/* 
I have spent at least 36 hours working on this.
*/

#include "matrix.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

void menu();
matrix defineMatrix();
void calculator(int choice);

int main()
{
	cout << "Welcome to Arno's rudimentary matrix calculator!\n";
	
	menu();
	
	_CrtDumpMemoryLeaks();
	return 0;
}

void menu()
{
	int choice, cont;
	
	do 
	{
		cout << "Please choose one of the following options:\n";
		cout << "1. Addition\n2.Subtraction\n3.Multiplicatoin\n0.Exit Program\n";
		cin.clear();
		cin >> choice;
		if (choice == 0)
			break;
		else
		{
			calculator(choice);
		}

		cout << "Would you like to continue? Enter any number for yes, or enter 0 to end the program:\n";
		cin >> cont;
		
	} while (choice != 0 && cont != 0);
}

void calculator(int choice)
{
	matrix sum, difference, product;
	cout << "Please define the first matrix:\n";
	matrix first = defineMatrix();
	cout << "Please define the second matrix:\n";
	matrix second = defineMatrix();

	switch (choice)
	{
	case 1:
		cout << "You've chosen addition.\n";
		
		//display
		cout << first;
		cout << setw(4) << "+" << endl;
		cout << second;
		sum = first + second;
		cout << setw(second.getNumCols() * 9) << setfill('-') << "" << endl;
		cout << setfill(' ') << sum;
		break;

	case 2:
		cout << "You've chosen subtraction.\n";

		//display
		cout << first;
		cout << setw(4) << "-" << endl;
		cout << second;
		difference = first - second;
		cout << setw(second.getNumCols() * 9) << setfill('-') << "" << endl;
		cout << setfill(' ') << difference;
		break;

	case 3:
		cout << "You've chosen multiplication.\n";

		//display
		cout << first;
		cout << setw(4) << "*" << endl;
		cout << second;
		product = first * second;
		cout << setw(second.getNumCols() * 9) << setfill('-') << "" << endl;
		cout << setfill(' ') << product;
		break;

	default:
		cout << "That was not a valid choice.\n";
		break;
	}
}

matrix defineMatrix()
{
	matrix A;
	cin >> A;
	return A; 
}
