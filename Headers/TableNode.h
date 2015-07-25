#ifndef TABLENODE.H
#define TABLENODE .H

namespace Ants {
class TableNode {
 private:
   bool isCurrentlyEmpty;
 public:
  TableNode() {}
  ~TableNode() {}
  /**4 DIRECTIONS**/
  TableNode *North;
  TableNode *East;
  TableNode *South;
  TableNode *West;
  bool IsEmpty();
};
}
#endif  // TABLENODE.H
