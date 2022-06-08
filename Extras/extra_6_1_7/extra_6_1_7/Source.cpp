#include <iostream>
using namespace std;

bool isPrime(int); //will output 1 if the input is a prime, 0 if it is not.
int numOfPrimes(int); //calculates the number of primes <= the input value


//this will print out the number of prime numbers less than or equal to a given input and a list of those primes
int main() {
    int input, numOP; //input and the number of primes <= input
    int checker = 0; //will be brought up to numOP. This is used for formatting.

    cout << "You give me a value, and I'll tell you how many primes are less than or\nequal to that input. I'll also print a list of them!\n";
    cout << "Sensible inputs are positive integers greater than 1 but less than one hundred thousand.\n";
    cout << "Enter your input: ";
    cin >> input;

    while (input < 2 || input > 100000) //input validation
    {
        if (input < 2)
            cout << "Sensible inputs should be greater than 1.\n";

        if (input > 100000)
            cout << "Sensible inputs should be no more than 100,000.\n";

        cout << "Please enter a sensible value: ";
        cin.clear();
        cin >> input;
    }
    cout << endl; //formatting

    numOP = numOfPrimes(input); //sets the number of primes <= input

    cout << "There are " << numOP << " primes less than or equal to your input of " << input << ".\n\n";

    cout << "Those primes are as follows:\n";
    for (int i = 2; i <= input; i++)
    {

        if (isPrime(i))
        {
            cout << i;
            ++checker;
        }

        if (checker != numOP && isPrime(i)) //formatting the output
            cout << ", ";
    }


    return 0;
}

//will output 1 if the input is a prime, 0 if it is not.
bool isPrime(int val)
{
    bool isPrime = 1;

    for (int i = 2; i < val; ++i)
    {
        if (val % i == 0) //if val % i == 0 then val is not prime
            isPrime = 0;
        if (isPrime == 0)
            return isPrime;
    }

    return isPrime;
}

//calculates the number of primes <= the input value
int numOfPrimes(int val)
{
    int num = 0; //our counter

    for (int i = 2; i <= val; ++i)
    {
        if (isPrime(i))
            ++num;
    }

    return num;
}