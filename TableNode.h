#ifndef TABLENODE.H
#define TABLENODE.H

namespace Ants
{
  class TableNode{
  public:
    TableNode() {} //constructor

    /**4 DIRECTIONS**/
    TableNode * North;
    TableNode * East;
    TableNode * South;
    TableNode * West;
    bool filled; // Aren't these two redundant?
    bool IsEmpty(); // Aren't these two redundant?
  };
}
#endif // TABLENODE.H
