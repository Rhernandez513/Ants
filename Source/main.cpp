#include "..\\Headers\\Ant.h"
#include "..\\Headers\\GameField.h"
#include "..\\Headers\Gameblock.h"
#include <iostream>
//#include <glut.h>
#include <string>
#include <stack>
#include <fstream>

using namespace Ants;

// Helps with clearing std::cin buffer to prevent infinite loops
// Can also work like std::cin.get() to accept a Return key press
void bufferClear();
// Combat testing method
void GameSetup();
// If two ants overlap over a block, they will attack by
// Getting popped from the stack
void ResolveCombat(std::stack<GameBlock>& stack);
// Flags checking if the queen has died.
bool red_queen_is_dead = false, blue_queen_is_dead = false;


// Prints to stdout the WelcomeMsg
bool PrintWelcome() {
  // Setup
  std::string file_name = "WelcomeMsg.txt";
  std::fstream rdr(file_name);
  rdr.open(file_name);
  if (!rdr.is_open()) return false;
  rdr.clear();
  // Parsing & Printing
  std::string tempLineString;
  while (rdr.peek() != EOF) {
    std::getline(rdr, tempLineString);
    std::cout << tempLineString << std::endl;
    if (tempLineString == "") {
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }
  // Cleanup
  rdr.close();
  return true;
}

int main() {
  if (!PrintWelcome()) return 1;
  bufferClear();

  int size = 0, numOfAntsToCreatePerTeam = 0;
  std::stack<GameBlock> blockStack;

  std::cout << "How Large should the field of battle be?\n"
    << "The battlefield will be square with sides equal to your choice...\n\n";
  std::cin >> size;
  bufferClear();

  std::cout << "How large should each colony be? ";
  std::cin >> numOfAntsToCreatePerTeam;
  GameField field(size);
  field.PopulateField(numOfAntsToCreatePerTeam);
  GameSetup();
  //for (int i = 0; i < 10; ++i) {
  //  Position temp = { 1,2 };
  //  blockStack.push(*field.GetBlock(temp));
  //}
  //ResolveCombat(blockStack);
  std::cout << "\n\n\t\tsuccess!!" << std::endl;
  bufferClear();
  return 0;
}

// Helps with clearing std::cin buffer to prevent infinite loops
// Can also work like std::cin.get() to accept a Return key press
void bufferClear() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

//// Combat testing method
 void GameSetup()
{
		Ant * RQueen = new Ant(Ants::Color::red, Hierarchy::Queen, 0);
		Ant * BQueen = new Ant(Ants::Color::blue, Hierarchy::Queen, 0);
		Ant * RWorker = new Ant(Ants::Color::red, Hierarchy::Worker, 1);
		Ant * BWorker = new Ant(Ants::Color::blue, Hierarchy::Worker, 1);
		Ant * RSoldier = new Ant(Ants::Color::red, Hierarchy::Soldier, 2);
		Ant * BSoldier = new Ant(Ants::Color::red, Hierarchy::Soldier, 2);
		Ant * RKnight = new Ant(Ants::Color::red, Hierarchy::Knight, 3);
		Ant * BKnight = new Ant(Ants::Color::blue, Hierarchy::Knight, 3);
		RWorker->Attack(BWorker);
		RWorker->Attack(BQueen);
		RWorker->Attack(BSoldier);
		RWorker->Attack(BKnight);
		BWorker->Attack(RWorker);
		BWorker->Attack(RQueen);
		BWorker->Attack(RSoldier);
		BWorker->Attack(RKnight);
		BWorker->Attack(RSoldier);
		RSoldier->Attack(BSoldier);
		RSoldier->Attack(BQueen);
		RSoldier->Attack(BWorker);
		RSoldier->Attack(BKnight);
		BSoldier->Attack(RSoldier);
		BSoldier->Attack(RQueen);
		BSoldier->Attack(RWorker);
		BSoldier->Attack(RKnight);
		RKnight->Attack(BWorker);
		RKnight->Attack(BSoldier);
		RKnight->Attack(BKnight);
		RKnight->Attack(BQueen);
		BKnight->Attack(RWorker);
		BKnight->Attack(RSoldier);
		BKnight->Attack(RKnight);
		BKnight->Attack(RQueen);
}

// If two ants overlap over a block, they will attack by
// Getting popped from the stack
void ResolveCombat(std::stack<GameBlock>& stack) {
  GameBlock temp;
  while (!stack.empty()) {
    temp = stack.top();  // First set both of the._ants to NULL pointers
    stack.pop();
    if (!temp._ant1 || !temp._ant2) continue; // Check for non-paired ants
    while (!temp._ant1->IsDead() || !temp._ant2 ->IsDead()) {
      // first while loop to check if either._ant is dead

      //._ant 1 will attack._ant 2
      temp._ant1->Attack(temp._ant2);
      if (temp._ant2->IsDead()) break; // Inner loop

      //._ant 2 will attack._ant 1
      temp._ant2->Attack(temp._ant1);
      if (temp._ant1->IsDead()) break; // Inner loop
    }
    temp._ant1 = nullptr; // set._ant 1 to null
    temp._ant2 = nullptr; // set._ant 2 to null
  }
}
