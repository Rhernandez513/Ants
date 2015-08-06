#include "..\\Headers\\AntHelper.h"
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
// Splash message
int GameSetup();
// Executes if game reaches end
void GameTearDown();


int main() {
  Ants::Ant * temp_ant = nullptr;
  std::stack<GameBlock> blockStack;
  int numOfAntsToCreatePerTeam = 0;
  try {
    GameField field(GameSetup());

    std::cout << "\n\nHow large should each colony be? " newline;
    std::cin >> numOfAntsToCreatePerTeam; bufferClear();
    field.PopulateField(numOfAntsToCreatePerTeam);

    // MAIN LOOP
    int max = std::numeric_limits<int>::max() / 20; // approx 100 million
    for (int i = 0; i < max; ++i) {
      temp_ant = Ants::AntHelper::PickAnt(field);
      if (!temp_ant) { continue; }
      Ants::AntHelper::Move(field.GetRandomValidPosition(), field, temp_ant);
    } // END MAIN LOOP
  } catch (std::runtime_error e) {
    std::cout << e.what() << std::endl;
    Ants::EventListener::SetGameFailure(); // Terminate Program not "Happy path"
  }
  Ants::EventListener::SetGameFailure("Maximum Ant Movement Attempts exceeded");
  return 2; // Should not reach
}

// Helps with clearing std::cin buffer to prevent infinite loops
// Can also work like std::cin.get() to accept a Return key press
void bufferClear() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

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

// Splash message
int GameSetup() {
  std::string question, desc, file_name;
  file_name = "WelcomeMsg.txt";
  question = "How Large should the field of battle be?";
  desc = "The battlefield will be square with sides equal to your choice...";
  PrintFile(file_name); bufferClear();
  file_name = "WelcomeMsg2.txt";
  PrintFile(file_name); bufferClear();
  for (int i = 0; i < 19; ++i) {
    std::cout << newline << std::endl;
  }
  LOG(question);
  LOG(desc);
  int _size = 0;
  do {
    std::cout << question << newline << newline << desc << std::endl;
    std::cin >> _size;
    if (_size <= 0) {
      std::cout << "Invalid input! Try again..." << newline << std::endl;
    }
  } while (_size <= 0);
  std::string msg("Creating a board of size " + std::to_string(_size));
  std::cout << newline << msg << std::endl; LOG(msg);
  bufferClear();
  return _size;
}
