#include "matrix.h"

int main()
{
	int Arows, Acols;
	cout << "Please enter a number greater than 0 for the number of rows of matrix A: ";
	cin >> Arows;
	cout << "Please enter a number greater than 0 for the number of columns of matrix A: ";
	cin >> Acols;
	matrix A(Arows, Acols);
	A.matrixFiller();
	cout << "Matrix A is shown below:\n";
	A.print();
	cout << endl;


	int Brows, Bcols;
	cout << "Please enter a number greater than 0 for the number of rows of matrix B: ";
	cin >> Brows;
	cout << "Please enter a number greater than 0 for the number of columns of matrix B: ";
	cin >> Bcols;
	matrix B(Brows, Bcols);
	B.matrixFiller();
	cout << "Matrix B is shown below:\n";
	B.print();
	cout << endl;


	matrix C = A + B;
	cout << "Matrix C = A + B is shown below:\n";
	C.print();
	cout << endl;

	matrix D = A - B;
	cout << "Matrix D = A - B is shown below:\n";
	D.print();
	cout << endl;

	matrix E(Arows, Bcols);
	E = A * B; //why does the '=' operator receive the numRows and 
	//numCols from A and not from the return from the A*B operation ?
	cout << "Matrix E = A * B is shown below: \n";
	E.print();

	return 0;
}

