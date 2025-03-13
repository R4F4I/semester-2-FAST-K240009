/*

? |
You're building a next-level game engine, and you need a system to keep track of all the important
stuff—like where things are and how badly they're injured. To do this, you decide to create two
almighty base classes:
* Position - This class ensures that your game objects know where they are in 3D space
?    because teleporting randomly isn't a great gameplay feature (unless you're making a glitch
?    simulator). It will have three trusty coordinates: x, y, and z—so objects don't accidentally
?    fall into the void.
* Health - Because what's a game without damage? This class keeps track of an object's
?    health, making sure your characters don't just shrug off dragon attacks like minor
?    inconveniences.
Now, things get even more interesting. 
* You create the Character class, 
?   which inherits from both Position and Health (because why settle for just one inheritance when you can have both?). 
?   This class will represent the heroes and warriors of your game, complete with their own special abilities and actions. 

Finally, in your main function, you'll create a Character object, set its position and
health, and then show it off—because what's the point of writing all this glorious code if you don't
get to see your hero standing (or limping) in 3D space? So, fire up your keyboard, prepare for some

legendary multiple inheritance, and let's build a game world that doesn't instantly collapse into
chaos! 🎮🚀🔥

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;


class Position
{
private:
    int x,y,z;
public:
    Position(){
        x = 0;
        y = 0;
        z = 0;
    }
    Position(int x, int y, int z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
    void display(){
        cout << "X: " << x << endl;
        cout << "Y: " << y << endl;
        cout << "Z: " << z << endl;
    }
};

class Health
{
private:
    int health;
public:
    Health(){
        health = 100;
    }
    Health(int h){
        this->health = h;
    }
    void display(){
        cout << "Health: " << health << endl;
    }
    
};


class Character : public Position, public Health
{
private:
    string name,ability,actions;
public:
    Character(): Position(), Health()
    {
        name = "Default";
        ability = "Default";
        actions = "Default";
    }
    Character(string name, string ability, string actions, int x, int y, int z, int health): Position(x,y,z), Health(health)
    {
        this->name = name;
        this->ability = ability;
        this->actions = actions;
    }

    void display(){
        Position::display();
        Health::display();
        cout << "Name: " << name << endl;
        cout << "Ability: " << ability << endl;
        cout << "Actions: " << actions << endl;
    }
};




int main(){

    Character hero("John","Coding","Debugging",10,20,30,100);
    hero.display();


    return 0;
}