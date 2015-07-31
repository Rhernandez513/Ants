#ifndef AntMover_H
#define AntMover_H
#include "GameField.h"
#include "Ant.h"

namespace Ants {
	class AntMover {
	private:
		int _res;
		int _max_turns;
		int _nblue, _nred;
		int _nummoves;
		bool _turn;  // false for red, true for blue

	public:
		int Mover(int n, int nblue, int nred, int m);
		bool move(Position position1, Position position2, GameField &field);
		void pickant(int& x, int& y, Color c, GameField &field);
		int Run(int nblue, int nred, Position position1, Position position2);
		int CloseAnt(GameField &field, Ant* ant1);
		int combat(Position position1, Position position2, GameField &field);
	};
}
#endif  // AntMover_H
