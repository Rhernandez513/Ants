#ifndef TABLE_H
#define TABLE_H

namespace Ants {
  class Table {
    public:
      TableNode * Root;
      Table(){ Root = NULL; }
      ~Table();
      int CreateTable (int length);
  };
} // End Namespace
#endif //TABLE_H

