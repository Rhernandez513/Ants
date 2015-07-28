#include <iostream>
#include <time.h>
#include "..\\Headers\\Ant.h"
#include "..\\Headers\\GameField.h"

using namespace Ants;

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
Position Ant::GetLocation() const { return this->_position;  }

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
  if (this->_hierarchy != Queen) {
    ++this->_hierarchy;  // Will not work if Hierarchy is non-continuous
  }
}

// Demote's Ant to next Lowest Rank
void Ant::Demote() {
  if (this->_hierarchy != Worker) {
    --this->_hierarchy;  // Will not work if Hierarchy is non-continuous 
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

void Ant::Turn() {  }

// Manually Set's the Ant's Location to the given Position on the given
// Field if that Location is availible
// Returns true if Ant was set to the new location, false otherwise
bool Ant::SetLocation(GameField &field, Position pos) {
  if (field.SetBlock(pos.x, pos.y)) return true;
  return false;
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

std::ostream& Ant::operator<<(std::ostream& os)
{
  if (this->_hierarchy && this->_color) {
    os << " " << this->_hierarchy << " " << this->_color << " " << "Ant ";
  } else {
    os.setstate(std::ios_base::failbit);
  }
  return os;
}


Direction Ant::GetDirection() const {
  return this->_direction;
}

void Ant::SetDirection(Direction direction) {
  this->_direction = direction;
}


// Helper Function for Demote()
// DO NOT CALL DIRECTLY
Hierarchy & Ants::operator--(Hierarchy & hierarchy) {
  switch (hierarchy) {
    case(Queen):
      hierarchy = Knight;
      break;
    case(Knight):
      hierarchy = Worker;
      break;
    case(Soldier):
      hierarchy = Worker;
      break;
    case(Worker):
      break;
  }
  return hierarchy;
}

// Helper Function for Promote()
// DO NOT CALL DIRECTLY
Hierarchy & Ants::operator++(Hierarchy & hierarchy) {
  switch (hierarchy) {
    case(Queen):
      break;
    case(Knight):
      hierarchy = Queen;
      break;
    case(Soldier):
      hierarchy = Knight;
      break;
    case(Worker):
      hierarchy = Knight;
      break;
  }
  return hierarchy;
}
