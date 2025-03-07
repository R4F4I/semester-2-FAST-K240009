/*

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;


class car
{
private:
    int capacity;
    int color;
    int modelYear;


public:
    void Display(){
        cout<< this->capacity << endl;
        cout<< this->color << endl;
        cout<< this->modelYear << endl;
    }
    car(){
        this->capacity = 53;
        this->color = 53;
        this->modelYear = 53;
    }
    car(int capacity= 53,int color= 53,int modelYear= 53): capacity(capacity), color(color), modelYear(modelYear)
    {}
    /* car(int capacity,int color,int modelYear){
        this->capacity = capacity;
        this->color = color;
        this->modelYear = modelYear;
    } */
    ~car(){}
};

class PetrolCar : public car
{
private:
    int fuelCapacity;
    
public:
    void display(){
        Display();
        cout<< this->fuelCapacity<<endl;
    }
    // to call consturctors of parent class use init list
    PetrolCar(int capacity,int color,int modelYear,int fuelCapacity): car(capacity,color,modelYear)
    {
        this->fuelCapacity=fuelCapacity;
    }
    ~PetrolCar(){}
};





int main(){

    PetrolCar c1(1,2,3,4);
    c1.display();
    


    return 0;
}   