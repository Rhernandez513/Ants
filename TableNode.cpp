#include "TABLENODE.H"
using namespace Ants;

TableNode::TableNode() //constructor
{
  North = NULL;
  East = NULL;
  South = NULL;
  West = NULL;
  filled = false;
};

bool TableNode::IsEmpty() { // Aren't these two redundant?
  return filled ? false : true;
}

