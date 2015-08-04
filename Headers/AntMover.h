#ifndef ANTMOVER_H
#define ANTMOVER_H
#include "Ant.h"
#include "GameField.h"

namespace Ants {
namespace AntMover {

  bool Move(Position position, GameField &field, Ant *ant);
  Ants::Ant * PickAnt(GameField &field);
  //int Run(int nblue, int nred, Position position);
  //int CloseAnt(GameField &field, Ant *ant1);
  //int combat(Position position, GameField &field);
};
}
#endif  // ANTMOVER_H
