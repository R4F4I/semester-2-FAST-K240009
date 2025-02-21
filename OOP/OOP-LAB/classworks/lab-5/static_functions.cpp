// can only work with static data members, no intance needed to call them

/*

? |

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;

class Bank { 
    private:
    string accountHolder;
    double balance;
static double totalBalance;
    
public:
    Bank(string name, double initialBalance):  accountHolder (name), balance(initialBalance) {
        totalBalance += initialBalance;
    }
    void deposit (double amount) {
        totalBalance += amount;
        balance += amount;
        cout << "Deposited account." << amount << "into" << accountHolder << " " <<endl;
    }
    
    void withdraw(double amount){
    
        if (amount>balance){
            cout<<"insuffiecent balance in "<<this->accountHolder<<endl;
        } else {
            balance-=amount;
            totalBalance-=amount;
            cout<<"withdarwn"<<amount<< "from"<<accountHolder<<endl;
        }       
    }
    
        static double getTotalBalance(){
            return totalBalance;    
        }
        void displayAccount(){
            cout<<"acoutn holder: "<< accountHolder<<endl;
            cout<<"balance: "<< balance<<endl;
        }
    
    
    };
    
    double Bank::totalBalance = 1000;
    
    
    int main(){
    
        Bank ac1("Sfigqy",1000);
        Bank ac2("Sfigq",3000);
    
        cout<<"total bank: "<< Bank::getTotalBalance()<<endl;
    
    
        return 0;
    }