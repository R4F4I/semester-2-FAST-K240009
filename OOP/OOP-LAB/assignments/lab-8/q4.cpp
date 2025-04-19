/*

? |
4. Traffic System Simulation
Create a `TrafficSystem` class to simulate traffic scenarios using operator overloading:
1. **Addition (+)**: Add cars to a road.
2. **Subtraction (-)**: Remove cars from a road.
3. **Multiplication (*)**: Double the delay time.
4. **Equality (==)**: Check if two roads have the same number of cars.

### Goal:
Implement the above operations and test them in `main()`.


* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;


class TrafficSystem
{
private:
    int cars; // number of cars on the road
public:
    TrafficSystem(int c = 0) : cars(c) {};
    
    int getCars() const
    {
        return cars;
    }

    TrafficSystem operator +(TrafficSystem &other)
    {
        TrafficSystem n;
        n.cars = this->cars + other.cars;
        return n;
    }

    TrafficSystem operator-(TrafficSystem &other)
    {
        TrafficSystem n;
        n.cars = this->cars - other.cars;
        return n;
    }

    TrafficSystem operator *(int delay)
    {
        TrafficSystem n;
        n.cars = this->cars * delay;
        return n;
    }

    bool operator ==(TrafficSystem &other)
    {
        return this->cars == other.cars;
    }




};




int main(){


    TrafficSystem road1(10), road2(5), road3(0);
    cout << "Initial number of cars on road 1: 10" << endl;
    cout << "Initial number of cars on road 2: 5" << endl;
    cout << "Initial number of cars on road 3: 0" << endl;

    cout<< "=========================" << endl;
    cout << "Adding cars on road 1 and road 2" << endl;
    TrafficSystem road4 = road1 + road2;
    cout << "Total cars on road 4: " << road4.getCars() << endl;
    
    cout<< "=========================" << endl;
    cout << "Removing cars from road 1: " << endl;
    TrafficSystem road5 = road1 - road2;
    cout << "Total cars on road 5: " << road5.getCars() << endl;
    
    cout<< "=========================" << endl;
    cout << "Doubling the delay time on road 1: " << endl;
    TrafficSystem road6 = road1 * 2;
    cout << "Total cars on road 6: " << road6.getCars() << endl;
    
    cout<< "=========================" << endl;
    cout << "Checking if road 1 and road 2 have the same number of cars: " << endl;
    if (road1 == road2)
    {
        cout<<"same" << endl;
    }
    else
    {
        cout<<"not same" << endl;
    }


    return 0;
}