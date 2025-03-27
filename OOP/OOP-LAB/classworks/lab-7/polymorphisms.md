# Polymorphism

## compile - time Polymorphism

### function overloading

#function-overloading

- when the function  executed depends on arguments given

```C++

#include <iostream>
using namespace std;

// Function to add two integers
int add(int a, int b) {
    return a + b;
}

// Function to add three integers
int add(int a, int b, int c) {
    return a + b + c;
}

int main() {
    cout << add(1, 2) << endl;
    cout << add(1, 2, 3) << endl;

return 0;

```


## Run - time Polymorphism

#function-overriding



```C++

#include <iostream>

using namespace std;


class base{
public:
    void foo (){cout<<"base class"<<endl;}

}
class der: public base
{
public:
    void foo (){cout<<"der class"<<endl;}

}

int main(){
    der d;
    d.foo(); //prints "der class"
    return 0;
}

```

- when derived class has a method "overriding" the a method from base


# binding

- process of connecting a function call ( e.g: main)
- To its implementation (method definition)


## [[Early binding|static binding]]
- occurs in compile-time


```C++

#include <iostream>

class Base {
public:
    void show() { // Non-virtual function
        std::cout << "Base class show function" << std::endl;
    }
};

int main() {
    Base obj;
    obj.show();  // Early binding, resolved at compile time
    return 0;
}


```

## [[late binding|dynamic binding]]

- function to be executed is determined during runtime
- Uses virtual functions in polymorphism


```C++

#include <iostream>

class Base {
public:
    virtual void show() { // Virtual function
        std::cout << "Base class show function" << std::endl;
    }
};

class Derived : public Base {
public:
    void show() override { // Overrides Base::show()
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


```

### virtual function

- redefined function in derived class

#### Rules of Virtual Function
- `Virtual` functions must be members of some class.
- `Virtual` functions cannot be static members.
- They are accessed through object pointers.
- They can be a friend of another class.
- A `virtual` function must be defined in the base class, even though it is not used.
- The prototypes of 
  - a `virtual` function of the base class and all the derived classes must be *identical*. 
  - If the two functions with the same name but different prototypes, 
    - C++ will consider them as the overloaded functions.
- We cannot have a `virtual` constructor, but we can have a `virtual` destructor
- Consider the situation when we don't use the `virtual` keyword.

### override keyword

- explicitly override the base class `virtual` function

- Prevent accidental function mismatches (e.g., incorrect function signature).
- Improve code readability by making it clear that a function is overriding a base class function.