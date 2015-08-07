#include "..\\Headers\\EventListener.h"
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

// If we determine that the overlapping ants are of different colonies
// They must engage in GLORIOUS COMBAT!!
void PrepForCombat(Ants::GameBlock * _block) {
  // Put the ACTUAL block into the stack
  if (_block) Ants::blockStack.push(_block);
}

// If two ants overlap over a block, they will attack by
// Getting popped from the stack
void ResolveCombat() {
  Ants::GameBlock * temp = nullptr;
  while (!Ants::blockStack.empty()) {
    temp = Ants::blockStack.top(); // used to manipulate blocks on the board
    Ants::blockStack.pop();
    if (!temp) { continue; } // Check for null blocks
    if (!temp->_ant1 || !temp->_ant2) continue;  // Check for non-paired ants
    while (!temp->_ant1->IsDead() || !temp->_ant2->IsDead()) {
      // first while loop to check if either _ant is dead

      // _ant 1 will attack _ant 2
      temp->_ant1->Attack(temp->_ant2);
      if (temp->_ant1->IsDead()) break;  // Inner loop
      if (temp->_ant2->IsDead()) break;  // Inner loop
      // _ant 2 will attack _ant 1
      temp->_ant2->Attack(temp->_ant1);
    } // End inner loop
  } // End outer loop
}

// Someone must have won the game
void SetWinningTeam(Color color) {
    EventListener::SetGameSuccess(color);
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

// Returns true if two ants are within the block of different colors
bool CheckBlock(GameBlock * _block) {
  if (!_block) return false;
  if (_block->_ant1) EventListener::Update(_block->_ant1);
  if (_block->_ant2) EventListener::Update(_block->_ant2);
  if(!_block->_ant1 || !_block->_ant2) {
      _block->isFilled = false; // Update Filled Value if missing one
  } else if (_block->_ant1 && _block->_ant2) {
    if (_block->_ant1->GetColor() != _block->_ant2->GetColor())
      return true;
  }
  return false;
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
    CleanAnt(ant);
  }
}

// Magic, do not touch
void Ants::EventListener::Update(GameBlock * _block) {
  if (!_block) return;
  if (CheckBlock(_block)) {
    PrepForCombat(_block);
    ResolveCombat();
  }
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
void Ants::EventListener::SetGameSuccess(Ants::Color color) {
  std::string msg;
  if (color == Color::blue) {
    msg = "\t\tThe Blue colony has triumphed!!!";
  } else if (color == Color::red) {
    msg = "\t\tThe Red colony has triumphed!!!";
  }/* else {
    msg =  "Both colonies fought bravely, but neither was the victor today...";
  }*/
  Ants::CommandRunner::TriggerExit(true, msg);
}
