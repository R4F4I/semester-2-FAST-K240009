/*

? |
FAST-NUCES has been running a dedicated Point Service for faculty and students to provide daily pick and
drop service from various parts of the city. Earlier, the entire system was managed manually by a transport
manager. However, the transport manager recently resigned. Instead of hiring a new resource, the
university administration has decided to digitize the transport operations by developing an automated
Transport Management System.
As a junior intern currently studying Object-Oriented Programming, you have been assigned the task of
designing and implementing this system using OOP concepts. The goal is to build a software system that
replicates the key responsibilities of the transport manager: assigning drivers, managing vehicle routes,
allocating seats, and handling bookings all through code.
FAST-NUCES currently outsources its transport service to two third-party providers: Nadeem Transporter
and Zulfiqar Transporter. Each transporter maintains a fleet of vehicles (called Points), a pool of drivers,
and a set of assigned routes. Vehicles can either be buses (with 52 seats) or coasters (with 32 seats), and
some of them are air-conditioned. Each vehicle follows a fixed route, has its own driver, and carries both
faculty and students. Seats in these vehicles are designated either for students or faculty to prevent
overlap.
Each vehicle (Point) has a list of seats which can be booked by registered users only after they’ve made a
payment. Faculty and student users have different fare structures with AC vehicles charging an additional
Rs. 2000. Bookings are limited to one seat per user per month and users must have completed their
payment before the seat is reserved. Each booking keeps track of the selected vehicle, route, user, and
seat.
Drivers have personal details and valid licenses, and can only be assigned to one vehicle at a time. Routes
have information about the start and end locations and the distance covered. If a route covers a long
distance (based on a threshold), it is marked accordingly.
To make the system maintainable and reusable, the university also wants the system to manage lists of
various entities (such as users, vehicles, and bookings) using a generic data structure. If a requested entity
is not found, the system should raise an appropriate exception. Moreover, all important operations, such
as saving user data, bookings, and vehicle states must be stored and loaded from files using file handling,
allowing the system to persist across sessions.
You are expected to design classes that reflect real-world responsibilities and relationships. For instance,
a vehicle cannot exist without a driver (composition), but can share routes and transporter affiliations
(aggregation). The system must also include exception handling to deal with common errors like booking
without payment, seat unavailability, or role-based seat violations.
The final system should be able to register faculty and student users, assign drivers to vehicles, define
routes, handle seat bookings, calculate fares, and display all relevant information through meaningful
output.

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;


///////////////////////////////////////////////////////
class Driver
{
private:

    string name;

public:
Driver(){}

};

///////////////////////////////////////////////////////
class Vehicle
{
private:
    int seats;
    bool ACservice;
    Driver* driver;
public:
Vehicle(int s=52, string r = "default route") : seats(s), route(r){}

    friend class BookingSystem;

};

///////////////////////////////////////////////////////
class Bus : public Vehicle
{
public:
Bus(string r = "default route") : Vechicle(52,r) {}

};
///////////////////////////////////////////////////////
class Coaster : public Vehicle
{
    public:
    Coaster(string r = "default route") : Vechicle(32,r) {}
    
};
///////////////////////////////////////////////////////
class Routes{
    string startingRoute;
    string EndingRoute;
    int distCovered;
}
///////////////////////////////////////////////////////

class Transporter
{
    private:
    
    Vehicle Vehicles[10];
    Driver Drivers[10];
    string Routes[10];
    
    public:
    Transporter(){}
    
    friend class BookingSystem;
    
};
///////////////////////////////////////////////////////

class User{
    string name;
    bool hasPaid;

public:
    void makePayment{
        this->hasPaid = true;
    }
};

///////////////////////////////////////////////////////

class Student : public User{

};

///////////////////////////////////////////////////////
class BookingSystem
{
private:

    string registerdUsers[100];
    float fare;

public:
BookingSystem(){}

    float calcFare(){

    }

};

int main(){




    return 0;
}