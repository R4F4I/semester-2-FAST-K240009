/*

? |You are hired as a billing manager at K-Electric. Your task is to calculate the monthly bill
? |according to the units consumed. Write a program to input electricity unit charge and calculate the
? |total electricity bill according to the given condition:
? |     For first 50 units Rs. 0.50/unit
? |     For next 100 units Rs. 0.75/unit
? |     For next 100 units Rs. 1.20/unit
? |     For unit above 250 Rs. 1.50/unit
? |An additional surcharge of 20% is added to the bill.

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

    float bill;
    int units;

    cout<< "Enter the number of units consumed: ";
    cin >> units;

    if (units>=250)
    {
        //     1st 50 u  next 100 u  next 100 u  above 250 u
        bill = 0.50*50 + 0.75*100 + 1.20*100 + 1.50*(units-250);
    } 
    else if (units>=150)
    {
        //     1st 50 u  next 100 u  next 100 u
        bill = 0.50*50 + 0.75*100 + 1.20*(units-150);
    } 
    else if (units>=50)
    {
        //     1st 50 u  next 100 u
        bill = 0.50*50 + 0.75*(units-50);
    } 
    else
    {
        //     1st 50 u
        bill = 0.50*units;
    }
    
    bill = 1.2*bill;

    cout << "Total electricity bill (including surcharge): Rs. " << bill <<".00"<< endl;

    return 0;
}