#include "Employee.h"


void Employee::get_data(){
    cout<<"name: "<<Employee::name<<" \n";
    cout<<"salary: "<<Employee::salary<<" \n";
    cout<<"tax_percentage: "<<Employee::tax_percentage<<" \n";
}

void Employee::set_data(string name,double salary,double tax_percentage){
    Employee::name = name;
    Employee::salary = salary;
    Employee::tax_percentage = tax_percentage;
}
void Employee::salary_after_tax(){
    Employee::salary = Employee::salary*(100-Employee::tax_percentage)/100;
}
    
void Employee::update_tax_percentage(double new_tax){
    Employee::tax_percentage = new_tax;
    Employee::salary_after_tax();
}