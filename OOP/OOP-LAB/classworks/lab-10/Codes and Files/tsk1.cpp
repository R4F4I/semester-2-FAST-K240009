#include <iostream>
#include <fstream>

using namespace std;

class Student
{

public:
    int ID;
    string name;
    float GPA;
    Student(){}
};

int main(){

    Student stds[6];
    int ID;
    string name;
    float GPA;
    cout<< "enter data for 5 students:"<<endl;
    /* for (size_t i = 0; i < 5; i++)
    {
        cout<< "ID: ";
        cin>> ID;
        cout<< "name: ";
        cin>> name;
        cout<< "GPA: ";
        cin>> GPA;

        stds[i].ID = ID;
        stds[i].name = name;
        stds[i].GPA = GPA;
    }
 */



    ofstream writerObj("students.txt",ios::out);


    for (size_t i = 0; i < 5; i++)
    {        
        writerObj << stds[i].ID<<" , " << stds[i].name << " , "<< stds[i].GPA<<"\n";
    }
    cout<< "written successfully\n";
    
    writerObj.close();

    writerObj.open("students.txt",ios::app);
    
    cout<< "enter data for an additional students:"<<endl;
    
    cout<< "ID: ";
    cin>> ID;
    cout<< "name: ";
    cin>> name;
    cout<< "GPA: ";
    cin>> GPA;

    stds[6].ID = ID;
    stds[6].name = name;
    stds[6].GPA = GPA;

    writerObj << stds[5].ID<<" , " << stds[5].name << " , "<< stds[5].GPA<<"\n";
    writerObj.close();


    // ifstream readerObj("students.txt",);

}