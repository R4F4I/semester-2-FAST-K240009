/* 

Implement a function that dynamically allocates an array of integers. The function should
take an integer parameter specifying the number of elements to allocate and return a pointer
to the allocated array.

name: rafay siddiqui
roll num: 24k-0009
class: bai-2a


 */

#include <iostream>

using namespace std;


int* allocArr(int *arr, int newSize){
    int *newArr = new int[newSize];
    return newArr;
}



int main(){


    int *arr = allocArr(arr,10);

    for (size_t i = 0; i < 10; i++)
    {
        arr[i]=i;
        cout<<arr[i]<<" ";
    }
    
    

    return 0;
}