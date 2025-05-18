#include <iostream>
#include <fstream>

using namespace std;

class Test { 
    int ID; 
    string name; 
    static int genID; 
public: 

  Test(){
    genID++;
    ID = genID;
    name = "000"+ to_string(genID);
  };

  void operator+ (string file){
    ofstream oFile(file,ios::app);

    oFile <<"ID = "<<this->ID<<", Name = "<<this->name<<"\n";
    oFile.close();
  }

}; 
 
int Test::genID = 0; 
 
int main() { 
    Test t1, t2; 
    t1 + "outfile.txt"; 
    t2 + "outfile.txt"; 
} 