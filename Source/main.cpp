#include <iostream>
#include <glut.h>
#include <time.h>
#include<string>
#include "..\\Headers\\Ant.h"
#include "..\\Headers\\GameField.h"
#include <vector>

using namespace Ants;

void bufferClear();
void GameSetup();
GameField field;

int main()
{
	std::cout << "Welcome to the battlefield!" << std::endl;
	std::cout << " Here, on this kitchen table, the most epic battle between " 
            << "Ants will take place!" << std::endl;
	std::cout << "On one side, there are the BLUE ants. The other side has RED " 
            << "Ants. They despise each other. . ." << std::endl;
	std::cout << "Each side has a hierarchy of ant ranks: Worker ant, Soldier " 
            << "ant, and Knight ant (worker ant being the weakest and Knight " 
            << "ant being the strongest)" << std::endl;
	std::cout << "Stronger ants can easily defeat weaker ants, but they will " 
            << "surely be damaged in battle" << std::endl;
	std::cout << "If there are two evenly matched ants, fate shall decide who "
            << "wins, and who dies" << std::endl;
	std::cout << "Each side has a weak spot, their Queen" << std::endl;
	std::cout << "Whichever side defeats the other sides' Queen, wins the game!" 
            << std::endl;
	std::cout << "Are you ready?" << std::endl;

  int numberOfAntsToCreate = (length * width) / 3;

}

// Helps with clearing std::cin buffer to prevent infinite loops
// Can also work like std::cin.get() to accept a Return key press
void bufferClear() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// GameField Factory Function
GameField* CreateField() {
  bool red_flag = false, blue_flag = false; // flags checking if the queen has died. 
  int length, width;
  std::cout << "How long should the Field of Battle be? ";
  std::cin >> length;
  bufferClear();
  std::cout << "How wide should the Field of Battle be? ";
  std::cin >> width;
  bufferClear();
  if (length > 0 && width > 0) {
    return new GameField(length, width);
  }
  return nullptr;
}

void::LocationFinder()
{

}

void GameSetup()
{
		Ant * RQueen = new Ant(Color::red, Hierarchy::Queen, 0);
		Ant * BQueen = new Ant(Color::blue, Hierarchy::Queen, 0);
		Ant * RWorker = new Ant(Color::red, Hierarchy::Worker, 1);
		Ant * BWorker = new Ant(Color::blue, Hierarchy::Worker, 1);
		Ant * RSoldier = new Ant(Color::red, Hierarchy::Soldier, 2);
		Ant * BSoldier = new Ant(Color::red, Hierarchy::Soldier, 2);
		Ant * RKnight = new Ant(Color::red, Hierarchy::Knight, 3);
		Ant * BKnight = new Ant(Color::blue, Hierarchy::Knight, 3);
		RWorker->Attack(BWorker);
		RWorker->Attack(BQueen);
		BWorker->Attack(RWorker);
		BWorker->Attack(RQueen);
		RSoldier->Attack(BSoldier);
		RSoldier->Attack(BQueen);
		BSoldier->Attack(RSoldier);
		BSoldier->Attack(RQueen);
		RKnight->Attack(BKnight);
		RKnight->Attack(BQueen);
		BKnight->Attack(RKnight);
		BKnight->Attack(RQueen);
}
