#ifndef AntMover_H
#define AntMover_H
#include "GameField.h"
#include "Ant.h"

namespace Ants {
	class Mover {
	private:
		int width, height;
		int res;
		int max_turns;
		int nblue, nred;
		int nummoves;
		bool turn;  // false for red, true for blue

	public:
		Mover(int width, int height, int n, int nblue, int nred, int m);
		bool move(Position position1, Position position2, GameField &field);
		void pickant(int& x, int& y, Color c, GameField &field);
		int Run(bool unlimited);
	};
}
#endif  // AntMover_H
