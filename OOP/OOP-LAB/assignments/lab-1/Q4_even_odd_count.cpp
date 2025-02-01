/*

? |Write a program to take an integer array as an input from user and count all the even and odd numbers in that list and print the counts.

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

    int n;
    printf("Enter the size of the array: ");
    cin >> n;
    int arr[n];
    int even = 0, odd = 0;
    for(int i = 0; i < n; i++){
        cout <<"Enter element " << i << ": ";
        cin >> arr[i];
        if(arr[i] % 2 == 0){
            even++;
        }
        else{
            odd++;
        }
    }
    cout << "Even numbers: " << even << endl;
    cout << "Odd numbers: " << odd << endl;


    return 0;
}