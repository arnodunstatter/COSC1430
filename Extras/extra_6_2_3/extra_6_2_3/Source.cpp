#include "Students.h"
#include <iostream>
#include <iomanip>



using namespace std;

void displayStudentsInfo(Students* array[], int arraySize);

int main()
{
	int boostArnosGrade;

	Students defaultStudent; //consctructs defaultStudent using default constructor

	Students student1("Slacker McSlacksaLot", -1, 12345678); //parameter constructor, tests invariant gates

	Students creator("Bjarne Stroustrup", 4.0, 0000001);

	Students author("Armo", 3.0, 1926976);




	Students* arrayStudents[4] = { &defaultStudent, &student1, &creator, &author };

	displayStudentsInfo(arrayStudents, 4);

	cout << "\n\nOpe! Looks like I mispelled my own name! How embarassing.\n";
	cout << "Let's test my name-setter!\n\n";

	author.set_name("Arno Dunstatter");
	cout << endl;

	displayStudentsInfo(arrayStudents, 4);

	cout << "If you think this was a nifty program then program then enter 1 to boost my grade!\n";
	cin >> boostArnosGrade;

	if (boostArnosGrade == 1)
	{
		author.set_gpa(4.00);
		cout << "\nThanks!\n\n";
		cout << "Arno's new grade is " << author.get_gpa() << "!\n";
	}
	else
	{
		cout << ":( Welp, there's always next time!\n\n";
	}

	return 0;
}




void displayStudentsInfo(Students* array[], int arraySize)
{
	string name;
	int id;
	double gpa;
	cout << endl;

	//arra[i] == defaultStudent-;
	for (int i = 0; i < arraySize; ++i)
	{
		name = (*array[i]).get_name(); //this syntax is equivalent to the syntax use don the next two lines
		id = array[i]->get_id();
		gpa = array[i]->get_gpa();
		cout << "Student " << i + 1 << " is named ";
		cout << name << ". ";
		cout << "Their ID is " << setw(7) << setfill('0') << id << " and ";
		cout << "their gpa is " << fixed << setprecision(2) << gpa << ".\n\n";
	}
}
