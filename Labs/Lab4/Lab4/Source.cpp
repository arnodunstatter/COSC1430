//find monthly payment of loan and outputs a table showing the history of repayment
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

//function prototypes
void mainInput(double& loan, double& rate, int& term); //calls indivInput to get all the inputs necessary 
double indivInput(string message); //individual inputs
void calculations(double loan, double rate, int term, double& payment); //calculates our payment per month
void output(double loan, double payment, double rate, int term); //outputs loan information and the formatted table

//^^^^^these functions are integrated via main which acts as a 'driver'
int main()
{
    // Declarations of local variables	
    double loan;
    double rate;
    int term;
    double payment;

    mainInput(loan, rate, term);
    calculations(loan, rate, term, payment); //changes payment
    output(loan, payment, rate, term);

    return 0;
}

//calls indivInput in order to get values for loan, rate, and term
void mainInput(double& loan, double& rate, int& term)
{
    loan = indivInput("Enter the value of loan: ");
    rate = indivInput("Enter the interest rate per year: ");
    term = int(indivInput("Enter the term (number of years): "));

    while (term <= 0) /*won't accept a term length of 1*/
    {
        cout << "The term length must be at least 1 year.\n";
        loan = indivInput("Enter the term (number of years): ");
    }
}

//requests input and repeats until input is > 0
double indivInput(string message)
{
    double input;

    cout << message;
    cin >> input;

    while (input < 0 || input > 10000000) //input validation
    {
        if (input < 0)
        {
            cout << "Please enter a non-negative value: ";
        }

        if (input > 10000000)
        {
            cout << "That value is much too high. Please enter a smaller value: ";
        }
        cin.clear();
        cin >> input;
    }
    return input;
}

//calculations
void calculations(double loan, double rate, int term, double& payment)
{
    int months = term * 12;
    double factor = 1 + (rate / 1200);
    double loanMultiplier = pow(factor, months); 

    double paymentMultiplier = 0; //this for loop will calculate the Payment Multiplier. It basically acts as a summation
    for (int i = months - 1; i >= 0; i--)
    {
        paymentMultiplier += pow(factor, i);
    }
    
    payment = loan * (loanMultiplier / paymentMultiplier);
}

//outputs loan information and the formatted table
void output(double loan, double payment, double rate, int term)
{
    //local variables for the table
    double balance = loan;
    double interest;
    double principal;

    //next four lines output the basic loan info
    cout << "Loan: " << setprecision(2) << fixed << loan << endl << endl;
    cout << "Monthly Payment: " << setprecision(2) << fixed << payment << endl << endl;

    //Next 13 lines outputs the formatted table header and column titles
    cout << setw(30) << "Amortization" << endl;
    cout << setfill('-') << setw(51) << " " << endl;
    cout << setfill(' ');
    cout << setw(7) << "Month";
    cout << setw(9) << "Payment";
    cout << setw(10) << "Interest";
    cout << setw(12) << "Principal";
    cout << setw(12) << "Balance" << endl;
    cout << setw(7) << "-----";
    cout << setw(9) << "-------";
    cout << setw(10) << "--------";
    cout << setw(12) << "---------";
    cout << setw(12) << "-------" << endl;

    for (int month = 1; month <= term * 12; month++) //outputs the table
    {
        interest = balance * rate / 100 / 12;
        principal = payment - interest;
        balance = balance - principal;

        if ((principal + interest) < payment)
        {
            payment = principal + interest;
        }
         
        cout << fixed << setprecision(2);
        cout << setw(7) << month;
        cout << setw(9) << payment;
        cout << setw(10) << interest;
        cout << setw(12) << principal;
        cout << setw(12) << balance << endl;
    }
}


