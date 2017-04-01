#include "missilefire.h"

#include <stdio.h>

using namespace std;

//Ship common variables
extern int shipmissile;
extern int shipmissileammo;
extern double shippower;
extern int shipgun;

//Gun variables
extern int aim120a[];

//Projectile common variables
extern double missilex;
extern double missiley;
extern double missilez;
extern double missilepitch;
extern double missileyaw;
extern double missilespeed;
extern double missilespeedmax;

//Ship navigation variables
extern double entitylocation[8][1000];
extern double entityvelocity[8][1000];
extern double entitystat[24][1000];

missilefire::missilefire()
{

    if(shipgun == 0){//No weapon
        printf("No weapon equipped!\n");
    }
    if(shipgun == 2){//aim120a
        if(entitystat[14][0] > 0 && entitystat[22][0] >= aim120a[7]){//Check ammo and power
        entitystat[14][0]--;//Decrease ammo
        entitystat[22][0] = entitystat[22][0] - aim120a[7];//Drain power
        //Local initial raycast
        missilex = entitylocation[5][0];
        missiley = entitylocation[6][0];
        missilez = entitylocation[7][0];
        missilepitch = entityvelocity[1][0];
        missileyaw = entityvelocity[3][0];
        missilespeed = entityvelocity[7][0];
        //Common variable load
        missilespeedmax = aim120a[2];
    }
    }
    //travel distance away from ship
    //angle towards target
    //detect hitbox
    //loop or cause damage
    //check range
}

missilefire::~missilefire()
{
    //dtor
}

