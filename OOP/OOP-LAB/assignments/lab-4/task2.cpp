/*

? |
Create a class called WeekDays that’s here to help you never lose track of what day it
is (because let’s face it, it happens). This class has two private data members:
• Days – A string array with the seven glorious days of the week (Sunday to
Saturday).
• CurrentDay – An integer variable to track which day you’re currently living
in.
Now, implement the following constructors and member functions:
• Default Constructor – Fills up the Days array with the usual suspects: Sunday,
Monday, Tuesday... you get it.
• Parameterized Constructor – Takes an integer for CurrentDay. If the value
is greater than 6 (because there’s no Day 8), do some math magic with modulus
(%) to bring it back within range. For example, if the input is 8, 8 % 7 = 1, so
CurrentDay becomes Monday. Oh, and don’t forget to fill the Days array too.
• getCurrentDay – Returns the name of the current day. (Think
Days[CurrentDay].)
• getNextDay – Returns the name of tomorrow, because who doesn’t want to
know what day’s coming next?
• getPreviousDay – Returns yesterday’s name, just in case you’re feeling
nostalgic.
• getNthDayFromToday – Takes an integer N and tells you what day it will be
N days from now. For example, if today is Monday and N = 20, it’ll tell you
that it’s Sunday in 20 days. Useful for planning vacations or just confusing
yourself for fun!

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;

class WeekDays
{
private:
    string Days[7];
    int CurrentDay;

public:
    WeekDays(){
        CurrentDay=0;
        Days[0] = "monday";
        Days[1] = "tuesday";
        Days[2] = "wednesday";
        Days[3] = "thursday";
        Days[4] = "friday";
        Days[5] = "saturday";
        Days[6] = "sunday";
    }
    WeekDays(int currDay){
        if (currDay>7)
        {
            currDay%=7;
        }
        CurrentDay = currDay;
        Days[0] = "monday";
        Days[1] = "tuesday";
        Days[2] = "wednesday";
        Days[3] = "thursday";
        Days[4] = "friday";
        Days[5] = "saturday";
        Days[6] = "sunday";
        
    }
    string getCurrentDay(){
        return Days[CurrentDay];
    }
    string getNextDay(){
        return Days[(CurrentDay+1)%7];
    }
    string getPreviousDay(){
        return Days[(CurrentDay-1)%7];
    }
    string getNthDayFromToday(int N){
        return Days[(CurrentDay+N)%7];
    }

};


int main(){

    WeekDays d1(4);

    cout<<d1.getCurrentDay()<<"\n";
    cout<<d1.getNextDay()<<"\n";
    cout<<d1.getPreviousDay()<<"\n";
    cout<<d1.getNthDayFromToday(20)<<"\n";




    return 0;
}