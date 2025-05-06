/*

? |

Task 2: Diary Entry Writer
Requirements:

Accept multiple lines of input using getline() until the user enters "exit".
Save each line into diary.txt.
Use appropriate stream handling with ofstream.
Expected Behaviour:

The file appends each diary entry and closes gracefully.



* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A



*/

#include <iostream>
#include <fstream>

using namespace std;






int main(){

    ofstream file;
    string message;
    
    file.open("diary.txt",ios::app); // Open in append mode
    if (!file) {cout << "Error opening file!" << endl;return 1;}
    

    while (message != "exit") {
        cout << "Enter messages: ";
        getline(cin, message);
        file << message << endl;
    }

    return 0;
}