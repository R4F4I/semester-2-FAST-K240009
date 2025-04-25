#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream in("input.txt", ios::binary);
    if (!in) {
        cerr << "File not found!";
        return 1;
    }

    // read first 5 bytes (properly null-terminated)
    char buffer[6] = {0};  // initialize with zeros
    in.read(buffer, 5);
    cout << "First 5 bytes: " << buffer << endl;

    // move get pointer 10 bytes from start
    in.seekg(10, ios::beg);
    streampos pos = in.tellg();
    cout << "Current position: " << pos << endl;

    // read next 5 bytes (using write for safety)
    in.read(buffer, 5);
    cout << "Bytes 10-14: ";
    cout.write(buffer, 5);
    cout << endl;

    in.close();
    return 0;
}