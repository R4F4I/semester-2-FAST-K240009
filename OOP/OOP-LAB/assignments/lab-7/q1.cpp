/*

? |

Imagine developing a comprehensive banking system simulator for a prominent financial
institution. 

@In this system, 

- a base class called `Account` encapsulates essential data members such as 
    - accountNumber, 
    - balance, 
    - accountHolderName, and optionally 
    - accountType. 
- It offers member functions like 
    - deposit(amount) to add funds, 
    - withdraw(amount) to remove funds with proper error checking, 
    - calculateInterest() to compute interest based on varying rules,
    - printStatement() to output detailed transaction histories, and 
    - getAccountInfo() to retrieve general account details.


- Derived classes like 
    - `SavingsAccount`, 
    - `CheckingAccount`, and 
    - `FixedDepositAccount` 

- extend this structure by incorporating specialized data members—such as 
    interestRate and 
    minimumBalance for 
        SavingsAccount 
- or 
    maturityDate and 
    fixedInterestRate for 
        FixedDepositAccount. 
    
    
- These derived classes override key functions like 
    calculateInterest() and 
    printStatement() 
- to provide account-type-specific functionalities. 

- Additionally, the withdraw() function is overridden in specific accounts to apply different transaction rules,
- ensuring that each account type follows realistic banking policies while maintaining polymorphic behavior.

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;

class Account
{
private:
    int accountNumber, balance;
    string accountHolderName, accountType;
public:

    Account(int a, int b, string n="default", string t="default") : accountHolderName(n), accountType(t) {
        this->accountNumber = a;
        this->balance = b;
    }

    //                  v`` change in practice of defining getter
    int getBalance() const {
        return balance;
    }

    void setBalance(int amount) {
        balance = amount;
    }

    void deposit(int amount)// to add 
    {
        this->balance+=amount;
    }
    void withdraw(int amount)// remove funds with  error checking,  
    {
        if (this->balance-amount>=0) {
            this->balance-=amount;
        } else
        {
            cout << "Insufficient balance" << endl;
        }
    }
    void calculateInterest() // compute interest
    {
        cout << "Interest calculated" << endl;
    }
    void printStatement() //outputs transaction histories for default account
    {
        cout<< "statement printed"<<endl;
    }
    void getAccountInfo() //to retrieve general account details.
    {
        cout << "Account Number: "<< this->accountNumber << endl;
        cout << "Account Holder Name: "<< this->accountHolderName << endl;
        cout << "Account Type: "<< this->accountType << endl;
        cout << "Balance: "<< this->balance << endl;
    }

    

};

class SavingsAccount : public Account
{
    int interestRate,minimumBalance;
public:

    SavingsAccount(int a, int b, string aHn, string aT, int i, int mB) : Account(a,b, aHn,aT), interestRate(i), minimumBalance(mB) {}

    void calculateInterest() //to compute interest based on varying rules,
    {
        cout << "Interest calculated for savings account" << endl;
    }
    void printStatement(){
        cout << "Statement printed for savings account" << endl;
    }

    void getAccountInfo(){
        Account::getAccountInfo();
        cout << "Interest Rate: "<< this->interestRate << endl;
        cout << "Minimum Balance: "<< this->minimumBalance << endl;

    }
};
class CheckingAccount : public Account
{
public:

    CheckingAccount(int a, int b, string aHn, string aT) : Account(a,b, aHn,aT) {}

    void withdraw(int amount)// remove funds with  error checking, 
    {
        int bal = getBalance();
        //              v`` different transaction rule
        if (bal-amount>=500) {
            setBalance(bal-amount);
        } else
        {
            cout << "Insufficient balance" << endl;
        }
    }


};
class FixedDepositAccount : public Account
{
    int maturityDate,fixedInterestRate;
public:

    FixedDepositAccount(int a, int b, string aHn, string aT) : Account(a,b, aHn,aT) {}

    void calculateInterest() 
    {
        cout << "Interest calculated for fixed deposit account" << endl;
    }
    void printStatement(){
        cout << "Statement printed for fixed deposit account" << endl;
    }

    void getAccountInfo(){
        Account::getAccountInfo();
        cout << "Maturity Date: "<< this->maturityDate << endl;
        cout << "Fixed Interest Rate: "<< this->fixedInterestRate << endl;

    }

};






int main(){

    Account a1(1,1000,"Alice","default");
    a1.deposit(1000);
    a1.withdraw(500);
    a1.calculateInterest();
    a1.printStatement();
    a1.getAccountInfo();

    std::cout << "\n --- \n" << std::endl;
    
    SavingsAccount s1(2,2000,"Bob","Savings",2,500);
    s1.deposit(1000);
    s1.withdraw(500);
    s1.calculateInterest(); 
    s1.printStatement();
    s1.getAccountInfo();
    
    std::cout << "\n --- \n" << std::endl;
    CheckingAccount c1(3,3000,"Chow","Checking");
    c1.deposit(1000);
    c1.withdraw(500);
    c1.calculateInterest();
    c1.printStatement();
    c1.getAccountInfo();
    
    std::cout << "\n --- \n" << std::endl;
    
    FixedDepositAccount f1(4,4000,"Darwin","Fixed Deposit");
    f1.deposit(1000);
    f1.withdraw(500);
    f1.calculateInterest();
    f1.printStatement();
    f1.getAccountInfo();
    
    std::cout << "\n --- \n" << std::endl;







    return 0;
}