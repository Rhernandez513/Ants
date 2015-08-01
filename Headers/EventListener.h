#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H
#include "Ant.h"
#include "Gameblock.h"

namespace Ants {
namespace EventListener {
void Update(Ant * ant);
void Update(GameBlock * _block);
void SetStartCond(int num);
}
}
#endif // EVENTLISTENER_H
