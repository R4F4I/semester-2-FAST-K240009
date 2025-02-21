
#include <iostream> 
using namespace std;

// class with static memebers example

class Account
{
public:
    int accno, balance, interestOwed;
    string name; // data member (also instance variable)

static float rateOfInterest; //static variable and will be shared in all instances of objects

    Account(int accno, string name, int balance)
    {
        this->accno = accno;
        this->name = name;
        this->balance = balance;
        this->interestOwed = balance*rateOfInterest/100;
    }
    void display()
    {
        cout << accno << " " << name << " " << rateOfInterest<< " " <<interestOwed << endl;
    }
};

float Account::rateOfInterest = 6.5;

int main()
{
    Account a1 = Account(7840, "Shafique",1000);
    Account a2 = Account(7841, "Ahmed",2000);
    a1.display();
    a2.display();
    return 0;
}