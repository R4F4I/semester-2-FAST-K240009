#include <iostream>
#include <fstream>  // for file operations
using namespace std;

int main() {
    ofstream file;

    // open file using open() method
    file.open("output.txt");

    // check if file is open
    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    // write to the file
    file << "This is a basic example of writing to a file in C++.\n";
    file << "File handling makes data storage easier.\n";

    // close the file
    file.close();

    cout << "Data written to file successfully." << endl;
    return 0;
}
