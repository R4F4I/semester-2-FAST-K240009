/*

? |

## Task 03
Envision creating a robust application for a global finance firm that needs to handle and compute multiple currencies with real-time conversion capabilities. 
This system is built on a base class called `Currency`, which contains core data members such as:

- `amount`
- `currencyCode`
- `currencySymbol`
- An optional `exchangeRate`

### Functions:
- `convertToBase()`: Converts the amount into a common base currency.
- `convertTo(targetCurrency)`: Converts between currencies.
- `displayCurrency()`: Showcases currency details.

### Derived Classes:
- **Dollar**
- **Euro**
- **Rupee**

These classes extend the foundation by introducing currency-specific details 
and overriding `convertToBase()` and `displayCurrency()` to reflect exchange rates and regional currency formats dynamically.


* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;


class Currency
{
private:
    int amount;
    string currencyCode;
    string currencySymbol;
    float exchangeRate;

public:
    Currency(int a, string cC, string cS, float eR){
        this->amount = a;
        this->currencyCode = cC;
        this->currencySymbol = cS;
        this->exchangeRate = eR;
    }

    
    
    

    void convertToBase(){
        cout<<"converting to base currency"<<endl;
    }

    void convertTo(string targetCurrency){
        cout<<"converting to "<<targetCurrency<<endl;
    }

    void displayCurrency(){
        cout<<"displaying currency"<<endl;
        cout<<"amount: "<<amount<<endl;
        cout<<"currency code: "<<currencyCode<<endl;
        cout<<"currency symbol: "<<currencySymbol<<endl;
        cout<<"exchange rate: "<<exchangeRate<<endl;
    }
};



class Dollar: public Currency
{
private:
    
public:
    Dollar(int a, string cC, string cS, float eR): Currency(a, cC, cS, eR){}
    

    void convertToBase(){
        cout<<"converting to gold"<<endl;
    }

    void displayCurrency(){
        cout<<"displaying currency"<<endl;
    }

    void convertTo(string targetCurrency){
        cout<<"converting to "<<targetCurrency<<endl;
    }

    
   
};




class Euro : public Currency
{
private:
    /* data */
public:
    Euro(int a, string cC, string cS, float eR): Currency(a, cC, cS, eR){}


    void convertToBase(){
        cout<<"converting to silver"<<endl;
    }

    void displayCurrency(){
        cout<<"displaying currency"<<endl;
        Currency::displayCurrency();
    }

    void convertTo(string targetCurrency){
        cout<<"converting to "<<targetCurrency<<endl;
    }



};

class Rupee : public Currency
{
private:
    /* data */
public:
    Rupee(int a, string cC, string cS, float eR): Currency(a, cC, cS, eR){}
    
    void convertToBase(){
        cout<<"converting to Dollar"<<endl;
    }

    void displayCurrency(){
        cout<<"displaying currency"<<endl;
        Currency::displayCurrency();
    }

    void convertTo(string targetCurrency){
        cout<<"converting to "<<targetCurrency<<endl;
    }

};




int main(){


    Dollar d(100, "USD", "$", 1);
    d.displayCurrency();
    d.convertToBase();
    d.convertTo("Euro");

    Euro e(100, "EUR", "€", 1.2);
    e.displayCurrency();
    e.convertToBase();
    e.convertTo("Rupee");

    Rupee r(100, "PKR", "Rs", 0.008);
    r.displayCurrency();
    r.convertToBase();
    r.convertTo("Dollar");




    return 0;
}