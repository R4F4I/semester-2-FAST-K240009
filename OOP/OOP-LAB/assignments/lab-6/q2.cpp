/*

You're about to craft the greatest game world ever (or at least one that compiles). 
It all starts with the legendary: 
- Character class—the grand ancestor of all fighters, with two crucial stats: 
    - health (so they don't collapse after a light breeze) and 
    - damage (because tickling enemies doesn't win battles).
- Of course, this class needs a constructor to give life to these brave souls and a display function so they can proudly show off their stats like RPG influencers. 

But what's a game without good guys and bad guys? 

- Enter the Enemy and Player classes, both inheriting from Character. 
    - The Enemy exists solely to make players rage-quit, 
    - while the Player is the hero who either saves the world or just hoards loot for hours. 
- Both get their own constructors and display functions—because villains and heroes alike deserve their moment in the spotlight. 

Now, hold onto your enchanted capes because here comes the real magic—
- The Wizard! 
    - This arcane warrior inherits from Player but also wields magic power and spells, because swinging a sword is way too basic. 
    - Naturally, it gets a constructor to infuse it with all the mystical goodness, 
    - plus a display function so it can flex its sorcery like a true magical influencer. 

Finally, in your main function, you'll 
- summon a Wizard object and 
- display its stats, 

because if you're writing all this code and not showing off the results, did the magic even happen? 
So, grab your coding wand, chant `std::cout,` and let's conjure up some legendary C++ wizardry! ✨🔥🧙♂️

* Name:         Rafay Siddiqui
* roll number:  24k-0009
* section:      BAI-2A


*/

#include <iostream>

using namespace std;

class Character
{
private:
    int health, damage;

public:

    Character(){
        this->health = 100;
        this->damage = 10;
    }
    Character(int health, int damage){
        this->health = health;
        this->damage = damage;
    }

    void display(){
        cout<<"health: " <<this->health << endl;
        cout<<"damage: " <<this->damage << endl;
    }
};

class Player : public Character
{
public:
    Player(): Character(){}
    Player(int health, int damage): Character(health,damage){}

    void display(){
        Character::display();
    }
};
class Enemy : public Character
{
public:
    Enemy(int health, int damage): Character(health,damage){}
};

class Wizard: public Player
{
    string spells, power;
public:
    Wizard(): Player()
    {
        this->spells = "Fireball";
        this->power = "Fire";
    }
    Wizard(string spells, string power,int health, int damage): Player(health,damage)
    {
        this->spells = spells;
        this->power = power;
    }

    void display(){
        Player::display();
        cout<<"spells: " <<this->spells << endl;
        cout<<"power: " <<this->power << endl;
    }
};




int main(){

    Wizard wiz("Iceball", "Ice", 90, 30);
    Wizard wiz1;
    wiz.display();
    wiz1.display();


    return 0;
}