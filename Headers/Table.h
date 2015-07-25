#ifndef TABLE_H
#define TABLE_H

namespace Ants {
class Table {
 private:
  void CreateTable(int length);
 public:
  TableNode *Root;
  Table() { };
  ~Table() { };
};
}  // End Namespace
#endif  // TABLE_H
