/*

? |
Task 01: Vehicle Rental System
Problem: A vehicle rental company needs a flexible system to manage cars, bikes, and future vehicle types. The system should handle daily rates and display vehicle details without exposing internal calculations. New vehicle types (e.g., scooters, trucks) should integrate seamlessly.

Classes and Structure:
Abstract Class Vehicle:
Data Members:
model (string): Vehicle’s model name.
rate (double): Daily rental rate.
Member Functions:
getDailyRate(): Pure virtual function to return the daily rate.
displayDetails(): Pure virtual function to show model and rate.
Derived Class Car:
Inherits Vehicle.
Overrides getDailyRate() and displayDetails() for car-specific behavior.
Derived Class Bike:
Inherits Vehicle.
Overrides getDailyRate() and displayDetails() for bike-specific behavior.
Flow:
Create Car and Bike objects.
Use polymorphism to call displayDetails() and getDailyRate() for each vehicle.
    


* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;


class Vehicle
{
public:
    virtual double getDailyRate() = 0; // Pure virtual function
    virtual void displayDetails() = 0; // Pure virtual function
};

class Car : public Vehicle
{
private:
    string model;
    double rate;
public:

    Car(string model = "Unknown", double rate = 0.0) : model(model), rate(rate){};

    double getDailyRate() {
        return rate;
    }
    void displayDetails() {
        cout << "Car Model: " <<model << ", Daily Rate: " << getDailyRate() << endl;
    }

};

class Bike : public Vehicle
{
private:
    string model;
    double rate;
public:
    Bike(string model = "Unknown", double rate = 0.0) : model(model), rate(rate){};

    double getDailyRate ()
    {
        return rate;
    }
    void displayDetails()
    {
        cout << "bike Model: " <<model << ", Daily Rate: " << getDailyRate() << endl;
    }   
};




int main(){

    Vehicle *v1;

    Car c1("Toyota", 100.0);
    Bike b1("Yamaha", 50.0);


    v1 = &c1;
    v1->displayDetails();
    cout << "Daily Rate: " << v1->getDailyRate() << endl;

    v1 = &b1;
    v1->displayDetails();
    cout << "Daily Rate: " << v1->getDailyRate() << endl;



    return 0;
}