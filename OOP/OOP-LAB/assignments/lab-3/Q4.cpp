/*

? |Design a class for a StationeryShop that maintains a list of all items it sells, stored as an array
? |of strings, along with a corresponding list of item prices, stored as an array of doubles. Create
? |a menu-driven program that allows the shop owner to perform the following operations: add
? |items and their prices, """retrieve the list of items""", edit item prices, and """view all items along with their prices""".
? |Additionally, implement functionality to generate a receipt that the shopkeeper
? |can share with customers. The receipt should be created only after the shopkeeper inputs the
? |items purchased by the customer along with their quantities.

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;

class StationaryShop{

private:
    string Items[20];
    double Prices[20];
    int NumOfItems;

public:
    void addItems(string itemName, double itemPrice){
        Items[NumOfItems]=itemName;
        Prices[NumOfItems]=itemPrice;
        NumOfItems++;
    }
    void getItems(int i){}
    void editItemPrices(int i,double itemPrice){
        Prices[i]=itemPrice;
    }
    void displayItems(){
        for (size_t i = 0; i < NumOfItems; i++)
        {
            cout<<i<<": "<<Items[i]<<" "<<Prices[i]<<"\n";
        }
    }
    void generateReceipt(){
        int quantity;
        double total=0;
        cout<<"Enter the quantity of items purchased: ";
        cin>>quantity;
        for (size_t i = 0; i < NumOfItems; i++)
        {
            cout<<i<<": "<<Items[i]<<" "<<Prices[i]<<"\n";
        }
    }
};





int main(){

    StationaryShop s;
    s.addItems("pen",10);
    s.addItems("pencil",5);
    s.addItems("eraser",2);
    s.addItems("sharpner",3);
    s.displayItems();



    return 0;
}