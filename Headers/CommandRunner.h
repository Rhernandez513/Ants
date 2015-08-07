#ifndef COMMANDRUNNER_H
#define COMMANDRUNNER_H
#include "Containers.h"
#include "Gameblock.h"
#include <stack>
#include <string>

namespace Ants {
// Flags checking if the queen has died.
namespace CommandRunner {
// FATAL ERROR!! Exits Program
void TriggerExit(bool good_exit);
// Exits program depending on input, optional message
void TriggerExit(bool good_exit, std::string msg);
// Starts the logging procedure
void SetUpLogging();
}
}
#endif // COMMANDRUNNER_H
