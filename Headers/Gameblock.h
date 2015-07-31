#ifndef GAMEBLOCK_H
#define GAMEBLOCK_H
#include "Ant.h"

namespace Ants {

// Extensible Storage
struct GameBlock {
  bool isFilled;
  Ants::Ant* _ant1;
  Ants::Ant* _ant2;
  Position _pos;
};
}
#endif // GAMEBLOCK_H
