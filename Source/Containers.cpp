#include "..\\Headers\\Containers.h"
#include "..\\Headers\\Ant.h"
#define TURN_ON_LOGGING
#include "..\\Headers\\Logger.h"
#include <iostream>

using namespace Ants;

std::ostream& Ants::operator<<(std::ostream& os, Color color) {
  switch (color) {
    case (Color::red):
      os << "Red";
      break;
    case (Color::blue):
      os << "Blue";
      break;
    default:
      os << "";
      break;
  }
  return os;
}

// Extensible Storage
struct GameBlock {
  bool isFilled = false;
  Ant* _ant1 = nullptr;
  Ant* _ant2 = nullptr;
  Position _pos;
};
