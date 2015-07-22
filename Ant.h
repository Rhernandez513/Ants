#ifndef ANT_H
#define ANT_H
#include <string>

namespace Ants {
class Ant {
 private:
  Tablenode *location;  // where this ant is
  int _attackPower;

  std::string _color;      // can be red and blue
  std::string _hierarchy;  // different classes, with different attacks, Queen =
                           // 0, worker = 1, soldier = 2

  bool _isDead;
  bool _joined;  // indicator to whether the ant has joined with another ant

  // the assigned energy that certain ants will have.
  // The higher the hierarchy of ants, the bigger
  int energy;
  // true/false on whether or not an ant is dead or not
  bool dead;

 public:
  Tablenode *Getlocation();

  Ant(std::string color, std::string hierarchy, int attackpower) { };
  ~Ant(){ };

  /**VARIOUS GETTERS AND SETTERS I THOUGHT USEFUL**/
  std::string GetColor();
  std::string GetHierarchy();
  std::string GetJoiner();
  int GetAttackPower();

  void Die();
  bool IsDead();
  void SetLocation;
  void Turn();
  void Attack(Ant *Enemy);
  int GetEnergy();
};
}
#endif  // ANT_H
