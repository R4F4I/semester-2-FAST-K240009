/*

? |Create a FootballPlayer class to manage superstar footballers, with attributes like
? |playerName, position, and goalCount—because every player deserves a legendary
? |profile. Implement a default constructor that sets values like "Unknown Player,"
? |"Benchwarmer," and 0 goals. Add a parameterized constructor for customizing football
? |icons and a copy constructor for cloning players (because every team could use two
? |Messis). Include a constructor with default arguments, where only playerName is
? |required, while position defaults to "Midfielder" and goalCount defaults to 10 (just to
? |flex a little). Test the class by creating footballers, boosting their goal counts, and
? |displaying their profiles like they’re about to win the Ballon d’Or!

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;


class FootballPlayer
{
private:
    string playerName,position;
    int goals;
public:
    FootballPlayer(){
        playerName = "Unknown Player";
        position = "Benchwarmer";
        goals = 0;
    }

    // parameterized constructor with default arguments, if no arguments are passed, default values will be used
    FootballPlayer(string playerName,string position="Midfielder",int goals=10){
        this->playerName = playerName;
        this->position = position;
        this->goals = goals;
    }
    FootballPlayer(const FootballPlayer &other) {
        this->playerName = other.playerName;
        this->position = other.position;
        this->goals = other.goals;
    }

    void displayPlayerStats(){
        cout<<"Name: "<<playerName<<endl;
        cout<<"Position: "<<position<<endl;
        cout<<"Goals: "<<goals<<endl;
    }

    FootballPlayer boostGoals(int goalsScored){
        this->goals+=goalsScored;
        return *this;
    }
    
    
    ~FootballPlayer(){
        cout<<"Player "<<playerName<<" is retiring from football"<<endl;
    }
};





int main(){

    FootballPlayer messi;
    FootballPlayer ronaldo("Cristiano Ronaldo","Forward",700);
    FootballPlayer neymar("Neymar Jr.");
    FootballPlayer mbappe(neymar);

    messi.boostGoals(100).displayPlayerStats();
    cout<<"---\n";
    ronaldo.boostGoals(50).displayPlayerStats();
    cout<<"---\n";
    neymar.boostGoals(20).displayPlayerStats();

    cout<<"---\n";
    mbappe.displayPlayerStats();
    




    return 0;
}