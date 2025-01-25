/* 
    name:  rafay siddiqui
    class: BAI-2A
    roll:  24K-0009

Imagine you are working on a project where the efficient generation of odd numbers is crucial.
Your task is to write a C++ function that prints an odd number after every sequence of 5 even
numbers in the range provided by the user. The catch is that you need to optimize the program for
both correctness and efficiency.
 */


#include <iostream>

using namespace std;


int main()
{
    int count;
    cout<<"Enter range: ";
    cin>>count;
    int range = 5;
    for (int i = 1; i < count; i++)
    {
        if (i% 2 != 0 && range == 1)
        {
            cout<<i<<" ";
            range = 5;
        }
        else if (i% 2 == 0){
            cout<<i<<" ";
            range--;
        }
    }

    return 0;
}