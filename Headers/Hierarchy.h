#ifndef HIERARCHY_H
#define HIERARCHY_H

namespace Ants {
enum class Hierarchy { Worker = 1, Soldier, Knight, Queen };

  Hierarchy& operator--(Hierarchy& hierarchy);
  Hierarchy& operator++(Hierarchy& hierarchy);
  //Hierarchy& operator<<(Hierarchy& hierarchy);
}
#endif // HIERARCHY_H
