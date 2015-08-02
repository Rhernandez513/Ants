#include <iostream>
#include "..\\Headers\\Ant.h"
#include "..\\Headers\\AntHelper.h"

using namespace Ants;

// Updates various Game Status's
void AntHelper::Update(Ants::Ant* ant) {
  if (ant->IsDead()) {
    EventListener::Update(ant);
  }
}

// Prints This ant's Hierarchy & Color
// Example
// Ant red_ant(red, worker, 1);
// std::cout << red_ant << std::endl;
// (prints "Red Worker Ant")
std::ostream& Ants::operator<<(std::ostream& os, Ants::Ant* const ant) {
  os << ant->GetColor() << " " << ant->GetHierarchy() << " Ant";
  return os;
}
