#include "..\\Headers\\EventListener.h"
#include "..\\Headers\\CommandRunner.h"
#include "..\\Headers\\AntHelper.h"
#include "..\\Headers\\Logger.h"
#include "..\\Headers\\Containers.h"
#include <sstream>
#include <stack>

using namespace Ants;

namespace {
std::stack<Ant *> Dead_Ants;

// Don't mind me, just a data-type
struct deadAntCount {
  struct colorHolder {
    int count;
  } red_holder, blue_holder;
  int totalAntPerTeamCount;
} count;

// Someone must have won the game
void SetWinningTeam(Color color) {
  if (CommandRunner::SetWinner(color)) {
    EventListener::SetGameSuccess();
  }
}

// If you look closely you'll see this is where the magic happens
void TrackDeadAnts(Ant * ant) {
  if (ant->GetHierarchy() == Hierarchy::Queen) {
    // If the ant that just died is a Queen Set the win condition
    SetWinningTeam(ant->GetColor()); // Exits Game
  }
   // If it's not the Queen we have to actually do stuff  (-.-)
  double temp_num = (double)count.totalAntPerTeamCount * .7;
  if (ant->GetColor() == Color::red) {
    ++count.red_holder.count;
    if (count.red_holder.count >= temp_num) {
      SetWinningTeam(Color::blue); // 70% of red ants dead, blue team wins
    }
  } else if (ant->GetColor() == Color::blue) {
    ++count.blue_holder.count;
    if (count.blue_holder.count >= temp_num) {
      SetWinningTeam(Color::red); // 70% of blue ants dead, red team wins
    }
  }
}

// No Comment
void SetTotalAntsPerTeam(int num) {
  count.totalAntPerTeamCount = num;
}

// Wipes that nasty Ant residue off of your block
// Leaves it Shiny and Chrome
void CleanAnt(Ant * ant) {
  if (ant) {
    if (ant->IsDead()) {
      ant = nullptr;
    }
  }
}

// MAGIC
void CheckBlock(GameBlock * _block) {
  if (_block->_ant1) {
    EventListener::Update(_block->_ant1);
    if (_block->_ant1->IsDead()) {
      CleanAnt(_block->_ant1);
    }
  }
  if (_block->_ant2) {
    EventListener::Update(_block->_ant2);
    if (_block->_ant2->IsDead()) {
      CleanAnt(_block->_ant2);
    }
  }
  if(!_block->_ant1 || !_block->_ant2) {
      _block->isFilled = false; // Update Filled Value if missing one
  }
  if (_block->_ant1 && _block->_ant2) {
    if (_block->_ant1->GetColor() != _block->_ant2->GetColor()) {
      // If we determine that the overlapping ants are of different colonies
      // They must engage in GLORIOUS COMBAT!!
      Ants::CommandRunner::PrepForCombat(_block);
      Ants::CommandRunner::ResolveCombat();
    }
  }
}
} // End Anon namespace

// Magic, do not touch
void Ants::EventListener::Update(Ant* ant) {
  if (!ant) return;
  if (ant->IsDead()) {
    std::ostringstream stream;
    stream << "A "
           << ant
           << " has died honorably trying to fight its foe. . . .\n";
    LOG(stream.str());
    TrackDeadAnts(ant);
  }
}

// Magic, do not touch
void Ants::EventListener::Update(GameBlock * _block) {
  if (_block) CheckBlock(_block);
}

// Magic, do not touch
void Ants::EventListener::SetStartCond(int num) {
  SetTotalAntsPerTeam(num);
}


// FATAL ERROR EXITS GAME, optional msg
void Ants::EventListener::SetGameFailure(std::string msg) {
  std::string _msg = newline "\t\tSeems Like Something Went Wrong..." newline;
  Ants::CommandRunner::TriggerExit(false, (msg + _msg));
}

// FATAL ERROR EXITS GAME, optional msg
void Ants::EventListener::SetGameFailure() {
  Ants::EventListener::SetGameFailure("");
}

// Evaluate's Win Condition and exits game
void Ants::EventListener::SetGameSuccess() {
  std::string msg;
  if (red_queen_is_dead) {
    msg = newline "\t\tThe Blue colony has triumphed!!!";
  } else if (blue_queen_is_dead) {
    msg = newline "\t\tThe Red colony has triumphed!!!";
  } else {
    msg = newline "Both colonies fought bravely,"
                  " but neither was the victor today...";
  }
  Ants::CommandRunner::TriggerExit(true, msg);
}
