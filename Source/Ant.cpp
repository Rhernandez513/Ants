#include "..\\Headers\\Ant.h"
#include "..\\Headers\\GameField.h"
#include "..\\Headers\Hierarchy.h"
#include <time.h>

using namespace Ants;

// Spawn an Ant!! But you first must construct more pylons!
Ant::Ant(Color color, Hierarchy heirarchy)
  : _color(color)
  , _hierarchy(heirarchy)
{
  _isDead = false;
  switch (this->_hierarchy) {
    case(Hierarchy::Queen) :
        _attackPower = 0;
      break;
    case(Hierarchy::Knight) :
        _attackPower = 3;
      break;
    case(Hierarchy::Soldier) :
        _attackPower = 2;
      break;
    case(Hierarchy::Worker) :
        _attackPower = 1;
      break;
  }
}

// Spawn an Ant!! But you first must construct more pylons!
Ant::Ant(Color color, Hierarchy hierarchy, int attackpower)
  : _color(color)
  , _hierarchy(hierarchy)
  , _attackPower(attackpower)
{
  _isDead = false;
};

Ant::~Ant(){};

// Return's Ant's Energy Value
int Ant::GetEnergy() const { return _energy; }

// Set Ant's Energy Value
void Ant::SetEnergy(int energy) {
  if (energy >= 0) {
    this->_energy = energy;
  } else {
    this->_energy = 0;
  }
}

// Return's Ant's Location
Ants::Position Ant::GetLocation() const { return this->_position;  }

// Return's Ant's Attack Power
int Ant::GetAttackPower() const { return this->_attackPower; }

// Return's Ant's  Color Value
Color Ant::GetColor() const { return this->_color; }

// Return's Ant's Ranking in the Hierarchy
Hierarchy Ant::GetHierarchy() const { return this->_hierarchy; }

// Set Ant's Attack Power
void Ant::SetAttackPower(int attackPower) {
  if (attackPower > 0) {
    this->_attackPower = attackPower;
  } else {
    this->_attackPower = 0;
  }
}

// Set Ant's Ranking in the Hierarchy
void Ant::SetHierarchy(Hierarchy hierarchy) {
  if (this->_hierarchy > hierarchy) {
    this->Promote();
  } else if (this->_hierarchy < hierarchy) {
    this->Demote();
  }
}

// Promote's Ant to next Highest Rank
void Ant::Promote() {
  if (this->_hierarchy != Hierarchy::Queen) {
    // Will not work if Hierarchy is non-continuous
    ++this->_hierarchy;
  }
}

// Demote's Ant to next Lowest Rank
void Ant::Demote() {
  if (this->_hierarchy != Hierarchy::Worker) {
    // Will not work if Hierarchy is non-continuous 
    --this->_hierarchy;
  }
}

// This Kills the Ant...
void Ant::Die() {
  this->_isDead = true;
  std::cout << "A" << this
            << "has died honorably trying to fight its foe. . . .\n";
}

// Returns true if the Ant is Dead
// False otherwise
bool Ant::IsDead() const {
  return this->_isDead;
}

// NOT IMPLEMENTED
void Ant::Turn() {  }

// Manually Set's the Ant's Location to the given Position on the given
// Field if that Location is availible
// Returns true if Ant was set to the new location, false otherwise
void Ant::SetLocation(Position pos) {
  this->_position = pos;
}

// The Ant slams it's enemy with a mighty blow!!
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
    srand(static_cast<unsigned>(time(nullptr)));
    int temp = rand() % 8;
    if (temp % 2 == 0) {
      Enemy->Die();
    } else {
      this->Die();
    }
  }
}

// Prints This ant's Hierarchy & Color
// Example
// Ant red_ant(red, worker, 1);
// std::cout << red_ant << std::endl;
// (prints "Red Worker Ant")
std::ostream& Ant::operator<<(std::ostream& os)
{
  os << " " <<  this->_color << " " << this->_hierarchy << " " << "Ant ";
  return os;
}

// Returns the direction the Ant is facing
Direction Ant::GetDirection() const {
  return this->_direction;
}

// Sets the direction the Ant is facing
void Ant::SetDirection(Direction direction) {
  this->_direction = direction;
}
