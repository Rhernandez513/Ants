#ifndef CONTAINERS_H
#define CONTAINERS_H
#include <ostream>

namespace Ants {
struct Position { int x; int y; };
enum class Direction { LEFT, RIGHT, UP, DOWN };
enum class Color { red, blue };
std::string Color_to_String(Ants::Color color);
std::ostream& operator<<(std::ostream& os, Color color);

// Flags checking if the queen has died.
static bool red_queen_is_dead = false, blue_queen_is_dead = false;
};
#endif  // CONTAINERS_H
