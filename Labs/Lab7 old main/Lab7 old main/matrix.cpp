#include "matrix.h"

matrix::matrix(const matrix& paramMatrix) //copy constructor
{
	this->numRows = paramMatrix.getConstsNumRows();
	this->numCols = paramMatrix.getConstsNumCols();
	Matrix = new int* [numRows];		//creates an array with numRows number of elements,
										//where each element is itself an empty pointer
	for (int rows = 0; rows < numRows; ++rows)
	{
		Matrix[rows] = new int[numCols]; //into each row we place another array of 
											//size numCols with doubles as values
	}

	for (int row = 0; row < numRows; ++row)
	{
		for (int col = 0; col < numCols; ++col)
		{
			int temp = paramMatrix.constsElemGetter(row, col);
			this->elemSetter(row, col, temp);
		}
	}

}

matrix::matrix(int rows, int cols) //parameter constructor
	:numRows(rows), numCols(cols)
{
	while (numRows < 1 || numRows > 100)
	{
		cout << "Please enter between 1 and 100, inclusive,";
		cout << " for the number of rows of your matrix: ";
		cin.clear();
		cin >> numRows;
	}

	while (numCols < 1 || numCols > 100)
	{
		cout << "Please enter between 1 and 100, inclusive, ";
		cout << " for the number of columns of your matrix: ";
		cin.clear();
		cin >> numCols;
	}

	Matrix = new int* [numRows];		//creates an array with numRows number of elements,
										//where each element is itself an empty pointer
	for (int rows = 0; rows < numRows; ++rows)
	{
		Matrix[rows] = new int[numCols]; //into each row we place another array of 
											//size numCols with doubles as values
	}
};



matrix::~matrix()
{
	for (int rows = 0; rows < numRows; ++rows)
	{
		delete Matrix[rows];
	}
	delete Matrix;
	cout << "Destructor successful!\n";
}

const int& matrix::getNumRows() { return numRows; }
const int& matrix::getConstsNumRows() const { return numRows; }
const int& matrix::getNumCols() { return numCols; }
const int& matrix::getConstsNumCols() const { return numCols; }

void matrix::elemSetter(int rows, int cols, int element) //element setter 
{
	Matrix[rows][cols] = element;
}

int matrix::elemGetter(int rows, int cols)
{
	return Matrix[rows][cols];
}

int matrix::constsElemGetter(int rows, int cols) const
{
	return Matrix[rows][cols];
}

void matrix::print()
{
	for (int r = 0; r < getNumRows(); ++r)
	{
		for (int c = 0; c < getNumCols(); ++c)
		{

			cout << setw(5) << fixed << setprecision(0) << this->elemGetter(r, c);

			if (c == (getNumCols() - 1))
				cout << endl;
		}
	}
}


void matrix::matrixFiller()
{
	string line; //will hold each line of input
	string temp; //will hold disected units from line and then load them into our rowArray
	string* rowArray = new string[numCols];
	int tempElem; //holds each element from our rowArray before it's loaded into the matrix

	cin.ignore();
	for (int rows = 0; rows < numRows; ++rows)
	{
		line = ""; //will hold each line of input

		cout << "Please enter each element for row " << rows << ", separated by spaces:  ";
		getline(cin, line);

		temp = ""; //initializes our temp string to be empty. This will be loaded into our array
		for (int i = 0, cols = 0; i <= line.length() && cols < numCols; ++i) //this creates our temp variable and loads it into our array
		{
			if (line[i] != ' ' && line[i] != '\0')
			{
				temp += line[i];
			}
			else
			{
				rowArray[cols] = temp;
				++cols;
				temp = "";
			}
		}

		for (int cols = 0; cols < numCols; ++cols)
		{
			tempElem = stoi(rowArray[cols]);
			this->elemSetter(rows, cols, tempElem);
		}
	}



}


