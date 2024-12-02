/* Name: Bria Weisblat
Date: 10/24/2022
Section: 4
Assignment: Homework 5 Matrix Norms
Due Date: 11/04/2022
About this project: This program computes the 1 Norm or the Maximum Absolute Column Sum Norm of a matrix.
Assumptions: Assume that the user will only enter the proper type of data.


All work below was performed by Bria Weisblat */

#include <iostream>
using namespace std;

// Define constant variables
const int ROWCAP = 100;
const int COLCAP = 100;

// Function declarations
void initializeMatrix(double mat[][COLCAP], int numRows, int numColumns);
void printMatrix(double mat[][COLCAP], int numRows, int numColumns);
double findNorm (double mat[][COLCAP], int numRows, int numColumns);


int main() {

    int numRows;
    int numColumns;
    double mat[ROWCAP][COLCAP];


    cout << "Enter the number of rows: ";
    cin >> numRows;

    cout << "Enter the number of columns: ";
    cin >> numColumns;

    cout << "Enter the matrix: " << endl;
    initializeMatrix(mat, numRows, numColumns);

    cout << endl << "The matrix entered was:  " << endl;
    printMatrix(mat, numRows, numColumns);

    cout << endl << "The Maximum Absolute Column Sum Norm is: " << findNorm (mat, numRows, numColumns);

    return 0;
}

// Gets the matrix from the user
void initializeMatrix(double mat[][COLCAP], int numRows, int numColumns) {

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            cin >> mat[i][j];
        }
    }
}

// Prints the matrix
void printMatrix(double mat[][COLCAP], int numRows, int numColumns) {

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            cout <<  mat[i][j] << "\t";
        }
        cout << endl;
    }
}

double findNorm (double mat[][COLCAP], int numRows, int numColumns){
    double tempSum = 0;
    // Sets column sum to the smallest possible double, any column sum determined by the matrix will be higher for the first iteration
    // This ensures that the if-statement is entered
    double columnSum = -1.79769E+308;
    // Calculates a temporary sum for a column
    for (int j=0; j<numColumns; j++){
        for (int i=0; i<numRows; i++){
            tempSum += mat[i][j];
        }
        //Stores the tempSum in the columnSum variable if the tempSum is larger
        if (tempSum >= columnSum) {
            columnSum = tempSum;
        }
        tempSum = 0;
    }
    return columnSum;
}


