#include <iostream>
//#include <glut.h>
#include <time.h>
#include <string>
#include "..\\Headers\\Ant.h"
#include "..\\Headers\\GameField.h"
#include <vector>
#include <stack>

using namespace Ants;

struct Position {
  int x;
  int y;
};
struct Overlap {
  Ant* ant1;
  Ant* ant2;
};

enum class Direction { LEFT, RIGHT, UP, DOWN };
enum class Color { red, blue };

void bufferClear();
void GameSetup();
void Combat(Ant* a, Ant* b);

// PLACEHOLDER VALUES
GameField field(50, 50);

int main() {
  bool red_flag = false,
       blue_flag = false;  // flags checking if the queen has died.
  int length, width;

  std::cout << "Welcome to the battlefield!" << std::endl;
  std::cout << " Here, on this kitchen table, the most epic battle between "
            << "Ants will take place!" << std::endl;
  std::cout << "On one side, there are the BLUE ants. The other side has RED "
            << "Ants. They despise each other. . ." << std::endl;
  std::cout << "Each side has a hierarchy of ant ranks: Worker ant, Soldier "
            << "ant, and Knight ant (worker ant being the weakest and Knight "
            << "ant being the strongest. )" << std::endl;
  std::cout << "Every Ant starts out as a worker ant and gets promoted as they "
               "battle, except Queen ants.\n";
  std::cout << "Stronger ants can easily defeat weaker ants, but they will "
            << "surely be damaged in battle" << std::endl;
  std::cout << "If there are two evenly matched ants, fate shall decide who "
            << "wins, and who dies" << std::endl;
  std::cout << "Each side has a weak spot, their Queen" << std::endl;
  std::cout << "Whichever side defeats the other sides' Queen, wins the game!"
            << std::endl;
  std::cout << "Are you ready?" << std::endl;

  std::cout << "How long should the Field of Battle be? ";
  std::cin >> length;
  bufferClear();
  std::cout << "How wide should the Field of Battle be? ";
  std::cin >> width;
  bufferClear();

  int numOfAntsToCreatePerTeam = (length * width) / 3;
  GameField field(length, width);
  field.PopulateField(numOfAntsToCreatePerTeam);
  std::cout << "success!!" << std::endl;
  return 0;
}
// Helps with clearing std::cin buffer to prevent infinite loops
// Can also work like std::cin.get() to accept a Return key press
void bufferClear() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// void GameSetup()
//{
//		Ant * RQueen = new Ant(Color::red, Hierarchy::Queen, 0);
//		Ant * BQueen = new Ant(Color::blue, Hierarchy::Queen, 0);
//		Ant * RWorker = new Ant(Color::red, Hierarchy::Worker, 1);
//		Ant * BWorker = new Ant(Color::blue, Hierarchy::Worker, 1);
//		Ant * RSoldier = new Ant(Color::red, Hierarchy::Soldier, 2);
//		Ant * BSoldier = new Ant(Color::red, Hierarchy::Soldier, 2);
//		Ant * RKnight = new Ant(Color::red, Hierarchy::Knight, 3);
//		Ant * BKnight = new Ant(Color::blue, Hierarchy::Knight, 3);
//		RWorker->Attack(BWorker);
//		RWorker->Attack(BQueen);
//		RWorker->Attack(BSoldier);
//		RWorker->Attack(BKnight);
//		BWorker->Attack(RWorker);
//		BWorker->Attack(RQueen);
//		BWorker->Attack(RSoldier);
//		BWorker->Attack(RKnight);
//		BWorker->Attack(RSoldier);
//		RSoldier->Attack(BSoldier);
//		RSoldier->Attack(BQueen);
//		RSoldier->Attack(BWorker);
//		RSoldier->Attack(BKnight);
//		BSoldier->Attack(RSoldier);
//		BSoldier->Attack(RQueen);
//		BSoldier->Attack(RWorker);
//		BSoldier->Attack(RKnight);
//		RKnight->Attack(BWorker);
//		RKnight->Attack(BSoldier);
//		RKnight->Attack(BKnight);
//		RKnight->Attack(BQueen);
//		BKnight->Attack(RWorker);
//		BKnight->Attack(RSoldier);
//		BKnight->Attack(RKnight);
//		BKnight->Attack(RQueen);
//}

