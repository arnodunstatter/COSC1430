#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	const float TAX = 0.085; //this taxrate will be multiplied by subtotal to get tax amount
	double subtotal, total, price; //all of these should be doubles. price is a unit price.
	int quantity;
	
	cout << "Please enter the number of items you'd like to purchase: ";
	cin >> quantity;

	while (quantity < 0 || quantity > 10000) //performs input validation for quantity
	{
		if (quantity < 0)
		{
			cout << "We cannot accept negative values, please enter a positive value: ";
			cin.clear(); //clears cin buffer, prevents endless looping
			cin >> quantity;
		}

		if (quantity > 10000)
		{
			cout << "We only have 10,000 items in stock. Please enter a value less than or equal to 10,000: ";
			cin.clear(); //clears cin buffer, prevents endless looping
			cin >> quantity;
		}
	}

	cout << "And what is the unit price of this item? ";
	cin >> price;

	while (price < 0 || price > 1000)
	{
		if (price < 0)
		{
			cout << "We definitely don't have anything we pay you to buy. Please enter a positive value: ";
			cin.clear();
			cin >> price;
		}

		if (price > 1000)
		{
			cout << "Our prices are more reasonable than that! Please enter a unit price less than 1000: ";
			cin.clear();
			cin >> price;
		}
	}

	subtotal = price * quantity;
	total = subtotal + (TAX * subtotal);

	cout << "Quantity: " << quantity << endl;
	cout << "Unit-price: " << fixed << setprecision(2) << price << endl;
	cout << "Subtotal: " << fixed << setprecision(2) << subtotal << endl;
	cout << "Tax: " << fixed << setprecision(2) << TAX * subtotal << endl;
	cout << "Total: " << fixed << setprecision(2) << total << endl;
	
	
	return 0;
}