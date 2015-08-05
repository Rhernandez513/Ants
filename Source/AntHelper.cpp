#include "..\\Headers\\Ant.h"
#include "..\\Headers\\AntHelper.h"
#include "..\Headers\EventListener.h"
#include "..\\Headers\\Containers.h"
#include "..\\Headers\\Hierarchy.h"
#include "..\\Headers\\GameField.h"
#include <time.h>
#include <string>
#include <iostream>

using namespace Ants;

// Updates various Game Status's
void AntHelper::Update(Ants::Ant* ant) {
  if (!ant) return;
  if (ant->IsDead()) {
    EventListener::Update(ant);
  }
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
  for (int i = 0; i < 4; ++i) {
    if (field.SetBlock(position, ant)) {
      EventListener::Update(field.GetBlock(ant->GetLocation()));
      return true;
    }
    int random_choice = std::rand() % 4;
    switch (random_choice) {
      case (0) :
        position.x += 1;
        break;
      case(1) :
        position.x -= 2; // Move x to "-1"
        break;
      case(2) :
        position.x += 1; // Reset's x back to "0"
        position.y += 1;
        break;
      case (3) :
        position.y -= 2; // Move y to "-1"
        break;
    }
  }
  return false;
}

// Randomly Selects a Gameblock on the field and randomly selects one of the Ants
// on said field.  If a valid Ant is found in a valid position, returns a pointer
// to said Ant, returns nullptr otherwise
Ants::Ant * Ants::AntHelper::PickAnt(GameField &field) {
  std::srand(static_cast<unsigned>(time(nullptr)));
  Ants::Ant * temp_ant;

  Ants::Position temp_pos;
  temp_pos.x = std::rand() % field.GetLength();
  temp_pos.y = std::rand() % field.GetWidth();
  GameBlock * temp_block = field.GetBlock(temp_pos);

  if (temp_block) { // Check for invalid positions
    int ant_to_choose = std::rand() % 2;
    // Random # is even -> pick _ant1
    if (ant_to_choose == 0) {
      temp_ant = temp_block->_ant1;
      temp_block = nullptr;
      if (temp_ant) return temp_ant;
    } 
    // Random # is even -> pick _ant2
    temp_ant = temp_block->_ant2;
    temp_block = nullptr;
    if (temp_ant) return temp_ant;
  }
  // Position chosen wasn't valid
  // OR Ant Chosen was nullptr
  return nullptr;
}
