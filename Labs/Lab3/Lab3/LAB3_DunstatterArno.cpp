#include <iostream> 
#include <iomanip>

using namespace std;

int main()
{
	int periods; //cannot be negative
	double rate, investment; //cannot be negative
	double new_val; //will be used for iterative calculations

	cout << "Enter the number of periods: ";
	cin >> periods;
	while (periods < 0 || periods > 10000)
	{
		if (periods < 0)
		{
			cout << "You're not going back in time.\nPlease enter a positive value for the number of periods: ";
			cin.clear(); ////prevents looping from really large inputs
			cin >> periods;
		}

		if (periods > 10000)
		{
			cout << "Society will have either transcended money by then or we'll have auto-annihliated.\nPlease give us a reasonable period: ";
			cin.clear(); //prevents looping from really large inputs
			cin >> periods;
		}
	}

	cout << "Enter a non-negative value for interest rate: ";
	cin >> rate; //this should be given as a % value, meaning 5% is given as 5, etc
	rate = 0.01 * rate; //converts to decimal 
	while (rate < 0 || rate > 71400)
	{
		if (rate < 0)
		{
			cout << "This isn't a loss calculator. We only serve winners!\nPlease enter a positive interest rate: ";
			cin.clear();
			cin >> rate;
		}

		if (rate > 71400)
		{
			cout << "The highest return on investment ever recorded was 71400% with eBay. You're not likely to beat that.\nPlease enter a reasonable interest rate: ";
			cin.clear();
			cin >> rate;
		}
	}

	cout << "Enter a non-negative value for investment: ";
	cin >> investment;
	while (investment < 0 || investment > 1000000000)
	{
		if (investment < 0)
		{
			cout << "You can't invest a negative amount.\nPlease enter a positive amount for investment: ";
			cin.clear();
			cin >> investment;
		}

		if (investment > 1000000000)
		{
			cout << "You probably shouldn't invest more than 1 billion. Smart investers diversify!\nPlease enter a smaller value: ";
			cin.clear();
			cin >> investment;
		}
	}

	//our calculations
	new_val = investment; 
	for (int i = 1; i <= periods; ++i)
	{
		new_val = new_val * (1 + rate);
	}

	//our output
	cout << "Future value is = " << fixed << setprecision(2) << new_val;

	return 0;
}