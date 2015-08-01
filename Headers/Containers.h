#ifndef CONTAINERS_H
#define CONTAINERS_H
#include <iostream>

namespace Ants {
struct Position {
  int x;
  int y;
};
enum Direction { LEFT, RIGHT, UP, DOWN };
enum Color { red, blue };
std::ostream& operator<<(std::ostream& os, Color color);
}
#endif // CONTAINERS_H
