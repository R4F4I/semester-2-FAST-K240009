/*

? |

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;

class calc
{
private:

public:

// type A: function / constructor overloading 
    int add(int a, int b){
        return a+b;
    }
    double add(double a, double b){
        return a+b;
    }
    float add(float a, float b){
        return a+b;
    }

    calc(){
        
    }
    calc(int a, int b){

    }

};

class A
{
private:
    /* data */
public:
    A(/* args */){
        cout << "base class\n";
    }
    
};

class B: public A
{
private:
    /* data */
public:
    B(){
        cout << "derived class\n";  
    }
};





int main(){

    calc c1;

    std::cout << c1.add(1,2) << std::endl;
    // std::cout << c1.add(1.4,2.1) << std::endl; //https://stackoverflow.com/questions/34960166/call-of-overloaded-function-is-ambiguous-double-vs-float
    std::cout << c1.add(1.4,2.1) << std::endl;


    return 0;
}