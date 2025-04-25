#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:  
    int id;
    char name[50];
};

int main() {
    // ---------- writing to file ----------
    Student s1 = {101, "Abdullah Shaikh"};
    ofstream outFile("student.dat", ios::binary);
    outFile.write((char*)&s1, sizeof(s1));
    outFile.close();

    // ---------- reading from file ----------
    Student s2;
    ifstream inFile("student.dat", ios::binary);
    inFile.read((char*)&s2, sizeof(s2));
    inFile.close();

    // ---------- displaying read data ----------
    cout << "Student ID: " << s2.id << endl;
    cout << "Student Name: " << s2.name << endl;

    return 0;
}