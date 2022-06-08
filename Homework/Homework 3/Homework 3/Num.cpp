#include "Num.h"
#include <iostream>


Num::Num(string temp)
	:StringNum(temp), num(setNum(temp)) {}



int Num::setNum(string temp)
{
	//some variables used in various cases:
	string number; //used for case 2, where the temp is a number in written form
	int sum, difference, modulate; //sum is used in case 3 (addition), difference and modulate are used in case 4 (subtraction)
	switch(getNumType())
	{
	case 1: //it's an integer
		num = stoi(getInputData());
		break;
	case 2:
		number = "";
		for (int i = 0; i < temp.length(); ++i) //this cuts off ' word' from our 'number word' line held in temp
		{
			if (temp[i] == ' ' || temp[i] == '\0')
				break;
			else
				number += temp[i]; 
		}
		if (number == "one")
			num = 1;
		else if (number == "two")
			num = 2;
		else if (number == "three")
			num = 3;
		else if (number == "four")
			num = 4;
		else if (number == "five")
			num = 5;
		else if (number == "six")
			num = 6;
		else if (number == "seven")
			num = 7;
		else if (number == "eight")
			num = 8;
		else if (number == "nine")
			num = 9;
		else if (number == "zero")
			num = 0;
		break;
	case 3:
		sum = 0;
		for (int i = 0; i < temp.length(); ++i)
		{
			if (temp[i] == '1' || temp[i] == '2' || temp[i] == '3' || temp[i] == '4' || temp[i] == '5' || temp[i] == '6' || temp[i] == '7' || temp[i] == '8' || temp[i] == '9' || temp[i] == '0')
			{
				number = temp[i];
				sum += stoi(number);
			}
		}
		num = sum;
		break;
	case 4:
		difference = 0;
		modulate = 1;
		for (int i = 0; i < temp.length(); ++i)
		{
			if (temp[i] == '1' || temp[i] == '2' || temp[i] == '3' || temp[i] == '4' || temp[i] == '5' || temp[i] == '6' || temp[i] == '7' || temp[i] == '8' || temp[i] == '9' || temp[i] == '0')
			{
				number = temp[i];
				difference += modulate * stoi(number);
			}
			else if (temp[i] = '-')
				modulate = -1;
		}
		num = difference;
		break;
	}
	return num;
}

int Num::getNum() { return num; }