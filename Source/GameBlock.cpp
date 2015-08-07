#include "..\\Headers\\Gameblock.h"

void Ants::GameBlock::UpdateFilled() {
  if (_ant1 && _ant1) {
    this->isFilled = true;
  } else {
    this->isFilled = false;
  }
}
