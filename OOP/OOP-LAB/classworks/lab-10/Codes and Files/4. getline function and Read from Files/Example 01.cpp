#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    
    ifstream inFile("example.txt");  
    
    // variable to store each line read from file
    string line;  

    // check if file opened successfully
    if (inFile.is_open()){  
        // read file line by line until end of file
        while (getline(inFile, line))  
        {
            // print current line to console
            cout << line << endl;  
        }
        // close the file when done reading
        inFile.close();  
    }
    else{

        cout << "Unable to open file." << endl;  
    }

    return 0;  
}

