#include <iostream>
#include <fstream>
using namespace std;

class FileWordReader {
private:
    ifstream file;

public:
    // constructor that opens the file
    FileWordReader(const string& filename) {
        file.open(filename);
        if (!file.is_open()) {
            cerr << "File not found." << endl;
            exit(1);
        }
    }

    // reads and displays words one by one
    void displayWords() {
        string word;
        while (file >> word) {
            cout << word << endl;
        }
    }

    // destructor closes the file automatically
    ~FileWordReader() {
        if (file.is_open()) {
            file.close();
        }
    }
};

int main() {
    FileWordReader reader("readfileexample.txt");
    reader.displayWords();
    return 0;
}