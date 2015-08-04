#include "..\\Headers\\Ant.h"
#include "..\\Headers\\AntHelper.h"
#include "..\Headers\EventListener.h"
#include "..\\Headers\\Containers.h"
#include "..\\Headers\\Hierarchy.h"
#include <string>
#include <iostream>

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
std::ostream& Ants::operator<<(std::ostream& os, Ants::Ant* ant) {
  std::string color_string = Color_to_String(ant->GetColor());
  std::string hierarchy_string = Hierarchy_to_String(ant->GetHierarchy());
  os << color_string << " " 
     << hierarchy_string << " Ant";
  return os;
}
