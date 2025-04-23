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
    /* data */
public:
    Book(/* args */);
    ~Book();
};

Book::Book(/* args */)
{
}

Book::~Book()
{
}



int main(){




    return 0;
}