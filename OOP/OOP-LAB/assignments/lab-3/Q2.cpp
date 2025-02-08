/*

? |2. Create a Circle class with the following member variables: radius, a double representing the
? |circle's radius, and pi, a double initialized with the value 3.14159. The class should include
? |the following member functions: setRadius(), a mutator function to set the radius; getRadius(),
? |an accessor function to retrieve the radius; getArea(), which returns the area of the circle using
? |the formula area = pi * radius * radius; getDiameter(), which calculates and returns the
? |diameter using diameter = radius * 2; and getCircumference(), which calculates and returns
? |the circumference using circumference = 2 * pi * radius. Write a program that demonstrates
? |the Circle class by prompting the user to input a radius, creating a Circle object, and displaying
? |the calculated area, diameter, and circumference.

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;

class Circle
{
private:
    double radius, pi=3.14159;
public:
    
    void setRadius(double r){
        radius = r;
    }
    double getRadius(){
        return radius;
    }
    double getArea(){
        return pi*radius*radius;
    }
    double getCircumference(){
        return 2*pi*radius;
    }
    double getDiameter(){
        return 2*radius;
    }


};




int main(){

    Circle c;
    double rad;
    cout<< "enter radius of a circle: ";
    cin>>rad;
    c.setRadius(rad);

    cout<< "Area of circle with radius "<<rad<<" is: "<<c.getArea()<<"\n";
    cout<< "Circumference of circle with radius "<<rad<<" is: "<<c.getCircumference()<<"\n";
    cout<< "Diameter of circle with radius "<<rad<<" is: "<<c.getDiameter()<<"\n";


    return 0;
}