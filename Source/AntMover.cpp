#include <iostream>
#include <time.h>
#include <string>
#include "..\\Headers\\Ant.h"
#include "..\\Headers\\GameField.h"
#include "..\\Headers\\AntMover.h"

using namespace Ants; 

struct Block {
	bool full;
	Ant* a;
};
Mover::Mover(int width, int height, int n, int nblue, int nred, int m)
{
	srand(time(NULL));
	this->width = width;
	this->height = height;
	turn = false;
	max_turns = m;
	this->nummoves = n;
	this->nred = nred;
	this->nblue = nblue;
}
bool Mover::move(Position position1, Position position2, GameField &field)  // return 1 if successful
{
	int temp; 
	if ((!field[position1.x][position2.y].SetBlock) ||
		field[position1.x][position2.y].SetBlock)  // if first position is empty (not full) then ant
			// cannot logically move from there. Likewise if
			// the second position is full the ant cannot move
			// there
		return false;

	field[position1.x][position2.y].SetBlock = field[position1.x][position2.y].SetBlock;
	field[position1.x][position2.y].SetBlock = nullptr;
	field[position1.x][position2.y].SetBlock = true;
	field[position1.x][position2.y].SetBlock = false;
	return true;
}

void Mover::pickant(int& x, int& y, Color c, GameField &field) {
	int skips;

	srand(time(NULL));

	if (c == Color::blue)
		skips = rand() % nblue;
	else
		skips = rand() % nred;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (field[i][j].a->color == c) {
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

int Run(bool unlimited, int nblue, int nred, int nummoves,Position position1, Position position2) {
	turn = false;  // if false it's blue's turn, if true red
	int i, j, x, y, res;
	i = j = x = y = res = 0;
	while (i < m || unlimited) {
		while (j < nummoves) {
			if (turn == true) {
				pickant(x, y, Color::blue);  // choose a random blue ant
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

			}
			else {
				pickant(x, y, Color::red);
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

			Color = !blue;
			j = 0;
			i++;
		}
		return 3;  // draw, end of trials
	}

int action(Position position1, Position position2, GameField &field)  // return combat result or 5 for no one killed
{
	srand(time(NULL));
	int adj[3][3];
	bool blocked = true;  // if true, then an ant has no empty space or enemy nearby
		// array of adjacent cells, -1 -> out of bounds,0-> empty, 1-> friendly, 2->
		// enemy
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			if (&position1 + i < 0 || &position1 + i > width || &position2 + j < 0 || &position2 + j > height) {
				adj[i + 1][j + 1] = -1;
				i++;
				continue;
			}
			if (!field[x + i][y + j].full) {
				adj[i + 1][j + 1] = 0;
				blocked = false;  // empty space nearby
			}
			else {
				if (field[x][y].a->color == field[&position1 + i][&position2 + j].a->color)
					adj[i + 1][j + 1] = 1;  // friendly
			}
			else {
				adj[i + 1][j + 1] = 2;  // enemy
				blocked = false;
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
			if (move(position1, position2, &position1 + r1, &position2 + r2))  // action successful
				return 5;

		}
		else  // spot has enemy
		{
			return combat(x, y, x + r1, y + r2);
		}
	}
}

	// returns: -1: both queens killed, draw. 0: both ants killed, game not over
	// yet. 1:first ant killed second. 2: second killed first. 3: queen 2 killed,
	// team 1 won. 4: queen 1 killed, team 2 won
int combat(Position position1, Position position2, GameField &field) {
	Block a1 = field[position1.x][position2.y];
	Block a2 = field[position1.x][position2.y];
	int r;
	srand(time(NULL));
	r = rand() % 3;
	int q1 = a1.a->GetAttackPower();
	int q2 = a2.a->GetAttackPower();

		if (q1 > q2 || (q1 == q2 && r == 1)) {
			if (q2 == 0)  // if ant 2 is queen
				return 3;  // game over
			a2.a = nullptr;  // otherwise, a1 replaces a2
			a2.full = false;
			move(position1, position2);
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
		else{					// game over, draw
			a1.a = nullptr;  // other wise, both ants got killed
			a1.full = false;
			a2.a = nullptr;
			a2.full = false;
			return 0;
		}
	}
}
