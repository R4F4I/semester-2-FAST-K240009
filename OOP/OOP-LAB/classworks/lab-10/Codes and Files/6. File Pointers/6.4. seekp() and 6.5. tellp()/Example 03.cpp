#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Open in read/write mode (create if missing)
    fstream file("data.txt", ios::in | ios::out | ios::trunc | ios::binary);
    if (!file) {
        cerr << "File error!";
        return 1;
    }

    // write data
    string quote = "In the middle of difficulty lies opportunity. -Albert_Einstein ";
    file.write(quote.c_str(), quote.size());
    
    // reset to beginning and read first 5 bytes
    file.seekg(0);
    char buffer[6] = {0};
    file.read(buffer, 5);
    cout << "First 5 bytes: " << buffer << endl;

    // overwrite 8th-13th bytes
    file.seekp(7);
    file.write("MIDDLE", 6);

    // read entire file directly
    file.seekg(0);  // rewind to start
    string content;
    getline(file, content, '\0');  // read until null character (entire file)
    cout << "Final content: " << content << endl;

    file.close();
    return 0;
}
