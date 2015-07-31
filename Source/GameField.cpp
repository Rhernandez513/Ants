#include "..\\Headers\\GameField.h"
#include "..\Headers\Ant.h"
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
GameField::GameField(int length, int width)
  : _length(length), _width(width)
{
  if (length < 0) length *= -1;  // Invert Negative Inputs
  if (width < 0) width *= -1;    // Invert Negative Inputs

  // Set member vars
  this->_length = length; // x co-ordinates
  this->_width = width;   // y co-ordinates

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
GameField::GameBlock *GameField::GetBlock(Position pos) {
  GameBlock * block;
  if (CheckIfPositionValid(pos)) {
    block = &this->_gameField[pos.x][pos.y];
    if (block) return block;
  }
  return nullptr;
}

// Sets the Specified Position to filled if it is empty
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

// Currently only populates RED team
void GameField::PopulateField(int numberOfAntsPerTeam) {
  // randomly fill field right side
  Position antPos;
  int i, x, y;
  i = x = y = 0;
  srand(static_cast<unsigned>(time(nullptr)));
  while (i < numberOfAntsPerTeam) {
    x = (rand() % this->_length) / 2; // x co-ordinates
    y = (rand() % this->_width) / 2;  // y co-ordinates
    antPos.x = (x + this->_width) / 2;
    antPos.y = (y + this->_length) / 2;

    if (this->GetBlock(antPos)->isFilled) {
      continue;
    }

    if (i == 0) {
      this->SetBlock(antPos, new Ant(Color::red, Hierarchy::Queen));
      ++i;
      continue;
    } else {
      this->SetBlock(antPos, new Ant(Color::red, Hierarchy::Worker));
      ++i;
    }
  }

   while(i<nred)
  {
  
    x=rand()%width/2;
    y=rand()%height;
    if(i==0)
    {
      Field[x][y].full=true;
      Field[x][y].a=new Ant(Color::Red,Heirarchy::Queen);
      i++;
      continue;
    }
  
    if(Field[x][y].full)
      continue;
  
  
    Field[x][y].full=true;
    if(i%3==0)
     Field[x][y].a=new Ant(Color::Red,Heirarchy::Worker);
    if(i%3==1)
     Field[x][y].a=new Ant(Color::Red,Heirarchy::Soldier);
     if(i%3==2)
     Field[x][y].a=new Ant(Color::Red,Heirarchy::Knight);
     i++;
  }
}
