#ifndef ANT_H
#define ANT_H
#include "Hierarchy.h"
#include "Containers.h"

namespace Ants {
class GameField;
class Ant {
 private:
  Color _color;    // red or blue
  Hierarchy _hierarchy;  // ant's "level"
  Direction _direction;  // direction ant is facing
  int _attackPower;
  bool _isDead;  // True if dead
  bool _just_promoted;

  Position _position;  // (x,y)

                  /*DEPRECATED*/
  //// the assigned energy that certain ants will have.
  //// The higher the hierarchy of ants, the more energy
  //int _energy;

 public:
  // Spawn an Ant!! But you first must construct more pylons!
  Ant(Color color, Hierarchy hierarchy);
  // Spawn an Ant!! But you first must construct more pylons!
  Ant(Color color, Hierarchy hierarchy, int AttackPower);
  // Destructor
  ~Ant();

  // Promote's Ant to next Highest Rank
  void Promote();
             /*DEPRECATED*/
  //// Demote's Ant to next Lowest Rank
  //void Demote();

  // Return's Ant's  Color Value
  Color GetColor() const;

             /*DEPRECATED*/
  //// Returns the direction the Ant is facing
  //Direction GetDirection() const;
  //// Sets the direction the Ant is facing
  //void SetDirection(Direction direction);

  // Return's Ant's Ranking in the Hierarchy
  Hierarchy GetHierarchy() const;
  // Set Ant's Ranking in the Hierarchy
  void SetHierarchy(Hierarchy hierarchy);

  // Return's Ant's Attack Power
  int GetAttackPower() const;
  // Set's Ant's Attack Power
  void SetAttackPower(int attackPower);

  void SetLocation(Position pos);
  // Return's Ant's Location
  Position GetLocation() const;

       /* DEPRECATED */
  //// Return's Ant's Energy Value
  //int GetEnergy() const;
  //// Set Ant's Energy Value
  //void SetEnergy(int energy);

  // This Kills the Ant...
  void Die();

  // Returns true if the Ant is Dead
  // False otherwise
  bool IsDead() const;

  //// NOT IMPLEMENTED
  //void Turn();

  // The Ant slams it's enemy with a mighty blow!!
  void Attack(Ant* Enemy);
};
}
#endif  // ANT_H
