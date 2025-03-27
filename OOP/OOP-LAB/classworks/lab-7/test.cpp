#include <iostream>

class Base {
public:
    virtual void show() { // Virtual function
        std::cout << "Base class show function" << std::endl;
    }
};

class Derived : public Base {
public:
    void show()  { // Overrides Base::show()
        std::cout << "Derived class show function" << std::endl;
    }
};

int main() {
    Base* b;  
    Derived d;
    b = &d;
    b->show();  // Late binding, resolved at runtime
    return 0;
}
