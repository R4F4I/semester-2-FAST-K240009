/*

? |
You've been assigned the ultimate challenge: 
developing a school management program that actually keeps track of students and teachers (because, apparently, shouting names during roll call isn't efficient). 

You start with a Person class, 
    because everyone in a school—students, teachers, and that one mysterious janitor—has a name and an age. 

But life gets more complicated! 
Students have a student ID (to misplace their library books officially) and a grade level (because calling everyone "kid" isn't ideal), 
while teachers have a subject (which they lecture about with varying enthusiasm) and a room number (where they trap students for extra assignments). 

Naturally, you create Student and Teacher classes that inherit from Person and add their own special attributes.

But here's where things get really wild: 
you need a GraduateStudent class that inherits from both Student and Teacher, 
    because some poor souls are both students AND teaching assistants—learning by day, grading papers by night, and questioning their life choices at all times. 
    
Finally, in your main function, you create a GraduateStudent object and display its details, 
because if they have to suffer through hybrid inheritance, the least you can do is let them see their own existence printed out.

Now, grab your keyboard, embrace the chaos of multiple inheritance, and let's make this school
system as smart as the overworked graduate students running it! 🎓📚💻

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;

class Person
{
private:
    int age; string name;
public:
    Person(){
        age = 0;
        name = "Unknown name";
    }
    Person(int age, string name){
        this->age = age;
        this->name = name;
    }
    void display(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student: public Person
{
private:
    int ID, grade;
public:
    Student():Person(){
        ID = 0;
        grade = 0;
    }
    Student(int age,string name,int ID, int grade):Person(age,name){
        this->ID = ID;
        this->grade = grade;
    }
    void display(){
        Person::display();
        cout << "ID: " << ID << endl;
        cout << "Grade: " << grade << endl;
    }
};


class Teacher: public Person
{
private:
    int room;
    string subject;
public:
    Teacher():Person(){
        room = 22;
        subject = "Unknown subject";
    }
    Teacher(int age,string name,int room, string sub):Person(age,name){
        this->room = room;
        this->subject = sub;
    }
    void display(){
        Person::display();
        cout << "Room: " << room << endl;
        cout << "Subject: " << subject << endl;
    }
};



class GraduateStudent: public Student, public Teacher
{
private:
public:
    GraduateStudent():Student(), Teacher(){}
    GraduateStudent(int age, string name, int id, int grade, int room, string sub)
        :   Student(age,name,id,grade), 
            Teacher(age,name,room,sub){}

    void display(){
        Student::display();
        Teacher::display();
    }
};


/* 
technically diamond problem is  present here because both student and teacher are inheriting from person class
and graduate student is inheriting from both student and teacher class yet the display function is not ambiguous
because the display function is being called explicitly from the student and teacher class

*/




int main(){

    GraduateStudent gs(22,"John",24,2,3,"OOP");
    GraduateStudent gs1;
    gs.display();
    cout << "---"<< endl;
    gs1.display();
    


    return 0;
}