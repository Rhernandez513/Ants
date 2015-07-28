#ifndef ANT_H
#define ANT_H
#include "Hierarchy.h"

namespace Ants {
  class GameField;
  struct Position { int x; int y; };
  enum Direction { LEFT, RIGHT, UP, DOWN };
  enum Color { red, blue };
class Ant {
 private:
  const Color _color; // red or blue
  Hierarchy _hierarchy; // ant's "level"
  Direction _direction; // direction ant is facing
  int _attackPower;
  bool _isDead;  // True if dead
  
  Position _position; // (x,y)

  // the assigned energy that certain ants will have.
  // The higher the hierarchy of ants, the more energy
  int _energy;

 public:
  Ant(Color color, Hierarchy hierarchy, int AttackPower);
  ~Ant();
  

  void Promote();
  void Demote();

  Color GetColor() const;

  Direction GetDirection() const;
  void SetDirection(Direction direction);

  Hierarchy GetHierarchy() const;
  void SetHierarchy(Hierarchy hierarchy);

  int GetAttackPower() const;
  void SetAttackPower(int attackPower);

  bool SetLocation(GameField &field, Position pos);
  Position GetLocation() const;

  int GetEnergy() const;
  void SetEnergy(int energy);

  void Die();
  bool IsDead() const;
  void Turn();
  void Attack(Ant *Enemy);

  //std::ostream& operator<<(std::ostream& os);
};
}
#endif  // ANT_H
