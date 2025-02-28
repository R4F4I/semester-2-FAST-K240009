/*

? |
Imagine Flight PK-303, a proud bird ready to soar from Karachi to England, dreaming of fish and
chips.
But plot twist—some unwanted guests (a.k.a. hijackers) decide to spice things up, forcing
the plane to make an unplanned pit stop in Islamabad instead.
Talk about a travel detour!
Your job?
Create a system that models this unexpected adventure using classes,
showing the relationship (aggregation) between the flight and the airports.

- The Flight class should be linked to multiple Airport objects
        (because clearly, this flight loves collecting destinations).
- Oh, and don’t forget a display() function
    - to keep everyone updated—whether the plane is taking off, landing, or
- stuck explaining things to airport security.

(Now, fasten your seatbelt and start coding before this flight gets delayed even further!)

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;

class Airports
{
private:
    string name, place;

public:
    void setName(string n){
        this->name=n;
    }
    
    void setPlace(string n){
        this->place=n;
    }
    string getName(){
        return this->name;
    }
    
    string getPlace(){
        return this->place;
    }

    Airports(){
        this->name = "default airport";
        this->place = "pakistan";
    }

    Airports(string name, string place)
    {
        this->name = name;
        this->place = place;
    }
};

class Flight
{
private:
    Airports *origin, *destination;
    string status;
    int duration;

public:
    void display()
    {
        cout << "Flight Status: "   << this->status                 <<                                              endl;
        cout << "Duration: "        << this->duration               << " minutes" <<                                endl;
        cout << "Origin: "          << this->origin->getName()      << ", " << this->origin->getPlace()         <<  endl;
        cout << "Destination: "     << this->destination->getName() << ", " << this->destination->getPlace()    <<  endl;
    }
    Flight(){
        this->origin = new Airports;
        this->destination = new Airports;
        this->status = "scheduled";
        this->duration = 19990;
    }

    Flight(Airports &origin, Airports &destination, string status, int duration) {
        
        this->origin = new Airports(origin);
        this->destination = new Airports(destination);
        this->status = status;
        this->duration = duration;
    }

    ~Flight(){
        delete this->origin;
        delete this->destination;
    }
};
int main()
{
    Airports Karachi("Karachi Airport", "Karachi");
    Airports Heathrow("Heathrow Airport", "London");

    Flight flight1(Karachi, Heathrow, "scheduled", 420);
    flight1.display();

    return 0;
}