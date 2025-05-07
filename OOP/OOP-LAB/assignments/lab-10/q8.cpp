/*

? |
Task 8: Blog Reader Preview
Requirements:

Open article.txt in read mode.
Use seekg() to move to the halfway point.
Print 10 lines from that position.
Expected Behaviour:

Users can preview the middle of the file.


* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>
#include <fstream>

using namespace std;


// last half of file to be printed


int main(){

    ifstream file("article.txt");
    if (!file) return 1;

    file.seekg(0, ios::end); // Move to the end of the file
    int length = static_cast<int>(file.tellg()); // tellg() returns the current position of the file pointer
    file.seekg(length / 2, ios::beg); // Move to the halfway point, from beginning


    int count = 0;
    string line;

    while (count < 10 && getline(file, line)) { // Read 10 lines from the halfway point
        cout << line << endl; // Print each line to the console
        count++;
    }

    file.close(); // Close the file after reading


    return 0;
}