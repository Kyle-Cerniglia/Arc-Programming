#include "shipload.h"
#include "catalogship.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

using namespace std;

extern char *f89xs;
extern double f89x[];
extern char *astrixs;
extern double astrix[];

//Generic ship vars
extern char *shiptype;
extern double entityinfo[61][220];

int shipselection = 0;

shipload::shipload()//Loads ship data from the selected ship
{
//[0]typeid (1=PShip 2=AIShip 3=Static 4=charge 5=missile), [1]id, [2]galaxy, [3]galx, [4]galy, [5]galz, [6]x, [7]y, [8]z,
//[9]pitch, [10]yaw, [11]xspeed, [12]yspeed,
//[13]zspeed, [14]targetable?, [15]maxspeed(m/s),
//[16]accel(m/sec^2), [17]mass(kg), [18]gun, [19]missile,
//[20]ammo1, [21]ammo2, [22]hitbox(m(radius)), [23]shieldhp,
//[24]shieldregen, [25]hullhp, [26]power(GJ),
//[27]powerregen(GJ/sec), [28]hyperdrivespeed(LY/s),
//[29]hyperdrive, [30]sublights, [31]manuvering, [32]shields,
//[33]reactor, [34]capacitor, [35]longrange sensors,
//[36]shortrange sensors, [37]subspace radio, [38]lifesupport,
//[39]inertial dampeners, [40]cloak, [41]dmg(weapon),
//[42]range(m weapon), [43]rotationspeedmax,
//[44]rotationspeedaccel, [45]rotationspeeddecell,
//[46]xmaxspeed, [47]xaccel, [48]xdecell, [49]ymaxspeed,
//[50]yaccel, [51]ydecell, [52]pitchspeed, [53]yawspeed,
//[54]baccel, [55]bmaxspeed, [56]shieldmax, [57]hullmax,
//[58]powermax, [59]dmgreceive, [60]cargo

    printf("Select your ship:\n");
    printf("1: %s\n", f89xs);
    printf("2: %s\n", astrixs);

    shipselection = getch();

    switch(shipselection){
        case '1':
        printf("%s", f89xs);
        printf(" selected!\n");
        shiptype = f89xs;

        entityinfo[0][0] = 1;
        entityinfo[1][0] = f89x[0];


        //entityinfo[44][0] = 1 / ((entityinfo[17][0] * entityinfo[16][0]) / 10000000);
        //entityinfo[43][0] = entityinfo[17][0] / (2 * pow(entityinfo[15][0], 2));

        return;

        case '2':
        printf("%s", astrixs);
        printf(" selected!\n");
        shiptype = astrixs;

        //entityinfo[44][0] = 1 / ((entityinfo[17][0] * entityinfo[16][0]) / 10000000);
        //entityinfo[43][0] = entityinfo[17][0] / (2 * pow(entityinfo[15][0], 2));

        return;
    }
}

shipload::~shipload()
{
    //dtor
}
