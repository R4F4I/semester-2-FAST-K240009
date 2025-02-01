/*

? |Create a program that moonlights as a basic calculator, wielding the power of pointer
? |arithmetic to crunch numbers like a pro. It should charm the user into entering two integers,
? |perform addition, subtraction, multiplication, or division (depending on the user's mood),
? |and then proudly display the result. Use pointers to juggle values between functions and
? |make the magic happen.

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;





int main(){

    int a, b;
    int *ptr1 = &a;
    int *ptr2 = &b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    char op;
    cout << "Enter the operation you want to perform (+, -, *, /): ";
    cin >> op;

    switch (op)
    {
    case '+':
        cout << "The sum of " << a << " and " << b << " is " << *ptr1 + *ptr2 << endl;
        break;
    case '-':
        cout << "The difference of " << a << " and " << b << " is " << *ptr1 - *ptr2 << endl;
        break;
    case '*':
        cout << "The product of " << a << " and " << b << " is " << *ptr1 * *ptr2 << endl;
        break;
    case '/':
        cout << "The division of " << a << " and " << b << " is " << *ptr1 / *ptr2 << endl;
        break;
    default:
        cout << "Invalid operation" << endl;
        break;
    }




    return 0;
}