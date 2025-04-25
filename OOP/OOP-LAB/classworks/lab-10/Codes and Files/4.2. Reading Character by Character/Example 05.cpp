#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inFile("readfileexample.txt");
    char ch;

    if (inFile.is_open()) {
        while (inFile.get(ch)) {  // reads one character at a time
            cout << ch;
        }
        inFile.close();
    } else {
        cout << "Unable to open file." << endl;
    }

    return 0;
}