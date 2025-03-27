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
- `updateInfo()`: Modifies personal details.

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
    Person(/* args */);
    ~Person();
};

Person::Person(/* args */)
{
}

Person::~Person()
{
}




int main(){




    return 0;
}