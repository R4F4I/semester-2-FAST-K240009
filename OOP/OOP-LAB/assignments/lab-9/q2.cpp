/*

? |

## Task 02: Smart Home Devices
**Problem**: A homeowner wants a unified system to control smart lights and thermostats from different brands. The system should allow turning devices on/off, adjusting settings, and checking statuses. Future devices (e.g., smart locks) should integrate seamlessly.

### Classes and Structure:
- **Abstract Class `SmartDevice`**:
  - **Member Functions**:
    - `turnOn()`: Pure virtual function to activate the device.
    - `turnOff()`: Pure virtual function to deactivate the device.
    - `getStatus()`: Pure virtual function to return the device’s current state.
- **Derived Class `LightBulb`**:
  - **Data Members**:
    - `isOn` (bool): Tracks if the light is on/off.
    - `brightness` (int): Brightness level (0-100%).
  - Implements `turnOn()`, `turnOff()`, and `getStatus()` for light control.
- **Derived Class `Thermostat`**:
  - **Data Members**:
    - `isOn` (bool): Tracks if the thermostat is active.
    - `temperature` (double): Current temperature setting.
  - Implements `turnOn()`, `turnOff()`, and `getStatus()` for temperature control.

### Flow:
1. Create `LightBulb` and `Thermostat` objects.
2. Turn devices on/off and display their statuses.


* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;

class SmartDevice
{
private:
    /* data */
public:

    virtual void turnOn() = 0; // Pure virtual function to turn on the device
    virtual void turnOff() = 0; // Pure virtual function to turn off the device
    virtual void getStatus() = 0; // Pure virtual function to get the device status
};

class LightBulb : public SmartDevice
{
private:
    bool isOn;
    int brightness; // Brightness level (0-100%)
public:
    LightBulb(bool status = false, int intensity = 0.0) : isOn(status), brightness(intensity){};
    
    void turnOn(){
        isOn = true;
    }
    void turnOff(){
        isOn = false;
    }

    void getStatus(){
        if (isOn) {
            cout << "Light is on with brightness level: " << brightness <<endl;
        } else {
            cout << "Light is off"<<endl;
        }
    }
};

class Thermostat : public SmartDevice
{
private:
    bool isOn;
    double temperature; // Current temperature setting
public:
    Thermostat(bool status = false, double temp = 22.0) : isOn(status), temperature(temp){};

    void turnOn(){
        isOn = true;
    }
    void turnOff(){
        isOn = false;
    }

    void getStatus(){
        if (isOn) {
            cout << "Thermostat is on with temperature setting: " << temperature <<endl;
        } else {
            cout << "Thermostat is off"<<endl;
        }
    }
};



int main(){

    SmartDevice *device1, *device2;
    LightBulb bulb1 (true, 75);
    Thermostat thermostat1 (false, 22.5);

    device1 = &thermostat1;
    device2 = &bulb1;

    device1->turnOn();
    device1->getStatus(); // Check status of the light bulb

    device2->turnOff();
    device2->getStatus(); // Check status of the thermostat



    return 0;
}