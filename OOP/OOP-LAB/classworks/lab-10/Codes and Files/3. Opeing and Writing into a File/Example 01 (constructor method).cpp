#include <iostream>
#include <fstream>  // required for file handling

using namespace std;

int main() {
    // create an ofstream object and open file using constructor
    ofstream outputFile("example.txt"); 

    // check if the file opened successfully
    if (!outputFile) {
        cout << "Error: File could not be created!" << endl;
        return 1;
    }

    // write data to the file
    outputFile << "Hello, this file was opened using the constructor method.\n";
    outputFile << "File handling in C++ is fun and useful!\n";

    // close the file
    outputFile.close();

    cout << "Data successfully written to example.txt" << endl;

    return 0;
}


