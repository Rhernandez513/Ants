#include "..\\Headers\\Ant.h"
#include "..\\Headers\Hierarchy.h"
#include "..\\Headers\AntHelper.h"
#include "..\Headers\EventListener.h"
#include "..\\Headers\\Logger.h"
#include "..\\Headers\\RandomHelper.h"
#include <sstream>

using namespace Ants;

// Spawn an Ant!! But you first must construct more pylons!
Ant::Ant(Color color, Hierarchy heirarchy)
  :// _num_kills(0)
/*,*/_color(color)
  , _hierarchy(heirarchy)
  , _isDead(false)
{
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
  : Ant(color, hierarchy)
{
  this->_attackPower = attackpower;
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

// Set Ant's Ranking in the Hierarchy
void Ant::SetHierarchy(Hierarchy hierarchy) { this->_hierarchy = hierarchy; }

// Set Ant's Attack Power
void Ant::SetAttackPower(int attackPower) {
  if (attackPower < 0) {
    attackPower *= -1; // Invert Negative Input
  }
  this->_attackPower = attackPower;
}

// Promote's Ant to next Highest Rank
void Ant::Promote() {
  if (this->_hierarchy <= Hierarchy::Soldier) {
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
void Ant::Die() { this->_isDead = true; }

// Returns true if the Ant is Dead
// False otherwise
bool Ant::IsDead() const { return this->_isDead; }

//// NOT IMPLEMENTED
//void Ant::Turn() {}

// Manually Set's the Ant's Location to the given Position on the given
// Field if that Location is available
// Returns true if Ant was set to the new location, false otherwise
void Ant::SetLocation(Position pos) { this->_position = pos; }

// The Ant slams it's enemy with a mighty blow!!
void Ant::Attack(Ant* Enemy) {
  if (!Enemy) { // Check for nullptr
    LOG("<!!WARN!!> Ant Attempted to Attack non-existent Enemy.");
    return;
  }
  if (this->GetAttackPower() > Enemy->GetAttackPower()) {
    // if your ant wins
    Enemy->Promote();
    this->Die();
    return;
  } else if (this->GetAttackPower() < Enemy->GetAttackPower()) {
    // if the Enemy ant wins
    this->Promote();
    Enemy->Die();
  } else {
    // they have equal attack power
    std::ostringstream stream;
    stream << "The " << this << " and " << Enemy
              << "s are equal in power!\n";
    LOG(stream.str());
    // Pick one to die randomly
    if (Ants::RandomHelper::GetRand() % 2 == 0) {
      this->Promote();
      Enemy->Die();
    } else {
      Enemy->Promote();
      this->Die();
    }
  }
}

          /* DEPRECATED */
//// Returns the direction the Ant is facing
//Direction Ant::GetDirection() const { return this->_direction; }
//
//// Sets the direction the Ant is facing
//void Ant::SetDirection(Direction direction) { this->_direction = direction; }
//
