/*

? |
You've been given the noble task of creating a vehicle management program—because tracking cars in your head is so last century. 
You start with a Vehicle class, the granddaddy of all things on wheels, 
    which proudly holds a make, model, and year, because even the rustiest old truck deserves an identity. 
    Naturally, you add a constructor to initialize these values because, well, cars don't just appear out of thin air (unless it's a sci-fi movie). 
    
But wait—here comes Car, a fancier, more detailed version of Vehicle that 
    adds the number of doors (so we know if it's a sleek two-door sports car or a minivan full of screaming toddlers) and 
    fuel efficiency (because let's be honest, gas prices aren't getting any cheaper). 
    This class, of course, calls the Vehicle constructor in style using an initialization list, because that's how classy programmers roll. But the real game-changer? 

The ElectricCar class! ⚡🚗 Inherits from Car, ditches gas, 
    and brings in a shiny new variable: battery life—so you know exactly how far you can go before panicking about the next charging station.
    Like a true inheritor, ElectricCar also makes use of the initialization list, because efficiency isn't just for batteries. 
    
    
Finally, in the main function, you create an ElectricCar object and display its
details—because after writing all this code, the least you deserve is seeing a virtual Tesla (or a
budget electric scooter) come to life. Now, plug in your C++ skills, buckle up for some inheritance
magic, and let's get this coding road trip started! 🚗💨💻

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;


class Vehicle
{
private:
    string make, model;
    int year;
public:
    Vehicle(){
        this->make = "Unknown make";
        this->model = "Unknown model";
        this->year = 0;
    }
    Vehicle(string make, string model, int year){
        this->make = make;
        this->model = model;
        this->year = year;
    }
};

class Car: public Vehicle
{
private:
    int doors, gas;
public:
    Car():Vehicle(){
        this->doors = 0;
        this->gas = 0;
    }
        Car(int doors, int gas, string make, string model, int year):Vehicle(make, model, year){
        this->doors = doors;
        this->gas = gas;
    }
};


class ElectricCar: public Car
{
private:
    /* data */
public:
    ElectricCar(/* args */){

    }
};








int main(){




    return 0;
}