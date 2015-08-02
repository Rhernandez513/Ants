#ifndef ANTHELPER_H
#define ANTHELPER_H
#include "Ant.h"
#include <iostream>

namespace Ants {
namespace AntHelper {
// Updates various Game Status's
void Update(Ant* ant);
}
// Prints This ant's Hierarchy & Color
// Example
// Ant red_ant(red, worker, 1);
// std::cout << red_ant << std::endl;
// (prints "Red Worker Ant")
std::ostream& operator<<(std::ostream& os, Ants::Ant* ant);
}
#endif  // ANTHELPER_H
