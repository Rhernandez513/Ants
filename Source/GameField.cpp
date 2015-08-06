#include "..\\Headers\\GameField.h"
#include "..\Headers\Ant.h"
#include "..\\Headers\\Gameblock.h"
#include "..\\Headers\\EventListener.h"
#include "..\\Headers\\Logger.h"
#include "..\\Headers\\RandomHelper.h"
#include <string>
#include <memory>
#include <sstream>

using namespace Ants;

// Returns Length (x-axis) of the Field
int GameField::GetLength() { return this->_length; }
// Returns Width (y-axis) of the Field
int GameField::GetWidth() { return this->_width; }

// Returns True if the Position is within the Game field false otherwise
bool GameField::CheckIfPositionValid(Position pos) {
  if (pos.x >= this->GetLength() || pos.x < 0) return false;  // x co-ordinates
  if (pos.y >= this->GetWidth()  || pos.y < 0) return false;  // y co-ordinates
  return true;
}

// Constructor
GameField::GameField(int size) : _length(size), _width(size) {
  if (this->_length < 0) this->_length *= -1;  // Invert Negative Inputs
  if (this->_width < 0) this->_width *= -1;    // Invert Negative Inputs

  // Instantiate the game board
  // Field is a 2D array of GameBlocks
  _gameField = new GameBlock *[_length];
  for (int i = 0; i < _length; ++i) {
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

// If the position is valid, returns a reference to the GameBlock
// at the Specified Position, else returns nullptr
GameBlock *GameField::GetBlock(Position pos) {
  if (this->CheckIfPositionValid(pos)) {
    return &this->_gameField[pos.x][pos.y];
  }
  return nullptr;
}

// Places the Ant at the Position provided
// Returns true if operation successful, false otherwise
bool GameField::SetBlock(Position pos, Ant *ant) {
  int x = Ants::RandomHelper::GetRand() % 2;
  if (!ant) return false; // Check for bad ant input
  if (!CheckIfPositionValid(pos)) return false; // Off the Grid
  if (this->_gameField[pos.x][pos.y].isFilled) return false; // Both spots taken
  if (x == 0) { // Try ant1 slot
    if (this->_gameField[pos.x][pos.y]._ant1) {
      return false;
    } else {  // 1st ant * spot is open
      this->_gameField[pos.x][pos.y]._ant1 = ant;
      ant->SetLocation(pos);
      return true;
    }
  } else if (x == 1) { // Try ant2 slot
    if (this->_gameField[pos.x][pos.y]._ant2) {
      return false;
    } else {  // 2nd ant * spot is open
      this->_gameField[pos.x][pos.y]._ant2 = ant;
      ant->SetLocation(pos);
      return true;
    }
  }
  // Both spots are open and block wasn't properly set to full
  if (this->_gameField[pos.x][pos.y]._ant1 &&
      this->_gameField[pos.x][pos.y]._ant1
     ) this->_gameField[pos.x][pos.y].isFilled = true;
  return false;
}

// Populates The Gamefield with 2x numberOfAntsPerTream
// OR ((length * width) * 2/3), whichever is greater
void GameField::PopulateField(int numberOfAntsPerTeam) {
  EventListener::SetStartCond(numberOfAntsPerTeam);
  if (this->_fieldPopAttempts >= this->_maxFieldPopAttempts) {
    std::string error_msg = "Field Population failed after 5 attempts";
    EventListener::SetGameFailure(error_msg); // Exits program w/ error_msg
  }
  std::string msg1, msg2;
  msg1 = PopulateFieldHelper(numberOfAntsPerTeam, Color::red);
  msg2 = PopulateFieldHelper(numberOfAntsPerTeam, Color::blue);
  if(!msg1.empty()) { // We expect an empty string to be returned
    std::ostringstream stream;
    stream << "<!!WARN!!>" << msg1.c_str() << " #" << _fieldPopAttempts;
    LOG(stream.str());
    this->PopulateField(numberOfAntsPerTeam);
  }
  if(!msg2.empty()) { // We expect an empty string to be returned
    std::ostringstream stream;
    stream << "<!!WARN!!>" << msg2.c_str() << " #" << _fieldPopAttempts;
    LOG(stream.str());
    this->PopulateField(numberOfAntsPerTeam);
  }
}

// Heavy lifting for PopulateField(int numberOfAntsPerTeam)
std::string GameField::PopulateFieldHelper(int num, Color inColor) {
  std::string color_string, msg;
  int x, y, attempts;
  x = y = attempts = 0;
  int upperLimit = std::numeric_limits<int>::max() / 20;  // approx 100million
  Position antPos;
  GameBlock * temp = nullptr;

  if (inColor == Color::red) {
    color_string = "red";
  } else {
    color_string = "blue";
  }

  // Upper limit on Ant amount to prevent over flow
  if (num > ((this->GetLength() * this->GetWidth()) / 4)) {
    num = (this->GetLength() * this->GetWidth()) / 4;
  }
  // randomly fill field right side
  for (int i = 0; i < num; ++i) {
    if (attempts == upperLimit) {
      msg = "Buffer Overflow, while trying to populate "
                      + color_string + " field";
      return msg;
    }

    antPos = this->GetRandomValidPosition();
    temp = this->GetBlock(antPos);
    if (!temp) continue;
    if (temp->isFilled) continue; 

    if (i == 0) {
      // Attempts to set the Queen until Successful
      if (!this->SetBlock(antPos, new Ant(inColor, Hierarchy::Queen))) {
        --i;
        ++attempts;
      }
    } else {
      // Attempts to set an Ant until Successful
      if (!this->SetBlock(antPos, new Ant(inColor, Hierarchy::Worker))) {
        --i;
        ++attempts;
      }
    }
  }
  return msg; // If operation is successful should be empty
}

// Returns a random block within the Field 
Ants::GameBlock * Ants::GameField::GetRandomBlock() {
  Ants::Position temp_pos = this->GetRandomValidPosition();
  GameBlock * temp_block = this->GetBlock(temp_pos);
  return temp_block ? temp_block : this->GetRandomBlock();
}

// Returns a valid random Ants::Position within the Field 
Ants::Position Ants::GameField::GetRandomValidPosition() {
  Ants::Position temp_pos;
  temp_pos.x = RandomHelper::GetRand() % this->GetLength();
  temp_pos.y = RandomHelper::GetRand() % this->GetWidth();
  return
    this->CheckIfPositionValid(temp_pos)
    ? temp_pos : this->GetRandomValidPosition();
}
