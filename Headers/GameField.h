#ifndef GAMEFIELD_H
#define GAMEFIELD_H
#include "Ant.h"
#include "Gameblock.h"
#include "Containers.h"
#include <memory>

namespace Ants {
class GameField {
 private:
  int _length;  // x co-ordinates
  int _width;   // y co-ordinates
  int _fieldPopAttempts = 0;
  int _maxFieldPopAttempts = 5;

  // Extensible Storage
  GameBlock** _gameField;

  // Heavy lifting for PopulateField(int numberOfAntsPerTeam)
  std::shared_ptr<std::string> PopulateFieldHelper(int num, Color inColor);

 public:
  // Constructor
  GameField(int size);
  // Destructor
  ~GameField();

  // Returns True if the Position is within the Gamefield false otherwise
  bool CheckIfPositionValid(Position pos);

  // Places the Ant at the Position provided
  // Returns true if operation successful, false otherwise
  bool SetBlock(Position pos, Ant* ant);
  // If the position is valid, returns a reference to the GameBlock
  // at the Specified Position, else returns nullptr
  GameBlock* GetBlock(Position pos);

  // Returns Length (x-axis) of the Field
  int GetLength();
  // Returns Width (y-axis) of the Field
  int GetWidth();

  // Populates The Gamefield with 2x numberOfAntsPerTream
  // OR ((length * width) * 2/3), whichever is greater
  void PopulateField(int numberOfAntsPerTeam);

  // Returns a random valid Ants::GameBlock * within the Field 
  Ants::GameBlock * GetRandomBlock();
  // Returns a valid random Ants::Position within the Field 
  Ants::Position GetRandomValidPosition();
};
}
#endif  // GAMEFIELD_H
