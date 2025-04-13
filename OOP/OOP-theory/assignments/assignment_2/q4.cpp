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
    string Name,permission, email;
    int ID, password;
public:

    
    string get_Name() const {
        return Name;
    }
    string get_email() const {
        return email;
    }
    string get_permission() const {
        return permission;
    }
    int get_ID() const {
        return ID;
    }
    int get_password() const {
        return password;
    }
    
    
    void set_permission(string p) {
             permission = p;
        }

    User(){
        this->Name = "Default Name";
        this->ID = 0;
        this->email = "Default Email";
        this->password = 0;
        this->permission = "NULL";
    }
    User(string name, int id, string email, int password){
        this->Name = name;
        this->ID = id;
        this->email = email;
        this->password = password;
        // this->permission = permission;
        
    }
    void display(){
        cout << "Name: " << this->Name << endl;
        cout << "ID: " << this->ID << endl;
        cout << "Email: " << this->email << endl;
        cout << "Permission: ";
        for (int i = 0; i < 10; i++)
        {
            cout << this->permission[i] << " ";
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
        
        if (this->permission == "STUDENT")
        {
            cout << "Student access granted!" << endl;
        }
        else if (this->permission == "TA")
        {
            cout << "TA access granted!" << endl;
        }
        else if (this->permission == "PROFESSOR")
        {
            cout << "Professor access granted!" << endl;
        }
    }

    friend int  passwordHashing(int password);
    friend void authenticateAndPerformAction(User* user, string action);
};


class Student : public User
{
private:
    int assignments[10]; // 0 = not submitted, 1 = submitted
public:
    Student():User(){};
    Student(string n,int i,string e,int pa):User(n,i,e,pa){
        set_permission("STUDENT");
        for (int i = 0; i < 10; i++)
        {
            this->assignments[i] = 0;
        }
    };


    void display(){
        User::display();
        cout << "Assignments: ";
        for (int i = 0; i < 10; i++)
        {
            cout << this->assignments[i] << " ";
        }
        cout << endl;
    }

    void submitAssignment(int index){
        if (index >= 0 && index < 10)
        {
            this->assignments[index] = 1;
            cout << "Assignment " << index << " submitted!" << endl;
        }
        else
        {
            cout << "Invalid assignment index!" << endl;
        }
    }
    
};




class TA : public Student
{
private:
    Student *assignedStudents[10]; // max 10 students
    string projects[2]; // max 2 projects
public:
    TA():Student(){};
    TA(string n, int i, string e, int pa) : Student(n, i, e, pa) {
        set_permission("TA");
    }
    void viewProjects(){
        cout << "Projects: ";
        for (int i = 0; i < 2; i++)
        {
            cout << this->projects[i] << " ";
        }
        cout << endl;
    }
    void assignStudent(Student *student){
        if (get_permission() == "TA")
        {
            for (int i = 0; i < 10; i++)
            {
                if (this->assignedStudents[i] == nullptr)
                {
                    this->assignedStudents[i] = student;
                    cout << "Student assigned!" << endl;
                    return;
                }
            }
            cout << "Max students assigned!" << endl;
        } else {
            cout << "Permission denied!" << endl;
        }
    }
    
    void manageStudent(Student *student){
        if (get_permission() == "TA")
        {
            for (int i = 0; i < 10; i++)
            {
                if (this->assignedStudents[i] == student)
                {
                    cout << "Managing student..." << endl;
                    return;
                }
            }
            cout << "Student not assigned!" << endl;
        } else
        {
            cout << "Permission denied!" << endl;
        }
    }
    void display(){
        User::display();
        cout << "Assigned Students: ";
        for (int i = 0; i < 10; i++)
        {
            if (this->assignedStudents[i] != nullptr)
            {
                cout << this->assignedStudents[i]->get_Name() << " ";
            }
        }
        cout << endl;
    }
    
};



class Professor : public User
{
private:
    /* data */
    public:
    Professor():User(){};
    Professor(string n,int i,string e,int pa):User(n,i,e,pa){
        set_permission("PROFESSOR");
    };


    
};



int passwordHashing(int password){
    int hash = 5381;
    while (password != 0)
    {
        hash = hash*33 + (password % 10);
        password /= 10;
    }
    return hash;
}


void authenticateAndPerformAction(User* user,string action){
    int password;
    cout << "Enter password: ";
    cin >> password;
    if (user->get_password() == passwordHashing(password))
    {
        cout << "Authenticated successfully!" << endl;
        if (action == "accessLab")
        {
            user->accessLab();
        }
        else if (action == "submitAssignment")
        {
            int index;
            cout << "Enter assignment index to submit: ";
            cin >> index;
            ((Student*)user)->submitAssignment(index);
        }
        else if (action == "viewProjects")
        {
            ((TA*)user)->viewProjects();
        }
    }
    else
    {
        cout << "Authentication failed!" << endl;
    }
}

int main(){




    return 0;
}