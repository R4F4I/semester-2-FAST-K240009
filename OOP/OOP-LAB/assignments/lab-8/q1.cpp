/*

? |

1. Distance Calculation
Create two C++ classes, `Speed` (in km/h) and `Time` (in hours), to calculate distance using the formula:  
**Distance = Speed × Time**.  

### Goal:
Write a `calculateDistance()` function to compute the distance using private members of both classes. Instantiate objects in `main()` and display the result.

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;

class Time; // forward declaration

class Speed
{
private:
    double val; // speed in km/h
public:
    Speed(double v = 0){val=v;}

    friend double calculateDistance(Speed s, Time t);

};

class Time
{
private:
    double val; // time in hours
public:
    Time(double v = 0){val=v;}

    friend double calculateDistance(Speed s, Time t);
};


double calculateDistance(Speed s, Time t)
{
    return s.val * t.val;
}

int main(){

    Speed speed(30);
    Time time(20);

    std::cout << "dist:" << calculateDistance(speed,time) << std::endl;


    return 0;
}