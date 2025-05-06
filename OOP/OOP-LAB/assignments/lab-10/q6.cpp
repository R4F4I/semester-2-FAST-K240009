/*

? |

Task 6: Encrypted Message Scanner
Requirements:

Read secret.txt character-by-character.
Count all uppercase letters.
Ignore spaces and punctuation.
Expected Behaviour:

Print the count of uppercase letters representing signals.


* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>
#include <fstream>

using namespace std;





int main(){

    ifstream file;
    char ch;
    int count = 0;
    file.open("secret.txt"); // Open the file in read mode
    if (!file)return 1;

    // count all uppercase char
    while (file.get(ch)) {
        if (isupper(ch))count++;
    }
    cout << count << endl;
    return 0;
}