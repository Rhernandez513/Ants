#include "..\\Headers\\Ant.h"
#include "..\\Headers\\AntHelper.h"
#include "..\Headers\EventListener.h"
#include "..\\Headers\\Containers.h"
#include "..\\Headers\\Hierarchy.h"
#include "..\\Headers\\GameField.h"
#include "..\\Headers\\RandomHelper.h"
#include <string>
#include <iostream>

using namespace Ants;

// Updates various Game Status's
void AntHelper::Update(Ants::Ant* ant) {
  if (!ant) return;
  EventListener::Update(ant);
}

// Prints This ant's Hierarchy & Color
// Example
// Ant red_ant(red, worker, 1);
// std::cout << red_ant << std::endl;
// (prints "Red Worker Ant")
std::ostream& Ants::operator<<(std::ostream& os, Ants::Ant* ant) {
  std::string color_string = Color_to_String(ant->GetColor());
  std::string hierarchy_string = Hierarchy_to_String(ant->GetHierarchy());
  os << color_string << " " 
     << hierarchy_string << " Ant";
  return os;
}


// Moves the specified Ant to the specified Position on the Provided Gamefield
// Returns true if operation successful, false otherwise
bool Ants::AntHelper::Move(Position position, GameField &field, Ant *ant) {
  if (!ant) return false; // Check for bad pointer input
  for (int i = 0; i < 256; ++i) {
    if (position.x < 0) position.x *= -1;  // invert neg
    if (position.y < 0) position.y *= -1;  // invert neg
    position.x = (position.x + field.GetLength()) % field.GetLength();
    position.y = (position.y + field.GetWidth()) % field.GetWidth();
    if (field.SetBlock(position, ant)) {
      EventListener::Update(field.GetBlock(ant->GetLocation()));
      return true;
    }
    int random_choice = RandomHelper::GetRand() % 12;
    int val = (RandomHelper::GetRand() % 4) + 1; // Avoid 0
    switch (random_choice) {
      case (0) :
        position.x += val;
        break;
      case (1) :
        position.x -= val;
        break;
      case (2) :
        position.x += val;
        position.y += val;
        break;
      case (3) :
        position.x -= val;
        position.y -= val;
        break;
      case (4) :
        position.x -= val;
        position.y += val;
        break;
      case (5) :
        position.x += val;
        position.y -= val;
        break;
      case (6) :
        position.y += val;
        break;
      case (7) :
        position.y -= val;
        break;
      case (8) :
        position.x *= val;
        position.y /= val;
        break;
      case (9) :
        position.x /= val;
        position.y *= val;
        break;
      case (10) :
        position.x *= val;
        position.y *= val;
        break;
      case (11) :
        position.x /= val;
        position.y /= val;
        break;
    }
  }
  return false;
}

// Randomly Selects a Gameblock on the field and randomly selects one of the Ants
// on said field.  If a valid Ant is found in a valid position, returns a pointer
// to said Ant, returns nullptr otherwise
Ants::Ant * Ants::AntHelper::PickAnt(GameField &field) {
  GameBlock * temp_block = field.GetRandomBlock();
  if (temp_block) { // Check for invalid blocks
    if ((RandomHelper::GetRand() % 2) == 0) {
      // Random # is even -> pick _ant1
      if (temp_block->_ant1) return temp_block->_ant1;
    }
    // Random # is even -> pick _ant2
    // AND/OR (since the block was already proven to be good
    // if _ant1 is null, attempt to chose _ant2)
    if (temp_block->_ant2) return temp_block->_ant2;
  }
  // Position chosen wasn't valid
  // OR both Ants were nullptr
  return nullptr;
}
