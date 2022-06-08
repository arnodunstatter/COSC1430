//this contains our class member function definitions
#include "Students.h"
#include <string>
#include <iostream>

using namespace std;

//constructors & destructor
Students::Students() //default constructor
	:name("No_Name"), gpa(0.00), id(0000000) {};

Students::Students(string set_name, double gradePointAverage, int studentID) //parameter constructor
	:name(set_name), gpa(gradePointAverage), id(studentID)
{
	while (gradePointAverage < 0.00 || gradePointAverage > 4.00) //invariant gate
	{
		cout << set_name << " has an invalid GPA.\n";
		cout << "GPA must be between 0.00 and 4.00, inclusive. Please re-enter GPA: ";
		cin >> gradePointAverage;
		cout << endl;
	}
	gpa = gradePointAverage;

	while (studentID < 0 || studentID > 9999999) //invariant gate
	{
		cout << set_name << " has an invalid student ID.\n";
		cout << "Student ID must be greater than 0 and less than 10000000.\n";
		cout << "Please re-enter student ID: ";
		cin >> studentID;
		cout << endl;
	}
	id = studentID;

};

Students::Students(const Students& other_student) //coppy constructor
	:name(other_student.name), gpa(other_student.gpa), id(other_student.id) {};

Students::~Students() { cout << "Memory cleared!\n"; }; //destructor


//member functions
void Students::set_name(string set_name) { name = set_name; }

string Students::get_name() const { return name; }


void Students::set_gpa(double set_gpa)
{
	while (set_gpa < 0 || set_gpa > 4) //invariant gate
	{
		cout << "GPA must be between 0.00 and 4.00, inclusive. Please re-enter GPA: ";
		cin >> set_gpa;
	}
	gpa = set_gpa;
}

double Students::get_gpa() const { return gpa; }

void Students::set_id(int set_id)
{
	while (set_id < 0 || set_id > 9999999) //invariant gate
	{
		cout << "Student ID must be greater than 0 and less than 10000000.\n";
		cout << "Please re-enter student ID: ";
		cin >> set_id;
	}
	gpa = set_id;
}

int Students::get_id() const { return id; }
