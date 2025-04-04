/*

? |

# Scenario # 2: Haunted House Simulation Game

### Overview:
Simulate a Haunted House-based game where users can:
- Create multiple Haunted Houses with ghosts of their choice.
- Run simulations to evaluate visitor experience and scares.

### Entities Involved:
1. **HauntedHouse**:
   - Attributes: Name, multiple ghosts.
   - Ensure runtime polymorphism.

2. **Ghost**:
   - Superclass for all types of ghosts.
   - Attributes:
     - Name of the worker playing the ghost.
     - Scare level (RNG 1-10).
   - Functions:
     - Perform haunting.
     - Operator overloading:
       - `<<` operator: Display ghost information.
       - `+` operator: Upgrade a ghost (combine two ghosts into one with combined scare levels).

3. **Types of Ghosts**:
   - **Poltergeists**: Move objects.
   - **Banshees**: Scream loudly.
   - **ShadowGhosts**: Whisper creepily.
   - **HybridGhosts**:
     - Example: ShadowPoltergeist (combines actions of ShadowGhost and Poltergeist).

4. **Visitor**:
   - Attributes:
     - Name.
     - Bravery level (1-10):
       - 1-4: Cowardly.
       - 5-7: Average.
       - 8-10: Fearless.
   - Behavior:
     - Ghosts haunt visitors.
     - Reactions depend on scare level vs bravery range:
       - Scare level < bravery range: Visitor laughs or taunts the ghost.
       - Scare level > bravery range: Visitor screams or runs away.
       - Scare level ≈ bravery range: Visitor gets a shaky voice.
     - **Important**: Check if scare level lies within bravery range (do not compare numbers directly).

### Main Method:
- Create 2-3 Haunted Houses with multiple ghosts of each type.
- Create an array of Visitors (group of friends visiting the Haunted House):
  - Ensure at least one visitor of each bravery level.
- Implement a global friend function `Visit`:
  - Accepts Visitors array and a Haunted House.
  - Simulates the visit for each Haunted House.


* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;

class Ghost
{
private:
    string performerName;
    string name;
    int scareLevel; // 1-10
    
    string action; // Move objects, Scream loudly, Whisper creepily
public:


    Ghost(/* args */){
      this->name = "NA";
      this->scareLevel = 0;
      this->action = "NA";
    }
    Ghost(string name,string pN ,int scareLevel,string action){
      this->performerName = pN;
      this->name = name;
      this->scareLevel = scareLevel;
      this->action = action;
    }
    string getName() const {
        return this->name;
    }
    void setName(string name){
        this->name = name;
    }
    void setAction(string action){
        this->action = action;
    }
    string getAction() const {
        return this->action;
    }
    int getScareLevel() const {
        return this->scareLevel;
    }
    void setScareLevel(int scareLevel){
        this->scareLevel = scareLevel;
    }
    string getPerformerName() const {
        return this->performerName;
    }
    Ghost operator +(Ghost &otherGhost){
        Ghost newGhost;
        newGhost.performerName = this->performerName + " & " + otherGhost.performerName;
        newGhost.name = this->name + " & " + otherGhost.name;
        newGhost.scareLevel = this->scareLevel + otherGhost.scareLevel;
        newGhost.action = this->action + " and " + otherGhost.action;
        return newGhost;
    }

    friend ostream &operator<<(ostream &out, const Ghost &g);

    // ~Ghost();
};

ostream &operator<<(ostream &out, const Ghost &g) {
  out << "Ghost Name: " << g.getName() << endl;
  out << "Performer Name: " << g.getPerformerName() << endl;
  out << "Scare Level: " << g.getScareLevel() << endl;
  out << "Action: " << g.getAction() << endl;
  return out;

}


class Poltergeist :virtual public Ghost
{
public:
    Poltergeist() : Ghost() {}
    Poltergeist(string name, string pN, int scareLevel) : Ghost(name,pN, scareLevel, "Move objects") {}
};

class Banshees : virtual public Ghost
{
public:
    Banshees(string name, string pN, int scareLevel) : Ghost(name,pN, scareLevel, "Scream loudly") {}
};

class ShadowGhosts : virtual public Ghost
{
public:
    ShadowGhosts() : Ghost() {}
    ShadowGhosts(string name, string pN, int scareLevel) : Ghost(name,pN, scareLevel, "Whisper creepily") {}
};

