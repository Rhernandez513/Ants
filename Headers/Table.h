#ifndef TABLE_H
#define TABLE_H
#include "TableNode.h"

namespace Ants {
class Table {
 private:
  void CreateTable(int length);
 public:
  TableNode *Root;
  Table(int length);
  ~Table();
};
}  // End Namespace
#endif  // TABLE_H
