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

  /////////*Use some of majed's logic to implement initial Ant setup*/////////
//
////randomly fill field right side
//int i=0,x,y;
//
//while(i<nblue)
//{
//  
//  x=rand()%width/2;
//  y=rand()%height;
//  if(i==0)
//  {
//    Field[x+width/2][y].full=true;
//    Field[x+width/2][y].a=new Ant(Color::Blue,Heirarchy::Queen);
//    i++;
//    continue;
//  }
//  
//  if(Field[x+width/2][y].full)
//    continue;
//    
//    
//  Field[x+width/2][y].full=true;
//  if(i%3==0)
//   Field[x+width/2][y].a=new Ant(Color::Blue,Heirarchy::Worker);
//  if(i%3==1)
//   Field[x+width/2][y].a=new Ant(Color::Blue,Heirarchy::Soldier);
//   if(i%3==2)
//   Field[x+width/2][y].a=new Ant(Color::Blue,Heirarchy::Knight);
//   i++;
//   
//}
//
//while(i<nred)
//{
//  
//  x=rand()%width/2;
//  y=rand()%height;
//  if(i==0)
//  {
//    Field[x][y].full=true;
//    Field[x][y].a=new Ant(Color::Red,Heirarchy::Queen);
//    i++;
//    continue;
//  }
//  
//  if(Field[x][y].full)
//    continue;
//    
//    
//  Field[x][y].full=true;
//  if(i%3==0)
//   Field[x][y].a=new Ant(Color::Red,Heirarchy::Worker);
//  if(i%3==1)
//   Field[x][y].a=new Ant(Color::Red,Heirarchy::Soldier);
//   if(i%3==2)
//   Field[x][y].a=new Ant(Color::Red,Heirarchy::Knight);
//   i++;  
//}
//
