
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    
    // ofstream is for output/read
    ofstream file;
    try{
        file.open("config.txt");
        if (!file)
            throw runtime_error("Configuration file not found");

    cout << "File loaded successfully" << endl;
    } catch (runtime_error& e){
        cout << "eror" <<endl;
    }
    
    file.close();
    


    return 0;

}