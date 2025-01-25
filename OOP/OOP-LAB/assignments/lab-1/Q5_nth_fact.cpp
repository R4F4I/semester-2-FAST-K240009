/*

? |Write a function that will take a number n; input by user and will return its factorial.

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-1A


*/

#include <iostream>

using namespace std;

void printf(string str){
cout << str;
}




int main(){

    unsigned n,fact=1;
    printf("Enter a number: ");
    cin >> n;
    while (n>0)
    {fact*=n--;}
    
    cout << "Factorial: " << fact << endl;


    return 0;
}