#include <iostream>

#include <string>

#include <stdlib.h>

#include <time.h>

#include <stdio.h>


using namespace std;


class Tablenode{

public:

    /**4 DIRECTIONS**/

    Tablenode *North;

    Tablenode *East;

    Tablenode *South;

    Tablenode *West;

    bool filled;

    bool IsEmpty()

    { if (filled = true){return true;} else {return false;}}

    Tablenode() //constructor

    {

        North = NULL; East = NULL;

        South = NULL; West = NULL;

        filled = false;

    }

};


class Table { //tracks where the table begins

public:

    Tablenode *Root;

    Table(){Root = NULL;}

    int createtable (int length);

};

int Table:: createtable(int length) //input a dimension to create the table

{

    /** 4 POINTERS TO TRACK WHICH NODES TO CONNECT **/

    Tablenode * topRight = Root;

    Tablenode * topLeft = Root;

    Tablenode * bottomRight = Root;

    Tablenode * bottomLeft = Root;

    topRight = new Tablenode();

    bottomLeft = new Tablenode();

    Root = topRight;

    topLeft = topRight;

    for (int i = 0; i<length; i++) //taking square left to right, different for very beginning

    {

        bottomRight = new Tablenode();

        topRight = new Tablenode;

        topRight->West = topLeft; topLeft->East = topRight;

        bottomRight->West = bottomLeft; bottomLeft->East = bottomRight;

        topLeft->South = bottomLeft; bottomLeft->North = topLeft;

        topRight->South = bottomRight; bottomRight->North = topRight;

        topLeft = topRight;

        bottomLeft = bottomRight;

    }

    for (int n = 0; n<length; n++){ //tracking the square downwards

        for (int i = 0; i<length; i++) {topLeft = topLeft->West;} //must make sure that the topLeft goes all the way back to the left

        topLeft = topLeft->South; //bring it down once

        topRight = topLeft->East;

        bottomLeft = new Tablenode();

        for (int i = 0; i<length; i++) //making the square go left to right, its different than the top because you do not have to relink the topLeft and topRight

        {

            bottomRight = new Tablenode();

            bottomRight->West = bottomLeft; bottomLeft->East = bottomRight;

            topLeft->South = bottomLeft; bottomLeft->North = topLeft;

            topRight->South = bottomRight; bottomRight->North = topRight;

            topLeft = topLeft->East;

            topRight = topRight->East;

            bottomLeft = bottomRight;

        }

    }


}

class Ant{

public:

    string color; //can be red and blue

    string hierarchy; // different classes, with different attacks, Queen = 0, worker = 1, soldier = 2

    Tablenode* location; // where this ant is

    int energy;

    bool dead;

    Ant(){};

    /**SET THE ANTS VARIABLES**/

    void set_up(string color_, string hierarchy_, int energy_)

    {

        color = color_;

        hierarchy = hierarchy_;

        energy = energy_;

        dead = false;

        location = NULL;

    };

    /**VARIOUS GETTERS AND SETTERS I THOUGHT USEFUL**/

    string getcolor(){ return color;}

    string gethierarchy() {return hierarchy;}

    int energy() {return energy;}

    Tablenode * getlocation() {return location;}

    void isdead();

    void SetLocation (Tablenode * new_location);

    void turn ();

};
