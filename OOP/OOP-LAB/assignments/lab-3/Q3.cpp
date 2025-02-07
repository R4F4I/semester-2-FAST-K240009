/*

? |Create a class called water bottle. The water bottle has a company (made by), color and water
? |capacity. The water capacity isstored in both liters(l) and milliliters(ml). Create variables and
? |methods for your class. Methods should include getters and setters. Also create an additional
? |method that updates the water capacity (both in l and ml) after asking user how much water a
? |person has drank. Assume that the user always enters the amount in ml. Demonstrate the
? |functionality of the water bottle in your main method.

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;

class waterBottle
{
private:
    
public:
    string company,color,unit;
    int waterCapacity;
    
    void set_company(string comp){
        company = comp;
    }
    void set_color(string col){
        color = col;
    }
    void set_unit(string u){
        unit = u;
    }
    void set_waterCapacity(int wCap){
        waterCapacity = wCap;
    }

    string get_company(){
        return company;
    }
    string get_color(){
        return color;
    }
    string get_unit(){
        return unit;
    }
    int get_waterCapacity(){
        return waterCapacity;
    }

    void l_to_ml_converter(){}
    void l_to_ml_converter(){}

    void drink(int amount, string unit){
        int waterCap = get_waterCapacity();
        
        if (unit == "l")
        {
            unit = "ml";
            amount*=1000;
        }
        
        if (get_unit()=="l")
        {
            set_unit("ml");
            set_waterCapacity(1000*waterCap);
        }
        
        

        set_waterCapacity(waterCap-amount);

        if (get_waterCapacity()<1)
        {
            unit = "ml";
            
            set_waterCapacity(1000*waterCap);
        }
        
    }

    
};



int main(){

    waterBottle b1;

    b1.set_color("white");
    b1.set_company("nestle");
    b1.set_unit("l");
    b1.set_waterCapacity(1.9);

    b1.drink(200,"ml");

    cout<<b1.get_color()<<"\n";
    cout<<b1.get_company()<<"\n";
    cout<<b1.get_unit()<<"\n";
    cout<<b1.get_waterCapacity()<<"\n";

    return 0;
}