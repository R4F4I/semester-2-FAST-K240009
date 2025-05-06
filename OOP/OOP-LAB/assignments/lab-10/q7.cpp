/*

? |

Task 7: Student GPA Records Manager
Requirements:

Define a struct Student with:
char name[50];
int id;
float gpa;
Take input for multiple students.
Use write() to store data in students.dat.
Read data back using read() and display it.
Expected Behaviour:

Binary file stores and retrieves accurate student data.


* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>
#include <fstream>

using namespace std;


struct Student
{
    char name[50];
    int id;
    float gpa;
};

int write_file(string filename, Student student[], int n) {
    ofstream outFile(filename, ios::binary);
    if (!outFile) return 1;

    outFile.write((char*)student, sizeof(Student) * n); // Write all students at once
    outFile.close(); // Close the file after writing

    return 0;
}

int read_file(string filename, Student student[], int n) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) return 1;

    inFile.read((char*)student, sizeof(Student) * n); // Read all students at once
    inFile.close(); // Close the file after reading

    return 0;
}

int main(){

    Student student[100]; // Array of 100 students
    int n; // Number of students
    cout << "Enter number of students: ";
    cin >> n;
    cin.ignore(); // Ignore the newline character left in the buffer

    // Input student data

    for (int i = 0; i < n; i++) {
        cout << "Enter name: ";
        cin.getline(student[i].name, 50); // Use getline to allow spaces in the name
        cout << "Enter ID: ";
        cin >> student[i].id;
        cout << "Enter GPA: ";
        cin >> student[i].gpa;
        cin.ignore(); // Ignore the newline character left in the buffer
    }

    // Write to file
    if (write_file("students.dat", student, n) != 0) return 1;

    cout << "Data written to file successfully." << endl;

    // Read from file
    if (read_file("students.dat", student, n) != 0) return 1;

    cout << "Data read from file successfully." << endl;

    // Display student data
    cout << "Student Data:" << endl;

    for (int i = 0; i < n; i++) {
        cout << "Name: " << student[i].name << ", ID: " << student[i].id << ", GPA: " << student[i].gpa << endl;
    }


    return 0;
}