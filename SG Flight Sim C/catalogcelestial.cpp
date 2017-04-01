#include "catalogcelestial.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//Galaxy vars
char *milkyways = "Milky Way";
int milkyway[4];
char *pegasuss = "Pegasus";
int pegasus[4];

catalogcelestial::catalogcelestial()//A data catalog of celestial objects in the universe
{
    //#id, x, y, z,
    //Galaxies
    milkyway[0] = 1;
    milkyway[1] = 0;
    milkyway[2] = 0;
    milkyway[3] = 0;

    pegasus[0] = 2;
    pegasus[1] = 100000;
    pegasus[2] = 100000;
    pegasus[3] = 50000;

}

catalogcelestial::~catalogcelestial()
{
    //dtor
}
