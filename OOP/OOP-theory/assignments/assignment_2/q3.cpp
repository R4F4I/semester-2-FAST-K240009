/*

? |
# Scenario # 3: Ramzan Box Delivery System

### Overview:
A futuristic AI-driven delivery company, **RamzanBox**, specializes in delivering food and supplies during Ramzan using:
- Autonomous drones.
- Time-traveling delivery ships.
- High-speed ground pods.

### System Features:
1. **Vehicle Class**:
   - Base class for all delivery vehicles.
   - Attributes:
     - Unique vehicle ID.
     - Static variable: Total number of active deliveries.
   - Functions:
     - Calculate optimal delivery route.
     - Determine estimated delivery time.

2. **Specialized Vehicles**:
   - **RamzanDrone**:
     - Small, fast, airborne.
     - Optimized for iftar meal deliveries.
   - **RamzanTimeShip**:
     - Ensures historical accuracy for time-sensitive deliveries.
   - **RamzanHyperPod**:
     - High-speed underground transport for bulk deliveries.

3. **AI Decision-Making System**:
   - Each vehicle follows a unique movement strategy:
     - **RamzanDrone**: Calculates aerial routes.
     - **RamzanTimeShip**: Verifies historical consistency.
     - **RamzanHyperPod**: Navigates underground tunnels.
   - Override a general movement function for unique operational logic.

4. **Operator Control Panel**:
   - Issue delivery commands:
     - `command("Deliver", packageID);`
     - `command("Deliver", packageID, urgencyLevel);`
   - Interpretation of "urgent" varies by vehicle:
     - **RamzanTimeShip**: Treats as historically sensitive.
     - **RamzanDrone**: Activates high-speed mode for timely iftar delivery.

5. **AI Conflict Resolution System**:
   - Resolves disagreements between AI systems on delivery priority.
   - Features:
     - Friend function: Access private attributes to compare vehicles.
     - Overloaded `==` operator: Compare vehicles based on speed, capacity, and energy efficiency.


* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;


class Vehicle
{
private:
static int totalDeliveries;
static int incrementor; 
  int vehicleID,speed, capacity, energyEfficiency;
public:



    Vehicle(){
        vehicleID=incrementor++;
        speed = 0;
        capacity = 0;
        energyEfficiency = 0;
    }
    Vehicle(int s, int c, int e):Vehicle(){
        this->speed = s;
        this->capacity = c;
        this->energyEfficiency = e;
    }

    void displayID(){
        cout << "Vehicle ID: " << vehicleID << endl;
    }


    void calculateOptimalRoute()
    {
        cout << "Calculating optimal route for vehicle: " << vehicleID << endl;
    }
    void estimateDeliveryTime()
    {
        cout << "Estimating delivery time for vehicle: " << vehicleID << endl;
    }

    void movementStrategy()
    {
        cout << "Vehicle: General movement strategy." << endl;
    }

    bool operator ==(const Vehicle &v){
        return (
          this->speed             == v.speed              && 
          this->capacity          == v.capacity           && 
          this->energyEfficiency  == v.energyEfficiency);
    }

    void command(string command, int packageID)
    {
        cout << "Command: " << command << " for package ID: " << packageID << endl;
    }
    void command(string command, int packageID, int urgencyLevel)
    {
        cout << "Command: " << command << " for package ID: " << packageID << " with urgency level: " << urgencyLevel << endl;
    }

    friend void resolveConflict(Vehicle &v1, Vehicle &v2);

};

void resolveConflict(Vehicle &v1, Vehicle &v2)
    {
        if (v1.speed > v2.speed) {
            cout << "Vehicle " << v1.vehicleID << " has higher speed." << endl;
        } else if (v1.speed < v2.speed) {
            cout << "Vehicle " << v2.vehicleID << " has higher speed." << endl;
        } else {
            cout << "Both vehicles have the same speed." << endl;
        }
    }




int Vehicle::totalDeliveries = 0;
int Vehicle::incrementor = 0;

class RamzanDrone : public Vehicle
{
private:
  /* data */
public:
  RamzanDrone(): Vehicle(){}
  RamzanDrone(int s, int c, int e): Vehicle(s, c, e){}

  void movementStrategy()
  {
      cout << "RamzanDrone: Calculating aerial route for delivery." << endl;
  }


};



class RamzanTimeShip : public Vehicle
{
private:
  /* data */
public:
  RamzanTimeShip(): Vehicle(){}
  RamzanTimeShip(int s, int c, int e): Vehicle(s, c, e){}

  void movementStrategy()
  {
      cout << "RamzanTimeShip: Verifying historical consistency for delivery." << endl;
  }


};



class RamzanHyperPod : public Vehicle
{
private:
  /* data */
public:
  RamzanHyperPod(): Vehicle(){};
  RamzanHyperPod(int s, int c, int e): Vehicle(s, c, e){};

  void movementStrategy()
  {
      cout << "RamzanHyperPod: Navigating underground tunnels for delivery." << endl;
  }


};


void splitter(){
    cout << "----------------------------------------" << endl;
}

int main(){
  // Create instances of each vehicle type
  Vehicle v1(10, 20, 30);
  v1.displayID();
  RamzanDrone drone1(15, 25, 35);
  drone1.displayID();
  RamzanTimeShip ship1(20, 30, 40);
  ship1.displayID();
  RamzanHyperPod pod1(25, 35, 45);
  pod1.displayID();

  // Display vehicle IDs
  splitter();

  // Test Vehicle class functionality
  cout << "Testing Vehicle class:" << endl;
  v1.command("Deliver", 101);
  v1.command("Deliver", 102, 1);
  v1.calculateOptimalRoute();
  v1.estimateDeliveryTime();
  v1.movementStrategy();
  splitter();

  // Test RamzanDrone functionality
  cout << "Testing RamzanDrone class:\n" << endl;
  drone1.command("Deliver", 103);
  drone1.command("Deliver", 104, 2);
  drone1.calculateOptimalRoute();
  drone1.estimateDeliveryTime();
  drone1.movementStrategy();
  splitter();

  // Test RamzanTimeShip functionality
  cout << "Testing RamzanTimeShip class:\n" << endl;
  ship1.command("Deliver", 105);
  ship1.command("Deliver", 106, 3);
  ship1.calculateOptimalRoute();
  ship1.estimateDeliveryTime();
  ship1.movementStrategy();
  splitter();

  // Test RamzanHyperPod functionality
  cout << "Testing RamzanHyperPod class:\n" << endl;
  pod1.command("Deliver", 107);
  pod1.command("Deliver", 108, 4);
  pod1.calculateOptimalRoute();
  pod1.estimateDeliveryTime();
  pod1.movementStrategy();
  splitter();

  // Test conflict resolution
  cout << "Testing conflict resolution:\n" << endl;
  resolveConflict(v1, drone1);
  resolveConflict(drone1, ship1);
  resolveConflict(ship1, pod1);
    

  v1.displayID();
  drone1.displayID();
  ship1.displayID();
  pod1.displayID();


    return 0;
}