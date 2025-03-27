/*

? |
Imagine designing a digital management system for a large university that seamlessly integrates academic and administrative operations. 
At the heart of this system is a `Person` class that stores universal data members such as:

- `name`
- `id`
- `address`
- `phoneNumber`
- `email`

### Functions:
- `displayInfo()`: Shows personal details.
- `updateInfo()`: Modifies ==personal== details.

### Derived Classes:
- **Student**: Includes 
    - `coursesEnrolled`, 
    - `GPA`, and 
    - `enrollmentYear`. 
    - Modifies `displayInfo()` to show academic records.
- **Professor**: Includes 
    - `department`, 
    - `coursesTaught`, and 
    - `salary`. 
    - Updates `displayInfo()` to display faculty-specific details.
- **Staff**: Maintains 
    - `department`, 
    - `position`, and 
    - `salary`. 
    - Tailors `displayInfo()` to reflect administrative roles.

### Additional Class:
- **Course**: Attributes include:
  - `courseId`
  - `courseName`
  - `credits`
  - `instructor`
  - `schedule`

Functions:
- `registerStudent(student)`
- `calculateGrades()`

This ensures an interactive system where function overrides enable dynamic role-based management.

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;


class Person
{
private:
    string name,id,address,phoneNumber,email;

public:
    Person(/* args */){

    }
    void displayInfo(){
        cout << "Name: " << this->name << endl;
        cout << "ID: " << this->id << endl;
        cout << "Address: " << this->address << endl;
        cout << "Phone Number: " << this->phoneNumber << endl;
        cout << "Email: " << this->email << endl;
    }
    void updateInfo(){
        cout << "Enter Name: ";
        cin >> this->name;
        cout << "Enter ID: ";
        cin >> this->id;
        cout << "Enter Address: ";
        cin >> this->address;
        cout << "Enter Phone Number: ";
        cin >> this->phoneNumber;
        cout << "Enter Email: ";
        cin >> this->email;
    }
};


class Student: public Person
{
private:
    int enrollmentYear, GPA, coursesEnrolled;

public:
    Student(/* args */){}

    void displayInfo(){
        Person::displayInfo();
        cout << "Enrollment Year: " << this->enrollmentYear << endl;
        cout << "GPA: " << this->GPA << endl;
        cout << "Courses Enrolled: " << this->coursesEnrolled << endl;
    }

    int get_coursesEnrolled(){
        return this->coursesEnrolled;
    }

    void set_coursesEnrolled(int e)
    {
        this->coursesEnrolled = e;
    }

};
class Professor: public Person
{
private:
    string department;
    int coursesTaught, salary;

public:
    Professor(/* args */);

    void displayInfo(){
        Person::displayInfo();
        cout << "Department: " << this->department << endl;
        cout << "Courses Taught: " << this->coursesTaught << endl;
        cout << "Salary: " << this->salary << endl;
    }
    
};


class Staff: public Person
{
private:
    string department;
    int position, salary;

public:
    Staff(/* args */);
    
    void displayInfo(){
        Person::displayInfo();
        cout << "Department: " << this->department << endl;
        cout << "Position: " << this->position << endl;
        cout << "Salary: " << this->salary << endl;
    }
};

class Course
{
private:
    int courseId, credits;
    string schedule, courseName, instructor;

public:

    void registerStudent(Student s)
    {
        s.set_coursesEnrolled(s.get_coursesEnrolled()+1);
    }
    int calculateGrades()
    {
        return credits*3;
    }

   
};


int main(){

    Student s;
    s.updateInfo();
    s.displayInfo();

    Professor p;
    p.updateInfo();
    p.displayInfo();

    Staff st;
    st.updateInfo();
    st.displayInfo();

    Course c;
    Student s1;
    c.registerStudent(s1);
    cout << "Courses Enrolled: " << s1.get_coursesEnrolled() << endl;
    cout << "Grades: " << c.calculateGrades() << endl;
    


    return 0;
}