// if two ants overlap over a block, they will attack by
// getting popped from the stack
void ResolveCombat(std::stack<Overlap>& stack) {
  Overlap temp;
  while (!stack.empty()) {
    temp = stack.top();  // First set both of the ants to NULL pointers
    stack.pop();
    while (
        !temp.ant1->IsDead() ||
        !temp.ant2
             ->IsDead()) {  // first while loop to check if either ant is dead
      temp.ant1->Attack(temp.ant2);  // ant 1 will attack ant 2
                                     // if ant 2 is dead, it will continue
      if (temp.ant2->IsDead()) break;
      // ant 2 will attack ant 1
      temp.ant2->Attack(temp.ant1);
      // if ant 1 is dead, it will continue
      if (temp.ant1->IsDead()) break;
    }                     // End while
    temp.ant1 = nullptr;  // set ant 1 to null
    temp.ant2 = nullptr;  // set ant 2 to null
  }                       // End outer while
}

// MOVEMENT FUNCTION NOT DONE, JUST TRYING TO FIGURE OUT LOGIC FOR NOW


/////////*Use some of Syed's logic to implement initial Ant setup*/////////
//
// void GameSetup(int numberOfAntsToCreate);
//{
//	int area = GameField * GameField;
//	int area1 = (GameField * GameField) - GameField;
//	Ant turns[area];
//	Ant turns1[area1];
//	if (GameField % 2 == 1) // for odd dimensions.
//	{
//		string red = "red", blue = "blue", Worker = "Worker", soldier =
//"soldier", Knight = "Knight", Queen = "Queen";
//		Ant * RQueen = new Ant(Color::red, Hierarchy::Queen, 0);
//		Ant * BQueen = new Ant(Color::blue, Hierarchy::Queen, 0);
//    RQueen->Attack(BQueen);
//		BQueen.Ant(blue, Queen, 0);
//		turns[0]=BQueen;
//		turns1[1]= RQueen;
//		for (int i = 2; i < area1; i++)
//		{
//			if (i < area1 / 2)
//			{
//				Ant Rsoldier; Rsoldier.Ant(red, Soldier, 2);
//				Ant Bsoldier; Bsoldier.Ant(blue, Soldier, 2);
//				turns[i] = Bsoldier;
//				i++;
//				turns1[i] = Rsoldier;
//			}
//			else if
//			{
//				Ant RWorker; RWorker.Ant(red, Worker, 1);
//				Ant BWorkere; BWorker.Ant(blue, Worker, 1);
//				turns[i] = BWorker;
//				i++;
//				turns1[i] = RWorker;
//			}
//			else
//			{
//				Ant RKnight; RKnight.Ant(red, Knight, 3);
//				And BKnight; BKnight.Ant(red, Knight, 3);
//				turns[i] = BKnight;
//				i++;
//				turns1[i] = RKnight;
//			}
//		}
//	}
//	else // for even dimensions
//	{
//		string red = "red", blue = "blue", Worker = "Worker", soldier =
//"soldier", Knight = "Knight", Queen = "Queen";
//		Ant RQueen;
//		RQueen.Ant(red, Queen, 0);
//		Ant BQueen;
//		BQueen.Ant(blue, Queen, 0);
//		turns[0] = BQueen;
//		turns1[1] = RQueen;
//		for (int i = 2; i < area; i++)
//		{
//			if (i <= area/2)
//			{
//				Ant Rsoldier; Rsoldier.Ant(red, Soldier, 2);
//				Ant Bsoldier; Bsoldier.Ant(blue, Soldier, 2);
//				turns[i] = Bsoldier;
//				i++;
//				turns1[i] = Rsoldier;
//			}
//			else if
//			{
//				Ant RWorker; RWorker.Ant(red, Worker, 1);
//				Ant BWorker; BWorker.Ant(blue, Worker, 1);
//				turns[i] = BWorker;
//				i++;
//				turns1[i] = RWorker;
//			}
//			else
//			{
//				Ant RKnight; RKnight.Ant(red, Knight, 3);
//				And BKnight; BKnight.Ant(red, Knight, 3);
//				turns[i] = BKnight;
//				i++;
//				turns1[i] = RKnight
//	}
//}
