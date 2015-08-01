#include "Containers.h"

using namespace Ants;

std::ostream & Ants::operator<<(std::ostream & os, Color color) {
  switch (color) {
    case(Color::red):
      os << "Red";
      break;
    case(Color::blue) :
      os << "Blue";
      break;
    default:
      os << "";
      break;
  }
  return os;
}