matrix matrix::operator=(const matrix right)
{
	if (this->numCols == right.numCols && this->numRows == right.numRows)
	{
		for (int rows = 0; rows < numRows; ++rows)
		{
			for (int cols = 0; cols < numCols; ++cols)
			{
				int temp = right.constsElemGetter(rows, cols);
				this->elemSetter(rows, cols, temp);
			}
		}
		return *this;
	}
	else
	{
		cout << "These matrices are different dimensions and cannot be set equal.\n";
		return *this;
	}
}


/*
const matrix matrix::operator+(matrix& right)
{
	matrix toReturn(numRows, numCols); //constructs our matrix to be returned


	if (numRows != right.getNumRows() || numCols != right.getNumCols())
	{
		cout << "These two matrices cannot be added.\n";
		return toReturn; //returns a matrix with garbage values
	}
	else
	{

		for (int rows = 0; rows < numRows; ++rows)
		{
			for (int cols = 0; cols < numCols; ++cols)
			{
				int temp = Matrix[rows][cols] + right.elemGetter(rows, cols);
				toReturn.elemSetter(rows, cols, temp);
			}
		}

		return toReturn;
	}

}


const matrix matrix::operator-(matrix& right)
{
	matrix toReturn(numRows, numCols); //constructs our matrix to be returned


	if (numRows != right.getNumRows() || numCols != right.getNumCols())
	{
		cout << "These two matrices cannot be subtracted.\n";
		return toReturn; //returns a matrix with garbage values
	}
	else
	{

		for (int rows = 0; rows < numRows; ++rows)
		{
			for (int cols = 0; cols < numCols; ++cols)
			{
				int temp = Matrix[rows][cols] - right.elemGetter(rows, cols);
				toReturn.elemSetter(rows, cols, temp);
			}
		}

		return toReturn;
	}

}


matrix matrix::operator*(matrix& right)
{
	if (this->numCols != right.getNumRows())
	{
		cout << "These two matrices cannot be multiplied. Returning left operand.\n";
		matrix original(*this);
		return original;
	}

	else
	{
		int n = numCols; //this is first operand's cols, and the second operand's rows
		int newRows = getNumRows(); //rows of product matrix
		int newCols = right.getNumCols(); //columns of product matrix
		matrix product(newRows, newCols); //instantiate my return matrix with parameter constructor

		for (int row = 0; row < newRows; ++row)
		{
			for (int col = 0; col < newCols; ++col)
			{
				int tempElem = 0; //gets loaded into the product
				for (int i = 0; i < n; ++i)
					tempElem += elemGetter(row, i) * right.elemGetter(i, col);
				product.elemSetter(row, col, tempElem);
			}
		}
		return product;
	}
}
*/

/*
matrix matrix::operator=(const matrix& right)
{
	this->numRows = right.getConstsNumRows();
	this->numCols = right.getConstsNumCols();
	this->Matrix = right.Matrix;
	
	for (int rows = 0; rows < numRows; ++rows)
	{
		for (int cols = 0; cols < numCols; ++cols)
		{
			int temp = right.constsElemGetter(rows, cols);
			this->elemSetter(rows, cols, temp);
		}
	}
	*
	return *this;
}
*/


const matrix operator+(const matrix& left, const matrix& right)
{

	if (left.numRows != right.numRows || left.numCols != right.numCols)
	{
		cout << "These two matrices cannot be added. Outputting garbage.\n";
		matrix toReturn(1, 1);
		return toReturn; //returns a 1x1 matrix with garbage values
	}
	else //left and right operands are same dimensions, so we can use either for constructing the matrix toReturn
	{
		int numRows = left.numRows;
		int numCols = left.numCols;
		matrix toReturn(numRows, numCols);
		for (int rows = 0; rows < numRows; ++rows)
		{
			for (int temp, cols = 0; cols < numCols; ++cols)
			{
				temp = left.constsElemGetter(rows, cols) + right.constsElemGetter(rows, cols); //calculates each element of toReturn
				toReturn.elemSetter(rows, cols, temp); //loads each element into toReturn
			}
		}

		return toReturn;
	}

}


