#ifndef ANTMOVER_H
#define ANTMOVER_H
#include "Ant.h"
#include "GameField.h"
#include "EventListener.h"

namespace Ants {
class AntMover {
 private:
  int _res;
  int _max_turns;
  int _nblue, _nred;
  int _nummoves;
  bool _turn;  // false for red, true for blue

 public:
  AntMover(int n, int nblue, int nred, int m);
  bool Move(Position position, GameField &field, Ant *ant);
  void pickant(Position position, GameField &field, Ant *ant, Ant *ant2);
  //int Run(int nblue, int nred, Position position);
  //int CloseAnt(GameField &field, Ant *ant1);
  //int combat(Position position, GameField &field);
};
}
#endif  // ANTMOVER_H
