#ifndef FIELD_H
#define FIELD_H

namespace Ants {
public static class GameField {
  private
    int _length;
    int _width;
    enum Type { EMPTY, ANT };
  public:
    Field(int length, width);
    ~Field();

    Type GetBlock(Position pos);
    bool SetBlock(Type blockType, int x, int y);

    int GetLength();
    int GetWidth();
};
}
#endif // FIELD_H

