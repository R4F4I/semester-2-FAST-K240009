#include <iostream>

using namespace std;


/*

? |
Imagine you're stuck counting days instead of months—sounds confusing, right? Now, create a
class called DayOfYear that takes a simple number (representing a day of the year) and turns it
into something more useful, like "March 15" or "October 31"—basically, a proper date! For
example, if you enter 2, it should say "January 2," and if you go for 365, it should proudly declare
"December 31." The class should have a constructor that takes this number and a print() function
to display the month and day. Inside the class, store the day as an integer and use some static
string variables to help with the conversion. Finally, test your class—enter different numbers and
see how well it translates them into real dates!

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>
#include <cstring>

using namespace std;

class DayOfYear
{
private:
    int months[12] = {31,28,31,30,31,30,31,31,30,31,30,32}; // extra day in dec to deal with zero error
    string monthsName[12] = {"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"};
    int day;


public:

    DayOfYear(int day){
        this->day = day;
    }

void getDate(){
    int temp=0;
    int date=this->day;
    string monthName;
    for (size_t i = 0; i < 12; i++)
    {

        if (date<this->months[i])
        {
            monthName = monthsName[i];
            break;
        }
        date-=months[i];
    }
    // int date = this->day - temp;
    cout<<monthName<<" "<<date<<endl;

}


};

int main(){

    DayOfYear s1(365);
    s1.getDate();


    return 0;
}