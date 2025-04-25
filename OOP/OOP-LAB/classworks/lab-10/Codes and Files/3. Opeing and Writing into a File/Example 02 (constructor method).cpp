#include <iostream>
#include <fstream>

using namespace std;

class FileHandler {
private:
    ofstream outputFile;
    string filename;

public:
    // constructor that opens the file
    FileHandler(string fname) : filename(fname) {
        outputFile.open(filename);
        if (!outputFile) {
            cerr << "Error: File could not be created!" << endl;
            exit(1); 
        }
    }

    // method to write data to the file
    void writeData(string data) {
        if (outputFile.is_open()) {
            outputFile << data;
        }
    }

    // method to close the file
    void closeFile() {
        if (outputFile.is_open()) {
            outputFile.close();
            cout << "Data successfully written to " << filename << endl;
        }
    }

};

int main() {
    
    FileHandler fileHandler("example.txt");

    // write data to the file
    fileHandler.writeData("Hello, this file was opened using the constructor method.\n");
    fileHandler.writeData("File handling in C++ is fun and useful!\n");

    // close the file explicitly
    fileHandler.closeFile();

    return 0;
}