/*

? |
Task 5: Vocabulary Builder
Requirements:

Read a paragraph from story.txt.
Print each word on a new line.
Use getline() and istringstream.
Expected Behaviour:

Words appear one-by-one on the console.

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;





int main(){

    ifstream file;
    string line, word;
    file.open("story.txt"); // Open the file in read mode
    if (!file) return 1;

    while (getline(file, line)) // read each line
    {
        istringstream iss(line);
        while (iss >> word){ // read each word
            cout << word << endl; // Print each word on a new line
        }
    }
    
    file.close(); // Close the file after reading
    return 0;
}