
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>

class Ant{
private:
    string color; //can be red and blue
    string hierarchy; // different classes, with different attacks/energy attack
    Tablenode* location; // where this ant is
    int energy;// the assigned energy that certain ants will have. The higher the hierarchy of ants, the bigger
    bool dead;// true/false on whether or not an ant is dead or not
public:
    Ant(){};
    void set_up(string color_, string hierarchy_, int energy_) // initializers
    {
        color = color_; // color of the ant
        hierarchy = hierarchy_;// the hierarchy of ants
        energy = energy_;// energy of ants
        dead = false;// set to false initially since all the ants are alive
        location = NULL;// the location is set to NULL because the user will be prompted first
    };
    string getcolor(){ return color;} // getter for strings
    string gethierarchy() {return hierarchy;}// getter for hierarchy
    int getenergy() {return energy;}// getter for energy
    Tablenode * getlocation() {return location;}// getter for location
    void attack(Ant enemy); // attack function
    void isdead();// is dead function
    void SetLocation (Tablenode * new_location);
};
void Ant:: SetLocation (Tablenode * new_location)// sets the initial new location with pointer.
{
    location = new_location;
}
void Ant:: isdead(){ dead = true; return;}

void Ant:: attack(Ant enemy)
{
    if (energy > enemy.getenergy()) //if your ant wins
    {
        enemy.isdead();
        cout << "A" << enemy.getcolor() << " " << enemy.gethierarchy() << " has died in a battle! \n";
    }
    else if (energy < enemy.getenergy())//if the enemy ant wins
    {
        dead = true;
       cout <<"A" << color << " " << hierarchy << " has died honorably trying to fight its foe. . . .\n";
    }
    else  //they have equal attack power
    {
        cout << "The two ants are equal in power! ";
        int temp;
        srand(time(NULL));
        temp = rand() % 8;
        if (temp % 2 == 0){enemy.isdead(); cout << "And the " << enemy.getcolor()<< " died!\n";}
    }
}
