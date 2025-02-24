/*

? |
FAST's transportation system currently has a troublesome process for student registration,
semester payments, and to verify it manually on points. They want you to automate the entire
process to streamline the system.
The system should
- Allow students to register for the transportation service.
- Enable students to pay semester fees to keep their transportation cards active.
- Manage routes, including pick-up and drop-off stops for students.
- Record attendance automatically when students tap their cards on the bus.
- Manage bus routes with stops and assign students to appropriate stops.

Identify the required classes, their data members, and member functions. Then, create a class
diagram to represent the system. Based on your class diagram, write a C++ program to
implement the system.
You must follow all the OOP rules learned up to the 5th week. This means using proper getters
and setters, constructors, destructors, and making use of constant and static variables where
needed.

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A
                                      ┌─────────────────────────────────┐                                       
                                      │           Transport             │                                       
                                      ├─────────────────────────────────┤                                       
                                      │static int incrementor,transport │                                       
                                      │string route[2]                  │                                       
                                      │int TransportID                  │                                       
                                      │Student *students[]              │                                       
                                      │                                 │                                       
                                      ├─────────────────────────────────┤                                       
                                      │Transport()                      │                                       
                                      │registerStudent(Student *s)      │                                       
                                      │~Transport()                     │                                       
                                      │                                 │                                       
                                      └────────────────┬────────────────┘                                       
                                                       │                                                        
                                                       ▼                                                        
┌──────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
│                                                   Student                                                    │
├──────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
│bool paidSemFee,registeredForTransport, attendance[]                                                          │
│string name                                                                                                   │
│int rollNO                                                                                                    │
│Card *card                                                                                                    │
├──────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
│string getName()                                                                                              │
│bool getPaidSemFee(),getCardActive(),getTransportStatus()                                                     │
│void setCardActive(bool b),setTransportStatus(bool b),markAttendance(int dayOfMonth),displaySheet()           │
│Student(bool cardActive = false, bool paidSemFee=false, bool registeredForTransport = false, string name="NA")│
│~Student()                                                                                                    │
└──────────────────────────────────────────────────────┬───────────────────────────────────────────────────────┘
                                                       │                                                        
                                                       │                                                        
                                                       ▼                                                        
                                 ┌────────────────────────────────────────────┐                                 
                                 │                   Card                     │                                 
                                 ├────────────────────────────────────────────┤                                 
                                 │bool active, isTapped                       │                                 
                                 │int  cardID                                 │                                 
                                 │static int incrementor                      │                                 
                                 ├────────────────────────────────────────────┤                                 
                                 │int getCardID()                             │                                 
                                 │bool getActive(),getTapped()                │                                 
                                 │void setActive(bool a),setTapped(bool t)    │                                 
                                 │Card(bool active=false, bool isTapped=false)│                                 
                                 └────────────────────────────────────────────┘                                 

*/

#include <iostream>

using namespace std;

const int MAX_ARR_SIZE = 5,daysInMonth = 30 ;

class Card
{
private:
static int incrementor;
    
    bool active,isTapped;
    int cardID;

public:

    bool getActive(){
        return this->active;
    }
    void setActive(bool b){
        this->active = b;
    }
    bool getTapped(){
        return this->isTapped;
    }
    void setTapped(bool b){
        this->isTapped = b;
    }
    int getCardID(){
        return this->cardID;
    }


    Card(bool active=false, bool isTapped=false ){
        this->active = active;
        this->isTapped = isTapped;
        this->cardID = incrementor++;
    }
    ~Card(){
        cout << "Card object destroyed." << endl;
    }
};

int Card::incrementor = 0;
class Student{


static int incrementor;
    // a student can pay fees but not have an active card, a card can only be active if the student has paid the fees, a transport can only provided if both are true
    bool paidSemFee,registeredForTransport, attendance[daysInMonth];
    string name;
    int rollNO;
    Card *card;

public:


