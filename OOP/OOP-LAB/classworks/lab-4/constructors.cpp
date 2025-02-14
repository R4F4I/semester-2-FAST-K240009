/* 

constructos:

- can be overloaded
- default
- parameterized
- copy (deep copy vs shallow copy)

destructor:

- called when program is finished
- 'destroys'/deallocates all objects in memmory
- synatax:
    "~ClassName(){}"
- no parameters
- no overloading

*/


#include <iostream>


using namespace std;



class bankAccount{
private:
    int id;
    string name;
    float amount;
public:
    bankAccount(){
        id = 0;
        name = "null";
        amount = 0;
    }
    bankAccount(int id,string name,float amount){
        id = id;
        name = name;
        amount = amount;
        // these data members can also be called using 'this->'
        // done to avoid confusion
        /* 
        this->id = id;
        this->name = name;
        this->amount = amount;
         */
    }
    
    void deposit(){
        amount+=0;
    }
    void deposit(int depositedAmount){
        amount+=depositedAmount;
    }

    void display(){
        cout<<"id: "<<id<<"\n";
        cout<<"name: "<<name<<"\n";
        cout<<"amount: "<<amount<<"\n";
    }

    ~bankAccount(){}

};

class Shallow{
public:
    int *data;
    // constructor
    Shallow(int value){
        data = new int(value);
    }
    // shallow Copy Constructor
    Shallow(Shallow &obj){
        data = obj.data; // copies the pointer, NOT the actual value
    }
    void display(){
        cout << "Data: " << *data << ", Address: " << data << endl;
    }
    ~Shallow(){
        cout<<"all objects destroyed\n";
    }
};

class Deep{
    public:
        int *data;
        // constructor
        Deep(int value)
        {
            data = new int(value);
        }
        // deep Copy Constructor
        Deep(Deep &obj)
        {
            data = new int(*obj.data); // allocates new memory and copies value
        }
    
        void display()
        {
            cout << "Data: " << data << ", Address: " << data << endl;
        }
    ~Deep(){
        cout<<"all objects destroyed\n";
    }
};

int main(){

    // ------ default & parameterized

    bankAccount u1;
    u1.deposit(10);

    u1.display();

    u1.deposit();

    u1.display();

    //---- shallow copy

    Shallow obj1(10);
    
    Shallow obj2(obj1); // shallow copy
    
    obj1.display();
    obj2.display();

    // deep copy

    Deep obj1(20);
    Deep obj2(obj1); // deep copy
    obj1.display();
    obj2.display();


    return 0;
}
