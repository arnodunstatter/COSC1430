#include <iostream>
#include <string>

using namespace std;

//calculates net earnings on an investment after paying commission to a broker
int main() {
	//first we'll initialize and declare variables
	double numShares = 1500; //number of shares purchased and sold
	double initialPrice = 45.75;
	double buyCommission = 0.0227;
	double sellPrice = 58.75;
	double sellCommission = 0.0255;
	double totSellCommission, profit; //total amount spent on commission when selling the shares
	double saleCostBeforeCom = initialPrice * numShares;
	double totBuyCommission = buyCommission * initialPrice * numShares;
	double saleBeforeCom = sellPrice * numShares;
	double totSpent = saleCostBeforeCom + totBuyCommission;
	double totSaleCom = sellCommission * sellPrice * numShares;

	//information relevant to the purchase
	cout << "Joe purchased 1500 shares of Amity Software, inc. \n";
	cout << "He paid $45.75 per share, so he spent $";
	cout << saleCostBeforeCom << " on the stock.\n";

	cout << "He paid a 2.27% commission on the purchase, which came to $";
	//calculate commission spent when buying
	cout << totBuyCommission << ".\n";


	//information relevant to the sale
	cout << "Two weeks later Joe sold his all 1500 shares at $58.75 per share, ";
	//calculate sale value before commission
	cout << "which came to $" << saleBeforeCom << ".\n";
	cout << "He paid a 2.55% commission on the sale, which came to $";
	//calculate sale commision
	cout << totSaleCom << ".\n";
	//add totSaleCom to totalSpent
	totSpent += totSaleCom;

	//calculate and report profit
	profit = saleBeforeCom - totSpent;
	cout << "All said and done, Joe made $" << profit << " in profit.\n";
	return 0;
}