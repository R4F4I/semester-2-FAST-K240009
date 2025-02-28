/*

? |Imagine you're creating the next big smartphone, but there's a twist—every phone must come
with a loyal, built-in battery that can never leave, like a clingy best friend. No swapping, no running
away, just a phone and its forever-attached power buddy. Every battery has a specific capacity
(mAh), and each smartphone must be born with its battery already locked in, like destiny. Your
mission? Build a system where every smartphone starts life with a battery, a function lets you
proudly show off both the phone and its battery details, and—most importantly—the battery can
never sneak off on its own. Now, grab your coding cape and design the Smartphone and Battery
classes, making sure their bond is unbreakable, like a phone addict and their charger!

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;


class battery
{
private:
    string modelName;
    int powerCapacity;
public:
    void setmodelName(string m){
        this->modelName = m;
    }
    string getmodelName(){
        return this->modelName;
    }
    void setPowerCapacity(int p){
        this->powerCapacity = p;
    }
    int getPowerCapacity(){
        return this->powerCapacity;
    }
    battery(){
        this->powerCapacity = 0;
    }
    battery(int b){
        this->powerCapacity = b;
    }
    
};


class smartphone
{
private:
    string modelName;
    battery b1;
public:
    string getModel(){
        return this->modelName;
    }
    void setModel(string m){
         this->modelName = m;
    }
    smartphone(){
        // b1;
        this->modelName = "default";
    }
    smartphone(string m, string m2, int n){
        // b1;
        this->modelName = m;
        this->b1.setPowerCapacity(n);
        this->b1.setmodelName(m2);
    }

    void display(){
        cout<< "model: "<<this->modelName<<endl;
        cout<< "battery: "<<this->b1.getmodelName()<<endl;
        cout<< "power: "<<this->b1.getPowerCapacity()<<endl;
    }
};




int main(){

    smartphone s1("samsung","X100",1300);
    s1.display();




    return 0;
}