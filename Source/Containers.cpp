#include "..\\Headers\\Containers.h"
#include "..\\Headers\\Ant.h"
#include <string>

using namespace Ants;

std::string Ants::Color_to_String(Ants::Color color) {
  std::string out_color;
  switch (color) {
    case (Color::red):
      out_color = "Red";
      break;
    case (Color::blue):
      out_color = "Blue";
      break;
    default:
      out_color = "";
      break;
  }
  return out_color;
}

std::ostream& Ants::operator<<(std::ostream& os, Color color) {
  os << Color_to_String(color);
  return os;
}
