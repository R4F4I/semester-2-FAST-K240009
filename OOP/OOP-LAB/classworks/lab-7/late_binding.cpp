// early binding: overloading                                                     , compile-time time polymorphism
// late  binding: virtual https://www.geeksforgeeks.org/virtual-function-cpp/     , Run time polymorphism   

#include <iostream>

using namespace std;


class Shape
{
private:
    /* data */
public:
    virtual void draw(){
        cout<<"drawing shape"<<endl;
    }
};
class circle:public Shape
{
private:
    /* data */
public:
    void draw(){
        cout<<"drawing circle"<<endl;
    }
};

class A
{
private:
    /* data */
public:
    int x;
    A(/* args */){
        x=10;
    }
};

class B: virtual public A {};
class C: virtual public A {};
class D:  public B, public C {};

int main(){

    // -- late binding
    circle c1;
    Shape *s1 = new circle;

    c1.draw();
    s1->draw();
    delete s1;

    Shape* s;
    s=&c1;
    s->draw();
    c1.draw();

    // diamond problem, comment out the `virtual` keywords

    D d;

    cout << d.x<< endl;


    delete s;
    return 0;
}
