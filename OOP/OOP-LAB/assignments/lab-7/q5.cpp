/*

? |
Visualize a digital multimedia library management system designed to catalog and circulate a diverse range of media items, 
including books, DVDs, CDs, and magazines. 
The `Media` class serves as the base, encapsulating core data members such as:

- `title`
- `publicationDate`
- `uniqueID`
- `publisher`

### Functions:
- `displayInfo()`: Outputs media details.
- `checkOut()`: Processes lending.
- `returnItem()`: Handles returns.

### Derived Classes:
- **Book**: Includes 
    `author`, 
    `ISBN`, and 
    `numberOfPages`. 
    Modifies `displayInfo()` for books.
- **DVD**: Incorporates 
    `director`, 
    `duration`, and 
    `rating`. 
    Updates `displayInfo()` for movie details.
- **CD**: Includes 
    `artist`, 
    `numberOfTracks`, and 
    `genre`. 
    Adapts `displayInfo()` for music albums.
- **Magazine**: Adds magazine-specific attributes.

### Additional Features:
The system supports function overloading for searching media by different attributes (e.g., `title`, `author`, or `publication year`).

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;

class Media
{
private:
    string title, publicationDate, uniqueID, publisher;
public:
  
    Media(string t, string pD, string ID, string pub){
        this->title = t;
        this->publicationDate = pD;
        this->uniqueID = ID;
        this->publisher = pub;
    }

    void displayInfo(){
        cout << "Title: " << this->title << endl;
        cout << "Publication Date: " << this->publicationDate << endl;
        cout << "Unique ID: " << this->uniqueID << endl;
        cout << "Publisher: " << this->publisher << endl;
    }
    void checkOut(){
        cout << "Item Checked Out" << endl;
    }

    void returnItem(){
        cout << "Item Returned" << endl;
    }
};


class Book : public Media
{
private:
    string author;
    int ISBN,numberOfPages;
public:
    Book(string t, string pD, string ID, string pub,string a, int ISBN, int numPages):Media(t,pD,ID,pub) {
        this->author = a;
        this->ISBN = ISBN;
        this->numberOfPages = numPages;
    }
    

    void displayInfo(){
        Media::displayInfo();
        cout << "Author: " << this->author << endl;
        cout << "ISBN: " << this->ISBN << endl;
        cout << "Number of Pages: " << this->numberOfPages << endl;
    }
};


class DVD : public Media
{
private:
    string director;
    int duration, rating;
public:
    DVD(string t, string pD, string ID, string pub,string d, int dur, int rating):Media(t,pD,ID,pub){
        this->director = d;
        this->duration = dur;
        this->rating = rating;
    }
    

    void displayInfo(){
        Media::displayInfo();
        cout << "Director: " << this->director << endl;
        cout << "Duration: " << this->duration << endl;
        cout << "Rating: " << this->rating << endl;
    }
};


class CD: public Media
{
private:
    string artist,genre;
    int numberOfTracks;
public:
    CD(string t, string pD, string ID, string pub,string artist, string genre, int numTracks):Media(t,pD,ID,pub){
        this->artist = artist;
        this->genre = genre;
        this->numberOfTracks = numTracks;
    }
    
    void displayInfo(){
        Media::displayInfo();
        cout << "Artist: " << this->artist << endl;
        cout << "Genre: " << this->genre << endl;
        cout << "Number of Tracks: " << this->numberOfTracks << endl;
    }
};



int main(){

    Book b("The Alchemist", "1988", "1234", "HarperCollins", "Paulo Coelho", 123456, 200);
    b.displayInfo();

    DVD d("Inception", "2010", "2345", "Warner Bros", "Christopher Nolan", 120, 5);
    d.displayInfo();

    CD c("Dil Dil Pakistan", "1987", "3456", "Shalimar Recording Company", "Vital Signs", "Pop Rock", 10);
    c.displayInfo();




    return 0;
}