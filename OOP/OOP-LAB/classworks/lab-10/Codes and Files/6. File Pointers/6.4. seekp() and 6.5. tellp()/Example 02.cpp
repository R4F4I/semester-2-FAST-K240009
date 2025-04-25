#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream out("output.txt", ios::binary);
    if (!out) {
        cerr << "File creation failed!";
        return 1;
    }

    // write at start
    out.write("HELLO", 5);
    streampos pos = out.tellp();
    cout << "Position after write: " << pos << endl; // 5

    // move put pointer to 10th byte and write
    out.seekp(10, ios::beg);
    out.write("WORLD", 5); // bytes 10-14: WORLD

    out.close();
    return 0;
}
