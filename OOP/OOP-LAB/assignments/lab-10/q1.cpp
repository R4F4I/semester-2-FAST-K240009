/*

? |
ask 1: Greeting Card Automation
Requirements:

Ask the user for the recipient’s name and a short message.
Open a file named greeting.txt in write mode.
Write the message in the format:
Dear [Name],
[Message]
Best Regards!
Expected Behaviour:

The file should contain a clean greeting format every time the program runs.

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>
#include <fstream>

using namespace std;




int main(){

    ofstream file;
    file.open("greeting.txt");
    
    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }
    
    string name, message;

    cout << "Enter the recipient's name: ";
    getline(cin, name); // Use getline to allow spaces in the name

    cout << "Enter a short message: ";
    getline(cin, message);

    file << "Dear " << name << "," << endl;
    file << message << endl;
    file << "Best Regards!" << endl;

    file.close(); // Close the file after writing



    return 0;
}