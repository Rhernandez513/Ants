#include "..\\Headers\\Ant.h"
#include "..\\Headers\Hierarchy.h"
#include "..\\Headers\AntHelper.h"
#include "..\Headers\EventListener.h"
#define TURN_ON_LOGGING
#include "..\\Headers\\Log.h"
#include <time.h>

using namespace Ants;

// Spawn an Ant!! But you first must construct more pylons!
Ant::Ant(Color color, Hierarchy heirarchy)
    :// _num_kills(0)
  /*,*/_color(color)
    , _hierarchy(heirarchy)
{
  _isDead = false;
  switch (this->_hierarchy) {
    case (Hierarchy::Queen):
      _attackPower = 0;
      break;
    case (Hierarchy::Knight):
      _attackPower = 3;
      break;
    case (Hierarchy::Soldier):
      _attackPower = 2;
      break;
    case (Hierarchy::Worker):
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

// Destructor
Ant::~Ant() { } ;

          /*DEPRECATED*/
//// Return's Ant's Energy Value
//int Ant::GetEnergy() const { return _energy; }
//
//// Set Ant's Energy Value
//void Ant::SetEnergy(int energy) {
//  if (energy > 0) {
//    this->_energy = energy;
//  } else {
//    this->_energy = 1;
//  }
//}

// Return's Ant's Location
Ants::Position Ant::GetLocation() const { return this->_position; }

// Return's Ant's Attack Power
int Ant::GetAttackPower() const { return this->_attackPower; }

// Return's Ant's  Color Value
Color Ant::GetColor() const { return this->_color; }

// Return's Ant's Ranking in the Hierarchy
Hierarchy Ant::GetHierarchy() const { return this->_hierarchy; }

// Set Ant's Attack Power
void Ant::SetAttackPower(int attackPower) {
  if (attackPower < 0) {
    attackPower *= -1; // Invert Negative Input
  }
  this->_attackPower = attackPower;
}

// Set Ant's Ranking in the Hierarchy
void Ant::SetHierarchy(Hierarchy hierarchy) {
  while (this->_hierarchy != hierarchy) {
    if (this->_hierarchy > hierarchy) {
      this->Promote();
    }
              /*DEPRECATED*/
    /* else if (this->_hierarchy < hierarchy) {
      this->Demote();
    }*/
  }
}

// Promote's Ant to next Highest Rank
void Ant::Promote() {
  if (this->_hierarchy != Hierarchy::Queen) {
    // Will not work if Hierarchy is non-continuous
    ++this->_hierarchy;
  }
}

/* DEPRECATED */
//// Demote's Ant to next Lowest Rank
//void Ant::Demote() {
//  if (this->_hierarchy != Hierarchy::Worker) {
//    // Will not work if Hierarchy is non-continuous
//    --this->_hierarchy;
//  }
//}

// This Kills the Ant...
void Ant::Die() {
  this->_isDead = true;
  AntHelper::Update(this);
}

// Returns true if the Ant is Dead
// False otherwise
bool Ant::IsDead() const { return this->_isDead; }

// NOT IMPLEMENTED
void Ant::Turn() {}

// Manually Set's the Ant's Location to the given Position on the given
// Field if that Location is availible
// Returns true if Ant was set to the new location, false otherwise
void Ant::SetLocation(Position pos) { this->_position = pos; }

// The Ant slams it's enemy with a mighty blow!!
void Ant::Attack(Ant* Enemy) {
  if (this->GetAttackPower() > Enemy->GetAttackPower()) {
    // if your ant wins
    Enemy->Promote();
    this->Die();
  } else if (this->GetAttackPower() < Enemy->GetAttackPower()) {
    // if the Enemy ant wins
    this->Promote();
    Enemy->Die();
  } else {
    // they have equal attack power
    std::cout << "The " << this << " and " << Enemy
              << "s are equal in power!\n";
    // Pick one to die randomly
    srand(static_cast<unsigned>(time(nullptr)));
    if ((rand() % 8) % 2 == 0) {
      this->Promote();
      Enemy->Die();
    } else {
      Enemy->Promote();
      this->Die();
    }
  }
}

// Returns the direction the Ant is facing
Direction Ant::GetDirection() const { return this->_direction; }

// Sets the direction the Ant is facing
void Ant::SetDirection(Direction direction) { this->_direction = direction; }
