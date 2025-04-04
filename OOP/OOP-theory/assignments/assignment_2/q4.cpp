/*

? |

# Scenario # 4: University Lab Management System

### Overview:
A system to manage different types of users in a university lab:
- **Students**: Access tools and complete assignments.
- **Teaching Assistants (TAs)**: Monitor students and assist in labs.
- **Professors**: Assign projects and manage research.

### Permissions:
- **STUDENT**: Submit assignments.
- **TA**: View projects, manage students.
- **PROFESSOR**: Assign projects, full lab access.

### Global Functions:
1. **Password Hashing**:
   - Formula: `hash = 5381`
   - Calculation: `hash * 33 + c` (where `c` is a single character).

2. **Authentication**:
   - `authenticateAndPerformAction(User* user, string action)`:
     - Authenticates the user.
     - Performs actions based on user roles and permissions.

### Class Structure:
1. **User Class**:
   - Attributes:
     - Name, ID, list of permissions, email, hashed password.
   - Functions:
     - Parameterized constructor: Set attributes and hash passwords.
     - `authenticate`: Authenticate based on password.
     - `display`: Display user information.
     - `accessLab`: Check permissions and provide lab access.

2. **Student Class** (Derived from User):
   - Overrides `display` function.
   - Attributes:
     - List of assignments (status: 0 = not submitted, 1 = submitted).
   - Functions:
     - Submit assignments and update status.

3. **TA Class** (Derived from Student):
   - Overrides `display` function.
   - Attributes:
     - List of assigned students (max: 10).
     - List of projects (max: 2).
   - Functions:
     - View/start projects.
     - Assign/manage students (permission-based).

4. **Professor Class** (Derived from User):
   - Overrides `display` function.
   - Functions:
     - Work with TAs on projects (max: 2 projects per TA).

### Implementation:
- Create objects for all classes.
- Call `display` and `authenticate` functions as needed.

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;


class User
{
private:
    string Name,permissions[10], email;
    int ID, password;
public:
    User(/* args */){
        this->Name = "Default Name";
        this->ID = 0;
        this->email = "Default Email";
        this->password = 0;
        for (int i = 0; i < 10; i++)
        {
            this->permissions[i] = "Default Permission";
        }
    }
    User(string name, int id, string email, string permissions[], int password){
        this->Name = name;
        this->ID = id;
        this->email = email;
        this->password = password;
        for (int i = 0; i < 10; i++)
        {
            this->permissions[i] = permissions[i];
        }
    }
    void display(){
        cout << "Name: " << this->Name << endl;
        cout << "ID: " << this->ID << endl;
        cout << "Email: " << this->email << endl;
        cout << "Permissions: ";
        for (int i = 0; i < 10; i++)
        {
            cout << this->permissions[i] << " ";
        }
        cout << endl;
    }

    void authenticate(int password){
        if (this->password == password)
        {
            cout << "Authenticated successfully!" << endl;
        }
        else
        {
            cout << "Authentication failed!" << endl;
        }
    }
    void accessLab(){
        cout << "Accessing lab..." << endl;
        for (int i = 0; i < 10; i++)
        {
            if (this->permissions[i] == "STUDENT")
            {
                cout << "Student access granted!" << endl;
            }
            else if (this->permissions[i] == "TA")
            {
                cout << "TA access granted!" << endl;
            }
            else if (this->permissions[i] == "PROFESSOR")
            {
                cout << "Professor access granted!" << endl;
            }
        }
    }

};


class Student : public User
{
private:
    /* data */
public:
    Student(/* args */);
    
};




class TA : public User
{
private:
    /* data */
public:
    TA(/* args */);
    
};



class Professor : public User
{
private:
    /* data */
public:
    Professor(/* args */);
    
};




int main(){




    return 0;
}