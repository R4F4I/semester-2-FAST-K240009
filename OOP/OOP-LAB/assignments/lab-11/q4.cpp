#include <iostream>
#include <exception>
using namespace std;

///////////////////////////////////////////////////////////////
// Task 4: BankAccount class with custom exception
class InsufficientFundsException : public exception {
public:
    const char* what() const noexcept override {
        return "Insufficient funds to complete withdrawal!";
    }
};

class BankAccount {
    double balance;
public:
    BankAccount(double b) : balance(b) {}

    void withdraw(double amount) {
        if (amount > balance)
            throw InsufficientFundsException();
        balance -= amount;
        cout << "Withdrawal successful! New Balance: $" << balance << endl;
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount account(500);
    cout << "Current Balance: $" << account.getBalance() << endl;

    cout << "Enter withdrawal amount: $";
    double amount;
    cin >> amount;

    try {
        account.withdraw(amount);
    } catch (const InsufficientFundsException &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}