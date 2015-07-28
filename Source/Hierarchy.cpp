#include "..\\Headers\\Hierarchy.h"

using namespace Ants;

Hierarchy& Ants::operator--(Hierarchy& hierarchy) {
  switch (hierarchy) {
    case(Hierarchy::Queen):
      hierarchy = Hierarchy::Knight;
      break;
    case(Hierarchy::Knight):
      hierarchy = Hierarchy::Worker;
      break;
    case(Hierarchy::Soldier):
      hierarchy = Hierarchy::Worker;
      break;
    case(Hierarchy::Worker):
      break;
  }
  return hierarchy;
}

Hierarchy& Ants::operator++(Hierarchy& hierarchy) {
  switch (hierarchy) {
    case(Hierarchy::Queen):
      break;
    case(Hierarchy::Knight):
      hierarchy = Hierarchy::Queen;
      break;
    case(Hierarchy::Soldier):
      hierarchy = Hierarchy::Knight;
      break;
    case(Hierarchy::Worker):
      hierarchy = Hierarchy::Knight;
      break;
  }
  return hierarchy;
}

//Hierarchy& Ants::operator<<(Hierarchy & hierarchy) {
//
//  return hierarchy;
//}
