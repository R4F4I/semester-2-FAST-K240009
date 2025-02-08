// "guard conditions"
#ifndef EMPLOYEE_CLASS_H
#define EMPLOYEE_CLASS_H :

#include <iostream>

using namespace std;

class Employee
{
private:
    string name;
    double salary,tax_percentage;
public:

    void get_data();
    void set_data(string name,double salary,double tax_percentage);
    void salary_after_tax();
    void update_tax_percentage(double new_tax);
};


#endif