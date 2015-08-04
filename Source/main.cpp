#include "..\\Headers\\Ant.h"
#include "..\\Headers\\GameField.h"
#include "..\\Headers\Gameblock.h"
#include "..\\Headers\\EventListener.h"
#include "..\\Headers\\Logger.h"
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
void TestCombat();
// Set's up gameboard etc
void GameSetup();
// Executes if game reaches end
void GameTearDown();

// Prints to stdout & logs the supplied file contents
bool PrintFile(std::string file_name) {
  // Setup
  std::fstream rdr(file_name);
  rdr.open(file_name);
  if (!rdr.is_open()) return false;
  rdr.clear();
  // Parsing & Printing
  std::string tempLineString;
  while (rdr.peek() != EOF) {
    std::getline(rdr, tempLineString);
    std::cout << tempLineString << std::endl;
    LOG(tempLineString);
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
  try {
    GameSetup();
    int size = 0, numOfAntsToCreatePerTeam = 0;
    std::stack<GameBlock> blockStack;
    std::string question = "How Large should the field of battle be?\n" newline
      "\nThe battlefield will be square with sides equal to your choice...\n\n";
    LOG(question + newline);
    for (int i = 0; i < 20; ++i) {
      std::cout << newline << std::endl;
    }
    std::cout << question;
    std::cin >> size;
    bufferClear();

    std::cout << "\n\nHow large should each colony be? " newline;
    std::cin >> numOfAntsToCreatePerTeam;
    EventListener::SetStartCond(numOfAntsToCreatePerTeam);
    GameField field(size);
    field.PopulateField(numOfAntsToCreatePerTeam);
    TestCombat();
    LOG(newline "\t\tSuccess!! Simulation ran to End!!");
    bufferClear();
  }
  catch (std::runtime_error e) {
    std::cout << e.what() << std::endl;
    Ants::EventListener::SetGameFailure(); // Terminate Program not "Happy path"
  }
  GameTearDown(); // Terminate program "Happy path"
  return 0; // Should not reach
}

// Helps with clearing std::cin buffer to prevent infinite loops
// Can also work like std::cin.get() to accept a Return key press
void bufferClear() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Combat testing method
void GameSetup() {
  std::string file_name = "WelcomeMsg.txt";
  PrintFile(file_name);
  bufferClear();
  file_name = "WelcomeMsg2.txt";
  PrintFile(file_name);
  bufferClear();
}

// Executes if game reaches end
void GameTearDown() {
  Ants::EventListener::SetGameSuccess();
}

// Simple method for testing some functionality
void TestCombat() {
  Ant* RQueen = new Ant(Ants::Color::red, Hierarchy::Queen, 0);
  Ant* BQueen = new Ant(Ants::Color::blue, Hierarchy::Queen, 0);
  Ant* RWorker = new Ant(Ants::Color::red, Hierarchy::Worker, 1);
  Ant* BWorker = new Ant(Ants::Color::blue, Hierarchy::Worker, 1);
  Ant* RSoldier = new Ant(Ants::Color::red, Hierarchy::Soldier, 2);
  Ant* BSoldier = new Ant(Ants::Color::red, Hierarchy::Soldier, 2);
  Ant* RKnight = new Ant(Ants::Color::red, Hierarchy::Knight, 3);
  Ant* BKnight = new Ant(Ants::Color::blue, Hierarchy::Knight, 3);
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