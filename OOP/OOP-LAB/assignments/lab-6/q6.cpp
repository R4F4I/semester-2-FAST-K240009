/*

? |
You've been hired by a fictional tech company that believes "more features = better product", and
your job is to design the ultimate multi-purpose gadget. 

You start with a base class called Device, 
    because every overpriced gadget—whether it's a smartphone, tablet, or toaster that plays Spotify—needs 
    a brand and model. So far, so good. 
    
    
Then, the marketing team gets involved. They demand
a Smartphone class that adds 
    a SIM slot count (because dual SIM = instant genius) and 


a Tablet class that adds stylus support (so people can pretend they're productive). 

Both of these classes inherit from Device, because duh, they're devices. 
But hold on—things are about to go off the rails.

The CEO, in a caffeine-fueled eureka moment, demands 
    a HybridDevice—a device that's both a Smartphone and a Tablet. 
    
You sigh, create a HybridDevice class that inherits from both Smartphone and Tablet, and BAM—welcome to the Diamond ProblemTM! 🚨 

Your HybridDevice now has two separate copies of the Device class, 
and your compiler is looking at you like, "What have you done?" 😡💥 

Now, your mission (if you choose to accept it): fix this disaster using virtual inheritance, so your HybridDevice doesn't cause a compiler meltdown. 
Finally, demonstrate how to create and use a HybridDevice object without the program catching fire.

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;


class Device
{
private:
    string brand, model;
public:
    Device(){
        this->brand = "Unknown brand";
        this->model = "Unknown model";
    }
    Device(string brand, string model){
        this->brand = brand;
        this->model = model;
    }
    void display(){
        cout << "Brand: " << this->brand << endl;
        cout << "Model: " << this->model << endl;
    }
};

class Smartphone: virtual public Device
{
private:
    int SIMslots;
public:
    Smartphone():Device(){
        this->SIMslots = 0;
    }
    
    Smartphone(string brand, string model, int s):Device(brand,model){
        this->SIMslots = s;
    }

    void display(){
        // Device::display();
        cout << "SIM Slots: " << this->SIMslots << endl;
    }

};

class Tablet: virtual public Device
{
private:
    bool stylusSupport;
public:
    Tablet():Device(){
        this->stylusSupport = false;
    }
    Tablet(string brand, string model, bool sSup):Device(brand,model){
        this->stylusSupport = sSup;
    }
    void display(){
        // Device::display();
        cout << "Stylus Support: " << (this->stylusSupport ? "Yes" : "No") << endl;
    }
};

class HybridDevice: public Smartphone, public Tablet
{
public:
    HybridDevice()
        :Device(),  // due to virtual inheritance, the constructor of the base class is called only once, and most derived class holds responsibility of constructing the base class
         Smartphone(),
         Tablet(){}

    HybridDevice(string brand, string model, int SimSlots, bool stylus)
        :Device(brand,model),
         Smartphone(brand,model,SimSlots),
         Tablet(brand,model,stylus){}

    void display(){
        Device::display();
        Smartphone::display();
        Tablet::display();
    }
};



int main(){

    HybridDevice hd("Apple","iPhone 12",2,true);
    hd.display();



    return 0;
}