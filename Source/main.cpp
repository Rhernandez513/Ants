#include <iostream>
#include <glut.h>
#include "../Headers/Ant.h"
#include "../Headers/GameField.h"

using namespace Ants;
using namespace GameField;

void bufferClear();

int main()
{
  int length, width, numberOfAntsToCreate;
  std::cout << "How long should the Field of Battle be? ";
  std::cin >> length;
  bufferClear();
  std::cout << "How wide should the Field of Battle be? ";
  std::cin >> width;
  bufferClear();
  if (length > 0 && width > 0) {
    GameField mainField(length, width);
  } else {
    return 1;
  }
  numberOfAntsToCreate = (length * width) / 3;
}

// Helps with clearing std::cin buffer to prevent infinite loops
// Can also work like std::cin.get() to accept a Return key press
void bufferClear() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
