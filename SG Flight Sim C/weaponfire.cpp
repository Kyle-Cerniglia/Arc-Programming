#include "weaponfire.h"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

//Ship common variables
extern int shipgun;
extern int shipgunammo;
extern double shippower;

//Gun variables
extern int railsm[];
/*
//Projectile common variables
extern double gunx;
extern double guny;
extern double gunz;
extern double gunpitch;
extern double gunyaw;
extern double gunspeed;
extern double gunspeedmax;
*/
//Ship navigation variables
extern double entityinfo[54][220];

//Entity variables
int extern railsmentitycount;
int railsmentityv[7][100];//[0]existance, [1]x, [2]y, [3]z, [4]pitch, [5]yaw, [6]truespeed, [7]maxspeed
int railsmentitycountcurrent = 0;

extern bool SPACE;
int looptemp = 0;

weaponfire::weaponfire()
{
    if(SPACE == true){
        if(entityinfo[18][0] == -1){//No weapon
            printf("No weapon equipped!\n");
        }

        if(entityinfo[18][0] == 2){//Weapon offline
            printf("Weapon offline");
        }

        if(entityinfo[18][0] == 0){//railsm
            if(entityinfo[20][0] > 0 && entityinfo[26][0] >= railsm[7]){//Check ammo and power
                entityinfo[20][0]--;//Decrease ammo
                entityinfo[26][0] = entityinfo[26][0] - railsm[7];//Drain power

                //Find a valid storage position
                while(looptemp <= 100){//If you are within the variable list bounds
                    if(railsmentityv[0][looptemp] == 0){//If the entity slot is available
//                        railsmentitycountcurrent = railsmentitycount;
                        looptemp = 0;
                    }
                    else{//If entity slot is not available
                        if(looptemp > 100){
                            printf("Error\n");
                        }
                        looptemp++;
                    }
                }
/*
                //railsm local initial entity raycast
                railsmentityv[0][railsmentitycountcurrent] = 1;
                railsmentityv[1][railsmentitycountcurrent] = x;
                railsmentityv[2][railsmentitycountcurrent] = y;
                railsmentityv[3][railsmentitycountcurrent] = z;
                railsmentityv[4][railsmentitycountcurrent] = pitch;
                railsmentityv[5][railsmentitycountcurrent] = yaw;
                railsmentityv[6][railsmentitycountcurrent] = truespeed;
*/
            }
        }
    }
}

weaponfire::~weaponfire()
{
    //dtor
}
