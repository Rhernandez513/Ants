#include "../Headers/Table.h"
#include "../Headers/TableNode.h"

using namespace Ants;

Table::Table(int length) {
  CreateTable(length);
};

Table::~Table() { };

void Table::CreateTable(int length)  // input a dimension to create the table
{
  /** 4 POINTERS TO TRACK WHICH NODES TO CONNECT **/
  TableNode *topRight = Root;
  TableNode *topLeft = Root;
  TableNode *bottomRight = Root;
  TableNode *bottomLeft = Root;

  topRight = new TableNode();
  bottomLeft = new TableNode();
  Root = topRight;
  topLeft = topRight;
  // Taking square left to right, different for very beginning
  for (int i = 0; i < length; i++) {
    bottomRight = new TableNode();
    topRight = new TableNode;

    topRight->West = topLeft;
    topLeft->East = topRight;

    bottomRight->West = bottomLeft;
    bottomLeft->East = bottomRight;

    topLeft->South = bottomLeft;
    bottomLeft->North = topLeft;

    topRight->South = bottomRight;
    bottomRight->North = topRight;

    topLeft = topRight;
    bottomLeft = bottomRight;
  } // End for
  // Tracking the square downwards
  for (int n = 0; n < length; n++) {
    // Must make sure that the topLeft goes all the way back to the left
    for (int i = 0; i < length; i++) {
      topLeft = topLeft->West;
    }
    topLeft = topLeft->South;  // bring it down once
    topRight = topLeft->East;
    bottomLeft = new TableNode();
    // Making the square go left to right, its different than the top because
    // You do not have to relink the topLeft and topRight
    for (int i = 0; i < length; i++) {
      bottomRight = new TableNode();
      bottomRight->West = bottomLeft;
      bottomLeft->East = bottomRight;

      topLeft->South = bottomLeft;
      bottomLeft->North = topLeft;

      topRight->South = bottomRight;
      bottomRight->North = topRight;

      topLeft = topLeft->East;
      topRight = topRight->East;
      bottomLeft = bottomRight;
    } // End Inner For
  } // End For
}

