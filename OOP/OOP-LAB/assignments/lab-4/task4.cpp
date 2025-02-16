/*

? |Create a CricketPlayer class to represent the superstars (or struggling rookies) of the
? |Pakistan cricket team, with attributes like name, jerseyNumber, and battingAverage—
? |because every player needs something to brag about on Instagram. Use a parameterized
? |constructor with the this keyword to avoid variable confusion, or worse, run-outs. Add
? |a method improveAverage(runs) that magically boosts the batting average and returns
? |the object for method chaining—because why stop at one record when you can break
? |several? Create displayPlayerStats() to proudly show off the player’s details, complete
? |with virtual commentary like, “This batting average is more consistent than Karachi’s
? |weather!”
? |To spice things up, add playMatch(runsScored) to update the batting average after each
? |match, so players can experience the highs of centuries and the lows of golden ducks.
? |Test it by creating players (Babar Azam, Muhammad Rizwan, Saim Ayub) like your
? |own dream squad, making them score big, boosting averages as if they’re on fire, and
? |then showing off their stats like they just hit six sixes in an over and became national
? |heroes overnight!

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;

class CricketPlayer
{
private:
    string name;
    int jerseyNumber, battingAverage;
public:
    CricketPlayer(string name,int jerseyNumber, int battingAverage){
        this->name = name;
        this->jerseyNumber = jerseyNumber;
        this->battingAverage = battingAverage;
    }

    CricketPlayer improveAverage(int runs){
        this->battingAverage = (this->battingAverage + runs)/2;
        return *this;
    }
    void displayPlayerStats(){
        cout<<"Name: "<<name<<endl;
        cout<<"Jersey Number: "<<jerseyNumber<<endl;
        cout<<"Batting Average: "<<battingAverage<<endl;
        cout << "This batting average is more consistent than Karachi's weather!" << endl;

    }
    void playMatch(int runsScored){
        this->battingAverage = (this->battingAverage + runsScored)/2;
    }

    ~CricketPlayer(){
        cout<<"Player "<<name<<" is retiring from cricket"<<endl;
    }
};





int main(){

    CricketPlayer babar("Babar Azam",56,50),
                 rizwan("Muhammad Rizwan",49,45),
                 saim("Saim Ayub",12,30);

    babar.displayPlayerStats();
    cout<<"---\n";
    rizwan.displayPlayerStats();
    cout<<"---\n";
    saim.displayPlayerStats();

    cout<<"\n------\n\n";

    babar.improveAverage(100).displayPlayerStats();
    cout<<"---\n";
    rizwan.improveAverage(50).displayPlayerStats();
    cout<<"---\n";
    saim.improveAverage(20).displayPlayerStats();

    cout<<"\n------\n\n";

    babar.playMatch(50);
    rizwan.playMatch(30);
    saim.playMatch(10);

    babar.displayPlayerStats();
    cout<<"---\n";
    rizwan.displayPlayerStats();
    cout<<"---\n";
    saim.displayPlayerStats();





    return 0;
}