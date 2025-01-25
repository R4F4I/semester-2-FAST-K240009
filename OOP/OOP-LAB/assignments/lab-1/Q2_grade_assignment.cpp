/*

? |Create a C++ program to handle student marks management. The program should allow users to
? |input marks for students in four courses: PF, OOP, DLD & ICT. It should then calculate the total
? |marks, average marks, and determine the grade for each student based on their average.
? |Use the following grading metrics:
? |     90 or above: Grade A
? |     80-89: Grade B
? |     70-79: Grade C
? |     60-69: Grade D
? |     Below 60: Grade F

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-1A


*/

#include <iostream>

using namespace std;

void printf(string str){
cout << str;
}

int main(){

    int PF,OOP,DLD,ICT;
    printf("Enter marks for PF: ");
    cin >> PF;
    printf("Enter marks for OOP: ");
    cin >> OOP;
    printf("Enter marks for DLD: ");
    cin >> DLD;
    printf("Enter marks for ICT: ");
    cin >> ICT;

    int total = PF + OOP + DLD + ICT;
    float avg = total/4.0;
    string grade;

    if(avg >= 90)
    grade = "A";
    else if(avg >= 80)
    grade = "B";
    else if(avg >= 70)
    grade = "C";
    else if(avg >= 60)
    grade = "D";
    else
    grade = "F";
    
    cout <<"Total marks: "<< total << endl;
    cout <<"Average marks: "<< avg << endl;
    cout <<"Grade: "<< grade << endl;


    return 0;
}