class ShadowPoltergeist : public ShadowGhosts, public Poltergeist
{
public:
    ShadowPoltergeist  (string name, string pN, int scareLevel) : Ghost(name,pN, scareLevel, "Scream loudly and Move objects") {}
};

class visitor 
{
private:
  string name;
  int braveryLevel; // 1-10
  // 1-4: Cowardly
  // 5-7: Average
  // 8-10: Fearless
  
public:
  visitor(/* args */){
    this->name = "NA";
    this->braveryLevel = 0;
  }
  visitor(string name, int braveryLevel){
    this->name = name;
    this->braveryLevel = braveryLevel;
  }

  string getName(){
    return this->name;
  }
  void setName(string name){
    this->name = name;
  }
  int getBraveryLevel(){
    return this->braveryLevel;
  }

  string braveryLevelToString(){
    if (this->braveryLevel <= 4){
        return "Cowardly";
    }else if (this->braveryLevel <= 7){
        return "Average";
    }else{
        return "Fearless";
    }
  }

  void reaction(int scareLevel){
    if (scareLevel < braveryLevel){
        cout << this->name << " laughs at the ghost." << endl;
    }else if (scareLevel > braveryLevel){
        cout << this->name << " screams and runs away." << endl;
    }else{
        cout << this->name << " gets a shaky voice." << endl;
    }
  }

  // ~visitor();
};

class HauntedHouse
{
private:
    string name;
    visitor *visitors[10]; // array of visitors (max 10 visitors)
    Ghost *ghosts[10]; // array of ghosts (max 10 ghosts)
    
public:
    // HauntedHouse(/* args */);


    HauntedHouse(string name, visitor *visitors[], Ghost *ghosts[]){
        this->name = name;
        for (int i = 0; i < 10; i++){
            this->visitors[i] = visitors[i];
            this->ghosts[i] = ghosts[i];
        }
    }

    string getName(){
        return this->name;
    }
    void setName(string name){
        this->name = name;
    }


    // ~HauntedHouse();
};






int main(){


    // Create ghosts
    Poltergeist ghost1("Ghost1", "Performer1", 5);
    Banshees ghost2("Ghost2", "Performer2", 7);
    ShadowGhosts ghost3("Ghost3", "Performer3", 8);
    ShadowPoltergeist ghost4("Ghost4", "Performer4", 9);

    cout << ghost1 << endl; // Display combined ghost information
    cout << ghost2 << endl; // Display combined ghost information
    cout << ghost3 << endl; // Display combined ghost information
    cout << ghost4 << endl; // Display combined ghost information
    Ghost ghost5 = ghost1 + ghost2; // Combine two ghosts
    cout << ghost5 << endl; // Display combined ghost information


    // Create visitors
    visitor visitor1("Visitor1", 3);
    visitor visitor2("Visitor2", 6);
    visitor visitor3("Visitor3", 9);
    visitor visitor4("Visitor4", 2);


    // Create haunted house
    visitor *visitors[] = {&visitor1, &visitor2, &visitor3, &visitor4};
    Ghost *ghosts[] = {&ghost1, &ghost2, &ghost3, &ghost4};
    HauntedHouse hauntedHouse("Haunted House 1", visitors, ghosts);

    
    cout << "Welcome to the " << hauntedHouse.getName() << endl;
    
    /* cout << "Visitors:" << endl;
    for (int i = 0; i < 4; i++){
        cout << visitors[i]->getName() << " (Bravery Level: " << visitors[i]->getBraveryLevel() << ")" << endl;
    }
    
    cout << "Ghosts:" << endl;
    for (int i = 0; i < 4; i++){
        cout << ghosts[i]->getName() << " (Scare Level: " << ghosts[i]->getScareLevel() << ")" << endl;
    } */

    //  "Simulating visit..."
    cout << "Simulating visit..." << endl;
    for (int i = 0; i < 4; i++){
        cout << visitors[i]->getName() << " is visiting the haunted house." << endl;
        for (int j = 0; j < 4; j++){
            cout << ghosts[j]->getName() << " is haunting " << visitors[i]->getName() << "." << endl;
            visitors[i]->reaction(ghosts[j]->getScareLevel());
        }
    }
    cout << "Visit completed." << endl;





    return 0;
}