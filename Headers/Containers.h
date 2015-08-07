#ifndef CONTAINERS_H
#define CONTAINERS_H
#include <ostream>

namespace Ants {
struct Position { int x; int y; };
enum class Direction { LEFT, RIGHT, UP, DOWN };
enum class Color { red, blue };
std::string Color_to_String(Ants::Color color);
std::ostream& operator<<(std::ostream& os, Color color);
};
#endif  // CONTAINERS_H
