#include <iostream>
#include "..\Headers\Ant.h"
#include "..\Headers\AntHelper.h"

using namespace Ants;

// Prints This ant's Hierarchy & Color
// Example
// Ant red_ant(red, worker, 1);
// std::cout << red_ant << std::endl;
// (prints "Red Worker Ant")
std::ostream & Ants::operator<<(std::ostream & os, Ants::Ant * ant) {
  os << ant->GetColor() << " " << ant->GetHierarchy() << " Ant";
  return os;
}
