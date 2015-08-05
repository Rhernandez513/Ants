#ifndef ANTHELPER_H
#define ANTHELPER_H
#include "Ant.h"
#include <iostream>
#include "GameField.h"

namespace Ants {
namespace AntHelper {
// Updates various Game Status's
void Update(Ant* ant);

// Moves the specified Ant to the specified Position on the Provided Gamefield
// Returns true if operation successful, false otherwise
bool Move(Position position, GameField &field, Ant *ant);

// Randomly Selects a Gameblock on the field and randomly selects one of the Ants
// on said field.  If a valid Ant is found in a valid position, returns a pointer
// to said Ant, returns nullptr otherwise
Ants::Ant * PickAnt(GameField &field);
} // namespace AntHelper

// Prints This ant's Hierarchy & Color
// Example
// Ant red_ant(red, worker, 1);
// std::cout << red_ant << std::endl;
// (prints "Red Worker Ant")
std::ostream& operator<<(std::ostream& os, Ants::Ant* ant);
}
#endif  // ANTHELPER_H
