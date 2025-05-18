
#include <iostream>
#include <fstream>

using namespace std;

class JewelryItem{
protected:
    string itemCode,itemName;
    int purity;
    double weight;
public:


    JewelryItem(const string &code, const string &name, int p, double w){
        itemCode = code;
        itemName = name;
        purity = p;
        weight = w;
    }

    virtual void displayDetails(){
        std::cout << "itemCode: " << itemCode << std::endl;
        std::cout << "itemName: " << itemName << std::endl;
        std::cout << "purity: " << purity << std::endl;
        std::cout << "weight: " << weight << std::endl;
    }

    virtual double calcPrice() = 0;

    bool operator <(JewelryItem &other){
        return this->calcPrice() < other.calcPrice();
    }
    bool operator >(JewelryItem &other){
        return this->calcPrice() > other.calcPrice();
    }
    bool operator ==(JewelryItem &other){
        return this->calcPrice() == other.calcPrice();
    }

};

class GoldJewelryItem : public JewelryItem {
protected:
    int goldKarat;

public:

    GoldJewelryItem(const string &code, const string &name, int p, double w, int g): JewelryItem(code,name,p,w)
    {
        goldKarat  = g; 
    }

    void set_goldKarat(int k) {
        goldKarat =  k;
    }

    double calcPrice() override{
        return goldKarat*purity*weight;
    }

    void displayDetails() override{
        JewelryItem::displayDetails();
        std::cout << "goldKarat: " << goldKarat << std::endl;
    }
};


class DiamondJewelryItem : public JewelryItem {
protected:  
    int diamondKarat;
    
public:

    DiamondJewelryItem(const string &code, const string &name, int p, double w, int d): JewelryItem(code,name,p,w)
    {
        diamondKarat  = d; 
    }

    void set_karat(int k) {
        diamondKarat =  k;
    }
    void displayDetails() override{
        JewelryItem::displayDetails();
        std::cout << "diamondKarat: " << diamondKarat << std::endl;
    }

    double calcPrice() override{
        return diamondKarat*purity*weight;
    }


};


class Customer
{
private:
    string ID, name;
    JewelryItem** purchasedItems;
    int itemCount; // puchased item metric
    int capacity; // puchased item metric

public:
    Customer(const string &id, const string &n, int cap = 2)
        : ID(id), name(n), itemCount(0), capacity(cap){}

    void purchaseItem(JewelryItem* item) {
        if (itemCount >= capacity) {
            // Increase capacity by reallocating a larger array
            int newCapacity = capacity * 2;
            JewelryItem** temp = new JewelryItem*[newCapacity];
            for (int i = 0; i < itemCount; i++) {
                temp[i] = purchasedItems[i];
            }
            delete[] purchasedItems;
            purchasedItems = temp;
            capacity = newCapacity;
        }
        purchasedItems[itemCount++] = item;
    }
    double calculateTotalPurchasePrice(){
        double total = 0;
        for (size_t i = 0; i < itemCount; i++)
        {
            total = purchasedItems[itemCount]->calcPrice();
        }
        return total;
    }
    

    ~Customer(){
        for (size_t i = 0; i < itemCount; i++)
        {
            delete purchasedItems[i];
        }
        delete[] purchasedItems;
    }
};



class StoreInventory
{
private:
    JewelryItem** inventory;
    int capacity, itemCount;
public:
    StoreInventory(int cap = 2)
        : capacity(cap), itemCount(0)
    {
        inventory = new JewelryItem*[capacity];
    }

    void addItemToInventory(JewelryItem* item){

        if(itemCount>=capacity){
            int newCapacity = capacity *2;
            JewelryItem** temp = new JewelryItem*[newCapacity];
            // copy all items from inventory to temp
            for (size_t i = 0; i < itemCount; i++)
            {
                temp[i] = inventory[i];
            }
            delete[] inventory;
            inventory = temp;
            capacity = newCapacity;
            
        }
        inventory[itemCount++] = item;
    }

    void displayInventory(){
        for (size_t i = 0; i < itemCount; i++)
        {
            inventory[i]->displayDetails();
        }
        
    }


    ~StoreInventory(){
        // Delete inventory items if StoreInventory owns them.
        for (int i = 0; i < itemCount; i++){
            delete inventory[i];
        }
        delete[] inventory;
    }
};

int main(){
    // ----- Create Gold and Diamond Jewelry Items -----
    // Create a GoldJewelryItem and set its details.
    GoldJewelryItem* goldItem = new GoldJewelryItem("G001", "Golden Necklace", 90, 5.0, 22);
    // If a separate setDetails method is available, you may call it here instead of using the constructor.
    // For example: goldItem->setDetails("G001", "Golden Necklace", 90, 5.0);
    // Then set the gold karat if needed.
    goldItem->set_goldKarat(22);
    
    // Create a DiamondJewelryItem and set its details.
    DiamondJewelryItem* diamondItem = new DiamondJewelryItem("D001", "Diamond Ring", 95, 2.0, 3);
    diamondItem->set_karat(3);
    
    // Display individual details of each jewelry item.
    cout << "----- Display Individual Jewelry Items -----" << endl;
    cout << "\nGold Item Details:" << endl;
    goldItem->displayDetails();
    cout << "Gold Item Price: " << goldItem->calcPrice() << endl;
    
    cout << "\nDiamond Item Details:" << endl;
    diamondItem->displayDetails();
    cout << "Diamond Item Price: " << diamondItem->calcPrice() << endl;
    
    // ----- Using Customer Class -----
    // Create a customer and let them purchase the items.
    Customer cust("C001", "Alice");
    // Customer takes ownership of the purchased items.
    cust.purchaseItem(goldItem);
    cust.purchaseItem(diamondItem);
    
    cout << "\nCustomer's Total Purchase Price: " << cust.calculateTotalPurchasePrice() << endl;
    
    // ----- Using StoreInventory Class -----
    StoreInventory storeInv;
    // Create new items for the store inventory (different from those in customer's possession).
    GoldJewelryItem* goldItem2 = new GoldJewelryItem("G002", "Golden Bracelet", 88, 3.0, 24);
    goldItem2->set_goldKarat(24);
    
    DiamondJewelryItem* diamondItem2 = new DiamondJewelryItem("D002", "Diamond Earrings", 92, 1.5, 2);
    diamondItem2->set_karat(2);
    
    // Add these items to the store inventory.
    storeInv.addItemToInventory(goldItem2);
    storeInv.addItemToInventory(diamondItem2);
    
    cout << "\n----- Store Inventory -----" << endl;
    storeInv.displayInventory();
    
    // The destructors for Customer and StoreInventory will release the allocated memory.
    return 0;
}