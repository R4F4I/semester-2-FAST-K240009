#include <iostream>
#include <fstream>
using namespace std;

class FileAppender {
private:
    ofstream file;

public:
    // constructor opens the file immediately
    FileAppender(string filename) {
        file.open(filename, ios::app);
        if (!file) {
            cout << "Failed to open file!" << endl;
            exit(1);
        }
    }

    // Simple method to append text
    void append(string text) {
        file << text;
    }

    // destructor closes the file automatically
    ~FileAppender() {
        file.close();
        cout << "Data written successfully." << endl;
    }
};

int main() {
    FileAppender myFile("data.txt");
    myFile.append("This line is appended using the open() method.\n");
    
    // file closes automatically when myFile goes out of scope
    return 0;
}