#include <ctime>
#include <iostream>
#include <cstdlib>

using namespace std;

//a random number generator and guessing game
int main()
{
	int totGuesses = 0;
	unsigned long long int randomNum, guess; //our variables
	int seed = time(0); //initializes our seed
	srand(seed); //seeds rand
	randomNum = rand(); //initializes the random number

	cout << "Welcome to the random number guessing game! A random number has been generated.\n";
	cout << "Now guess the random number, like your life depends on it!\n"; //requests the first guess


	do
	{
		cin >> guess; //takes the user's guess
		++totGuesses; //increments our counter

		//lets the user know which direction they should move their guess
		if (guess < randomNum)
			cout << "Too low, try again.\n";
		else if (guess > randomNum)
			cout << "Too high, try again.\n";

		//lets the user know how many guesses they took, and then praises or admonishes them accoridngly
		else
		{
			switch (totGuesses) {
			case 1:
				cout << "Congrats! You got it on your 1st guess! Unheard of!\n";
				break;
			case 2:
				cout << "Congrats! You got it on your 2nd guess! Very impressive!\n";
				break;
			case 3:
				cout << "Congrats! You got it on your 3rd guess! Very lucky!\n";
				break;
			default:
				cout << "Congrats! You got it on your " << totGuesses << "th guess.";
				if (totGuesses < 10)
					cout << " Impressive!\n";
				else if (totGuesses < 20)
					cout << " Great job!\n";
				else if (totGuesses < 30)
					cout << " Good job!\n";
				else if (totGuesses < 40)
					cout << " Not bad.\n";
				else if (totGuesses < 50)
					cout << "..but you can probably do better.\n";
				else if (totGuesses < 60)
					cout << "..but are you even actually trying?\n";
				else
					cout << "..which isn't good at all. You are a disappointment to all who know you.\n";
				break;
			}


		}

	} while (guess != randomNum);

}