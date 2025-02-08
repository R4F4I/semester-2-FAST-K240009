/*

 ? |5. Design an Employee class that takes care of the not-so-fun part of earning money—taxes! 
 ? |Start by crafting a get_data function that collects 
 ? |   the employee's name (because we need to know whose salary to slash), 
 ? |   their monthly salary (so we can pretend like they're making money),
 ? |   and their tax percentage (because who doesn't love the feeling of money slipping through their fingers?). 
 ? |Next, add a Salary_after_tax function that 
 ? |   dramatically deducts 2% tax from the salary—because why let them keep all of it, right? 
 ? |   It returns the remaining salary, which will hopefully be enough to buy a cup of coffee (if they're lucky). 
 ? |But hold onto your hat! There's also an "update_tax_percentage function" that lets you 
 ? |   increase the tax rate—because who doesn't enjoy surprising your employees with an unexpected increase in taxes (like 3% instead of 2%)? 
 ? |After that delightful change, the salary gets recalculated, and they get to see just how little they're left with. 
 ? |It's a perfect reminder that the only thing certain in life is taxes and less money!
 
 ? |6. Now, considering question 5, you are tasked with separating the class definition into a header
 ? |file (Employee.h), then implementation file (Implement.cpp). Lastly, demonstrate it all by
 ? |creating at least 3 instances in a separate file containing main function (main.cpp).

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include "Implement.cpp"

int main(){

    Employee e1,e2,e3;

    e1.set_data("Ali",5000,10);
    e2.set_data("Ahmed",6000,15);
    e3.set_data("Asad",7000,20);

    e1.get_data();
    e2.get_data();
    e3.get_data();
    

    e1.salary_after_tax();
    e2.salary_after_tax();
    e3.salary_after_tax();

    cout<<"---------\n";

    e1.get_data();
    e2.get_data();
    e3.get_data();

    e1.update_tax_percentage(20);
    e2.update_tax_percentage(25);
    e3.update_tax_percentage(30);

    cout<<"---------\n";

    e1.get_data();
    e2.get_data();
    e3.get_data();

    return 0;
}