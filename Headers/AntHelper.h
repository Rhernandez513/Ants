#ifndef ANTHELPER_H
#define ANTHELPER_H

#include <iostream>
#include "Ant.h"

namespace Ants {
// Prints This ant's Hierarchy & Color
// Example
// Ant red_ant(red, worker, 1);
// std::cout << red_ant << std::endl;
// (prints "Red Worker Ant")
std::ostream & operator<<(std::ostream & os, Ants::Ant * ant);
}
#endif // ANTHELPER_H
