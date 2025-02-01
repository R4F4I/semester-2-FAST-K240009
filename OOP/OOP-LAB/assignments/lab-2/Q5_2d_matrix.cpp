/*

? |You need to make a program that works like a Matrix Wizard. First, it will ask the user for
? |the size of a 2D matrix and then create it using memory magic (dynamic allocation). Next,
? |the program will fill the matrix with numbers given by the user. After that, it will show off
? |by doing matrix addition, subtraction, and multiplication (only if the sizes match). Finally,
? |it will display the results and clean up the memory like a good, tidy wizard.

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;


int main(){

    int rows, cols;
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;

    int **matrix1 = new int*[rows];
    int **matrix2 = new int*[rows];

    for (size_t i = 0; i < rows; i++)
    {
        matrix1[i] = new int[cols];
        matrix2[i] = new int[cols];
    }

    // fill matrix1
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            cout << "Enter the elements of matrix1: " << endl;
            cin >> matrix1[i][j];
        }
    }
    // fill matrix2
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            cout << "Enter the elements of matrix2: ";
            cin >> matrix2[i][j];
        }
    }
    
    // display matrix1
    cout << "Matrix1: " << endl;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            cout << matrix1[i][j] << " ";
        }
        cout << endl;
    }
    // display matrix2
    cout << "Matrix2: " << endl;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }
    // matrix addition
    cout << "Matrix Addition: " << endl;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            cout << matrix1[i][j] + matrix2[i][j] << " ";
        }
        cout << endl;
    }
    // matrix subtraction
    cout << "Matrix Subtraction: " << endl;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            cout << matrix1[i][j] - matrix2[i][j] << " ";
        }
        cout << endl;
    }
    // matrix multiplication
    cout << "Matrix Multiplication: " << endl;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            cout << matrix1[i][j] * matrix2[i][j] << " ";
        }
        cout << endl;
    }
    // deallocate memory
    for (size_t i = 0; i < rows; i++)
    {
        delete[] matrix1[i];
        delete[] matrix2[i];
    }
    delete[] matrix1;
    delete[] matrix2;




    return 0;
}