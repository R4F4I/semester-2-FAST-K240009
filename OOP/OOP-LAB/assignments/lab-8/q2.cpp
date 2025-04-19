/*

? |
2. Cricket Strike Rate Calculation
Create two C++ classes, `Runs` and `BallsFaced`, to calculate a batsman's strike rate using the formula:  
**Strike Rate = (Runs / Balls Faced) × 100**.  

### Goal:
Write a `calculateStrikeRate()` function to compute the strike rate using private members of both classes. Instantiate objects in `main()` and display the result.


* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;

class BallsFaced; // forward declaration

class Runs
{
private:
    int val;    
public:
    Runs(int v = 0){val=v;}
    friend int calculateStrikeRate(BallsFaced b, Runs r);
};


class BallsFaced
{
private:
    int val;
public:
    BallsFaced(int v = 0){val=v;}

    friend int calculateStrikeRate(BallsFaced b, Runs r);
    
};


int calculateStrikeRate(BallsFaced b,Runs r)
{
    return (r.val / b.val) * 100;
}

int main(){

    BallsFaced balls(50);
    Runs runs(200);

    std::cout << "Strike Rate: " << calculateStrikeRate(balls,runs) << std::endl;


    return 0;
}