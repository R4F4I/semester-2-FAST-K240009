/*

? |Question 01. [ Marks 10]
FAST has many sports enthusiasts, and to encourage their growth, the university wants to
implement a mentorship program. In this program, mentors guide learners (students), but each
mentor has a limited capacity to manage a fixed number of learners. The university sports
mentorship system involves two main roles: mentors and learners (students).
The Student class has data members such as studentID, name, age, sportsInterests[], and
mentorAssigned. A student can register for mentorship under a mentor by calling the
registerForMentorship(Mentor m) method. The student can also view the mentor's details and
update their sports interests through viewMentorDetails() and updateSportsInterest(Sport s)
methods, respectively.

The Mentor class, on the other hand, has data members like mentorID, name, sportsExpertise[],
maxLearners, and assignedLearners[]. The maxLearners attribute specifies the maximum number
of learners the mentor can handle. The mentor can assign learners using the assignLearner(Student s) method, 
as long as they have available capacity. If a learner needs to be removed,
the removeLearner(Student s) method can be used. The mentor can also view their list
of assigned learners by calling viewLearners() and provide guidance using the
provideGuidance() method.

The Sport class defines the sports offered for mentorship. It includes attributes like sportID,
name, description, and requiredSkills[]. The mentor can add new skills required for a specific
sport using the addSkill(Skill s) method, and they can also remove skills from the list using
removeSkill(Skill s).

The Skill class defines the various skills related to each sport, including data members like
skillID, skillName, and description. This class provides methods such as showSkillDetails() to
display the skill details and updateSkillDescription(String newDescription) to update a skill’s
description. In this system, each mentor has a limited capacity to handle learners. For example, a
mentor named Ali who specializes in Tennis can only mentor up to three students at a time.
When a student like Saad, who is interested in Tennis, registers for mentorship, Ali can assign
him as a mentee if there is space. If Ali already has three learners, Saad cannot be assigned until
a slot becomes available. If Saad later decides to stop the mentorship, Ali can remove them,
freeing up space for a new student. The system allows mentors to guide students on their sports
skills, providing training and advice to improve their performance.

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>
#include <string>

using namespace std;

const int MAX_ARR_SIZE = 2;

/* 
The university sports mentorship system involves two main roles: 
    mentors and learners (students).

- Student class has data members such as studentID, name, age, sportsInterests[], and
  mentorAssigned

- A student can register for mentorship under a mentor by calling the
  registerForMentorship(Mentor m) method.

- The student can also view the mentor's details and
  update their sports interests through viewMentorDetails() and updateSportsInterest(Sport s)
  methods, respectively.

---------------------------

- The Mentor class, on the other hand, has data members like mentorID, name, sportsExpertise[],
  maxLearners, and assignedLearners[].

    - The maxLearners attribute specifies the maximum number
      of learners the mentor can handle.

- The mentor can assign learners using the assignLearner(Student s) method, 
  as long as they have available capacity.

- If a learner needs to be removed,
  the removeLearner(Student s) method can be used. 

- The mentor can also view their list
  of assigned learners by calling viewLearners() and 
  provide guidance using the provideGuidance() method.

---------------------------

- The Sport class defines the sports offered for mentorship. It includes attributes like sportID,
  name, description, and requiredSkills[]. 

- The mentor can add new skills required for a specific sport using the addSkill(Skill s) method,
  and they can also remove skills from the list using removeSkill(Skill s).

---------------------------

- The Skill class defines the various skills related to each sport, including data members like
  skillID, skillName, and description.

- This class provides methods such as showSkillDetails() to
  display the skill details and updateSkillDescription(String newDescription) to update a skill's
  description. 

---------------------------

- In this system, each mentor has a limited capacity to handle learners. 
- For example,
    - mentor named Ali who specializes in Tennis can only mentor up to three students at a time.
    - When a student like Saad, who is interested in Tennis, registers for mentorship, 
    - Ali can assign him as a mentee if there is space. 
    - If Ali already has three learners, Saad cannot be assigned until a slot becomes available. 
    - If Saad later decides to stop the mentorship, Ali can remove them, freeing up space for a new student. 
- The system allows mentors to guide students on their sports skills, providing training and advice to improve their performance.


                                                                                                            
                                         ┌───────────────────────────────┐                                  
                  ┌──────────────────────┼            student            ┼──────────────────────┐           
                  │                      │───────────────────────────────┤                      │           
                  │                      │studentID                      │                      │           
                  │                      │name                           │                      │           
                  │                      │age                            │                      │           
                  │                      │sportsInterests[]              │                      │           
                  │                      │mentorAssigned                 │                      │           
                  │                      │───────────────────────────────┤                      │           
                  │                      │registerForMentorship(Mentor m)│                      │           
  ┌───────────────▼───────────────┐      │viewMentorDetails()            │                      │           
  │             sport             │      │updateSportsInterest(Sport s)  │                      │           
  │───────────────────────────────┤      │                               │                      │           
  │sportID                        │      │                               │                      │           
  │name                           │      └───────────────────────────────┘                      │           
  │description                    │                                                             │           
  │requiredSkills[]               │                                       ┌─────────────────────▼─────┐     
  │───────────────────────────────┤                                       │          mentor           │     
  │addSkill(Skill s)              │                                       │───────────────────────────┤     
  │removeSkill(Skill s)           │                                       │mentorID                   │     
  │                               │                                       │name                       │     
  │                               │                                       │sportsExpertise[]          │     
  │                               │                                       │maxLearners                │     
  │                               │                                       │assignedLearners[]         │     
  └────────────────┬──────────────┘                                       │───────────────────────────┤     
                   │                                                      │assignLearner(Student s)   │     
                   │                                                      │removeLearner(Student s)   │     
                   │                                                      │viewLearners()             │     
                   │                                                      │provideGuidance()          │     
  ┌────────────────▼────────────────────────────┐                         │                           │     
  │                    skill                    │                         └───────────────────────────┘     
  │─────────────────────────────────────────────┤                                                           
  │skillID                                      │                                                           
  │skillName                                    │                                                           
  │description                                  │                                                           
  │─────────────────────────────────────────────┤                                                           
  │showSkillDetails()                           │                                                           
  │updateSkillDescription(String newDescription)│                                                           
  └─────────────────────────────────────────────┘                                                           
 */


