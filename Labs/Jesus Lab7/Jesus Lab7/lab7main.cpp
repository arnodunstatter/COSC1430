//Name: Jesus Barrios
//ID: 1280333
//Lab7
//16th of June, 2020

#include <iostream>
#include <limits>
#include "matrix.h"
using namespace std;

//Function Declarations
//allow : clears bad inputs
void allow();

//numMatrix : input # of matrices
int numMatrix();

//setter : User inputs dimensions per matrix, and matrix is initialized + filled
void setter(Matrix** matptr,const int nums);

//reminder : Prints out created matrices to output
void reminder(Matrix** matptr, const int nums);

//looper : Main loop of program. Chooses what calculation to do (+ - or *), which matrices to choose, and outputs result
void looper(Matrix** matptr, const int nums);

//menuSelect : choosing a menu action
int menuSelect();

//matrixSelection : choose what 2 matrices to use for calculation
int matrixSelection(int i, const int n);

//calc_out : calculates the result chosen by user, and outputs it to the console
void calc_out(int select, Matrix ** matptr, const int mats[]);

//cleaner : wraps up the program by deleting the used heap memory
void cleaner(Matrix** matptr, const int nums);

//------------------------------------------------------------------------------------------------------------------------------------------------------
//Main
int main(){
    //Input Phase 1 - Creation of Matrix objects and pointer to Matrix type
    int nums = numMatrix();
    Matrix** matptr = new Matrix* [nums];


    //Input Phase 2 - Setting Size to each Matrix and filling their contents
    setter(matptr, nums);


    //Output Phase 1 - Remind user what matrices have been created
    reminder(matptr, nums);


    //Menu + Processing + Output Phase
    looper(matptr, nums);


    //Memory Cleanup
    cleaner(matptr,nums);


    return 0;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------
//Functions

//allow : clears bad inputs
void allow(){
    //In case of bad input
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//numMatrix : input # of matrices
int numMatrix(){
    //Local Variables
    int matrices=0, check=0, limit = 10; //Limit is set to keep things simple, this can be adjusted

    do{
        //Users inputs however many matrices they want, within reason
        cout << "Please enter # of matrices to be created (from 2 up to " << limit << " for simplicity's sake): ";
        check = scanf("%i", &matrices);

        //Quality Control of Input
        if(check != 1 || matrices < 2 || matrices > limit){
            cout <<"You did not enter a valid input, try again.\n\n";
            allow();
        }
    }while(check != 1 || matrices < 2 || matrices > limit);

    //End function
    cout << "\n";
    return matrices;
}

//setter : User inputs dimensions per matrix, and matrix is initialized + filled
void setter(Matrix** matptr,const int nums){

    //Initialize as many times as there are supposed to be matrices
    for(int j=0; j<nums; j++){

        //Local Variables
        int sample[2];
        int flag = 0;

        //Input Phase - Row and Column Sizes
        do{
            //User input
            cout << "For Matrix " << j+1 << ", please enter row and column size, separated by a space: ";
            for(int i=0; i<2; i++){
                cin >> sample[i];
            }

            //Quality Control
            if(cin.fail()==1){
                cout << "You entered the integers wrong. Try Again.\n\n";
                allow();
            }
            else{
                flag=1;
            }

        }while(!flag);


        //Create matrix and call member function to fill them
        matptr[j] = new Matrix(sample[0],sample[1]);
        matptr[j]->setElements();

        cout << "-----------------------------------------------------------------\n\n";
    }
}

//reminder : Prints out created matrices to output
void reminder(Matrix** matptr, const int nums){
    for(int i=0; i<nums; i++){
        cout << "Matrix " << i+1 << " is: \n";
        cout << *matptr[i] << "\n";
    }
    cout << "-----------------------------------------------------------------\n\n";
}

//looper : Main loop of program. Chooses what calculation to do (+ - or *), which matrices to choose, and outputs result
void looper(Matrix** matptr,int nums){
    while(true){
        //Input Phase 3 - Choosing what calculation to do
        int select = menuSelect();


        //Control - Quit Program
        if(select == 4){
            cout << "\nQuiting Program...\n\n";
            break;
        }


        //Input Phase 4 - Choosing which 2 matrices to use for calculation
        int mats[2] = {0};
        for(int i=0; i<2; i++){
            mats[i] = matrixSelection(i, nums);
        }


        //Process and Output Phase 1 - Attempt to perform calculation, then output the results
        calc_out(select, matptr, mats);
        cout << "-----------------------------------------------------------------\n\n";
    }

}

//menuSelect : choosing a menu action
int menuSelect(){
    int check = 0, selection = 0;
    do{
        cout << "Menu: " << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Quit Application" << endl;
        cout << "Select one of the operations (1 through 4): ";

        check = scanf("%d", &selection);

        //Check for bad input
        if(check != 1 || selection<1 || selection>4){
            cout << "\nYou have not entered a proper digit.\n";
            cout << "Going back to menu...\n\n";
            allow();
        }
    }while(check != 1 || selection<1 || selection>4);

    return selection;
}

//matrixSelection : choose what 2 matrices to use for calculation
int matrixSelection(int i, const int n){
    int check = 0, val = 0;

    do{
        //User input
        if(i == 0)
            cout << "\nPlease select from " << 1 << " through " << n <<", which matrix you want to use (LEFT of operator): ";
        if(i == 1)
            cout << "Please select from " << 1 << " through " << n <<", which matrix you want to use (RIGHT of operator): ";

        check = scanf("%i", &val);

        //Quality Control
        if(check != 1 || val < 1 || val > n){
            cout <<"You did not enter a valid input, try again.\n\n";
            allow();
        }
    }while(check != 1 || val < 1 || val > n);

    return val-1;
}

//calc_out : calculates the result chosen by user, and outputs it to the console
void calc_out(int select, Matrix ** matptr, const int mats[]){
    try{
        cout << "\n";
        switch(select){
            case 1:
                cout << "The resulting matrix from the calculation of \n" << *matptr[mats[0]] << "+ \n" << *matptr[mats[1]] << "is: \n";
                cout << *matptr[mats[0]] + *matptr[mats[1]];
                break;
            case 2:
                cout << "The resulting matrix from the calculation of \n" << *matptr[mats[0]] << "- \n" << *matptr[mats[1]] << "is: \n";
                cout << *matptr[mats[0]] - *matptr[mats[1]];
                break;
            case 3:
                cout << "The resulting matrix from the calculation of \n" << *matptr[mats[0]] << "* \n" << *matptr[mats[1]] << "is: \n";
                cout << *matptr[mats[0]] * *matptr[mats[1]];
                break;
        }
    }
    catch(int x){
        if(x==1)
            cout << "Incompatible matrix due to wrong row and column sizes, try again.\n\n";
        if(x==2)
            cout << "Incompatible matrix due to wrong column sizes, try again.\n\n";
        if(x==3)
            cout << "Incompatible matrix due to wrong row sizes, try again.\n\n";
    }


}

//cleaner : wraps up the program by deleting the used heap memory
void cleaner(Matrix** matptr, const int nums){
    for(int i = 0; i < nums; i++){
        delete matptr[i];
    }
    delete [] matptr;
}
