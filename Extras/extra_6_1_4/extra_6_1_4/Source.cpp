#include <iostream>
#include <ios>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

/* this program will act as a geometry calculator which can calculate
the area of a circle, a rectangle, and a triangle. It explores the use of the if, else if, else construction*/
int main()
{
	//this will output the welcome prompt, the menu, and will take in the user's choice.
	int choice;
	cout << "Welcome to the Geometry Calculator.\n";
	cout << "1. Calculate the Area of a Circle.\n";
	cout << "2. Calculate the Area of a Rectangle.\n";
	cout << "3. Calculate the Area of a Triangle.\n";
	cout << "4. Quit.\n";
	cout << "Enter your choice (1-4):\n";
	cin >> choice;

	if (choice == 1) {
		//this will ask for the radius of a circle, and then compute and output the area
		double radius;
		const double pi = 3.14159;
		cout << "So you want to calculate a circle's area, eh? Please input the radius of said circle.\n";
		cin >> radius;
		if (radius >= 0)
		{
			double circleArea = pi * pow(radius, 2);
			cout << "The area of a cricle with a radius of " << radius << " is " << circleArea << ".\n";
		}
		else //we can't accept negative values
		{
			cout << "The radius cannot be negative. Please rerun the program and give appropriate values.\n";
			return 0;
		}

	}
	else if (choice == 2) {
		//this will ask for the length and width of a rectangle, and then compute and output the area
		double width;
		double length;
		cout << "Ah, so a rectangle it is then.\n Please enter the width.\n";
		cin >> width;
		cout << "Now please enter the length.\n";
		cin >> length;
		if (width >= 0 && length >= 0)
		{
			double rectangleArea = width * length;
			cout << "A rectangle whose width is " << width << " and whose length is " << length << endl;
			cout << "has an area of " << rectangleArea << ".\n";
		}
		else //we can't accept negative values
		{
			cout << "We cannot work with negative values. Please rerun the program and give appropriate values.\n";
			return 0;
		}
	}
	else if (choice == 3) {
		//this will ask for the length of the triangle's base, it's height, and then compute
		//and output the area
		double base;
		double height;
		double triangleArea;
		cout << "So it's the triangle then, hmm? \n";
		cout << "Please enter your traingle's base.\n";
		cin >> base;
		cout << "Now please enter your triangle's height.\n";
		cin >> height;
		if (base >= 0 && height >= 0)
		{
			triangleArea = base * height * 0.5;
			cout << "A triangle with a base of " << base << " and a height of " << height << endl;
			cout << "has an area of " << triangleArea << ".\n";
		}
		else //we can't accept negative values
		{
			cout << "We cannot work with negative values. Please rerun the program and give appropriate values.\n";
			return 0;
		}
	}
	else if (choice == 4) //This will quit the program
	{
		cout << "Program ending.\n";
		return 0;
	}
	else //error message if they don't select 1-4
	{
		cout << "That was not a valid choice. Please rerun the program and make appropriate selections.\n";
		return 0;
	}
	return 0;
}
