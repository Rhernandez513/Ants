#include "..\\Headers\\CommandRunner.h"

bool Ants::CommandRunner::SetWinner(Ants::Color color) {
  switch (color) {
    case(Color::red) :
      red_queen_is_dead = true;
      return true;
    case(Color::blue) :
      blue_queen_is_dead = true;
      return true;
  }
  return false;
}

void Ants::CommandRunner::PrepForCombat(Ants::GameBlock * _block) {
  Ants::blockStack.push(*_block);
}

// If two ants overlap over a block, they will attack by
// Getting popped from the stack
void Ants::CommandRunner::ResolveCombat(std::stack<Ants::GameBlock>& stack) {
  Ants::GameBlock temp;
  while (!stack.empty()) {
    temp = stack.top();
    stack.pop();
    if (!temp._ant1 || !temp._ant2) continue;  // Check for non-paired ants
    while (!temp._ant1->IsDead() || !temp._ant2->IsDead()) {
      // first while loop to check if either _ant is dead

      // _ant 1 will attack _ant 2
      temp._ant1->Attack(temp._ant2);
      if (temp._ant2->IsDead()) break;  // Inner loop

      // _ant 2 will attack _ant 1
      temp._ant2->Attack(temp._ant1);
      if (temp._ant1->IsDead()) break;  // Inner loop
    }
    temp._ant1 = nullptr;  // set._ant 1 to null
    temp._ant2 = nullptr;  // set._ant 2 to null
  }
}
