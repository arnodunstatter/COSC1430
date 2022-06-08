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

	//param-constructor
	matrix(int rows = 0, int cols = 0);

	//copy connstructor
	matrix(const matrix& paramMatrix);

	//destructor
	~matrix();

	const int& getNumRows(); //getter for numRows
	const int& getConstsNumRows() const; //constant version
	const int& getNumCols(); //getter for numCols
	const int& getConstsNumCols() const; //constant version

	void elemSetter(int, int, int); //element setter (row, col, element)
	int elemGetter(int, int); //row, col
	int constsElemGetter(int, int) const;
	
	
	void print(); //this and the next one basically got replaced by << and >>, respectively
	void matrixFiller();


	//overloading
	matrix& operator=(const matrix right);

	friend const matrix operator + (const matrix& left, const matrix& right);

	friend const matrix operator - (const matrix& left, const matrix& right);

	friend const matrix operator * (const matrix& left, const matrix& right);
	
	friend istream& operator >> (istream& left, matrix& right);

	friend ostream& operator << (ostream& left, const matrix& right);



};


#endif
