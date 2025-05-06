/*

? |
## Task 4: System Startup Logger

**Requirements:**
- Use `ios::app` to append to `system_log.txt`.
- Log the message:
    ```
    System started at: [current time]
    ```
- Use `<ctime>` to fetch the timestamp.

**Expected Behaviour:**
- No log entries are overwritten. Every run adds a new log line.

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>
#include <fstream>
#include <ctime> // For time functions

using namespace std;





int main(){

    ofstream file;
    time_t now = time(0); // Get current time

    file.open("system_log.txt", ios::app); // Open in append mode
    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    file << "System started at: " << ctime(&now); // Write the current time to the file



    return 0;
}