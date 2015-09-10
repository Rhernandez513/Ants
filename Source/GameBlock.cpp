#include "..\\Headers\\Gameblock.h"
#include "..\\Headers\\RandomHelper.h"

void Ants::GameBlock::UpdateFilled() {
  this->isFilled = false;
  if (this->GetAnt1() && this->GetAnt2()) {
    this->isFilled = true;
  }
}

bool Ants::GameBlock::GetFilled() {
  return this->isFilled;
}
Ants::Ant* Ants::GameBlock::GetAnt1() {
  return this->_ant1;
}
Ants::Ant* Ants::GameBlock::GetAnt2() {
  return this->_ant2;
}

bool Ants::GameBlock::SetAnt(Ants::Ant * ant) {
  int x = Ants::RandomHelper::GetRand() % 2;
  if (x == 0) {
    // Try ant1 slot
    if (this->GetAnt1()) return false;
    // 1st ant * spot is open
    this->GetAnt1() = ant;
    ant->SetLocation(this->GetPosition());
    return true;
  }
  // Try ant2 slot
  if (this->GetAnt2()) return false;
  // 2nd ant * spot is open
  this->_ant2 = ant;
  ant->SetLocation(this->GetPosition());
  return true;
}

Ants::Position Ants::GameBlock::GetPosition() {
  return this->_pos;
}
