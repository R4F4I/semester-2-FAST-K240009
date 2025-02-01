/*

? |Imagine you are tasked with creating a program to manage a library's book inventory. Each
? |book has attributes such as title, author, publication year, and genre. Design a struct that
? |effectively represents a book as a real-world entity. Then, write a C++ program that utilizes
? |this struct to demonstrate the creation, modification, and display of book information.
? |     a) Extend the program to manage multiple books in an array.
? |     b) Implement a function to search for a book by title or author.
? |     c) Allow the user to input new books and update existing book information
? |     interactively.

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;

struct book
{
    string title, author, genre;
    int publication_year;
};

int searchBook(string searchMaterial, book arr[],int arr_size){

    for (size_t i = 0; i < arr_size; i++)
    {
        if (arr[i].title == searchMaterial || arr[i].author == searchMaterial)
        {
            return i;
        }
    }
    return -1;
}

void updateBook(book arr[],int i){
    i--;
    book newBook;
    string title, author, genre;
    int publication_year;

    cout<<"Enter the new title of the book(leave blank to ignore change): ";
    cin>>title;
    if (title != "")
    {
        newBook.title = title;
    }
    else
    {
        newBook.title = arr[i].title;
    }
    
    cout<<"Enter the new author of the book(leave blank to ignore change): ";
    cin>>author;
    if (author != "")
    {
        newBook.author = author;
    }
    else
    {
        newBook.author = arr[i].author;
    }
    cout<<"Enter the new genre of the book(leave blank to ignore change): ";
    cin>>genre;
    if (genre != "")
    {
        newBook.genre = genre;
    }
    else
    {
        newBook.genre = arr[i].genre;
    }
    cout<<"Enter the new publication year of the book(enter 0 to ignore change): ";
    cin>>publication_year;
    if (publication_year != 0)
    {
        newBook.publication_year = publication_year;
    } else
    {
        newBook.publication_year = arr[i].publication_year;
    }
    


    arr[i] = newBook;
}

void addBook(book arr[],int i){
    string title, author, genre;
    int publication_year;

    cout<<"Enter the title of the book: ";
    cin>>title;
    cout<<"Enter the author of the book: ";
    cin>>author;
    cout<<"Enter the genre of the book: ";
    cin>>genre;
    cout<<"Enter the publication year of the book: ";
    cin>>publication_year;

    book newBook = {title, author, genre, publication_year};

    arr[i] = newBook;
}

void displayBooks(book arr[],int arr_size){
    for (size_t i = 0; i < arr_size; i++)
    {
        cout<<"Book "<<i+1<<": "<<"\nTitle: "<<arr[i].title<<"\nAuthor: "<<arr[i].author<<"\nGenre: "<<arr[i].genre<<"\nPublication Year: "<<arr[i].publication_year<<"\n---"<<endl;
    }
}

int main(){

    book books[20];

    books[0] = {"The Alchemist", "Paulo Coelho", "Fiction", 1988};
    books[1] = {"The Da Vinci Code", "Dan Brown", "Mystery", 2003};
    books[2] = {"The Great Gatsby", "F. Scott Fitzgerald", "Fiction", 1925};
    books[3] = {"The Catcher in the Rye", "J.D. Salinger", "Fiction", 1951};
    books[4] = {"The Hobbit", "J.R.R. Tolkien", "Fantasy", 1937};
    books[5] = {"The Hunger Games", "Suzanne Collins", "Science Fiction", 2008};
    books[6] = {"The Kite Runner", "Khaled Hosseini", "Fiction", 2003};
    books[7] = {"The Lord of the Rings", "J.R.R. Tolkien", "Fantasy", 1954};
    books[8] = {"The Lovely Bones", "Alice Sebold", "Fiction", 2002};
    books[9] = {"The Notebook", "Nicholas Sparks", "Romance", 1996};

    displayBooks(books, 10);

    int index = searchBook("F. Scott Fitzgerald", books, 10);

    cout<<"Book found at index: "<<index<<endl;

    // -----
    // Update and add book
    cout<<"Enter the index of the book you want to update: ";
    int updateIndex;
    cin>>updateIndex;



    updateBook(books, updateIndex);

    displayBooks(books, 10);

    // -----
    // Add book

    cout<<"Enter the index of the book you want to add: ";
    int addIndex;
    cin>>addIndex;

    addBook(books, addIndex);

    displayBooks(books, addIndex+1);

    return 0;
}