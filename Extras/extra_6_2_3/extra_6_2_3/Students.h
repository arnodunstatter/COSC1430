//this contains our class declaration along with its data members 
//and member functions
#include <string>

using namespace std;

#ifndef Students_h  //guard
#define Students_h //guard

class Students
{
private:
	string name;
	double gpa;
	int id;

public:
	Students(); //default constructor
	Students(string set_name, double gradePointAverage, int studentID); //parameter constructor
	Students(const Students& other_student); //copy constructor

	~Students();

	//member functions
	void set_name(string);
	string get_name() const;

	void set_gpa(double);
	double get_gpa() const;

	void set_id(int);
	int get_id() const;
};

#endif //guard. the guards can be replaced with '#pragma once' at the very top