class Skill
{
private:
    static int timesCalled;
    string skillName,description;
    int skillID;
public:
    //default constructor
    Skill(){
        this->skillID = -1;
        this->skillName = "NA";
        this->description = "NA";
    };
    // para constructor
    Skill(int skillID, string skillName, string description){
        this->skillID = skillID;
        this->skillName = skillName;
        this->description = description;
    }
    // copy constructor
    Skill(Skill &s){
        this->skillID = s.skillID;
        this->skillName = s.skillName;
        this->description = s.description;
    }
    int getSkillID(){return this->skillID;}
    void setSkillID(int sID){this->skillID=sID;}
    void showSkillDetails(){
        cout << "Skill ID: " << this->skillID << endl;
        cout << "skillName: " << this->skillName << endl;
        cout << "description: " << this->description << endl;
    }
    void updateSkillDescription(string newDescription){
        this->description = newDescription;
    }

    ~Skill(){
        cout << timesCalled++ << " Skill object destroyed." << endl;
    }

};

int Skill::timesCalled = 0;



class Sport
{
private:
    int skillsCount=0;
    string name,description;
    Skill requiredSkills[MAX_ARR_SIZE];
    int sportID;
public:
    Sport(){
        this->sportID = -1;
        this->name = "NA";
        this->description = "NA";
    }
    Sport(int sportID, string name, string description, Skill requiredSkills[])
    {
        this->sportID = sportID;
        this->name = name;
        this->description = description;
        for (size_t i = 0; i < MAX_ARR_SIZE; i++)
        {
            this->requiredSkills[i] = requiredSkills[i];
        }
    }
    void addSkill(Skill s){
        requiredSkills[skillsCount++] = s;
    }
    void removeSkill(Skill s){
        for (size_t i = 0; i < skillsCount; i++)
        {
            if (requiredSkills[i].getSkillID() == s.getSkillID())
            {
                requiredSkills[i].setSkillID(-1);
                skillsCount--;
            }
        }
    }

    ~Sport(){
        cout << "Sport object destroyed." << endl;
    }
};

class Mentor;

class Student
{
    
private:
    int sportsInterest=0;
    string name;
    Sport sportsInterests[MAX_ARR_SIZE];
    string mentorAssigned;
    int age,studentID;

public:
    Student(){
        this->age = -1;
        this->studentID = -1;
        this->name = "NA";
    }
    Student(int age, int studentID, string name,string mentorAssigned, Sport sportsInterests[]){
        this->age = age;
        this->studentID = studentID;
        this->name = name;
        this->mentorAssigned = mentorAssigned;
        for (size_t i = 0; i < MAX_ARR_SIZE; i++)
        {
            this->sportsInterests[i] = sportsInterests[i];
        }
    }
    void setStudentID(int studentID){this->studentID= studentID;}
    int getStudentID(){return this->studentID;}
    int getStudentAge(){return this->age;}
    string getStudentName(){return this->name;}
    