const matrix operator-(const matrix& left, const matrix& right)
{

	if (left.numRows != right.numRows || left.numCols != right.numCols)
	{
		cout << "These two matrices cannot be subtracted. Outputting garbage.\n";
		matrix toReturn(1, 1);
		return toReturn; //returns a 1x1 matrix with garbage values
	}
	else //left and right operands are same dimensions, so we can use either for constructing the matrix toReturn
	{
		int numRows = left.numRows;
		int numCols = left.numCols;
		matrix toReturn(numRows, numCols);
		for (int rows = 0; rows < numRows; ++rows)
		{
			for (int temp, cols = 0; cols < numCols; ++cols)
			{
				temp = left.constsElemGetter(rows, cols) - right.constsElemGetter(rows, cols); //calculates each element of toReturn
				toReturn.elemSetter(rows, cols, temp); //loads each element into toReturn
			}
		}

		return toReturn;
	}

}





const matrix operator*(const matrix& left, const matrix& right)
{
	if (left.numCols != right.numRows)
	{
		cout << "These two matrices cannot be multiplied. Returning left operand.\n";
		const matrix original(left);
		return original;
	}
	else
	{
		int n = left.numCols; //this is left operand's cols, and the right operand's rows
		int newRows = left.numRows; //rows of product matrix
		int newCols = right.numCols; //columns of product matrix
		matrix product(newRows, newCols); //instantiate my return matrix with parameter constructor

		for (int row = 0; row < newRows; ++row)
		{
			for (int col = 0; col < newCols; ++col)
			{
				int tempElem = 0; //gets loaded into the product
				for (int i = 0; i < n; ++i)
					tempElem += left.constsElemGetter(row, i) * right.constsElemGetter(i, col);
				product.elemSetter(row, col, tempElem);
			}
		}
		return product;
	}
}

istream& operator >> (istream& left, matrix& right)
{
	int newRows, newCols;
	do
	{
		cout << "Please enter the number of rows for your matrix: ";
		cin.clear();
		cin >> newRows;
		if (newRows < 1 || newRows > 10)
			cout << "Please enter an integer value between 1 and 10.";
	} while (newRows < 0 || newRows > 10);

	do
	{
		cout << "Please enter the number of columns for your matrix: ";
		cin.clear();
		cin >> newCols;
		if (newCols < 1 || newCols > 10)
			cout << "Please enter an integer value between 1 and 10.";
	} while (newCols < 0 || newCols > 10);

	matrix replace(newRows, newCols);
	right = replace;

	string line; //will hold each line of input
	string temp; //will hold disected units from line and then load them into our rowArray
	string* rowArray = new string[right.numCols];
	int tempElem; //holds each element from our rowArray before it's loaded into the matrix

	cin.ignore();
	for (int rows = 0; rows < right.numRows; ++rows)
	{
		line = ""; //will hold each line of input

		cout << "Please enter each element for row " << rows << ", separated by spaces:  ";
		getline(cin, line);

		temp = ""; //initializes our temp string to be empty. This will be loaded into our array
		for (int i = 0, cols = 0; i <= line.length() && cols < right.numCols; ++i) //this creates our temp variable and loads it into our array
		{
			if (line[i] != ' ' && line[i] != '\0')
			{
				temp += line[i];
			}
			else
			{
				rowArray[cols] = temp;
				++cols;
				temp = "";
			}
		}

		for (int cols = 0; cols < right.numCols; ++cols)
		{
			tempElem = stoi(rowArray[cols]);
			right.elemSetter(rows, cols, tempElem);
		}
	}

	//delete rowArray; //why don't we need this?

	return left;
}

ostream& operator << (ostream& left, const matrix& right)
{
	for (int r = 0; r < right.getConstsNumRows(); ++r)
	{
		for (int c = 0; c < right.getConstsNumCols(); ++c)
		{

			cout << setw(6) << right.constsElemGetter(r, c);

			if (c == (right.getConstsNumCols() - 1))
				cout << endl;
		}
	}
	return left;
}


