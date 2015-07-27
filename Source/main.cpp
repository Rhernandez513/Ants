#include <iostream>
#include <glut.h>
#include <time.h>
#include<string>
#include<stdlib.h>
#include "..\\Headers\\Ant.h"
#include "..\\Headers\\GameField.h"

using namespace std;
using namespace Ants;

void bufferClear();
void GameSetup();

int main()
{
	cout << "Welcome to the battlefield!" << endl;
	cout << " Here, on this kitchen table, the most epic battle between Ants will take place!" << endl;
	cout << "On one side, there are the BLUE ants. The other side has RED Ants. They despise each other. . ." << endl;
	cout << "Each side has a hierarchy of ant ranks: Worker ant, Soldier ant, and Knight ant (worker ant being the weakest and Knight ant being the strongest)"<<endl;
	cout << "Stronger ants can easily defeat weaker ants, but they will surely be damaged in battle" << endl;
	cout << "If there are two evenly matched ants, fate shall decide who wins, and who dies" << endl;
	cout << "Each side has a weak spot, their Queen" << endl;
	cout << "Whichever side defeats the other sides' Queen, wins the game!" << endl;
	cout << "Are you ready?" << endl;

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

void GameSetup(int numberOfAntsToCreate);
{
	int area = GameField * GameField;
	int area1 = (GameField * GameField) - GameField;
	Ant turns[area];
	Ant turns1[area1];
	if (GameField % 2 == 1) // for odd dimensions. 
	{
		string red = "red", blue = "blue", Worker = "Worker", soldier = "soldier", Knight = "Knight", Queen = "Queen";
		Ant RQueen;
		RQueen.Ant(red, Queen, 0);
		Ant BQueen;
		BQueen.Ant(blue, Queen, 0);
		turns[0]=BQueen;
		turns1[1]= RQueen;
		for (int i = 2; i < area1; i++)
		{
			if (i < area1 / 2)
			{
				Ant Rsoldier; Rsoldier.Ant(red, Soldier, 2);
				Ant Bsoldier; Bsoldier.Ant(blue, Soldier, 2);
				turns[i] = Bsoldier;
				i++;
				turns1[i] = Rsoldier;
			}
			else if
			{
				Ant RWorker; RWorker.Ant(red, Worker, 1);
				Ant BWorkere; BWorker.Ant(blue, Worker, 1);
				turns[i] = BWorker;
				i++;
				turns1[i] = RWorker;
			}
			else
			{
				Ant RKnight; RKnight.Ant(red, Knight, 3);
				And BKnight; BKnight.Ant(red, Knight, 3);
				turns[i] = BKnight;
				i++;
				turns1[i] = RKnight;
			}
		}
	}
	else // for even dimensions
	{
		string red = "red", blue = "blue", Worker = "Worker", soldier = "soldier", Knight = "Knight", Queen = "Queen";
		Ant RQueen;
		RQueen.Ant(red, Queen, 0);
		Ant BQueen;
		BQueen.Ant(blue, Queen, 0);
		turns[0] = BQueen;
		turns1[1] = RQueen;
		for (int i = 2; i < area; i++)
		{
			if (i <= area/2)
			{
				Ant Rsoldier; Rsoldier.Ant(red, Soldier, 2);
				Ant Bsoldier; Bsoldier.Ant(blue, Soldier, 2);
				turns[i] = Bsoldier;
				i++;
				turns1[i] = Rsoldier;
			}
			else if
			{
				Ant RWorker; RWorker.Ant(red, Worker, 1);
				Ant BWorker; BWorker.Ant(blue, Worker, 1);
				turns[i] = BWorker;
				i++;
				turns1[i] = RWorker;
			}
			else
			{
				Ant RKnight; RKnight.Ant(red, Knight, 3);
				And BKnight; BKnight.Ant(red, Knight, 3);
				turns[i] = BKnight;
				i++;
				turns1[i] = RKnight
	}
}