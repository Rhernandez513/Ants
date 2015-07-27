#ifndef GAMEFIELD_H
#define GAMEFIELD_H

namespace Ants {
class GameField {
  private:
    int _length; // x co-ordinates
    int _width;  // y co-ordinates

    // Extensible Storage
    struct GameBlock {
      bool isFilled;
    } ** _gameField;

  public:
    GameField(int length, int width);
    ~GameField();

    // Sets the Specified Position to filled if it is empty
    bool SetBlock(int x, int y);
    bool GetBlock(int x, int y);

    int GetLength();
    int GetWidth();
};
}
#endif // GAMEFIELD_H
