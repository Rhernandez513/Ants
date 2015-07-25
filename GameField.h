#ifndef GAMEFIELD_H
#define GAMEFIELD_H
#include "GameBlock.h"

namespace Ants {
static class GameField {
  private:
    int _length; // x co-ordinates
    int _width;  // y co-ordinates

    // Extensible Storage
    struct GameBlock {
      bool isFilled;
    } GameBlock _gameField[][];

  public:
    Field(int length, int width);
    ~Field();

    // Sets the Specified Position to filled if it is empty
    bool SetBlock(int x, int y);
    bool GetBlock(int x, int y);

    int GetLength();
    int GetWidth();
};
}
#endif // GAMEFIELD_H

