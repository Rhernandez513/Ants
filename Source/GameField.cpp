#include "..\\Headers\\GameField.h"
#include "..\Headers\Ant.h"

using namespace Ants;

int _length; // x co-ordinates
int _width;  // y co-ordinates

int GameField::GetLength() { return this->_length; }
int GameField::GetWidth() { return this->_width; }

// Extensible Storage
struct GameBlock {
  bool isFilled;
  Ant * _ant1;
  Ant * _ant2;
} ** _gameField;

// Constructor
GameField::GameField(int length, int width) {
  if (length < 0) length *= -1;  // Invert Negative Inputs
  if (width < 0) width *= -1;   // Invert Negative Inputs

  // Set member vars
  this->_length = length;
  this->_width = width;
  // Instantiate the gameboard
  // Field is a 2D array of GameBlocks
  _gameField = new GameBlock *[_length];
  for (int i = 0; i < _width; ++i) {
    _gameField[i] = new GameBlock[_width];
  }
  // Assign initial empty block values
  for (int i = 0; i < _length; ++i) {
    _gameField[i]->isFilled = false;
    for (int j = 0; j < _width; ++j)
      _gameField[i][j].isFilled = false;
  }
}

// Destructor
GameField::~GameField() {
  // Field is a 2D array of GameBlocks
  for (int i = 0; i < _length; ++i)
    delete [] _gameField[i];
  delete _gameField;
}

// Returns True is block is currently Occupied, False otherwise
bool GameField::GetBlock(int x, int y) {
  return this->_gameField[x][y].isFilled;
}

// Sets the Specified Position to filled if it is empty
bool GameField::SetBlock(int x, int y) {
 if (this->_gameField[x][y].isFilled) {
   return false;
 } else {
  this->_gameField[x][y].isFilled = true;
 }
 return true;
}
