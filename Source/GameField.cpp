#include "..\\Headers\\GameField.h"
#include "..\Headers\Ant.h"
#include "..\\Headers\\Gameblock.h"
#include <time.h>

using namespace Ants;

// Returns Length (x-axis) of the Field
int GameField::GetLength() { return this->_length; }
// Returns Width (y-axis) of the Field
int GameField::GetWidth() { return this->_width; }

// Returns True if the Position is within the Gamefield false otherwise
bool GameField::CheckIfPositionValid(Position pos) {
  if (pos.x > _length || pos.x < 0) return false; // x co-ordinates
  if (pos.y > _width || pos.y < 0) return false;  // y co-ordinates
  return true;
}

// Constructor
GameField::GameField(int size)
  : _length(size), _width(size)
{
  if (this->_length < 0) this->_length *= -1;  // Invert Negative Inputs
  if (this->_width < 0) this->_width *= -1;    // Invert Negative Inputs

  // Instantiate the gameboard
  // Field is a 2D array of GameBlocks
  _gameField = new GameBlock *[_length];
  for (int i = 0; i < _width; ++i) {
    _gameField[i] = new GameBlock[_width];
  }
  // Assign initial empty block values
  for (int i = 0; i < _length; ++i) {
    _gameField[i]->isFilled = false;
    _gameField[i]->_ant1 = nullptr;
    _gameField[i]->_ant2 = nullptr;
    _gameField[i]->_pos.x = i;
    for (int j = 0; j < _width; ++j) {
      _gameField[i][j].isFilled = false;
      _gameField[i][j]._ant1 = nullptr;
      _gameField[i][j]._ant2 = nullptr;
      _gameField[i][j]._pos.y = j;
    }
  }
}

// Destructor
GameField::~GameField() {
  // Field is a 2D array of GameBlocks
  for (int i = 0; i < _length; ++i) delete[] _gameField[i];
  delete _gameField;
}

// Returns a reference to the GameBlock at the Specified Position
GameBlock *GameField::GetBlock(Position pos) {
  GameBlock * block;
  if (CheckIfPositionValid(pos)) {
    block = &this->_gameField[pos.x][pos.y];
    if (block) return block;
  }
  return nullptr;
}

// Places the Ant at the Position provided
// Returns true if operation succesfull, false otherwise
bool GameField::SetBlock(Position pos, Ant *ant) {
  if (this->_gameField[pos.x][pos.y].isFilled) {  // Both spots are open
    return false;
  }
  if (!this->_gameField[pos.x][pos.y]._ant1) {  // 1st ant* spot is open
    this->_gameField[pos.x][pos.y]._ant1 = ant;
    ant->SetLocation(pos);
    return true;
  }
  if (!this->_gameField[pos.x][pos.y]._ant2) {  // 2nd ant * spot is open
    this->_gameField[pos.x][pos.y]._ant2 = ant;
    ant->SetLocation(pos);
    return true;
  }
  // Both spots are open and block wasn't properly set to full
  this->_gameField[pos.x][pos.y].isFilled = true;
  return false;
}

// Populates The Gamefield with 2x numberOfAntsPerTream
// OR ((length * width) * 2/3), whichever is greater
void GameField::PopulateField(int numberOfAntsPerTeam) {
  PopulateFieldHelper(numberOfAntsPerTeam, Color::red);
  PopulateFieldHelper(numberOfAntsPerTeam, Color::blue);
}

// Heavy lifting for PopulateField(int numberOfAntsPerTeam)
void GameField::PopulateFieldHelper(int num, Color inColor) {
  int x, y;
  int attemps = 0;
  int upperLimit = std::numeric_limits<int>::max();
  Position antPos;

  // Upper limit on Ant amount to prevent over flow
  if (num > ((this->_length * this->_width) / 3)) {
    num = (this->_length * this->_width) / 3;
  }
  // randomly fill field right side
  srand(static_cast<unsigned>(time(nullptr)));
  for (int i = 0; i < num; ++i) {
    if (attemps == upperLimit) {
      throw new std::exception("Buffer Overflow");
    }
    x = (rand() % this->_length) / 2; // x co-ordinates
    y = (rand() % this->_width) / 2;  // y co-ordinates
    antPos.x = (x + this->_width) / 2;
    antPos.y = (y + this->_length) / 2;

    if (this->GetBlock(antPos)->isFilled) { continue; }

    if (i == 0) {
      // Attempts to set the Queen until Successful
      if (!this->SetBlock(antPos, new Ant(inColor, Hierarchy::Queen))) {
        --i;
        ++attemps;
      }
    } else {
      // Attempts to set an Ant until Successful
      if (!this->SetBlock(antPos, new Ant(inColor, Hierarchy::Worker))) {
        --i;
        ++attemps;
      }
    }
  }
}
