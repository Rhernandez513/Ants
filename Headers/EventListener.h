#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H
#include "Ant.h"
#include "Gameblock.h"

namespace Ants {
namespace EventListener {
// Magic, do not touch
void Update(Ant * ant);
// Magic, do not touch
void Update(GameBlock * _block);
// Magic, do not touch
void SetStartCond(int num);
// FATAL ERROR EXITS GAME, optional msg
void SetGameFailure();
// FATAL ERROR EXITS GAME, optional msg
void SetGameFailure(std::string msg);
// Evaluate's Win Condition and exits game
void SetGameSuccess();
}
}
#endif // EVENTLISTENER_H
