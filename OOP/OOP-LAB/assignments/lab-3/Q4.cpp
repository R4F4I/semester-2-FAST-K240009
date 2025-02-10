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
    int NumOfItems=0;

public:
    void addItems(string name, double price){
        if (NumOfItems<20){    
            Items[NumOfItems]=name;
            Prices[NumOfItems]=price;
            NumOfItems++;
        }
        else{
            cout<<"cannot add more items";
        }
    }
    void retrieveItems(){
        cout<<"\n\n";
        for(int i =0; i<NumOfItems;i++){
            cout << i + 1 << ". " << Items[i]<<endl;
        }
        cout<<"\n\n";
    }
    void editItemPrices(int i,double itemPrice){
        Prices[i]=itemPrice;
    }
    void displayItems(){
        for (size_t i = 0; i < NumOfItems; i++)
        {
            cout<<"\n\n";
            cout << Items[i] << " - $"  << Prices[i] << endl;
            cout<<"\n\n";
        }
    }
    void generateReceipt(){
        if (NumOfItems == 0) {
            cout << "No items available in the shop.\n";
            return;
        }
        
        int numItems;
        cout << "Enter the number of items to purchase: ";
        cin >> numItems;
        string purchasedItems[20];
        int quantities[20];

        double total = 0;

        // Collect item names and quantities
        for (int i = 0; i < numItems; i++) {
            string item;
            int quantity;
            cout << "Enter item name: ";
            cin >> item;
            cout << "Enter quantity: ";
            cin >> quantity;

            bool found = false;
            for (int j = 0; j < NumOfItems; j++) {
                if (Items[j] == item) {
                    purchasedItems[i] = item;
                    quantities[i] = quantity;
                    total += Prices[j] * quantity;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Item " << item << " not found in the shop.\n";
                i--;  // Ask for input again
            }
        }

        // Print receipt
        cout << "\n--- Receipt ---\n";
        cout << "Item " << "Quantity " << "Price \n";
        for (int i = 0; i < numItems; i++) {
            for (int j = 0; j < NumOfItems; j++) {
                if (Items[j] == purchasedItems[i]) {
                    cout << purchasedItems[i] <<" "<<quantities[i] << " $" << Prices[j] * quantities[i] << endl;
                    break;
                }
            }
        }
        cout << "\nTotal: $" << total << endl;
    }
};





int main(){


    StationaryShop shop;
    int choice;
    shop.addItems("pen",10);
    shop.addItems("pencil",5);
    shop.addItems("eraser",2);
    shop.addItems("sharpner",3);
    // shop.displayItems();

    do {
        cout << "\n--- Stationery Shop Menu ---\n";
        cout << "1. Add Item\n";
        cout << "2. Retrieve Items\n";
        cout << "3. Edit Item Price\n";
        cout << "4. View All Items with Prices\n";
        cout << "5. Generate Receipt\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string item;
                double price;
                cout << "Enter item name: ";
                cin>>item;
                
                cout << "Enter item price: ";
                cin >> price;
                shop.addItems(item, price);
                break;
            }
            case 2:
                shop.retrieveItems();
                break;
            case 3: {
                int index;
                double newPrice;
                shop.displayItems();
                cout << "Enter item index to edit price: ";
                cin >> index;
                cout << "Enter new price: ";
                cin >> newPrice;
                shop.editItemPrices(index, newPrice);
                break;
            }
            case 4:
                shop.displayItems();
                break;
            case 5:
                shop.generateReceipt();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}