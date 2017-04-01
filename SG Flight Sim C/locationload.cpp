#include "locationload.h"
#include "catalogcelestial.h"

using namespace std;

extern double entitylocation[8][1000];
extern int milkyway[];

locationload::locationload()//Sets the starting location of your ship
{
    entitylocation[5][0] = 0;
    entitylocation[6][0] = 0;
    entitylocation[7][0] = 0;
    entitylocation[2][0] = 0;
    entitylocation[3][0] = 0;
    entitylocation[4][0] = 0;
    entitylocation[1][0] = milkyway[0];
}

locationload::~locationload()
{
    //dtor
}
