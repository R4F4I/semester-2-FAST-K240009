/*

? |Imagine your restaurant is booming, but there’s a problem—orders are a mess, payments are
missing, and the menu keeps changing like it has a mind of its own. 
You need a system that keeps everything in check before the chef throws a frying pan at someone. 
Here’s the plan: 
    menu items are simple—
        they have a name (because "that thing with cheese" isn’t helpful) and 
        a price (because exposure doesn’t pay the bills). 
        The Menu class holds all the food items, 
            and you should be able to 
                add, 
                remove, or 
                display them like a true menu wizard. 
        The restaurant has only one menu—no secret ones for VIPs, sorry! 
    Orders? 
        Any staff member can enter them on behalf of customers (even that one waiter who always forgets things). 
        Each order consists of one or more delicious menu items 
        and—because no meal is free—
        a payment, 
            which is calculated the moment the order is placed. 

Now, roll up your sleeves and code a system where orders make sense, 
    payments don’t mysteriously disappear, 
    and customers can’t escape without settling their bill!
    
a) Menu is a class that holds an array of menu items.
b) Menu Items hold two things: food name and food price.
c) Any staff member can place an order to the system on behalf of a customer. The order class
consists of one or more menu items and a payment.
d) Payment is a class that holds the amount of money that a customer needs to pay. This is
generated when the order is placed.

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;

class menuItem
{
private:
    string foodName;
    int foodPrice;
public:
    menuItem(){
        foodName = "default";
        foodPrice = 0;
    }

    string getFoodName(){
        return this->foodName;
    }
    int getFoodPrice(){
        return this->foodPrice;
    }
    void setFoodName(string n){
        this->foodName = n;
    }
    void setFoodPrice(int p){
        this->foodPrice = p;
    }


    ~menuItem(){}
};

class Menu
{
private:
    menuItem *menuItems[10];
    int count;
public:
    void add(menuItem item){
        *menuItems[count++] = item;
    }
    void remove(menuItem item){
        // decrement to overwrite the value at add
        count--;
        // *menuItems[count++] = item;
    }
    void display(){
        for (size_t i = 0; i < 10; i++)
        {
            cout << "item "<< i<<":\n   "<< menuItems[i]->getFoodName() <<"\n   "<<menuItems[i]->getFoodPrice();
        }
        
    }
    bool isAvailable(menuItem mI){
        for (size_t i = 0; i < 10; i++)
        {
            if (
                menuItems[i]->getFoodName() == mI.getFoodName() && 
                menuItems[i]->getFoodPrice()== mI.getFoodPrice()
                )
            {
                return true;
            }
            
        }
        return false;
        
    }

    Menu(){
        menuItem j;
        for (size_t i = 0; i < count; i++){
            *menuItems[i] = j;
        }        
    }
    ~Menu(){
        for (size_t i = 0; i < count; i++)
        {
            delete menuItems[i];
        }
        
        delete[] menuItems;
    }
};

class Payment
{
private:
    /* data */
public:
    Payment(/* args */);
    ~Payment();
};

Payment::Payment(/* args */)
{
}

Payment::~Payment()
{
}


void Order(menuItem order[],Menu m,int orderSize){
    int payment=0;
    for (size_t i = 0; i < orderSize; i++)
    {
        if (m.isAvailable(order[i]))
        {
            payment+=order[i].getFoodPrice();
        } else
        {
            cout<<"order not found\n";
        }
    }
    
    
    

}



int main(){




    return 0;
}