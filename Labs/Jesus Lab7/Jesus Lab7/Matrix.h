#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
using namespace std;


class Matrix {
private:
    int rows;
    int cols;
    int** ptr;

    //Sets the pointer to a new 2D array in heap
    void setptr();

public:
    //Parameter Constructor
    Matrix(int r, int c);

    //Destructor (destroys 2D array as well)
    ~Matrix();

    //Output Stream
    friend ostream& operator<<(ostream& out, const Matrix& mat);

    //Input Stream
    friend istream& operator>>(istream& in, const Matrix& mat);

    //Set Elements in Matrix
    void setElements();

    //Operator Overloads:
    //Equal Operator
    Matrix& operator=(const Matrix& mat);

    //Plus Operator
    Matrix operator+(const Matrix& mat);

    //Minus Operator
    Matrix operator-(const Matrix& mat);

    //Multiplication
    Matrix operator*(const Matrix& mat);
};


#endif // MATRIX_H
