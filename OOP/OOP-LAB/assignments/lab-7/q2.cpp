/*

? |

Picture an innovative design tool aimed at architects and graphic designers that allows for creating, 
manipulating, and analyzing various geometric shapes. 
The system is structured around 

a `Shape` class, which includes data members such as 
    `position`, 
    `color`, and an 
    optional `borderThickness`. 

It provides functions like:

- `draw()` for rendering.
- `calculateArea()` for area measurement.
- `calculatePerimeter()` for perimeter computation.

### Derived Classes:
- **Circle**: Includes `radius` and `center position`.
- **Rectangle**: Includes `width`, `height`, and `top-left corner position`.
- **Triangle** and **Polygon**: Introduce their own properties.

Each derived class overrides `draw()`, `calculateArea()`, and `calculatePerimeter()` to handle their respective geometries.

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;

const float PI = 3.14159;

class Shape
{
private:
    int position, color, borderThickness;
public:
    Shape(int p, int c, int bT){
        this->position = p;
        this->color = c;
        this->borderThickness = bT;
    }

    void draw(){
        cout<<"drawing shape"<<endl;
    }

    void calculateArea(){
        cout<<"area of shape"<<endl;
    }

    void calculatePerimeter(){
        cout<<"perimeter of shape"<<endl;
    }
};

class Circle: public Shape
{
private:
    int radius, centerPosition;
public:
    Circle(int p, int c, int bT,int r, int cP): Shape(p, c, bT){
        this->radius = r;
        this->centerPosition = cP;
    }

    void draw(){
        cout<<"drawing circle"<<endl;
    }

    void calculateArea(){
        cout<<"area of circle: "<<PI*radius*radius<<endl;
    }

    void calculatePerimeter(){
        cout<<"perimeter of circle: "<<2*PI*radius<<endl;
    }


};


class Rectangle: public Shape
{
private:
    int width, height, topLeftCornerPosition;
public:
    Rectangle(int p, int c, int bT,int w, int h, int tLCP): Shape(p, c, bT){
        this->width = w;
        this->height = h;
        this->topLeftCornerPosition = tLCP;

    }
    

    void draw(){
        cout<<"drawing rectangle"<<endl;
    }

    void calculateArea(){
        cout<<"area of rectangle: "<<width*height<<endl;
    }

    void calculatePerimeter(){
        cout<<"perimeter of rectangle: "<<2*(width+height)<<endl;
    }

};




class Triangle: public Shape

{
private:
    int side1, side2, side3;
public:
    Triangle(int p, int c, int bT,int s1, int s2, int s3): Shape(p, c, bT){
        this->side1 = s1;
        this->side2 = s2;
        this->side3 = s3;
    }

    void draw(){
        cout<<"drawing triangle"<<endl;
    }

    void calculateArea(){
        
       
        cout<<"area of triangle"<<endl;
    }

    void calculatePerimeter(){
        cout<<"perimeter of triangle: "<<side1+side2+side3<<endl;
    }

};

class polygon: public Shape
{
private:
    int sides;
public:
    polygon(int p,int c, int bT,int s): Shape(p,c,bT){
        this->sides = s;
    }

    void draw(){
        cout<<"drawing polygon"<<endl;
    }

    void calculateArea(){
        cout<<"area of polygon"<<endl;
    }

    void calculatePerimeter(){
        cout<<"perimeter of polygon"<<endl;
    }
    
};








int main(){

    Circle c(1,2,3,4,5);
    c.draw();
    c.calculateArea();
    c.calculatePerimeter();

    Rectangle r(1,2,3,4,5,6);
    r.draw();
    r.calculateArea();
    r.calculatePerimeter();

    Triangle t(1,2,3,4,5,6);
    t.draw();
    t.calculateArea();

    polygon p(1,2,3,4);
    p.draw();
    p.calculateArea();

    


    return 0;
}