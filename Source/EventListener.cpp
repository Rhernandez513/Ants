#include "..\\Headers\\EventListener.h"
#include "..\\Headers\\CommandRunner.h"

using namespace Ants;

namespace {
struct deadAntCount {
  struct colorHolder {
    int count;
  };
  colorHolder red_holder;
  colorHolder blue_holder;
  int totalAntPerTeamCount = 0;
} count;
void TrackWinConditon(Color color) {
  CommandRunner::SetWinner(color);
}

void TrackDeadAnts(Ant * ant) {
  if(ant->GetHierarchy() == Hierarchy::Queen) {
    TrackWinConditon(ant->GetColor()); // If the ant that just died is a Queen
                                       // Set the win condition
  } else {
    if (ant->GetColor() == Color::red) {
      ++count.red_holder.count;
    } else if (ant->GetColor() == Color::blue) {
      ++count.blue_holder.count;
    }
    ++count.totalAntPerTeamCount;
    if(count.red_holder.count >= (count.totalAntPerTeamCount * (9/10))) {
      TrackWinConditon(Color::blue); // 90% of red ants dead, blue team wins
    } else if (count.blue_holder.count >= (count.totalAntPerTeamCount * (9/10))) {
      TrackWinConditon(Color::red); // 90% of blue ants dead, red team wins
    }
  }
}
void SetTotalAnts(int num) {
  count.totalAntPerTeamCount = num;
}
void CheckBlock(GameBlock * _block) {
  if (_block->_ant1 && _block->_ant2) {
    if(!_block->isFilled) // Update Filled Value
      _block->isFilled = true;
    if (_block->_ant1->GetColor() != _block->_ant2->GetColor()) {
      Ants::CommandRunner::PrepForCombat(_block);
    }
  } else {
    _block->isFilled = false;
  }
}
}

void Ants::EventListener::Update(Ant* ant) {
  if(ant->IsDead()) TrackDeadAnts(ant);
}

void Ants::EventListener::Update(GameBlock * _block) {
  CheckBlock(_block);
}

void Ants::EventListener::SetStartCond(int num) {
  SetTotalAnts(num);
}
