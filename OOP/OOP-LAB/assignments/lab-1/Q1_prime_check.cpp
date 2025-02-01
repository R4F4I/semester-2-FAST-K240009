/*

? |Write a C++ program to check whether a given number is prime or not. Allow the user to input a
? |number and display whether it's prime or not?

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;

void printf(string str){
    cout << str;
}


int main(){

    int num,i;
    cout << "Enter a number: ";
    cin >> num;

    for (i = 2; i < num; i++)
    {
        if (num%i==0)
        {
            break;
        }
        
    }
    if (i==num){
        printf("The number is prime\n");
    }
    else{
        printf("The number is not prime\n");
    }
    


    return 0;
}