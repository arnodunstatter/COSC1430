#include <iostream>
#include <string>
using namespace std;


//a simple exploration of floats, arithmetic, and output
int main()
{
	float holds, travel, mpg; //initialize variables in gal., mi., miles per gallon
	holds = 15; //gives data to the variables
	travel = 375;
	mpg = travel / holds; //calculates mpg
	cout << "That car gets " << mpg << " mpg.\n"; //prints answer
	return 0;
}