    string getName(){
        return this->name;
    }
    bool getPaidSemFee(){
        return this->paidSemFee;
    }
    bool getCardActive(){
        return this->card->getActive();
    }
    void setCardActive(bool b){
        this->card->setActive(b);
    }
    bool getTransportStatus(){
        return this->registeredForTransport;
    }
    void setTransportStatus(bool b){
        this->registeredForTransport = b;
    }
    Student(
        bool cardActive = false, 
        bool paidSemFee=false, 
        bool registeredForTransport = false, 
        string name="NA") 
        : 
        card(new Card(cardActive)), 
        paidSemFee(paidSemFee), 
        registeredForTransport(registeredForTransport), 
        name(name), 
        rollNO(incrementor++) 
        {
        
        /* this->paidSemFee = paidSemFee;
        this->registeredForTransport = registeredForTransport;
        this->name = name; 
        this->rollNO = incrementor++;*/
        for (size_t i = 0; i < daysInMonth; i++)
        {
            attendance[i] = false; // for the entire month
        }
        
    }

    void markAttendance(int dayOfMonth){
        if (getTransportStatus()){
            attendance[dayOfMonth] = true;
        } else {
            cout << "illegal student being marked." << endl;
        }
    }

    void displaySheet(){
        for (size_t i = 0; i < daysInMonth; i++)
        {
            cout <<  attendance[i] << " ";
        }
    }

    ~Student(){
        delete card;
        cout << "Student object destroyed." << endl;
    }
};

int Student::incrementor = 0;

// class does not explicitly  define a bus or a van, rather the overall service
class Transport
{
    private:
    static int incrementor,transport;
    string route[2];
    int TransportID;
    Student *students[MAX_ARR_SIZE];
public:
    Transport(){
        this->TransportID = incrementor++;
        this->route[0] = "NA0";
        this->route[1] = "NA1";
        for (int i = 0; i < MAX_ARR_SIZE; i++) {
            this->students[i] = nullptr; // initialize array with nullptr
        }
    }
    
    void registerStudent(Student *s){
        if (s->getPaidSemFee() == true && transport < MAX_ARR_SIZE && s->getCardActive() == true){
            students[transport++] = s;
            s->setTransportStatus(true);
            
        } else {
            s->setTransportStatus(false);
            cout << "error registering " << s->getName()<<" (check for card status, sem fee status, system transport capability status)." << endl;
        }
    }



    ~Transport(){
        // delete all students
        for (size_t i = 0; i < MAX_ARR_SIZE; i++)
        {
            delete students[i];
        }
        cout << "Transport object destroyed." << endl;
    }
};

int Transport::incrementor = 0;
int Transport::transport = 0;



int main(){
    // cout << "creating Transport object ." << endl;
    Transport t1;
    // cout << "Transport object created." << endl;
    
    //          

    // cout << "creating Student object1 ." << endl;

    // rafay has not paid the fees, so his attendance will not be marked
    Student s1(false, true, true, "Rafay");
    // cout << "created Student object1 ." << endl;
    
    // cout << "creating Student object2 ." << endl;
    
    // ali has paid the fees and has an active card and has registered for transport, so his attendance is marked
    Student s2(true, true, true, "Ali");    
    // cout << "created Student object2 ." << endl;
    
    // cout << "creating Student object3 ." << endl;

    // ali has paid the fees and has an active card but did not register for transport, so his attendance will be marked
    Student s3(true, true, false, "Saad");
    // cout << "created Student object3 ." << endl;
    
    
    // cout << "registering s1." << endl;
    t1.registerStudent(&s1); // s1 will fail registration as he has not paid the fees
    // cout << "registered s1." << endl;
    
    // cout << "registering s2." << endl;
    t1.registerStudent(&s2);
    // cout << "registered s2." << endl;
    
    // cout << "registering s3." << endl;
    t1.registerStudent(&s3);
    // cout << "registered s3." << endl;
    

    // simulating attendance for 4 days
    
    int day = 0;
    // day 1
    s1.markAttendance(day);
    s2.markAttendance(day);
    s3.markAttendance(day);

    // day 2
    day++;
    s1.markAttendance(day);
    s2.markAttendance(day);

    // day 3
    day++;
    s1.markAttendance(day);
    s2.markAttendance(day);

    // day 4
    day++;
    s1.markAttendance(day);
    s3.markAttendance(day);

    cout << "Attendance for s1: ";
    s1.displaySheet();
    cout << endl;

    cout << "Attendance for s2: ";
    s2.displaySheet();
    cout << endl;

    cout << "Attendance for s3: ";
    s3.displaySheet();
    cout << endl;

    return 0;
}
