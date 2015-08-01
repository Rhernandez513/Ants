#ifndef COMMANDRUNNER_H
#define COMMANDRUNNER_H
#include "Containers.h"
#include "Gameblock.h"
#include <stack>

namespace Ants {
namespace CommandRunner {
bool SetWinner(Color color);
void PrepForCombat(Ants::GameBlock * _block);
void ResolveCombat(std::stack<Ants::GameBlock>& stack);
}
}
#endif // COMMANDRUNNER_H
