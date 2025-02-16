/*

? |Create a SmartDevice class to represent your high-tech home gadgets—because
? |flipping switches manually is so last century. Give it attributes like device name, type
? |(smart light, robo-vacuum, coffee overlord), and status (on or off). Build a
? |parameterized constructor to bring these gadgets to life and a destructor that delivers an
? |emotional farewell message when they meet their inevitable end. Test it by creating and
? |deleting objects, and enjoy watching each device’s dramatic exit as they "power down"
? |for the last time.

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;

class SmartDevice
{
private:
    string deviceName,type,status;
public:
    SmartDevice(string deviceName,string type,string status){
        this->deviceName=deviceName;
        this->type=type;
        this->status=status;
    }
    ~SmartDevice(){
        cout<<"device"<<deviceName<<"is powering down"<<endl;
    }
};






int main(){

    SmartDevice light("light","smart light","on"),
                vacuum("vacuum","robo-vacuum","off"),
                coffee("coffee","coffee overlord","on");

    



    return 0;
}