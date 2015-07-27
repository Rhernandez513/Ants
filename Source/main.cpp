#include <iostream>
#include <glut.h>
#include "..\\Headers\\Ant.h"
#include "..\\Headers\\GameField.h"

using namespace Ants;

void bufferClear();

int main()
{

  int numberOfAntsToCreate = (length * width) / 3;
}

// Helps with clearing std::cin buffer to prevent infinite loops
// Can also work like std::cin.get() to accept a Return key press
void bufferClear() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// GameField Factory Function
GameField* CreateField() {
  int length, width;
  std::cout << "How long should the Field of Battle be? ";
  std::cin >> length;
  bufferClear();
  std::cout << "How wide should the Field of Battle be? ";
  std::cin >> width;
  bufferClear();
  if (length > 0 && width > 0) {
    return new GameField(length, width);
  }
  return nullptr;
}
