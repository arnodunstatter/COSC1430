#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class matrix
{
private:
	int numRows;
	int numCols;
	int** Matrix;
	

public:
	//member functions

	//copy connstructor
	matrix(const matrix& paramMatrix);

	//param-constructor
	matrix(int rows, int cols);

	//destructor
	~matrix();

	const int& getNumRows(); //getter for numRows
	const int& getConstsNumRows() const;
	const int& getNumCols(); //getter for numCols
	const int& getConstsNumCols() const;

	void elemSetter(int, int, int); //element setter (row, col, element)
	int elemGetter(int, int); //row, col
	int constsElemGetter(int, int) const;
	void print();

	void matrixFiller();


	//overloading

	//void operator=(const matrix right);
	//matrix operator=(const matrix right); //****Either this or the above should work
	matrix operator=(const matrix right);

	const matrix operator+(matrix& right);
	//matrix operator+(matrix& right); //this would have returned a new matrix
	//after 8 hours of unsuccessful debugging, decided to go with work around:
	//void operator+(matrix& right); //work around, holds values of the sum in the left operand matrix

	//same work around as +
	//void operator-(matrix& right);

	const matrix operator-(matrix& right);

	matrix operator*(matrix& right); //returns new object created
	//matrix operator*(matrix& right) const;

	




};


#endif
