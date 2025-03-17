/*

? |

We're gonna be picking up where we left off in the last assignment: FAST's Transportation
System.
For this scenario, you are required to revisit the system, and update it according to the newer
concepts that we have discussed. It should include the following concepts: Inheritance,
Constructor Chaining, Polymorphism (static/dynamic), Operator Overloading, etc.
Things to consider:
Introduce new classes, such as teacher and staff members who can also avail the transport. Is
there a parent class that can encompass some of the functionalities for students, teachers and
staff members? Are some functionalities different between users? For example, students pay on
a semester-by-semester basis, and teachers pay on a monthly basis.
Can you perform operator overloading to verify if two objects are the same or not? If so,
demonstrate it in your classes. For example; are two routes the same?
Feel free to refer to the question # 4 from the previous assignment for functionalities that you
have used.
----------------------------------------------------------------------
Now, keeping all these things in mind, show what your updated class diagram looks like (show
inheritance, aggregation and composition clearly). And update your previous code accordingly.

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;

const int MAX_ARR_SIZE = 5,daysInMonth = 30;

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




    return 0;
}