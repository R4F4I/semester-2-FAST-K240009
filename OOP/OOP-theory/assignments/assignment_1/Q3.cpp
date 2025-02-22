/*

? |Question 03. [ Marks 10]
Imagine you are developing a vehicle rental application that allows users to register, update their
details, and rent vehicles based on certain eligibility criteria. The rental system must consider
different types of users and vehicles. Users will provide their personal information, including
details such as their age, contact number, and license type, while the system will offer a range of
vehicles with varying rental conditions.
The application needs to handle user registration, allowing them to update their details as needed,
and rent vehicles by checking eligibility based on their license type. Once a user is registered,
they can view a list of available vehicles and choose one to rent. The system should check the
user’s eligibility to rent a specific vehicle based on their license type, and it should ensure users
can only rent vehicles they are qualified for.
You are asked to create a vehicle rental system where users can register with their details, update
their personal information, and rent vehicles. The vehicles will have different types and rental
conditions, and users will be restricted from renting vehicles they are not qualified for. The
system will manage the following:

1. Users can register and provide information such as:
    o Age
    o License type (e.g., Learner, Intermediate, Full)
    o Contact information
    o User ID

2. Once registered, users can update their details, including their name, age, and license
type, which will be stored in the system.

3. The system will display a list of available vehicles, with attributes such as:
    o Model
    o Rental price per day
    o Eligibility for different license types (e.g., Learners can only rent certain vehicles)

4. The system will check if the user meets the requirements to rent a specific vehicle based
on their license type.

5. If the user is eligible for a vehicle, they can proceed with the rental; otherwise, they will
be informed that they cannot rent that particular vehicle.

To store the available vehicles, a pointer array will be used. This allows for dynamic
management of vehicle objects, providing flexibility for adding or removing vehicles as needed
without resizing fixed arrays. The vehicle objects should be created dynamically using pointers,
and the array will store the addresses of these objects. The system will access and modify vehicle
details using these pointers.
By using a pointer array, the system ensures efficient memory usage and the ability to scale the
number of vehicles as needed.
Task:
- Allow the user to register with their information, including personal details and license
type.
- Implement functionality for users to update their information at any time.
- Create a dynamic array of pointers for vehicles. Each pointer in the array will point to a
dynamically allocated vehicle object.
- For each vehicle, specify eligibility requirements based on license type (e.g., Learners,
Full license).
- Based on the user’s license type, check if they are eligible to rent a vehicle.
- Ensure that users with different license types (e.g., Learner, Intermediate, Full) have
access to different vehicle options.
- If eligible, allow users to rent a vehicle, displaying the rental details and the vehicle they
have selected.
- If not eligible, inform the user that they cannot rent that vehicle

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;

class User
{

static int counter;
    int Age, UserID; // will increment for each new user
    string licenseType,contactInfo;
    public:

    User(int age = 18, string licenseType = "Learner",string contactInfo = "123456789") 
        :   Age(age), 
            licenseType(licenseType), 
            contactInfo(contactInfo)
            {
                this->UserID=counter++;
            }
    
            /* { by default counter will assign id
        this->Age = age;
        this->licenseType = licenseType;
        this->contactInfo = contactInfo;
        this->UserID=counter++;
    } */


/* 
    // setters not needed as constructor is doing the job

    void setAge(int age){
        this->Age = age;
    }

    void setLicenseType(string licenseType){
        this->licenseType = licenseType;
    }

    void setContactInfo(string contactInfo){
        this->contactInfo = contactInfo;
    } */

    // getters

    int getAge(){
        return this->Age;
    }

    string getLicenseType(){
        return this->licenseType;
    }

    string getContactInfo(){
        return this->contactInfo;
    }


    
};

int User::counter = 0;



class vehicle
{
private:
    string Model; //  Eligibility; for different license types
    double rentalPrice;
    bool rented;

public:
    vehicle(string mod= "NA", double price=0.0)
    {
        this->Model = mod;
        this->rentalPrice = price;
        this->rented = false;

    }

    string getModel(){
        return this->Model;
    }
    double getRentalPrice(){
        return this->rentalPrice;
    }
    double isRented(){
        return this->rented;
    }
    void setRentStatus(bool rented){
        this->rented = rented;
    }

};


class System
{
private:
    string learner[3] = {"Toyota Yaris", "Honda Fit", "Ford Fiesta"};
    string intermediate[3] = {"Toyota Corolla", "Honda Civic", "Ford Focus"};
    string fullLicense[3] = {"Toyota Camry", "Honda Accord", "Ford Mustang"};

public:

    bool Eligible(User &user, vehicle &vehicle){
        // check licence validity
        if (user.getLicenseType()=="learner")
        {
            if (
                vehicle.getModel() == learner[0] || 
                vehicle.getModel() == learner[1] || 
                vehicle.getModel() == learner[2]
                )
            {
                return true;
            }
            else
            {
                return false;
            }
            
        }
        else if (user.getLicenseType()=="intermediate")
        {
            if (
                vehicle.getModel() == intermediate[0] || 
                vehicle.getModel() == intermediate[1] || 
                vehicle.getModel() == intermediate[2]
                )
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (user.getLicenseType()=="full")
        {
            if (
                vehicle.getModel() == fullLicense[0] || 
                vehicle.getModel() == fullLicense[1] || 
                vehicle.getModel() == fullLicense[2]
                )
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }

        
    }

    void rentVehicle(User user, vehicle &vehicle){
        if (Eligible(user, vehicle))
        {
            vehicle.setRentStatus(true);
            cout << "Vehicle Rented: " << vehicle.getModel() << " for " << vehicle.getRentalPrice() << " per day" << endl;
        }
        else
        {
            cout << "You are not eligible to rent this vehicle" << endl;
        }
    }


};

int main(){
    /* string learner[3] = {"Toyota Yaris", "Honda Fit", "Ford Fiesta"};
    string intermediate[3] = {"Toyota Corolla", "Honda Civic", "Ford Focus"};
    string fullLicense[3] = {"Toyota Camry", "Honda Accord", "Ford Mustang"}; */
    
    System system;
    User 
    user1(20, "full", "123456789"), 
    user2(18, "learner", "987654321"), 
    user3(25, "intermediate", "123123123");
    
    vehicle 
    *vehicle1 = new vehicle("Toyota Camry", 100.0), 
    *vehicle2 = new vehicle("Toyota Corolla", 90.0), 
    *vehicle3 = new vehicle("Toyota Yaris", 80.0);
    
    
    // only user1 can rent vehicle1, vehicle2, vehicle3
    system.rentVehicle(user1, *vehicle1);
    system.rentVehicle(user2, *vehicle2);
    system.rentVehicle(user3, *vehicle3);





    
    return 0;
}