/*

? |1. Design a class named BoardMarker with the following attributes:
? |    - Company (e.g., Dollar)
? |    - Color (e.g., black, red)
? |    - Refillable (Boolean – specifies if the marker can be refilled)
? |    - Ink status (Boolean – indicates whether the ink is empty)
? |
? |Implement appropriate getters and setters for these attributes. Additionally, include the
? |following methods:
? |- write() – This method should check if the ink is empty before allowing writing. If the
? |ink is empty, display a message indicating that writing is not possible; otherwise,
? |proceed with writing.
? |- refill() – This method should verify if the marker is refillable. If it is, refill the ink and
? |update the ink status; otherwise, display a message stating that the marker cannot be
? |refilled.

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;

class BoardMarker
{
private:
    int ink_status;

public:
    bool refillable ;
    string company,color ;

    void set_company(string comp) { 
        company = comp; 
    }
    void set_color(string col) { 
        color = col; 
    }
    void set_refillable(bool refill) { 
        refillable = refill; 
    }
    void set_ink_status(int ink_stat) { 
        ink_status = ink_stat; 
    }

    string get_company() {
        return company; 
    }
    string get_color() {
        return color; 
    }
    bool get_refillable() {
        return refillable; 
    }
    int get_ink_status() {
        return ink_status; 
    }


    void refill(){
        if (get_refillable()==true){
            int ink = get_ink_status();
            set_ink_status(ink++);
            cout<<"marker filled\n";
        }
        else
        {
            cout<<"marker cannot be refilled\n";
        }
        
    }

    void write(){
        int ink = get_ink_status();
        if (ink==0)
        {
            cout<<"writing is not possible\n";
        }else
        {
            cout<<"writing...\n";
        }
        
        
    }


};



int main(){

    BoardMarker pen1,pen2,pen3;
    pen1.set_company("Dollar");
    pen1.set_color("red");
    pen1.set_ink_status(10);
    pen1.set_refillable(true);
    
    pen2.set_company("Piano");
    pen2.set_color("black");
    pen2.set_ink_status(5);
    pen2.set_refillable(true);
    
    pen3.set_company("Piano");
    pen3.set_color("green");
    pen3.set_ink_status(0);
    pen3.set_refillable(false);

    pen1.write();
    pen2.write();
    pen3.write();

    pen1.refill();
    pen2.refill();
    pen3.refill();

    return 0;
}