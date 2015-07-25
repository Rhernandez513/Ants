#include "TABLENODE.H"
using namespace Ants;

TableNode::TableNode()  // constructor
{
  isCurrentlyEmpty = true; 
};

TableNode::~TableNode()  // constructor
{
  North = nullptr;
  East = nullptr;
  South = nullptr;
  West = nullptr;
};

bool TableNode::IsEmpty() {
  return isCurrentlyEmpty;
}
