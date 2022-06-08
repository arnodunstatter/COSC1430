#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	double sales1, sales2, sales3, sales4, sales5; //declaring sales values for each store
	vector<double> sales = { sales1 = 0, sales2 = 0, sales3 = 0, sales4 = 0, sales5 = 0 }; //initializing a vector for easy access to all sales values

	ofstream outputFile; //creating our outputFile object
	outputFile.open("salesbarchart.txt"); //establishes the "pipeline" to salesbarchart.txt and creates said file
	//if it's not already extant
	if (outputFile) { //this if statement verifies that the salesbarchart.txt file was opened properly
		for (int i = 1; i <= 5; ++i) //will get values for today's sales for each store
		{
			cout << "Enter today's sales for store " << i << ": ";
			do //this will validate the input and repeatedly ask for valid input if the input is invalid 
			{
				cin >> sales[i - 1];
				if (sales[i - 1] <= 0 || sales[i-1] > 10000) //input validation
				{
					cout << "That was not valid. Please enter a positive value which is no more than 10,000 for sales: ";
					cin.clear();
				}

			} while (sales[i - 1] <= 0  || sales[i-1] > 10000);

		}

		cout << "\nFor every $100 in sales we will print one * to produce a bar graph:\n";

		for (int i = 0; i <= 4; ++i)
		{
			cout << "Store " << i + 1 << ": "; //output to screen
			outputFile << "Store " << i + 1 << ": "; //output to file

			for (int j = 0; j <= sales[i] / 100; ++j)
			{
				if (j > 0)
				{
					cout << "*"; //output to screen
					outputFile << "*"; //output to file
				}

			}
			cout << endl; //new line for each store on the screen
			outputFile << endl; //new line for each store in the file
		}
		outputFile.close(); //closes salesbarchart.txt
	}

	else //lets the user know that the salesbarchart.txt file wasn't properly opened
		cout << "The desired file, salesbarchart.txt, could not open correctly. Please try to run the program again.\n";


	return 0;
}
