#include "..\\Headers\\Hierarchy.h"
#include <string>

using namespace Ants;

Hierarchy& Ants::operator--(Hierarchy& hierarchy) {
  switch (hierarchy) {
    case (Hierarchy::Queen):
      hierarchy = Hierarchy::Knight;
      break;
    case (Hierarchy::Knight):
      hierarchy = Hierarchy::Worker;
      break;
    case (Hierarchy::Soldier):
      hierarchy = Hierarchy::Worker;
      break;
    case (Hierarchy::Worker):
      break;
  }
  return hierarchy;
}

Hierarchy& Ants::operator++(Hierarchy& hierarchy) {
  switch (hierarchy) {
    case (Hierarchy::Queen):
      break;
    case (Hierarchy::Knight):
      hierarchy = Hierarchy::Queen;
      break;
    case (Hierarchy::Soldier):
      hierarchy = Hierarchy::Knight;
      break;
    case (Hierarchy::Worker):
      hierarchy = Hierarchy::Knight;
      break;
  }
  return hierarchy;
}

std::string Ants::Hierarchy_to_String(Ants::Hierarchy hierarchy) {
  std::string out_hierarchy;
  switch (hierarchy) {
    case (Hierarchy::Queen):
      out_hierarchy = "Queen";
      break;
    case (Hierarchy::Knight):
      out_hierarchy = "Knight";
      break;
    case (Hierarchy::Soldier):
      out_hierarchy = "Soldier";
      break;
    case (Hierarchy::Worker):
      out_hierarchy = "Worker";
      break;
    default:
      out_hierarchy = "";
      break;
  }
  return out_hierarchy;
}

std::ostream& Ants::operator<<(std::ostream& os, Hierarchy hierarchy) {
  os << Hierarchy_to_String(hierarchy);
  return os;
}
