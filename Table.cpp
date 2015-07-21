#include "TABLE.H"

using Namespace Ants;
int Table::Createtable(int length)  // input a dimension to create the table
{
  /** 4 POINTERS TO TRACK WHICH NODES TO CONNECT **/
  Tablenode *topRight = Root;
  Tablenode *topLeft = Root;
  Tablenode *bottomRight = Root;
  Tablenode *bottomLeft = Root;

  topRight = new Tablenode();
  bottomLeft = new Tablenode();
  Root = topRight;
  topLeft = topRight;
  // Taking square left to right, different for very beginning
  for (int i = 0; i < length; i++) {
    bottomRight = new Tablenode();
    topRight = new Tablenode;

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
  }  // End for
  // Tracking the square downwards
  for (int n = 0; n < length; n++) {
    // Must make sure that the topLeft goes all the way back to the left
    for (int i = 0; i < length; i++) {
      topLeft = topLeft->West;
    }                          // End For
    topLeft = topLeft->South;  // bring it down once
    topRight = topLeft->East;
    bottomLeft = new Tablenode();
    // Making the square go left to right, its different than the top because
    // You do not have to relink the topLeft and topRight
    for (int i = 0; i < length; i++) {
      bottomRight = new Tablenode();
      bottomRight->West = bottomLeft;
      bottomLeft->East = bottomRight;

      topLeft->South = bottomLeft;
      bottomLeft->North = topLeft;

      topRight->South = bottomRight;
      bottomRight->North = topRight;

      topLeft = topLeft->East;
      topRight = topRight->East;
      bottomLeft = bottomRight;
    }  // End Inner For
  }    // End For
}  // End Func
