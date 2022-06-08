#include <iostream>

using namespace std;

const int SIZE = 5;

void populator(int, int (&Array)[SIZE][SIZE][SIZE][SIZE][SIZE]);

int main(int argc, char** argv) {
    int base[SIZE][SIZE][SIZE][SIZE][SIZE] = {};
    int size, start, end; //dimensional size, start index for summing, end index for summing
    int filler = 1; //will act simultaneously as a counter and as the value we are filling the array with
    int sum = 0; //the sum we will return


    /*if (argc >= 4 && (atoi(argv[2]) >= 0 && atoi(argv[2]) <= 4) && (atoi(argv[3]) >= 0 && atoi(argv[3]) <= 4) && (atoi(argv[2]) <= atoi(argv[3])))
    {
        size = atoi(argv[1]);
        start = atoi(argv[2]);
        end = atoi(argv[3]);
    }


    else
    {
        size = 0;
        start = 0;
        end = 0;

        if (argc < 4)
        cout << "You did not give enough inputs. Program ending.";

        else if (atoi(argv[3]) > atoi(argv[1]) || atoi(argv[2]) > atoi(argv[1]))
            cout << "The start and end value must be less than or equal to the dimensionality of the array. Program ending.";

        else if (atoi(argv[2]) < 0 || atoi(argv[2]) > 4 || atoi(argv[3]) < 0 || atoi(argv[3]) > 4)
            cout << "The start and end values must be between 0 and 4, inclusive. Program ending.";

        else if (atoi(argv[2]) > atoi(argv[3]))
            cout << "The starting value must be less than or equal to the ending value. Program ending.";

        return 0;
    }*/

    if (argc >= 4)
    {
        size = atoi(argv[1]);
        start = atoi(argv[2]);
        end = atoi(argv[3]);
    }

    else
    {
        size = 0;
        start = 0;
        end = 0;
        cout << "Not enough inputs. Program ending.\n";
        return 0;
    }

    if (size < 1 || size > 5) //error
    {
        cout << "The dimensions must be between 1 and 5, inclusive. Program ending.\n";
        return 0;
    }

    else if (start >= size || end >= size) //error
    {
        cout << "The start and end indices must be less than the dimensionality. Program ending.\n";
        return 0;
    }

    else if (start > end) //error
    {
        cout << "The start must be less than or equal to the end. Program ending.\n";
        return 0;
    }

    else if (start < 0 || start > 4 || end < 0 || end > 4) //error
    {
        cout << "The start and end values must be between 0 and 4. Program ending.\n";
        return 0;
    }

  


    switch (size) //this will fill our array 'base'. This is what we wanted in our 'populator' function
    {
    case 1: //a 1x1 array
    {
        base[0][0][0][0][0] = 1;
        sum = 1;

    }
    break;

    case 2: //a 2x2 array
    {
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                base[i][j][0][0][0] = filler;
                ++filler;
            }

        }
    }
    for (int i = start; i <= end; ++i)
    {
        sum += base[i][i][0][0][0];
    }
    break;

    case 3: //a 3x3x3 array
    {
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                for (int k = 0; k < size; ++k)
                {
                    base[i][j][k][0][0] = filler;
                    ++filler;
                }
            }
        }
    }
    for (int i = start; i <= end; ++i)
    {
        sum += base[i][i][i][0][0];
    }
    break;

    case 4: //a 4x4x4x4 array
    {
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                for (int k = 0; k < size; ++k)
                {
                    for (int l = 0; l < size; ++l)
                    {
                        base[i][j][k][l][0] = filler;
                        ++filler;
                    }
                }
            }
        }   
    }
    for (int i = start; i <= end; ++i)
    {
        sum += base[i][i][i][i][0];
    }
    break;

    case 5: //a 5x5x5x5x5 array
    {
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                for (int k = 0; k < size; ++k)
                {
                    for (int l = 0; l < size; ++l)
                    {
                        for (int m = 0; m < size; ++m)
                        {
                            base[i][j][k][l][m] = filler;
                            ++filler;
                        }
                    }
                }
            }
        }
    }
    for (int i = start; i <= end; ++i)
    {
        sum += base[i][i][i][i][i];
    }
    break;
    }


    cout << sum << endl;

    return 0;
}


/* Still need to:
1) Figure out test case 2
2) do error outputs for invalid inputs
3) beautification */