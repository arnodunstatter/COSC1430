#include <iostream>

using namespace std;

//first our prototypes
void getJudgeData(double&); //gets input
double findLowest(double, double, double, double, double); //finds lowest score
double findHighest(double, double, double, double, double); //finds highest score
void calcScore(double, double, double, double, double);

//main integrates our two main functions
int main()
{
	double score[5] = {}; //our scores will be stored in an array
	for (int i = 0; i <= 4; ++i)
	{
		getJudgeData(score[i]);
	}

	cout << "The final score was ";
	calcScore(score[0], score[1], score[2], score[3], score[4]); //passes our values from our array to the function
	cout << ".\n";


	return 0;
}

void getJudgeData(double& score)
{
	//prompt user for input
	cout << "Please enter the judge's given score: ";
	cin >> score;
	while (score < 0 || score > 10) //performs validation. Score must be between 0 and 10, inclusive
	{
		cout << "That score was not valid. The score should be between 0 and 10. Please re-enter the judge's given score: ";
		cin >> score;
	}
}

//this will be called by calcScore
double findLowest(double score1, double score2, double score3, double score4, double score5) //uses a simple algorithm to return the lowest value from 5 given values
{
	double score[5] = { score1, score2, score3, score4, score5 };
	double lowest = score1;
	for (int i = 1; i <= 4; ++i)
	{
		if (lowest > score[i])
			lowest = score[i];
	}
	return lowest;
}

//this will be called by calcScore
double findHighest(double score1, double score2, double score3, double score4, double score5) //uses a simple algorithm to return the highest value from 5 given values
{
	double score[5] = { score1, score2, score3, score4, score5 };
	double highest = score1;
	for (int i = 1; i <= 4; ++i)
	{
		if (highest < score[i])
			highest = score[i];
	}
	return highest;
}

void calcScore(double score1, double score2, double score3, double score4, double score5)
{
	double score[5] = { score1, score2, score3, score4, score5 }; //makes cycling through the data easier
	double lowest = findLowest(score1, score2, score3, score4, score5);
	double highest = findHighest(score1, score2, score3, score4, score5);
	double sum = 0, scoreFinal;

	for (int i = 0; i <= 4; ++i) //this will add all of our scores to sum
	{
		sum += score[i];
	}

	sum = sum - highest - lowest; //this removes the highest and the lowest score from our sum

	scoreFinal = sum / 3; //averages the three middle scores

	cout << scoreFinal;
}