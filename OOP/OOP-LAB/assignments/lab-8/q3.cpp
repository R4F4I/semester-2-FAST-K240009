/*

? |
3. Complex Number Operations
Create a `ComplexNumber` class to perform the following operations using operator overloading:
1. **Addition (+)**: Add two complex numbers.
2. **Subtraction (-)**: Subtract two complex numbers.
3. **Multiplication (*)**: Multiply two complex numbers.
4. **Equality Check (==)**: Check if two complex numbers are equal.

### Goal:
Implement the above operations and test them in `main()`.


* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;


class ComplexNumber
{
private:
    double real,imag; // imaginary part
public:
    ComplexNumber(double r= 0, double i = 0) : real(r), imag(i) {};

    void display()
    {
        if (imag > 0)
        {
            
            cout << real << " + " << imag <<"i"<< endl;
        }
        else{
            cout << real << imag <<"i"<< endl;
        }
        
    }
    
    ComplexNumber operator +(ComplexNumber &other)
    {
        ComplexNumber n;
        n.real = this->real + other.real;
        n.imag = this->imag + other.imag;
        return n;
    }
    ComplexNumber operator -(ComplexNumber &other)
    {
        
        ComplexNumber n;
        n.real = this->real - other.real;
        n.imag = this->imag - other.imag;
        return n;
    }

    ComplexNumber operator *(ComplexNumber &other)
    {
        // (a + bi)(c + di) = ac+ adi + bci + bd(i^2) = (ac - bd) + (ad + bc)i
        // where i^2 = -1
        // 
        ComplexNumber n;
        n.real = this->real * other.real - this->imag * other.imag;
        n.imag = this->real * other.imag + this->imag * other.real;
        return n;
    }

    bool operator ==(ComplexNumber &other)
    {
        return (this->real == other.real && this->imag == other.imag);
    }

};





int main(){

    ComplexNumber c1(3, 4), c2(1, 2);
    ComplexNumber c3, c4, c5, c6;

    c3 = c1 + c2; // Addition
    cout << "Addition: ";
    c3.display();
    cout << endl;
    
    c4 = c1 - c2; // Subtraction
    cout << "Subtraction: ";
    c4.display();
    cout << endl;
    
    c5 = c1 * c2; // Multiplication
    cout << "Multiplication: ";
    c5.display();
    cout << endl;

    if (c1 == c2) // Equality Check
        cout << "Equal" << endl;
    else
        cout << "Not Equal" << endl;






    return 0;
}