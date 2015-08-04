#include "..\\Headers\\EventListener.h"
#include "..\\Headers\\CommandRunner.h"
#include "..\\Headers\\Logger.h"

using namespace Ants;

namespace {

// Don't mind me, just a datatype
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

// If you look closely you'll see this is where the magic happens
void TrackDeadAnts(Ant * ant) {
  if (ant->GetHierarchy() == Hierarchy::Queen) {
    TrackWinConditon(ant->GetColor()); // If the ant that just died is a Queen
                                       // Set the win condition
  } else { // If it's not the Queen we have to actually do stuff  (-.-)
    if (ant->GetColor() == Color::red) {
      ++count.red_holder.count;
    } else if (ant->GetColor() == Color::blue) {
      ++count.blue_holder.count;
    }
    ++count.totalAntPerTeamCount;
    if (count.red_holder.count >= (count.totalAntPerTeamCount * (9 / 10))) {
      TrackWinConditon(Color::blue); // 90% of red ants dead, blue team wins
    } else if (count.blue_holder.count >= (count.totalAntPerTeamCount * (9 / 10))) {
      TrackWinConditon(Color::red); // 90% of blue ants dead, red team wins
    }
  }
}

// No Comment
void SetTotalAntsPerTeam(int num) {
  count.totalAntPerTeamCount = num;
}

// Wipes that nasty Ant residue off of your block
// Leaves it Shiny and Chrome
bool CleanAnt(Ant * ant) {
  if (ant) {
    if (ant->IsDead()) {
      delete ant;
      ant = nullptr;
      return true;
    }
  }
  return false;
}

// MAGIC
void CheckBlock(GameBlock * _block) {
  if (CleanAnt(_block->_ant1) || CleanAnt(_block->_ant2)) {
    _block->isFilled = false; // Update Filled Value if scrubbed
  }
  if (_block->_ant1 && _block->_ant2) {
    if (_block->_ant1->GetColor() != _block->_ant2->GetColor()) {
      // If we determine that the overlapping ants are of different colonies
      // They must engage in GLORIOUS COMBAT!!
      Ants::CommandRunner::PrepForCombat(_block);
    }
  } else {
    // Apparently we are missing an ant somewhere
    _block->isFilled = false;
  }
}
} // End Anon namespace

// Magic, do not touch
void Ants::EventListener::Update(Ant* ant) {
  if (ant->IsDead()) {
    std::stringstream stream;
    stream << "A " << ant << " has died honorably trying to fight its foe. . . .\n";
    Ants::Logger::LOG(stream.str());
    TrackDeadAnts(ant);
  }
}

// Magic, do not touch
void Ants::EventListener::Update(GameBlock * _block) {
  CheckBlock(_block);
}

// Magic, do not touch
void Ants::EventListener::SetStartCond(int num) {
  SetTotalAntsPerTeam(num);
}

// FATAL ERROR EXITS GAME, optional msg
void Ants::EventListener::SetGameFailure() {
  std::string msg = "\n\n\t\tSeems Like Something Went Wrong...\n\n";
  Ants::CommandRunner::TriggerExit(false, msg);
}

// FATAL ERROR EXITS GAME, optional msg
void Ants::EventListener::SetGameFailure(std::string msg) {
  std::string _msg = "\n\n\t\tSeems Like Something Went Wrong...\n\n";
  Ants::CommandRunner::TriggerExit(false, (msg + _msg));
}

// Evaluate's Win Condition and exits game
void Ants::EventListener::SetGameSuccess() {
  std::string msg;
  if (red_queen_is_dead) {
    msg = "\n\n\t\tThe Blue colony has triumphed!!!";
  } else if (blue_queen_is_dead) {
    msg = "\n\n\t\tThe Red colony has triumphed!!!";
  } else {
    msg = "Both colonies fought bravely, but neither was the victor today...";
  }
  Ants::CommandRunner::TriggerExit(true, msg);
}
