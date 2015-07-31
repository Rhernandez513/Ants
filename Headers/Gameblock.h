#ifndef GAMEBLOCK_H
#define GAMEBLOCK_H
#include "Ant.h"

namespace Ants {
struct GameBlock {
  bool isFilled;
  Ants::Ant* _ant1;
  Ants::Ant* _ant2;
};
}
#endif // GAMEBLOCK_H
