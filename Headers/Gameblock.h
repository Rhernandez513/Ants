#ifndef GAMEBLOCK_H
#define GAMEBLOCK_H
#include "Ant.h"
#include "Containers.h"
#include <stack>

namespace Ants {

// Extensible Storage
struct GameBlock {
  bool isFilled;
  Ant* _ant1;
  Ant* _ant2;
  Position _pos;
};
static std::stack<GameBlock> blockStack;
}
#endif  // GAMEBLOCK_H
