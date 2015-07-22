#include "Ant.h"
#include <iostream>
#include <time.h>

using namespace Ants;

Ant::Ant() { };

Ant::Ant(std::string color, std::string hierarchy, int attackpower)
{
  this->_color = color;
  this->_hierarchy = hierarchy;
  this->_attackPower = attackpower;
  dead = false;
  joined = false;
  location = nullptr;
  joiner = "";
};

Ant::~Ant(){};

/**VARIOUS GETTERS AND SETTERS I THOUGHT USEFUL**/
Ant::TableNode *GetLocation() { return location; }
std::string Ant::GetColor() { return _color; }
std::string Ant::GetHierarchy() { return _hierarchy; }
std::string Ant::GetJoiner() { return joiner; }
bool Ant::GetJoined() { return joined; }
int Ant::GetAttackPower() { return _attackpower; }

void Ant::Die() {
  this->dead = true;
  std::cout << "A" << this->GetColor() << " " << this->GetHierarchy
            << " has died honorably trying to fight its foe. . . .\n";
}

bool Ant::IsDead() {
  return this->dead;
}

void Ant::Turn();

Tablenode* Ant::SetLocation(Tablenode *new_location) {
  return new_location->IsEmpty() ? new_location : this->GetLocation();
}

void Ant::Attack(Ant *Enemy) {
  // if your ant wins
  if (this->GetEnergy() > Enemy->GetEnergy()) {
    Enemy->Die();
  } else if (this->GetEnergy() < Enemy->GetEnergy()) {
    // if the Enemy ant wins
    Enemy->Die();
  } else {
    // they have equal attack power
    std::cout << "The two ants are equal in power!\n";
    srand(time(NULL));
    int temp = rand() % 8;
    if (temp % 2 == 0) {
      Enemy->Die();
    }
  }
}

