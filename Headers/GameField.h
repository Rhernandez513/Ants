#ifndef GAMEFIELD_H
#define GAMEFIELD_H
#include "Ant.h"

namespace Ants {
class GameField {
 private:
  int _length;  // x co-ordinates
  int _width;   // y co-ordinates

  // Extensible Storage
  struct GameBlock {
    bool isFilled;
    Ant* _ant1;
    Ant* _ant2;
  } * *_gameField;

 public:
  GameField(int length, int width);
  ~GameField();

  // Sets the Specified Position to filled if it is empty
  bool SetBlock(Position pos, Ant* ant);
  GameBlock* GetBlock(Position pos);

  int GetLength();
  int GetWidth();

  void PopulateField(int numberOfAntsPerTeam);
};
}
#endif  // GAMEFIELD_H
