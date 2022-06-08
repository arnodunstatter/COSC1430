#include <iostream>
#include <string>

using namespace std;

void romToInt();  
int rcti(char); //Roman Numeral To Integer
void intToRom(); //Integer to Roman Numeral

int main()
{
	int choice;
	string input;
	
	do
	{
		cout << "Enter 1 if you want to convert a Roman Numeral to an Integer or\n";
		cout << "enter 2 if you want to convert an Integer to a Roman Numeral: ";
		cin.clear();
		cin >> choice; 
	} while (choice != 1 && choice != 2);

	if (choice == 1)
		romToInt();

	else if (choice == 2)
		intToRom();

	return 0;
}

void romToInt()
{
	string rom;
	//int length = rom.length();
	bool rule2 = 1, rule3 = 1, ruleA = 1;// These should all be set to 1 to start and then will be changed to 0 if either rule is broken. 
	/*
	Rules relevant to whether a string is or is not a roman numeral
	2. The letters are in uppercase only.
	3. A letter cannot be used more than three times.
	A. Only one letter of lesser value is allowed before a higher value. 
	*/

	int icount = 0, vcount = 0, xcount = 0, lcount = 0, ccount = 0, dcount = 0, mcount = 0; //counters for checking rule3 compliance

	int value = 0; //the value we will print at the end, aka the value of the Roman Numeral 

	int pre, cur, temp; 


	cout << "Please enter your Roman Numeral: ";
	cin >> rom;


	for (int i = 0; i < rom.length(); ++i) //this checks for rule2 compliance
	{
		if (rom[i] != 'I' && rom[i] != 'V' && rom[i] != 'X' && rom[i] != 'L' && rom[i] != 'C' && rom[i] != 'D' && rom[i] != 'M')
		{
			rule2 = 0;
			break;
		}
	} 

	if(rule2) //checks for rule3 compliance if rule2 is compliant
	{
		for (int i = 0; i < rom.length(); ++i) //this checks for rule3 compliance
		{
			if (rom[i] == 'M') //checks if the first char is 'M', if so it increments the counter, if the counter is >= 4 it sets rule3 to false and breaks the for loop
			{
				++mcount;
				if (mcount >= 4)
				{
					rule3 = 0;
					break;
				}
			}
			else if (rom[i] == 'D')
			{
				if (rom[i] == 'D')
				{
					++dcount;
					if (dcount >= 4)
					{
						rule3 = 0;
						break;
					}
				}
			}
			else if (rom[i] == 'C')
			{
				if (rom[i] == 'C')
				{
					++ccount;
					if (ccount >= 4)
					{
						rule3 = 0;
						break;
					}
				}
			}
			else if (rom[i] == 'L')
			{
				if (rom[i] == 'L')
				{
					++lcount;
					if (lcount >= 4)
					{
						rule3 = 0;
						break;
					}
				}
			}
			else if (rom[i] == 'X')
			{
				if (rom[i] == 'X')
				{
					++xcount;
					if (xcount >= 4)
					{
						rule3 = 0;
						break;
					}
				}
			}
			else if (rom[i] == 'V')
			{
				if (rom[i] == 'V')
				{
					++vcount;
					if (vcount >= 4)
					{
						rule3 = 0;
						break;
					}
				}
			}
			else if (rom[i] == 'I')
			{
				if (rom[i] == 'I')
				{
					++icount;
					if (icount >= 4)
					{
						rule3 = 0;
						break;
					}
				}
			}

		}
	}

	if (rule2 && rule3 && rom.length() >= 3) //this check for ruleA compliance will only commense if rules 2 and 3 are compliant
	{
		for (int i = 2; i < rom.length(); ++i)
		{
			if (rom[i - 1] == rom[i - 2])
				ruleA = 0;
		}
	}





	/*
	Rules relevant to computing value of a Roman Numeral
	1. There is no zero in Roman literals
	4. If a letter is placed after a letter with a greater value, the value of the lower letter is added to
		the one with the higher value.For example, XI is 11.
	5. If a letter is placed before a letter with a greater value, then the value of the letter with the
		lower value is subtracted from the value of the letter with the higher value.For example, IX is 9.
	*/


	if (rule2 && rule3 && ruleA)
	{
		if (rom.length() == 1)
		{
			cout << rcti(rom[0]); 
		}
		else
		{
			for (int i = 1; i <= rom.length(); ++i)  
			{
				temp = 0;
				cur = rcti(rom[i]);
				pre = rcti(rom[i - 1]);

					
				if (pre < cur) //no repeats
				{
					temp -= pre;
				}

				else if (pre >= cur) //no repeats
				{
					temp += pre;
				}
				
				
				
				value += temp;
			}
			if (value <= 0 || value > 3338)
				cout << "That was not a valid Roman Numeral! Program ending.\n";
			else
				cout << value;

		}
	}
	else
		cout << "That was not a valid Roman Numeral! Program ending.\n";


	
}


int rcti(char x) //Roman Character To Integer
{
	switch (x)
	{
	case 'M':
		return 1000;
		break;
	case 'D':
		return 500;
		break;
	case 'C':
		return 100;
		break;
	case 'L':
		return 50;
		break;
	case 'X':
		return 10;
		break;
	case 'V':
		return 5;
		break;
	case 'I':
		return 1;
		break;
	default:
		break;
	}
}

void intToRom()
{
	int integer, temp1;
	int thos, huns, tens, ones;
	string romNum = "";

	cout << "Enter an integer greater than 0 and less than 3889.\n";
	cin >> integer;
	if (integer < 1 || integer > 3889)
	{
		cout << "That number cannot be represented as a Roman Numeral! Program ending.\n";
	}
	else
	{
		
		{ //this block converts the breaks the integer into its constituent parts
			thos = integer % 10000;
			huns = integer % 1000;
			tens = integer % 100;
			ones = integer % 10;
			thos -= huns;
			huns -= tens;
			tens -= ones;
		}

		switch (thos)
		{
		case 3000:
			romNum += "MMM";
			break;
		case 2000:
			romNum += "MM";
			break;
		case 1000:
			romNum += "M";
			break;
		}

		switch (huns)
		{
		case 900:
			romNum += "CM";
			break;
		case 800:
			romNum += "DCCC";
			break;
		case 700:
			romNum += "DCC";
			break;
		case 600:
			romNum += "DC";
			break;
		case 500:
			romNum += "D";
			break;
		case 400:
			romNum += "CD";
			break;
		case 300:
			romNum += "CCC";
			break;
		case 200:
			romNum += "CC";
			break;
		case 100: 
			romNum += "C";
			break;
		}

		switch (tens)
		{
		case 90:
			romNum += "XC";
			break;
		case 80:
			romNum += "LXXX";
			break;
		case 70:
			romNum += "LXX";
			break;
		case 60:
			romNum += "LX";
			break;
		case 50:
			romNum += "L";
			break;
		case 40:
			romNum += "XL";
			break;
		case 30:
			romNum += "XXX";
			break;
		case 20:
			romNum += "XX";
			break;
		case 10: 
			romNum += "X";
			break;
		}

		switch (ones)
		{
		case 9:
			romNum += "IX";
			break;
		case 8:
			romNum += "VIII";
			break;
		case 7:
			romNum += "VII";
			break;
		case 6:
			romNum += "VI";
			break;
		case 5:
			romNum += "V";
			break;
		case 4:
			romNum += "IV";
			break;
		case 3:
			romNum += "III";
			break;
		case 2:
			romNum += "II";
			break;
		case 1:
			romNum += "I";
			break;
		}

		cout << romNum;
	}


}