/* 
    name:  rafay siddiqui
    class: BAI-2A
    roll:  24K-0009

Write a program to make a simple calculator performing the four basic operations (+, -, *, /) on
two numbers input by user. The following conditions must be satisfied:
a) A ‘+’ sign must not be used for addition.
b) You can only use a maximum of 3 variables. No more variables are allowed.
c) Your program should ask the user which operation he/she wants to perform and gives the
output accordingly.

 */

#include <iostream>

using namespace std;


int main(){
    int num1,num2,op,res;

    cout<<"enter num1: ";
    cin>>num1;
    cout<<"enter num2: ";
    cin>>num2;
    cout<<"\n 1: '+'\n 2: '-'\n 3: '*'\n 4: '/' \nenter operation: ";
    cin>>op;

    switch (op)
    {
    case 1:
        res = num1 - (-num2) ;
        break;
    case 2:
        res = num1 - num2 ;
        break;
    case 3:
        res = num1 * num2;
        break;
    case 4:
        res = num1 / num2;
        break;
    
    default:
        break;
    }
    cout<<"res: "<<res;
}