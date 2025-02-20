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

using namespace std;


class Student
{
private:
    string name,sportsInterests[10],mentorAssigned;
    int age,studentID;

public:
    Student(/* args */);
    ~Student();
};

Student::Student(/* args */)
{
}

Student::~Student()
{
}



int main(){




    return 0;
}