#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	const int SIZE_LIMIT = 4; //maximum size
	int size;
	int square[SIZE_LIMIT][SIZE_LIMIT];
	int row = 0, col = 0; //used for navigating the 2D array and printing the Linear Table

	do
	{
		cout << "Please input an integer size greater than 0 but no more than 4: ";
		cin.clear();
		cin >> size;
	} while (size < 0 || size > 4); //input request and validation
	cout << endl;

	for (int r = 0; r < size; ++r) //gets input into our array
	{
		for (int c = 0; c < size; ++c)
		{
			cout << "Please enter a value for row " << r  << ", column " << c << ": ";
			cin >> square[r][c];
			
			while (square[r][c] < -1000 || square[r][c] > 1000) //input validation
			{
				if (square[r][c] < -1000)
					cout << "Too low. Please enter a higher number: ";
				if (square[r][c] > 1000)
					cout << "Too high. Please enter a lower number: ";
				cin.clear();
				cin >> square[r][c];
			}
		}
	}

	//shows our 2-D array
	cout << endl << "Your 2-D array is shown below:\n";
	for (int r = 0; r < size; ++r)
	{
		for (int c = 0; c < size; ++c)
		{

			cout << setw(5) << to_string(square[r][c]);
			
			if (c == (size - 1))
				cout << endl;
		}
	}

	cout << endl << "The contents of the linear table is:\n";
	cout << square[row][col]; //prints the very first entry
	while (row != (size - 1) || col != (size - 1)) //will stop the printing at the end of the 2D array
	{
		if ((row == 0) && (col % 2 == 0))
			++col;
		else if ((row == 0) && (col % 2 != 0))
		{
			--col;
			++row;
		}
		else if ( (col == 0 || col == (size - 1))  &&  (row % 2 != 0)  &&  (row != (size-1) ))
			++row;
		else if (col == 0 && row % 2 == 0)
		{
			--row;
			++col;
		}
		else if ((row + col) % 2 == 0)
		{
			--row;
			++col;
		}
		else if ((row + col) % 2 != 0  && row != (size-1))
		{
			++row;
			--col;
		}
		else if (col == (size - 1) && row % 2 == 0)
		{
			++row;
			--col;
		}
		else if (row == (size - 1) && col % 2 == 0)
			++col;


	
		cout << " " << square[row][col]; //prints the 'current' character
	}
	
	cout << endl; 

	return 0;
}