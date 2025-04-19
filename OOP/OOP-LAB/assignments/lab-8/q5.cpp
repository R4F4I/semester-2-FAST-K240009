/*

? |
## 5. Student and Teacher Interaction
Create a `Student` class to store a student's name and grades. Use a `Teacher` class as a friend to modify grades. Add a `calculateAverageGrade()` function to compute the average grade.

### Goal:
Simulate grade updates in `main()`:
1. Display the student's grades.
2. Update a grade using the `Teacher` class.
3. Recalculate and display the average grade.

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;


class Student
{
private:
    int grades[5];
    string name;
public:
    Student(string n="null",int g[]={0}) : name(n){
        for (size_t i = 0; i < 5; i++)
        {
            this->grades[i] = g[i];
        }
    };

    
    int getGrade( int index)
    {
        if (index >= 0 && index < 5)
        {
            return this->grades[index];
        }
        else
        {
            cout << "Invalid index!" << endl;
            return -1; // or some error value
        }
    }

    friend class Teacher; // make Teacher a friend class
};

class Teacher
{
private:
    /* data */
public:

    void modifyGrade(Student &s, int index, int newGrade)
    {
        if (index >= 0 && index < 5)
        {
            s.grades[index] = newGrade;
        }
        else
        {
            cout << "Invalid index!" << endl;
        }
    }

    void calculateAverageGrade(Student &s)
    {
        int sum = 0;
        for (size_t i = 0; i < 5; i++)
        {
            sum += s.grades[i];
        }
        cout << "Average Grade: " << sum / 5 << endl;
    }
};




int main(){

    int grades[5] = {85, 90, 78, 92, 88};
    Student s("John Doe", grades);
    Teacher t;


    cout << "Initial Grades: ";
    for (size_t i = 0; i < 5; i++)
    {
        cout << s.getGrade(i) << " ";
    }




    cout << endl;

    t.modifyGrade(s, 2, 95); // Update the third grade to 95
    cout << "Updated Grades: ";
    for (size_t i = 0; i < 5; i++)
    {
        cout << s.getGrade(i) << " ";
    }


    cout << endl;

    t.calculateAverageGrade(s); // Calculate and display the average grade

    cout << endl;




    return 0;
}