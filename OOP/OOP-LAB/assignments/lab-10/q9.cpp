/*

? |
ask 9: Spell Checker
Requirements:

Open a file draft.txt.
Search for "teh".
Replace it using seekp() and correct it in-place.
Expected Behaviour:

Only the first instance is corrected, and the file structure remains intact.

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>
#include <fstream>
#include <string>


using namespace std;





int main(){

    // ios::in          opens the file in read mode
    // ios::out         opens the file in write mode
    // ios::ate         moves the file pointer to the end of the file
    // ios::app         opens the file in append mode, but we don't need it here

    // ios::trunc       truncates the file to zero length, which we don't want
    // ios::binary      opens the file in binary mode, which is not necessary for text files
    
    // ios::nocreate and 
    // ios::noreplace are not standard flags in C++

    fstream file("draft.txt", ios::in | ios::out); // Open the file in read and write mode

    if (!file) {return 1;} // Check if the file opened successfully
    else {cout << "found draft.txt" << endl;}

    char word[4];
    // seekp() moves the file pointer to a specific position in the file
    // tellg() returns the current position of the file pointer
    // seekg(0, ios::end) moves the file pointer to the end of the file

    while (!file.eof()){
        file.read(word,3);
        std::cout << word << std::endl;
        word[3] = '\0'; // Null-terminate the string to make it a valid C-string
        if (
            string(word) == "teh" // Check if the word is "teh"
            )
        {
            cout << "found teh" << endl;
            file.seekp(static_cast<streamoff>(file.tellg()) - static_cast<streamoff>(4)); // will set the file pointer to the current position
            file.write("the", 3); // Replace "teh" with "the"
            file.flush(); // Flush the output buffer to ensure the changes are written to the file
            break;
        }
    }
    
    file.close(); // Close the file after writing
    return 0;
}