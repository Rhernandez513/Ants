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

// MOVEMENT FUNCTION NOT DONE, JUST TRYING TO FIGURE OUT LOGIC FORNOW
bool Movement(GameField field, Overlap) {
  Overlap temp;
  temp.ant1 = nullptr;
  temp.ant2 = nullptr;
  // while the ant queen of either side is not dead(so a while loop will be
  // needed)
  // loop through the ants so that they can take turns
  // set up a direction method that is random
  // set up if statement stating that if its their queen, they can bypass it
  // if its a dead ant, they can bypass
  // if its out of bounds, return null
  // maybe a for loop stating if an ant is in the way blocking a friendly ant
  //

  void pickant(int& x, int& y, color c) {
    int skips;

    srand(time(NULL));

    if (c == Color::Blue)
      skips = rand() % nblue;
    else
      skips = rand() % nred;
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        if (Field[i][j].a->color == c) {
          if (skips > 0) {
            skips--;
            continue;
          }
          x = i;
          y = j;
          return;
        }
      }
    }
  }

  int Run(bool unlimited) {
    turn = false;  // if false it's blue's turn, if true red
    int i = 0, j = 0;
    int x, y;
    int res;
    while (i < max_turns || unlimited) {
      while (j < nummoves) {
        if (turn == true) {
          pickant(x, y, Color::Blue);  // choose a random blue ant
          res = action(x, y);
          if (res == -2)  // ant we picked is blocked, choose another one
            continue;

          if (res == -1) return 0;
          if (res == 3) return 1;  // blue won
          if (res == 4) return 2;  // red won
          if (res == 0) {
            nblue--;
            nred--;
          }
          if (res == 1) nred--;
          if (res == 2) nblue--;

        } else {
          pickant(x, y, Color::Red);
          res = action(x, y);
          if (res == -2)  // ant we picked is blocked, choose another one
            continue;
          if (res == -1) return 0;
          if (res == 3)  // red team won
            return 2;
          if (res == 4)  // blue team won
            return 1;
          if (res == 0) {
            nblue--;
            nred--;
          }
          if (res == 1) nblue--;
          if (res == 2) nred--;
        }

        j++;
      }

      blue = !blue;
      j = 0;
      i++;
    }
    return 3;  // draw, end of trials
  }

  int action(int x, int y)  // return combat result or 5 for no one killed
  {
    srand(time(NULL));
    int adj[3][3];

    bool blocked =
        true;  // if true, then an ant has no empty space or enemy nearby
    // array of adjacent cells, -1 -> out of bounds,0-> empty, 1-> friendly, 2->
    // enemy
    for (int i = -1; i < 2; i++) {
      for (int j = -1; j < 2; j++) {
        if (x + i < 0 || x + i > width || y + j < 0 || y + j > height) {
          adj[i + 1][j + 1] = -1;
          i++;
          continue;
        }
        if (!Field[x + i][y + j].full) {
          adj[i + 1][j + 1] = 0;
          blocked = false;  // empty space nearby
        } else {
          if (Field[x][y].a->color == Field[x + i][y + j].a->color) {
            adj[i + 1][j + 1] = 1;  // friendly
          } else {
            adj[i + 1][j + 1] = 2;  // enemy
            blocked = false;
          }
        }
      }
    }
    if (blocked) return -2;

    int r1 = rand() % 3, r2 = rand() % 3;  // choose a random spot
    r1--;
    r2--;

    while ((r1 == 0 && r2 == 0) || adj[r1][r2] == -1 ||
           adj[r1][r2] == 1)  // if chosen spot is (0,0), or chosen spot is out
                              // of bounds or friendly
    {
      r1 = rand() % 3, r2 = rand() % 3;  // choose again
      r1--;
      r2--;
    }
    if (adj[r1][r2] == 0)  // if spot is empty
    {
      if (move(x, y, x + r1, y + r2))  // action successful
        return 5;

    } else  // spot has enemy
    {
      return combat(x, y, x + r1, y + r2);
    }
  }

  // returns: -1: both queens killed, draw. 0: both ants killed, game not over
  // yet. 1:first ant killed second. 2: second killed first. 3: queen 2 killed,
  // team 1 won. 4: queen 1 killed, team 2 won
  int combat(int x1, int y1, int x2, int y2) {
    Block a1 = Field[x1][y1];
    Block a2 = Field[x2][y2];
    int r;
    srand(time(NULL));
    r = rand() % 3;
    int q1 = a1.a->getAttackPower();
    int q2 = a2.a->getAttackPower();

    if (q1 > q2 || (q1 == q2 && r == 1)) {
      if (q2 == 0)     // if ant 2 is queen
        return 3;      // game over
      a2.a = nullptr;  // otherwise, a1 replaces a2
      a2.full = false;
      move(x1, y1, x2, y2);
      return 1;
    }
    if (q1 < q2 || (q1 == q2 && r == 2)) {
      if (a1.a->getAttackPower() == 0)  // a1 is queen
        return 4;                       // game over
      a1.a = nullptr;                   // otherwise, a2 replaces a1
      a1.full = false;
      return 2;
    }
    if (q1 == 0)     // draw,both queens were killed
      return -1;     // game over, draw
    a1.a = nullptr;  // other wise, both ants got killed
    a1.full = false;
    a2.a = nullptr;
    a2.full = false;
    return 0;
  }
}
}
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
