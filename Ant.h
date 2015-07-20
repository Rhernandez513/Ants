#ifndef ANT_H
#define ANT_H

namespace Ants
{
  class Ant{
    private:

      Tablenode* location; // where this ant is
      int _attackPower;

      std::string _color; //can be red and blue
      std::string _hierarchy; // different classes, with different attacks, Queen = 0, worker = 1, soldier = 2
      std::string _joiner; // the ant class that joined with, initially set to nobody
      
      bool _isDead;
      bool _joined; // indicator to whether the ant has joined with another ant

    public:
      Tablenode * Getlocation();

      Ant(std::string _color, std::string _hierarchy, int _attackpower) {};
      ~Ant() {};

      /**VARIOUS GETTERS AND SETTERS I THOUGHT USEFUL**/
      std::string GetColor();
      std::string GetHierarchy();
      std::string GetJoiner();
      int GetAttackPower();
      bool GetJoined();

      bool isDead();
      void SetLocation;
      void Turn ();
  };
}
#endif //ANT_H

