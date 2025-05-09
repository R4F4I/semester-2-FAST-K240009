#include <iostream>
#include <exception>
using namespace std;

///////////////////////////////////////////////////////////////
// Task 6: Specific exceptions for multiple validations
class InvalidAgeException : public exception {
public:
    const char* what() const noexcept override {
        return "Age must be between 1 and 119";
    }
};

class InvalidSalaryException : public exception {
public:
    const char* what() const noexcept override {
        return "Salary must be positive";
    }
};

class InvalidHeightException : public exception {
public:
    const char* what() const noexcept override {
        return "Height must be positive";
    }
};

void validateUserProfile() {
    int age;
    double salary, height;

    try {
        cout << "Enter age: ";
        cin >> age;
        if (age <= 0 || age >= 120)
            throw InvalidAgeException();

        cout << "Enter salary: ";
        cin >> salary;
        if (salary <= 0)
            throw InvalidSalaryException();

        cout << "Enter height: ";
        cin >> height;
        if (height <= 0)
            throw InvalidHeightException();

        cout << "All inputs are valid!" << endl;

    } catch (const InvalidAgeException &e) {
        cout << "InvalidAgeException caught: " << e.what() << endl;
    } catch (const InvalidSalaryException &e) {
        cout << "InvalidSalaryException caught: " << e.what() << endl;
    } catch (const InvalidHeightException &e) {
        cout << "InvalidHeightException caught: " << e.what() << endl;
    }
}

int main() {
    validateUserProfile();
    return 0;
}