#ifndef COMMANDRUNNER_H
#define COMMANDRUNNER_H
#include "Containers.h"
#include "Gameblock.h"
#include <stack>
#include <string>

namespace Ants {
namespace CommandRunner {
// FATAL ERROR!! Exits Program
void TriggerExit(bool good_exit);
// Exits program depending on input, optional message
void TriggerExit(bool good_exit, std::string msg);
// Trip Wire for the Winner!
bool SetWinner(Color color);
// If we determine that the overlapping ants are of different colonies
// They must engage in GLORIOUS COMBAT!!
void PrepForCombat(GameBlock * _block);
// If two ants overlap over a block, they will attack by
// Getting popped from the stack
void ResolveCombat(std::stack<GameBlock*>& stack);
// Starts the logging procedure
void SetUpLogging();
}
}
#endif // COMMANDRUNNER_H
