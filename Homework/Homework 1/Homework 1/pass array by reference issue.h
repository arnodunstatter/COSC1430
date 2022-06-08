#include <iostream>

using namespace std;

const int SIZE = 5;

void populator(int, int(&Array)[SIZE][SIZE][SIZE][SIZE][SIZE]);

int main(int argc, char** argv) {
    int base[SIZE][SIZE][SIZE][SIZE][SIZE] = {};
    int size, start, end;

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
    }

    populator(5, base);
    cout << base[5][5][5][5][5];





    return 0;
}

void populator(int size, int(&Array)[SIZE][SIZE][SIZE][SIZE][SIZE])
{
    Array[5][5][5][5][5] = 10;


}
