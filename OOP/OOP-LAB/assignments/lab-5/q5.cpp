/*

? |You’ve got a class called ValidateString and it’s basically the gatekeeper of the alphabet world. Its
job? To make sure only the coolest, most well-behaved letters (A-Z, a-z) are allowed in. Numbers,
symbols, and random chaos? No way! Using a parameterized constructor, create a bunch of
objects, each with its own string to scrutinize. Then, to really make things interesting, add a
constant function to spill the tea—telling you if your string is a total saint or secretly smuggling in
some rogue digits and weird symbols like a string rebel!"
What’s the big deal if you don’t make your function constant? Now, go ahead and add a comment
above your function, explaining why making it constant is like giving it a ‘don’t mess with me’
badge!"

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;


class ValidateString
{
    string str;
public:
    const bool validate(){
        for (char c: str)
        {
            if(!isalpha(c)){return false;}
        }
        return true;        
    }
    ValidateString(string string){
        str=string;
    }
    
};




int main(){

    ValidateString str1("strinohj2");
    ValidateString str2("strinohj");

    cout<<str1.validate()<<endl;
    cout<<str2.validate()<<endl;


    return 0;
}