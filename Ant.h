#ifndef ANT_H
#define ANT_H
#include <string>

namespace Ants {
class Ant {
 private:
  Tablenode *location;  // where this ant is
  int _attackPower;

  const Color _color;
  const enum Color { red, blue };
  enum Hierarchy { worker = 1, soldier, knight, Queen };
  enum Direction { LEFT, RIGHT, UP, DOWN };
  struct Position { int x; int y; }
  bool _isDead;

  // the assigned energy that certain ants will have.
  // The higher the hierarchy of ants, the bigger
  int _energy;
  bool dead;

 public:
  Ant(Color, Hierarchy, int AttackPower, int Energy);
  ~Ant();

  void Promote();
  void Demote();

  Color GetColor() const;
  void SetColor(Color color);

  Direction GetDirection() const;
  bool SetDirection(Direction direction);

  Hierarchy GetHierarchy() const;
  void SetHierarchy(Hierarchy hierarchy);

  int GetAttackPower() const;
  void SetAttackPower(int attackPower);

  bool SetLocation(int x, int y);
  Position GetLocation() const;

  int GetEnergy() const;
  void SetEnergy(int energy);

  void Die();
  bool IsDead() const;
  void Turn();
  void Attack(Ant *Enemy);

  std::ostream& operator<<(std::ostream& os, color c)
};
}
#endif  // ANT_H
