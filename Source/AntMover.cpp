#include "..\\Headers\\Ant.h"
#include "..\\Headers\\GameField.h"
#include "..\\Headers\\AntMover.h"
#include "..\\Headers\\CommandRunner.h"
//#include "..\\Headers\Gameblock.h"
#include <iostream>
#include <time.h>

using namespace Ants;

AntMover::AntMover(int n, int nblue, int nred, int max_turns) {
  srand(static_cast<unsigned>(time(nullptr)));
  _turn = false;
  this->_max_turns = max_turns;
  this->_nummoves = n;
  this->_nred = nred;
  this->_nblue = nblue;
}

// Checks if positions nearby are empty or not
bool AntMover::Move(Position position, GameField &field, Ant *ant) {
  int r = (rand() % 4) + 1;  // randomly choosing four directions
  for (int i = 0; i < 4; ++i) {
    if (field.SetBlock(position, ant)) {
      EventListener::Update(field.GetBlock(ant->GetLocation()));
      return true;
    }
    switch (i) {
      case (0) :
        position.x += 1;
        break;
      case(1) :
        position.x -= 2; // Move x to "-1"
        break;
      case(2) :
        position.x += 1; // Reset's x back to "0"
        position.y += 1;
        break;
      case (3) :
        position.y -= 2; // Move y to "-1"
        break;
    }
  }
  return false;
}

// this function picks an ant on either side of the field and moves it until the win condition
void AntMover::pickant(Position position, GameField &field, Ant *ant1, Ant *ant2) {
	while (!red_queen_is_dead || !blue_queen_is_dead);
	{
		ant1 = rand() % _nblue; // cannot manipualte ant pointer with random operator
		Move.ant; // will finish
	}

// if an ant is close by, it will do this
/*int AntMover::CloseAnt(GameField &field, Ant *ant1) {
  GameBlock *tempBlock = field.GetBlock(ant1->GetLocation());  // setting tempBlock equal to the ants location on the block
  if (!tempBlock) // it it's empty then return 0
    return 0;
  srand(time(NULL));
  bool blocked = true;
  // if true, then an ant has no empty space or enemy nearby
  // array of adjacent cells, -1 -> out of bounds,0-> empty, 1-> friendly, 2->
  // enemy
  for (int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++) {
      if () {
        adj[i + 1][j + 1] = -1;
        i++;
        continue;
      }
      if (!field[position1 + i][position2 + j].full) {
        adj[i + 1][j + 1] = 0;
        blocked = false;  // empty space nearby
      } else {
      if (field[position1][position2].a->color == field[&position1 + i][&position2 + j].a->color)
        adj[i + 1][j + 1] = 1;  // friendly
      } else {
      adj[i + 1][j + 1] = 2;  // enemy
      blocked = false;
      }
    }
    if (blocked) return -2;
    int r1 = rand() % 3, r2 = rand() % 3;  // choose a random spot
    r1--;
    r2--;

    while ((r1 == 0 && r2 == 0) || adj[r1][r2] == -1 || adj[r1][r2] == 1)  // if chosen spot is (0,0), or chosen spot is out of bounds or friendly
    {
    r1 = rand() % 3, r2 = rand() % 3;  // choose again
    r1--;
    r2--;
    }
    if (adj[r1][r2] == 0)  // if spot is empty
    {
      if (this->move(position1, position2, position1 + r1, position2 + r2))
      // action successful
      return 5;

    } else { // spot has enemy
    return combat(x, y, x + r1, y + r2);
    }
  }
  tempBlock = nullptr;
}

int AntMover::Run( int nblue, int nred,Position position) {
  _turn = false;  // if false it's blue's turn, if true red
  int i, j, x, y, res;
  i = j = x = y = res = 0;
  while (i < this->_max_turns) {
    while (j < _nummoves) {
    if (_turn == true) {
    this->pickant(position.x, position.y,
    Color::blue);  // tries to call the pickant function from a random position and
    color
    res = CloseAnt(x, y);// don't know what's going
    on here
    if (res == -2)  // ant we picked is blocked,
    choose another one
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
      pickant(x, y, Color::red); // I guess he was trying to use the "pickant" function to take a turn
      res = CloseAnt(x, y); // don't know what's going on here
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
  }
  return 3;  // draw, end of trials
}



// returns: -1: both queens killed, draw. 0: both ants killed, game not over
// yet. 1:first ant killed second. 2: second killed first. 3: queen 2 killed,
// team 1 won. 4: queen 1 killed, team 2 won
int AntMover::combat(Position position, GameField &field) {
  // Majed set the positions of the two queens on either side of the board, they were originally called "a1" "a2"
  int r;
  srand(time(NULL));
  r = rand() % 3;
  int q1 = a1.a->GetAttackPower(); // "a1" is queens set position
  int q2 = a2.a->GetAttackPower(); // "a2" is the second queens position

  if (q1 > q2 || (q1 == q2 && r == 1)) {
    if (q2 == 0)  // if ant 2 is queen
      return 3;  // game over
  a2.a = nullptr;  // otherwise, a1 replaces a2
  a2.full = false;
  this->move(position.x, position.y); // moves the
  position of the ant to the new position of it's foe
  return 1;
  }
  if (q1 < q2 || (q1 == q2 && r == 2)) {
    if (a1.a->GetAttackPower() == 0)  // a1 is queen
      return 4;  // game over
    a1.a = nullptr;  // otherwise, a2 replaces a1
    a1.full = false;
    return 2;
  }
  if (q1 == 0)  // draw,both queens were killed
    return -1;
  else {          // game over, draw
    a1.a = nullptr;  // other wise, both ants got killed
    a1.full = false;
    a2.a = nullptr;
    a2.full = false;
    return 0;
  }
}

*/