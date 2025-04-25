/*

? |
Task 03: Library Management System
Problem: A library needs a digital system to securely manage book records (title, author, ISBN). Staff should access book details without modifying records directly. The system should separate public interfaces (e.g., searching books) from internal data handling.

Classes and Structure:
Class Book:
Data Members:
title, author, ISBN (strings): Book metadata.
Member Functions:
Constructor to initialize book details.
getTitle(), getAuthor(), getISBN(): Return book properties.
Class Library (Optional):
Data Members:
A collection (e.g., array/list) of Book objects.
Member Functions:
addBook(), removeBook(), searchBook(): Manage the collection.
Flow:
Define Book in header and source files.
In main(), create a Book object and display its metadata.

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;


class Book
{
private:
    string title, author, ISBN;
public:
    Book(string t = "new title",string a = "new author",string I = "new ISBN") title(t),author(a),ISBN(I){}
    
    string getTitle(){
        return title;
    }
    string getAuthor(){
        return author;
    }
    string getISBN(){
        return ISBN;
    }


};

class Library
{
private:
    Book books[10];
    int index;
public:
    Library();
    
    void addBook(book b){
        this->books[this->index] = b;
        index++;
    }
    void removeBook(){
        index--;
    }

};

Library::Library()
{
}

Library::~Library()
{
}



int main(){




    return 0;
}