#include <iostream>

using namespace std;



class Media
{
public:
    string title;
    int yearOfPublication;
    virtual void displayDetails(){
        cout << title << endl;
        cout << yearOfPublication << endl;
    }
};


class Book : public Media
{
public:
    string author, ISBN;
    void displayDetails() override {
        Media::displayDetails();
        std::cout << author << std::endl;
        std::cout << ISBN << std::endl;
    }

};


class Magazine : public Media
{
public:
    string editor;
    int issueNumber;
    void displayDetails() override {
        Media::displayDetails();
        std::cout << editor << std::endl;
        std::cout << issueNumber << std::endl;
    }
};



int main(){

    


    return 0;
}