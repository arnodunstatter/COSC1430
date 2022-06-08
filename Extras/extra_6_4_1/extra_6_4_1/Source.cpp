#include <iostream>
using namespace std;

int factorial(int);
int sum(int);
int gcd(int, int);
long long fib(int);
string reverse(string);
bool isPalindrome(string);

int main()
{
    int choice;
    cout << "Which funciton would you like to test?\n";
    cout << "1.Factorial\n2.Sum\n3.Greatest Common Divisor\n4.Fibonacci Numbers\n5.String Reverse\n6.Is string"

}


/*
Definition for the factorial of negative integers taken from the following paper:
Factorials of real negative and imaginary numbers - A new perspective, by Ashwani K Thukral. PMID: 25520905, https://www.ncbi.nlm.nih.gov/pmc/articles/PMC4247832/#:~:text=the%20integral%20equation%2C-,.,imaginary%20numbers%20are%20complex%20numbers.
*/
int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else if (n > 0)
        return n * factorial(n - 1);
    else //n is negative
        return n * factorial(n + 1);
}

int sum(int n)
{
    if (n == 0 || n == 1)
        return n;
    else if (n > 1)
        return n + sum(n - 1);
    else //n is less than 0
        return n + sum(n + 1);
}

int gcd(int x, int y)
{
    if (x % y == 0)
        return y;

    return gcd(y, x % y);
}

long long fib(int x)
{
    if (x == 0 || x == 1)
    {
        return x;
    }
    else
    {
        return (fib(x - 1) + fib(x - 2));
    }
}

string reverse(string str)
{
    if (str.length() == 1)
        return str;
    else
    {
        return str[str.length() - 1] + reverse(str.substr(0, str.length() - 1));
    }
}

bool isPalindrome(string str)
{
    if (str.length() == 1)
        return true;
    else if (str[0] != str[str.length() - 1])
        return false;
    return isPalindrome(str.substr(1, str.length() - 2));
}