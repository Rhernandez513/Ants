#ifndef HIERARCHY_H
#define HIERARCHY_H
#include <iostream>

namespace Ants {

enum class Hierarchy { Worker = 1, Soldier, Knight, Queen };
Hierarchy& operator--(Hierarchy& hierarchy);
Hierarchy& operator++(Hierarchy& hierarchy);
std::string Hierarchy_to_String(Ants::Hierarchy hierarchy);
std::ostream& operator<<(std::ostream& os, Hierarchy hierarchy);
}
#endif  // HIERARCHY_H
