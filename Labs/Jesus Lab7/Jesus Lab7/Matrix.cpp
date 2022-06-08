#include "matrix.h"
#include <iostream>
#include <limits>
#include <limits>
using namespace std;

//Sets the pointer to a new 2D array in heap
void Matrix::setptr() {
    ptr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        ptr[i] = new int[cols];
    }
}

//Parameter Constructor
Matrix::Matrix(int r, int c) {
    rows = r;
    cols = c;
    this->setptr();
}

//Destructor (destroys 2D array as well)
Matrix :: ~Matrix() {
    if (ptr != NULL) {
        for (int i = 0; i < rows; i++) {
            delete[] ptr[i];
        }
        delete[] ptr;
    }
}

//Output Stream
ostream& operator<<(ostream& out, const Matrix& mat) {

    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            out << mat.ptr[i][j] << " ";
        }
        out << "\n";
    }
    return out;
}

//Input Stream
istream& operator>>(istream& in, const Matrix& mat) {
    for (int i = 0; i < mat.rows; i++) {
        cout << "For row " << i << ", type in " << mat.cols << "elements separated by spaces: ";

        for (int j = 0; j < mat.cols; j++) {
            in >> mat.ptr[i][j];
        }

    }
    return in;
}

//Set Elements in Matrix
void Matrix::setElements() {

    //User input
    for (int i = 0; i < rows; i++) {
        cout << "Set " << cols << " element(s) for row " << i << ", separated by spaces: ";

        for (int j = 0; j < cols; j++) {
            cin >> ptr[i][j];
        }

        //Quality Control
        if (cin.fail() == 1) {
            cout << "You entered the integers wrong for row " << i << ". Try Again.\n\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            i--;
        }
    }
    cout << "\n";
}

//Operator Overloads:
//Equal Operator
Matrix& Matrix :: operator=(const Matrix& mat) {
    rows = mat.rows;
    cols = mat.cols;
    ptr = mat.ptr;
    return *this;
}

//Plus Operator
Matrix Matrix :: operator+(const Matrix& mat) {
    if (mat.rows != this->rows && mat.cols != this->cols)
        throw 1;
    if (mat.cols != this->cols)
        throw 2;
    if (mat.rows != this->rows)
        throw 3;

    Matrix temp(mat.rows, mat.cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            temp.ptr[i][j] = this->ptr[i][j] + mat.ptr[i][j];
        }
    }
    return temp;
}

//Minus Operator
Matrix Matrix :: operator-(const Matrix& mat) {
    if (mat.rows != this->rows && mat.cols != this->cols)
        throw 1;
    if (mat.cols != this->cols)
        throw 2;
    if (mat.rows != this->rows)
        throw 3;
    Matrix temp(mat.rows, mat.cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            temp.ptr[i][j] = this->ptr[i][j] - mat.ptr[i][j];
        }
    }
    return temp;
}

//Multiplication Operator
Matrix Matrix :: operator*(const Matrix& mat) {
    if (mat.rows != this->cols)
        throw 1;

    Matrix temp(this->rows, mat.cols);
    //From 0 to # of resulting rows
    for (int i = 0; i < temp.rows; i++) {
        //From 0 to # of resulting columns
        for (int j = 0; j < temp.cols; j++) {
            //From 0 to # of left cols or right rows of calculation
            //Have to set temp position = 0 to do matrix multiplication correctly (as it adds up all the products)
            temp.ptr[i][j] = 0;
            for (int k = 0; k < mat.rows; k++) {
                temp.ptr[i][j] += this->ptr[i][k] * mat.ptr[k][j];
            }
        }
    }
    return temp;
}
