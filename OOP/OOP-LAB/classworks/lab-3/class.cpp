/* 

pillars of OOP
- abstraction
- polymorphism
- inheritance
- encapsulation

type of classes
- concrete class
    - implementation of all methods (every thing is deined)
- generalised class
    - defines main features not specific details
- specialised class
    - 


header file



 */

#include <iostream>
using namespace std;



class Person{
private:
    float weight;
public:
    int age;
    string name;



};


class student{
private:
    int age;
    string address;
    
public:
    int id;
    string name,programme;

    void set_age(int a){age=a;}
    void set_address(string ad){address=ad;}

    int get_age(){
        return age;
    }
    string get_address(){
        return address;
    }
    
};


int main(){

    Person  p1,p2;
    p1.age=10;
    p2.age=50;



    return 0;
}