    void registerForMentorship(Mentor *m);
    /* {
        m->assignLearner(*this);
    } */
    void viewMentorDetails(Mentor *m);
    /* {
        m->showMentorDetails();
    } */

    void updateSportsInterest(Sport s){
        sportsInterests[sportsInterest++] = s;
    }

    ~Student(){
        cout << "Student object destroyed." << endl;
    }
};



class Mentor
{      
    int underMentorship=0;
    string name,sportsExpertise[MAX_ARR_SIZE];
    int mentorID,maxLearners = 2;
    Student assignedLearners[MAX_ARR_SIZE]; // 10 is the max limit of learners a mentor can have

public:
    // default constructor
    Mentor(){
        this->mentorID = -1;
        this->maxLearners = -1;
        this->name = "NA";
        for (int i = 0; i < MAX_ARR_SIZE; i++) {
            this->sportsExpertise[i] = "";
        }
        for (int i = 0; i < MAX_ARR_SIZE; i++) {
            this->assignedLearners[i] = Student();
        }
    }
    // parameterized constructor
    Mentor(int mentorID, string name,  int maxLearners,Student assignedLearners[]){
        this->mentorID = mentorID;
        this->maxLearners = maxLearners;  
        this->name = name;
        for (int i = 0; i < MAX_ARR_SIZE; i++) {
            this->sportsExpertise[i] = "";
        }
        for (size_t i = 0; i < maxLearners; i++)
        {
            this->assignedLearners[i] = assignedLearners[i];
        }
        
    }

    void showMentorDetails(){
        cout << "Mentor ID: " << this->mentorID << endl;
        cout << "Mentor Name: " << this->name << endl;
        cout << "Mentor Expertise: " << this->sportsExpertise << endl;
    }

    void assignLearner(Student &s){
        if (underMentorship < maxLearners) {
            assignedLearners[underMentorship++] = s;
        } else {
            cout << "Cannot assign more learners, capacity full." << endl;
        }
    }
    void removeLearner(Student s){
        for (size_t i = 0; i < maxLearners; i++)
        {
            if (assignedLearners[i].getStudentID() == s.getStudentID())
            {
                assignedLearners[i].setStudentID(-1);
                underMentorship--;
            }
            /* code */
        }
        
        
    }
    void viewLearners(){
        for (size_t i = 0; i < underMentorship; i++)
        {
            cout << "Student ID: " << assignedLearners[i].getStudentID() << endl;
            cout << "Student Age: " << assignedLearners[i].getStudentAge() << endl;
            cout << "Student Name: " << assignedLearners[i].getStudentName() << endl;
        }
        
    }
    void provideGuidance(){
        cout << "Guidance provided." << endl;
    }

    ~Mentor(){
        cout << "Mentor object destroyed." << endl;
    }
};

// int Mentor::underMentorship = 0;

void Student::registerForMentorship(Mentor *m){
        m->assignLearner(*this);
    }
void Student::viewMentorDetails(Mentor *m){
    m->showMentorDetails();
}



int main() {
    // Skills function correctly
    cout << "Skills" << endl;
    Skill skill1(1, "Skill1", "Skill1 Description");
    Skill skill2(2, "Skill2", "Skill2 Description");
    Skill skill3(3, "Skill3", "Skill3 Description");
    cout << "skills function correctly" << endl;

    Skill skills[MAX_ARR_SIZE] = {skill1, skill2};

    // Sports function correctly
    cout << "Sports" << endl;
    Sport sp1(1, "Sport1", "Sport1 Description", skills);
    Sport sp2(2, "Sport2", "Sport2 Description", skills);
    cout << "sports function correctly" << endl;

    Student s1, s2;
    cout << "students function correctly" << endl;

    Student Learners[MAX_ARR_SIZE] = {s1, s2};

    cout << "Mentor" << endl;
    Mentor m1(1, "Mentor1", 2, Learners);
    cout << "Mentor function correctly" << endl;

    Sport Sports[MAX_ARR_SIZE] = {sp1, sp2};
    cout << "new sports arr" << endl;

    cout << "new student defined by para const" << endl;
    Student st1(20, 1, "Student1", "mentor1", Sports);
    cout << "defined successfully" << endl;

    st1.registerForMentorship(&m1);
    st1.viewMentorDetails(&m1);

    cout << "exiting..." << endl;

    return 0;
}