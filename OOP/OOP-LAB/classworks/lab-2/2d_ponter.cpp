
#include <iostream>
using namespace std;

int main()
{
    int rows = 3;
    int cols = 4;
    int **matrix = new int *[rows];
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new int[cols];
    }
    // Access and modify elements matrix[0][0] = 10; matrix[1][2] = 20;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
             matrix[i][j] = (i+1)*(i+1+j);
        }
    }
    // Display elements
    
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << endl;
    // Deal Locate memory
    for (int i = 0; i < rows; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}