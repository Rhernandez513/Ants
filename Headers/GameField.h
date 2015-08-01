#ifndef GAMEFIELD_H
#define GAMEFIELD_H
#include "Ant.h"
#include "Gameblock.h"

namespace Ants {
class GameField {
 private:
  int _length;  // x co-ordinates
  int _width;   // y co-ordinates

  // Returns True if the Position is within the Gamefield false otherwise
  bool CheckIfPositionValid(Position pos);

  // Extensible Storage
  GameBlock ** _gameField;

  // Heavy lifting for PopulateField(int numberOfAntsPerTeam)
  void PopulateFieldHelper(int num, Color inColor);
 public:
  // Constructor
  GameField(int size);
  // Destructor
  ~GameField();

  // Places the Ant at the Position provided
  // Returns true if operation succesfull, false otherwise
  bool SetBlock(Position pos, Ant* ant);
  // Returns a reference to the GameBlock at the Specified Position
  GameBlock* GetBlock(Position pos);

  // Returns Length (x-axis) of the Field
  int GetLength();
  // Returns Width (y-axis) of the Field
  int GetWidth();

  void PopulateField(int numberOfAntsPerTeam);
};
}
#endif  // GAMEFIELD_H
