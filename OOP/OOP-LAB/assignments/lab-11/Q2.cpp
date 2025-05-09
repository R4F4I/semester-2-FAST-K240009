#include <iostream>
#include <stdexcept>
using namespace std;

///////////////////////////////////////////////////////////////
// Task 2: Division with exception handling
void safeDivide() {
    int numerator, denominator;
    cout << "Enter numerator: ";
    cin >> numerator;
    cout << "Enter denominator: ";
    cin >> denominator;

    try {
        if (denominator == 0)
            throw runtime_error("Division by zero is not allowed!");
        cout << "Result: " << numerator / denominator << endl;
    } catch (const runtime_error &e) {
        cout << "Error: " << e.what() << endl;
    }
}

int main() {
    safeDivide();
    return 0;
}