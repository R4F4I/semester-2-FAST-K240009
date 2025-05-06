/*

? |
ask 3: Workshop Registration Tool
Requirements:

Take user input: name and email.
Open signup.txt in append mode.
Write the data as:
Name: <name>, Email: <email>
Repeat for multiple users if needed.
Expected Behaviour:

Old data is preserved, and new entries are appended.

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>
#include <fstream>

using namespace std;





int main(){

    ofstream file;
    string name, email;

    file.open("signup.txt",ios::app); // Open in append mode
    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    cout << "Enter your name: ";
    getline(cin, name); // Use getline to allow spaces in the name
    
    cout << "Enter your email: ";
    getline(cin, email); // Use getline to allow spaces in the email

    file << "Name: " << name << ", Email: " << email << endl;

    return 0;
}