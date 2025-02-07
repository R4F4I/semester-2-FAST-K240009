// "guard conditions"
#ifndef STUDENT_CLASS_H
#define STUDENT_CLASS_H:

#include <iostream>
using namespace std;

namespace people
{
    class student
    {
    private:
        int age;
        string address;

    public:
        int id;
        string name, programme;

        void set_age(int a) { age = a; }
        void set_address(string ad) { address = ad; }

        int get_age()
        {
            return age;
        }
        string get_address()
        {
            return address;
        }
    };
} // namespace myNameSpace

#endif