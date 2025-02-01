/*

? |Time to code a program that manages an ever-growing hungry integer array! The array
? |starts small with a size of 5, but every time you keep stuffing it with numbers and it gets
? |full, it will double in size to satisfy its appetite. Once you're done feeding it all the elements,
? |the array will go on a diet and shrink down to perfectly fit the number of elements it holds.
? |No wasted space, no extra fluff—just a happy, well-fed array.

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;





int main(){


    int *arr = new int[5];
    int size = 5;
    int index = 0;
    int num;
    char choice='y';

    while (choice == 'y'){
        cout << "Enter a number: ";
        cin >> num;

        // when exceeding size of array
        if (index == size)
        {
            // double temp array size
            int *temp = new int[size * 2];
            for (size_t i = 0; i < size; i++)
            {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
            size *= 2;
        }

        arr[index] = num;
        index++;

        cout << "Do you want to enter another number? (y/n): ";
        cin >> choice;
    }

    // after adding all elements, shrink the array to the size 'index'
    int *temp = new int[index];
    
    for (size_t i = 0; i < index; i++)
    {
        temp[i] = arr[i];
    }
    
    // deallocate memory
    delete[] arr;
    
    // assign temp to arr
    arr = temp;

    cout << "The array is: ";
    for (size_t i = 0; i < index; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}