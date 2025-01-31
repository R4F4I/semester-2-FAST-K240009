/* 
2. You are tasked with building a simple product management system for an online store that
does the following stuff:
a) Create a function that allows the addition of a new product to the system. The function
should take parameters such as product name, price, quantity, and any other relevant
details.
b) Implement a function that takes a product ID as input and displays detailed information
about the product, including its name, price, quantity in stock, and any other relevant
details.
c) Design a function that enables the update of product information. It should take a
product ID as well as the new details (e.g., updated price, quantity, etc.) and modify the
existing product's information accordingly.
d) Create a function that removes a product from the system based on its product ID.
Ensure that the inventory is updated after the removal.


name: rafay siddiqui
roll num: 24k-0009
class: bai-2a

 */

#include <iostream>

using namespace std;

struct product
{
    string name;
    int quantity,ID;
    float price;
};



product* addProduct(string name,int quantity,int ID,float price){
    product *prodPtr = new product;

    prodPtr->name = name;
    prodPtr->ID = ID;
    prodPtr->quantity = quantity;
    prodPtr->price = price;

    return prodPtr;
}

void updateProduct(product arr[],int id,string name,int quantity,float price){
    
    for (size_t i = 0; i < 5; i++)
    {
        if (arr[i].ID==id)
        {
            arr[i].name = name;
            arr[i].quantity = quantity;
            arr[i].price = price;
        }
    }
    
    
}
        
void displayProduct(int id,product arr[]){

    for (size_t i = 0; i < 5; i++)
    {
        if (arr[i].ID==id)
        {
            cout<< (arr[i].name) << endl;
            cout<< (arr[i].ID) << endl;
            cout<< (arr[i].quantity) << endl;
            cout<< (arr[i].price) << endl;
        }
        
    }
    
}

void removeProduct(int id, product arr[]){

    for (size_t i = 0; i < 5; i++)
    {
        if (arr[i].ID==id)
        {
            arr[i].name = "";
            arr[i].quantity = 0;
            arr[i].price = 0;
        }
        
    }
    

}


int main(){

    // create a dynamic array of products

    product arr[5];

    
    arr[0] = *(addProduct("wrench",10,100,110.1));
    arr[1] = *(addProduct("pickaxe",11,101,110.11));
    arr[2] = *(addProduct("hammer",12,102,110.12));
    arr[3] = *(addProduct("rope",13,103,110.13));
    arr[4] = *(addProduct("ladder",14,104,110.14));
    
    
    displayProduct(102,arr);
    cout<< "---\n";

    displayProduct(103,arr);cout<< "---\n";
    updateProduct(arr,103,"shovel",12,212.22);cout<< "---\n";

    displayProduct(103,arr);cout<< "---\n";
    removeProduct(103,arr);cout<< "---\n";
    cout<< "removed product \n";
    displayProduct(103,arr);cout<< "---\n";

    // product *p1 = addProduct("lamp",10,101,110.1);


    return 0;
}
