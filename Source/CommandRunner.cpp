#include "..\\Headers\\CommandRunner.h"
#include "..\\Headers\\EventListener.h"
#include "..\\Headers\\Logger.h"

// Exits program depending on input, optional message
// Also Closes the Logger, if open
void Ants::CommandRunner::TriggerExit(bool good_exit) {
  Ants::Logger::Terminate_Logging();
  good_exit ? exit(EXIT_SUCCESS) : exit(EXIT_FAILURE);
}

// Exits program depending on input, optional message
void Ants::CommandRunner::TriggerExit(bool good_exit, std::string msg) {
  std::cout << msg << std::endl;
  TriggerExit(good_exit);
}

// Trip Wire for the Winner!
bool Ants::CommandRunner::SetWinner(Ants::Color color) {
  switch (color) {
    case(Color::red) :
      Ants::red_queen_is_dead = true;
      return true;
    case(Color::blue) :
      Ants::blue_queen_is_dead = true;
      return true;
  }
  return false;
}

// If we determine that the overlapping ants are of different colonies
// They must engage in GLORIOUS COMBAT!!
void Ants::CommandRunner::PrepForCombat(Ants::GameBlock * _block) {
  Ants::blockStack.push(*_block); // Put the ACTUAL block into the stack
}

// If two ants overlap over a block, they will attack by
// Getting popped from the stack
void Ants::CommandRunner::ResolveCombat(std::stack<Ants::GameBlock>& stack) {
  Ants::GameBlock * temp;
  while (!stack.empty()) {
    temp = &stack.top(); // used to manipulate actual blocks on the board
    stack.pop();
    if (!temp->_ant1 || !temp->_ant2) continue;  // Check for non-paired ants
    while (!temp->_ant1->IsDead() || !temp->_ant2->IsDead()) {
      // first while loop to check if either _ant is dead

      // _ant 1 will attack _ant 2
      temp->_ant1->Attack(temp->_ant2);
      if (temp->_ant2->IsDead()) break;  // Inner loop

      // _ant 2 will attack _ant 1
      temp->_ant2->Attack(temp->_ant1);
      if (temp->_ant1->IsDead()) break;  // Inner loop
    }
    Ants::EventListener::Update(temp);
  }
}

// Starts the logging procedure
void Ants::CommandRunner::SetUpLogging() {
  try {
    Ants::Logger::StartLogging();
  }
  catch (std::runtime_error e) {
    std::string error_msg = e.what();
    Ants::CommandRunner::TriggerExit(false, error_msg);
  }
}
