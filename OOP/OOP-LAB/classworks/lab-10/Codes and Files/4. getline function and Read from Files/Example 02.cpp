#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileReader {
private:
    ifstream file;
    string filename;

public:
    // constructor takes filename and opens the file
    FileReader(const string& fname) : filename(fname) {
        file.open(filename);
    }

    // check if file is open
    bool isOpen() const {
        return file.is_open();
    }

    // read and display file contents
    void displayContents() {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
    }

    // destructor closes the file automatically
    ~FileReader() {
        if (file.is_open()) {
            file.close();
        }
    }
};

int main() {
    
    FileReader reader("example.txt");

    if (reader.isOpen()) {
        reader.displayContents();
    }
    else {
        cout << "Unable to open file." << endl;
    }

    return 0;
}

