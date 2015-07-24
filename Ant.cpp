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
std::string Ant::GetJoiner() { return joiner; }
int Ant::GetAttackPower() { return _attackpower; }

Color Ant::GetColor() const { return _color; }


void Promote() {
  this->Hierarchy++;
}

Hierarchy Ant::GetHierarchy() const { return _hierarchy; }
void Ant::SetHierarchy(Hierarchy hierarchy) {
  if (this->_hierarchy > hierarchy) {
    this->Promote();
  } else if (this->_hierarchy < hierarchy) {
    this->Demote();
  }
}

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
// enumeration types (both scoped and unscoped) can have overloaded operators
std::ostream& operator<<(std::ostream& os, color c)
{
  switch(c) {
    case red    : os << "red";    break;
    case green  : os << "green";  break;
    default : os.setstate(std::ios_base::failbit);
  }
  return os;
}

Color GetColor() const;
void SetColor(Color color);

Direction GetDirection() const;
bool SetDirection(Direction direction);


int GetAttackPower() const;
void SetAttackPower(int attackPower);

bool SetLocation(int x, int y) {
  
}

Position GetLocation() const {
  if (this->Position) {
    Position pos = this->Position;
    return pos;
  }
}


void Die();
bool IsDead() const;
void Turn();
void Attack(Ant *Enemy);
int GetEnergy() const;
void SetEnergy(int energy);
