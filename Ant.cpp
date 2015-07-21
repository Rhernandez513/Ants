#include "Ant.h"
#include <iostream>
#include <time.h>

using namespace Ants;

Ant::Ant(std::string color_, std::string hierarchy_, int attackpower_) {
  color = color_;
  hierarchy = hierarchy_;
  attackpower = attackpower_;
  dead = false;
  joined = false;
  location = NULL;
  joiner = "";
};

Ant::~Ant(){};

/**VARIOUS GETTERS AND SETTERS I THOUGHT USEFUL**/
Ant::TableNode *GetLocation() { return location; }
std::string Ant::GetColor() { return color; }
std::string Ant::GetHierarchy() { return hierarchy; }
std::string Ant::GetJoiner() { return joiner; }
bool Ant::GetJoined() { return joined; }
int Ant::GetAttackPower() { return attackpower; }

void Ant::IsDead() {
  dead = true;
  return;
}

void Ant::Turn();

void Ant::SetLocation(Tablenode *new_location) { location = new_location; }

void Ant::Attack(Ant Enemy) {
  // if your ant wins
  if (energy > Enemy.GetEnergy()) {
    Enemy.isdead();
    std::cout << "A" << Enemy.GetColor() << " " << Enemy.GetHierarchy()
              << " has died in a battle! \n";
  } else if (energy < Enemy.GetEnergy()) {
    // if the Enemy ant wins
    dead = true;
    std::cout << "A" << color << " " << hierarchy
         << " has died honorably trying to fight its foe. . . .\n";
  } else {
    // they have equal attack power
    std::cout << "The two ants are equal in power! ";
    srand(time(NULL));
    int temp = rand() % 8;
    if (temp % 2 == 0) {
      Enemy.isdead();
      std::cout << "And the " << Enemy.GetColor() << " died!\n";
    }
  }
}

