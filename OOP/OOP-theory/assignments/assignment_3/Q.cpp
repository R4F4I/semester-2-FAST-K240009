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
Driver(string n = "def") :name(n) {}

};

///////////////////////////////////////////////////////
class Route{
    string startingRoute;
    string endingRoute;
    int distCovered;

public:
    Route(string s = "start",string e = "end", int d = 0): startingRoute(s),endingRoute(e),distCovered(d){}
    Route(Route& r){
        this->startingRoute = r.startingRoute;
        this->endingRoute = r.endingRoute;
        this->distCovered = r.distCovered;
    }
    string getRoute() const {
        return startingRoute + " to " + endingRoute;
    }

    int getDistance() const {
        return distCovered;
    }

};

///////////////////////////////////////////////////////
class Vehicle
{
private:
    int seats;
    bool ACservice;
    Driver* driver;
    Route* route;
public:
    Vehicle(Route& r,int s=52,bool ac = false) : seats(s),ACservice(ac) {
        // ,string start = "start",string end = "end",int dist = 0
        route = new Route(r); 
    }
    Vehicle(Vehicle& v){
        this->seats = v.seats;
        this->ACservice = v.ACservice;
        this->driver = v.driver;
        this->route = v.route;
    }
    bool hasAC() const {
        return ACservice;
    }

    string getRouteInfo() const {
        return route->getRoute();
    }

    friend class BookingSystem;

};

///////////////////////////////////////////////////////
class Bus : public Vehicle
{
public:
    Bus(Route& r,bool ac = false) : Vehicle(r,52,ac) {}

};
///////////////////////////////////////////////////////
class Coaster : public Vehicle
{
    public:
    Coaster(Route& r,bool ac = false) : Vehicle(r,32,ac) {}
    
};
///////////////////////////////////////////////////////

class Transporter
{
    private:
    
    Vehicle* vehicles[10];
    Driver drivers[10];
    string routes[10];
    
    public:
    Transporter() {
        for (int i = 0; i < 10; i++) vehicles[i] = nullptr;
    }

    ~Transporter() {
        for (int i = 0; i < 10; i++)
            if (vehicles[i]){ 
                delete vehicles[i];  // clean up
            }
    }
    
    friend class BookingSystem;
    friend int main();
    
};
///////////////////////////////////////////////////////

class User {
protected:
    string name;
    bool hasPaid;
    string userType;

public:
    User(string n = "User", bool b = false, string type = "User")
        : name(n), hasPaid(b), userType(type) {}

    void makePayment() {
        hasPaid = true;
    }

    bool paid() const {
        return hasPaid;
    }

    string getType() const {
        return userType;
    }

    string getName() const {
        return name;
    }

    friend class BookingSystem;
};


///////////////////////////////////////////////////////

class Student : public User{
    public:
    Student(string n = "name",bool b=false)
        :User(n,b,"Student"){}
};
///////////////////////////////////////////////////////

class Faculty : public User{
    public:
    Faculty(string n = "name",bool b=false)
        :User(n,b,"Faculty"){}
};

class Seat {
private:
    int seatNum;
    bool isBooked;
    User* user;

public:
    Seat(int s = 0) : seatNum(s), isBooked(false), user(nullptr) {}

    bool book(User* u) {
        if (!isBooked) {
            isBooked = true;
            user = u;
            return true;
        }
        return false;
    }

    bool booked() const {
        return isBooked;
    }
};


///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
// 1 obj represents 1 record
class BookingSystem {
private:
    Vehicle* vehicle;
    float fare;

public:
    BookingSystem(Vehicle* v) : vehicle(v), fare(0) {}

    float calcFare(User& user) {
        if (!user.paid()) {
            throw runtime_error("Booking denied: Payment not completed.");
        }

        // Basic fare by role
        fare = (user.getType() == "Faculty") ? 5000 : 3000;

        if (vehicle->hasAC()) {
            fare += 2000;
        }

        return fare;
    }

    void bookSeat(User& user) {
        try {
            float total = calcFare(user);
            cout << "Booking successful for " << user.getName() << " (" << user.getType() << ") on route " << vehicle->getRouteInfo() << ". Fare: Rs. " << total << endl;
        } 
        catch (const exception& e) {
            cout << e.what() << endl;
        }
    }
};


///////////////////////////////////////////////////////


int main() {
    // Create route
    Route r1("North Karachi", "FAST-NUCES", 20);

    // Create transporter
    Transporter nadeem, jadoon;

    // Add a Bus and a Coaster to the transporter's vehicle fleet
    Bus* bus1 = new Bus(r1, true);         // AC bus
    Coaster* coaster1 = new Coaster(r1);   // Non-AC coaster

    // Assign vehicles to transporter
    nadeem.vehicles[0] = bus1;
    nadeem.vehicles[1] = coaster1;

    // Assign drivers to transporter
    nadeem.drivers[0] = Driver("Imran");
    nadeem.drivers[1] = Driver("Kashif");

    // Create users
    Faculty f1("Dr. Ahsan");
    Student s1("Ali");

    // Booking system using the transporter's bus
    BookingSystem bookingBus(bus1);

    // Attempt booking without payment
    bookingBus.bookSeat(f1); // should show error

    // Make payment
    f1.makePayment();
    s1.makePayment();

    // Book seats
    bookingBus.bookSeat(f1);
    bookingBus.bookSeat(s1);

    cout<<"deleting...\n";
    // Clean up
    delete bus1;
    delete coaster1;
    cout<<"deleted\n";

    return 0;
}
