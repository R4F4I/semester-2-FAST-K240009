/*

? |Say hello to your new financial sidekick, LoanHelper—the class that will kindly remind you how
? | much you're paying every month for that loan you may or may not regret. It has a special variable
? |to store the interest rate as a user defined constant value (but don't go wild, it's between 0% and
? |0.5%—just enough to make you feel slightly guilty). You'll give it your loan amount and the
? |number of months you're willing to spend thinking about your life choices. The process is simple:
? |divide the loan by the months, add a sprinkle of interest, and boom! It'll spit out something like,
? |'You have to pay 999 every month for 12 months to repay your loan.' No more confusion—just
? |pure, financial reality!""

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;


class LoanHelper
{
private:
const float interestRate;
      float loanAmt;
      int NumOfMonths;

public:
    LoanHelper(float i=0.5,float l=10, int n=2) : interestRate(i), loanAmt(l), NumOfMonths(n){
        float monthly;
        monthly = (this->loanAmt * this->interestRate * this->NumOfMonths) / 100;
        cout << "You have to Pay "<< monthly/NumOfMonths<< " every month for " << NumOfMonths<< " months to repay your loan"<< endl;
    }

};


int main(){

    LoanHelper l1(0.2,10000,4);


    return 0;
}