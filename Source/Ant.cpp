#include <iostream>
#include <time.h>
#include "../Headers/Ant.h"
#include "../Headers/GameField.h"

using namespace Ants;

Ant::Ant(Color color, Hierarchy hierarchy, int attackpower)
  : Color(color)
  , Hierarchy(hierarchy)
  , _attackPower(attackpower)
{
  dead = false;
  location = nullptr;
};

Ant::~Ant(){};

int Ant::GetEnergy() const { return _energy; }

void Ant::SetEnergy(int energy) {
  if (energy >= 0) {
    this->_energy = energy;
  } else {
    this->_energy = 0;
  }
}

/**VARIOUS GETTERS AND SETTERS I THOUGHT USEFUL**/
Position Ant::GetLocation() const { if (Position) return Position; }

int Ant::GetAttackPower() const { return _attackpower; }

Color Ant::GetColor() const { if (Color) return Color; }

Hierarchy Ant::GetHierarchy() const { return _hierarchy; }

void Ant::SetHierarchy(Hierarchy hierarchy) {
  if (this->_hierarchy > hierarchy) {
    this->Promote();
  } else if (this->_hierarchy < hierarchy) {
    this->Demote();
  }
}

void Ant::Promote() {
  if (this->Hierarchy != Queen) {
    ++this->Hierarchy;  // Will not work if Hierarchy is non-continuous
  }
}

void Ant::Demote() {
  if (this->Hierarchy != worker) {
    --this->Hierarchy;  // Will not work if Hierarchy is non-continuous 
  }
}
void Ant::Die() {
  this->dead = true;
  std::cout << "A" << this
            << "has died honorably trying to fight its foe. . . .\n";
}

bool Ant::IsDead() const {
  return this->dead;
}

void Ant::Turn();

bool Ant::SetLocation(int x, int y) {
  if (GameField->SetBlock(x, y)) return true;
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
  if (this->Hierarchy && this->Color) {
    os << " " << Hierarchy << " " << Color << " " << "Ant ";
  } else {
    os.setstate(std::ios_base::failbit);
  }
  return os;
}


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

