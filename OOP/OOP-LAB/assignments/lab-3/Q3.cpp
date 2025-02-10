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
    double waterCapacity;
    
    void set_company(string comp){company = comp;}
    void set_color(string col){color = col;}
    void set_unit(string u){unit = u;}
    void set_waterCapacity(double wCap){waterCapacity = wCap;}

    string get_company(){return company;}
    string get_color(){return color;}
    string get_unit(){return unit;}
    double get_waterCapacity(){return waterCapacity;}

    double l_to_ml_converter(double liters) {
        return liters * 1000;  // 1 liter = 1000 milliliters
    }
    double ml_to_l_converter(double ml) {
        return ml / 1000;  // 1 liter = 1000 milliliters
    }

    void drink(double amount, string unit){
        waterCapacity-=amount;
        if (waterCapacity<1){
            unit = "ml";
            ml_to_l_converter(waterCapacity);
        }
    }
    void displayCapacity() {
        cout << "Water capacity: " << waterCapacity << " ml (" << waterCapacity / 1000 << " l)" << endl;
    }

};



int main(){

    waterBottle b1;

    b1.set_color("White");
    b1.set_company("Nestle");
    b1.set_waterCapacity(1500); // assum ml

    cout << "Before drinking:" << endl;
    cout << "Color: " << b1.get_color() << endl;
    cout << "Company: " << b1.get_company() << endl;
    b1.displayCapacity(); // Display initial capacity

    // Drink 200 ml of water
    b1.drink(200, "ml");

    cout << "\nAfter drinking 200 ml:" << endl;
    b1.displayCapacity(); // Display updated capacity

    // Drink 0.5 liters (500 ml)
    b1.drink(500, "l");

    cout << "\nAfter drinking 0.5 liters (500 ml):" << endl;
    b1.displayCapacity(); // Display updated capacity


    return 0;
}