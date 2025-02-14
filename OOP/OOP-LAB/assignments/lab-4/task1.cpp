/*

? |Design a Book class for a library system that’s in desperate need of organization, with
? |attributes title, author, and price—because even imaginary books need royalties.
? |Implement a default constructor that sets the blandest values possible (think "Untitled,"
? |"Anonymous," and free), a parameterized constructor for when you want your book to
? |have an actual identity, a copy constructor for duplicating your masterpiece, and a
? |constructor with default arguments where you only need to provide the title, while
? |author defaults to "Unknown" and price to 0.0 (clearly a bestseller). Test your creation
? |by spawning book objects every way imaginable and proudly showing off their details
? |like they’re competing in a talent show.

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;

class Book
{
private:
    string author, title;
    float price;
public:
    // def 
    Book(){
        author="anonymous";
        price=0;
        title="untitled";
    }
    Book(string title){
        this->author="anonymous";
        this->price=0;
        this->title=title;
    }
    // para
    Book(string author, string title,float price){
        this->author=author;
        this->price=price;
        this->title=title;
    }
    //  copy

    //shallow
    Book(Book &obj){
        author=obj.author;
        price=obj.price;
        title=obj.title;

    }
    // deep
    /* Book(Book &obj){
        author=obj.author;
        price=new float (*obj.price);
        title=obj.title;

    } */

    void display(){
        cout<<"author: "<<author<<"\n";
        cout<<"price: "<<price<<"\n";
        cout<<"title: "<<title<<"\n";
    }
    ~Book(){
        // delete price;
    }
};




int main(){

    Book b1;
    Book b2("book title");
    Book b3("rafay","book everything",12.3);
    Book b4(b2);

    cout<<"book 1:\n";
    b1.display();
    cout<<"---\n";
    cout<<"book 2:\n";
    b2.display();
    cout<<"---\n";
    cout<<"book 3:\n";
    b3.display();
    cout<<"---\n";
    cout<<"book 4:\n";
    b4.display();
    
    return 0;
}