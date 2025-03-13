/*

? |
You're designing a library system in C++, 
but this isn't just any boring old database—this is where books come to life (well, sort of). 

- First, you need a Book class because, let's be honest, a library without books is just a fancy warehouse. 
    - This class will hold the VIP details: title, author, and publisher—the holy trinity of bookish existence. 
    - Of course, like any respectable book, it needs a constructor to bring it into the world and a display function to proudly announce, "Hey, look at me! I exist!" 

But hold onto your bookmarks, because here comes the real page-turner! 

- You need a FictionBook class that inherits from Book—because let's face it, fiction books are the fun ones!
    - This subclass adds genre (so we know if it's a thrilling mystery or a sappy romance) and protagonist (because every story needs a hero—or an anti-hero if you're feeling dramatic). 
    - This class will also have a constructor to set everything up and a display function to spill all the juicy details. 


Finally, in the main function, you'll create an object of FictionBook and display its details, because what's
the point of writing code if you can't flex it? 

So, grab your imaginary reading glasses, and let's turn this coding project into a bestseller! 📖💻✨

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;

class Book
{
private:
    string title, author, publisher;
public:
    Book(){
        this->title = "default title";
        this->author = "default author";
        this->publisher = "default publisher";
    }
    Book(string title, string author, string publisher){
        this->title = title;
        this->author = author;
        this->publisher = publisher;
    }

    void display(){
        cout<<"title: " <<this->title << endl;
        cout<<"author: " <<this->author << endl;
        cout<<"publisher: " <<this->publisher << endl;
    }
    
};


class FictionBook : public Book
{
private:
    string genre, protagonist;
public:
    FictionBook(): Book()
    {
        this->genre = "default genre";
        this->protagonist = "default protagonist";
    }
    FictionBook(string title,string  author,string  publisher,string genre, string protagonist)
        : Book(title, author, publisher)
    {
        this->genre = genre;
        this->protagonist = protagonist;
    }

    void display(){
        Book::display();
        cout<< "genre: "<< this->genre << endl;
        cout<< "protagonist: "<< this->protagonist << endl;
    }

};





int main(){

    FictionBook book1("The Alchemist", "Paulo Coelho", "HarperCollins", "Adventure", "Santiago");
    book1.display();
    cout<<"---\n\n";
    Book book2("The Alchemist", "Paulo Coelho", "HarperCollins");
    book2.display();


    return 0;
}